<?php

/**
 * @file
 * NY Senate Statute Lib.
 */

/**
 * Clean out duplicate url_aliases.
 */
function nys_statute_import_clean_duplicate_url_aliases() {

  // Set maintenance mode
  $default_maintenance_message = variable_get('maintenance_mode_message');
  variable_set('maintenance_mode_message', 'NYSenate.gov is currently disabled for routine maintenance. Service should resume shortly. Please refresh this page after a few minutes.');
  variable_set('maintenance_mode', 1);
  nys_utils_send_slack_notification("NYSenate.gov maintenance mode enabled for statute alias de-duplication process.",null,'#publicwebsite-notices',null,'warning');


  // Get size of `url_alias` table.
  $num_rows = db_query("SELECT COUNT(*) FROM `url_alias`")->fetchField();
  watchdog("nys_statute_clean", "The size of `url_alias` table = $num_rows BEFORE");

  // Clone the `url_alias` table.
  db_query("CREATE TABLE `url_alias_copy` LIKE `url_alias`");
  watchdog("nys_statute_clean", "Created temporary `url_alias_copy` table.");

  // Copy the distinct rows into the new table.
  db_query("INSERT INTO url_alias_copy(`source`, `alias`, `language`)
            SELECT DISTINCT source, alias, language FROM `url_alias`");

  // Get the number of rows copied.
  $num_rows = db_query("SELECT COUNT(*) FROM `url_alias_copy`")->fetchField();
  watchdog("nys_statute_clean", "The number of rows copied = $num_rows");

  // Clear out the `url_alias` table.
  db_truncate('url_alias')->execute();
  $num_rows = db_query("SELECT COUNT(*) FROM `url_alias`")->fetchField();
  watchdog("nys_statute_clean", "Truncated the `url_alias` table in preparation. Size = $num_rows");

  // Copy the compacted table into the url_alias table.
  db_query("INSERT `url_alias`
            SELECT * FROM `url_alias_copy`");

  // Get the number of rows copied into the `url_alias` table.
  $num_rows = db_query("SELECT COUNT(*) FROM `url_alias`")->fetchField();
  watchdog("nys_statute_clean", "The number of rows copied into the `url_alias` table = $num_rows AFTER");

  // Get rid of the temp tables.
  db_drop_table('url_alias_copy');
  watchdog("nys_statute_clean", "Deleted the `url_alias_copy` table.");

  // Unset maintenance mode
  variable_set('maintenance_mode', 0);
  variable_set('maintenance_mode_message',$default_maintenance_message);
  nys_utils_send_slack_notification("NYSenate.gov maintenance mode is now disabled.",null,'#publicwebsite-notices',null,'good');

}

/**
 * Clean out content url_aliases for statutes.
 * This is an expensive transaction that should not be run with any frequency.
 */
function nys_statute_import_clean_content_url_aliases() {

  // Get size of `url_alias` table.
  $num_rows = db_query("SELECT COUNT(*) FROM `url_alias`")->fetchField();
  watchdog("nys_statute_clean_content", "The size of `url_alias` table = $num_rows BEFORE");

  // Do this first - creates copy of the url_alias table.
  db_query("CREATE TABLE `url_alias_util` LIKE `url_alias`");
  watchdog("nys_statute_clean_content", "Created temp table `url_alias_util`.");

  // Copies the url_alias table to the url_alias_util table.
  db_query("INSERT `url_alias_util` SELECT * FROM `url_alias`");
  watchdog("nys_statute_clean_content", "Copied `url_alias` to `url_alias_util` table.");

  // Deletes the `content/*` aliases.
  db_query("DELETE   FROM url_alias WHERE pid IN (SELECT url_alias_util.pid FROM url_alias_util, node WHERE
            node.nid = SUBSTRING_INDEX(url_alias_util.source, '/', -1) AND
            url_alias_util.alias LIKE 'content/%' AND
            type = 'statute' AND
            source IN (SELECT source FROM url_alias_util WHERE source LIKE 'node/%' GROUP BY source HAVING COUNT(source) > 1))");
  watchdog("nys_statute_clean_content", "Deleted the `content/*` aliases.");

  // Delete copy backup table.
  db_drop_table('url_alias_util');
  watchdog("nys_statute_clean_content", "Deleted the `url_alias_util` table.");

  // Get size of `url_alias` table.
  $num_rows = db_query("SELECT COUNT(*) FROM `url_alias`")->fetchField();
  watchdog("nys_statute_clean_content", "The size of `url_alias` table = $num_rows AFTER");

}

/**
 * Cleans out bad nidless url aliases with the source 'node/'.
 */
function nys_statute_import_remove_nidless_url_aliases() {

  // Get count of bad aliases
  $num_rows = db_query("SELECT COUNT(*) FROM url_alias WHERE source = 'node/'")->fetchField();
  watchdog("url_alias_cleanup", "There are $num_rows aliases where source = 'node/' BEFORE");

  // Deletes the nidless 'node/' url aliases.
  db_query("DELETE FROM url_alias WHERE source = 'node/'");
  watchdog("url_alias_cleanup", "Copied `url_alias` to `url_alias_util` table.");


  // Get count of bad aliases
  $num_rows = db_query("SELECT COUNT(*) FROM url_alias WHERE source = 'node/'")->fetchField();
  watchdog("url_alias_cleanup", "There are $num_rows aliases where source = 'node/' BEFORE");

}

/**
 * Cleans out duplicate url aliases for bills.
 * These are the shorter aliases that were for an amendment.
 * They have been replaced by new short aliases that always point to the latest amendment.
 * The aliases removed still pointed to the original or earlier mendment.
 */
function nys_statute_import_remove_duplicate_bill_url_aliases() {
  for ($i = 0; $i <= 4; $i++) {
    $original_source = '';
    $delete_count = 0;
    $results = db_query("select alias, count(pid) from url_alias group by alias having count(pid) > 1");
    foreach($results as $row) {
      // Lookup the alias
      $set_of_sources = "";
      $alias_results = db_query("SELECT * FROM url_alias WHERE alias = :alias", array(':alias' => $row->alias));
      foreach($alias_results as $index => $alias_result) {

        if (strncmp($alias_result->source, 'node', strlen('node')) == 0) {
          // It's a node
          if ($index == 0) {
            $set_of_sources .= "'" . $alias_result->source . "'";
          }
          else {
            $set_of_sources .= ",'" . $alias_result->source . "'";
          }
        }
        elseif(strncmp($alias_result->source, 'taxonomy/term', strlen('taxonomy/term')) == 0) {
          // It's a taxonomy term.
          // There are so few (6) by hand would be best.
          //print "It's a taxonomy term <br>";
        }
      }

      // A set of url aliases has been determined.
      if (!empty($set_of_sources)) {
        $deleted_url_alias = false;

        $url_alias_results = db_query("SELECT * FROM url_alias WHERE source IN ($set_of_sources)");

        $aliases_array = $url_alias_results->fetchAll();

        // We are going to loop thru two or three times.
        // Pass 1 looking for node id of one with an alias ending with */amendment/original.
        foreach($aliases_array as $alias_array) {
          // The url alias ends with '/amendment/original'.
          if (substr_compare($alias_array->alias, '/amendment/original', -strlen('/amendment/original')) === 0) {
            $original_pid = $alias_array->pid; //??? used ??
            $original_source = $alias_array->source;
            break;
          }
        }

        // Second pass looking for the pid to delete ie same source as /amendment/original.
        foreach($aliases_array as $alias_array) {
          // The url alias DOES NOT end with '/amendment/original' AND source matches.
          if (substr_compare($alias_array->alias, '/amendment/original', -strlen('/amendment/original')) != 0 && strcmp($alias_array->source, $original_source) == 0) {
            $delete_count++;

            db_query("DELETE FROM `url_alias` WHERE `pid` = :pid", array(':pid' => $alias_array->pid) );
            $deleted_url_alias = true;
            break;
          }
        }

        if ($deleted_url_alias == false) {
          // Third pass catch any lettered amendments.
          $pids =  array();
          foreach($aliases_array as $alias_array) {
            // If its one of duplicates.
            if (strcasecmp($alias_array->alias, $row->alias) == 0) {
              $pids[] = $alias_array->pid;
            }
          }

          db_query("DELETE FROM `url_alias` WHERE `pid` = :pid", array(':pid' => min($pids)) );
          $deleted_url_alias = true;
          $delete_count++;

        }

      }
    }

    watchdog('url_alias_cleanup',"Deleted $delete_count Duplicate Bill url aliases.");
  }
}
