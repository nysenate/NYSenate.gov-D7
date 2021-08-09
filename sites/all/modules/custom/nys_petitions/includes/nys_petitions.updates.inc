<?php

/**
 * @file nys_petitions.updates.inc
 * Functions providing for various nys_petitions data updates.
 */

/**
 * See issue #10612.
 *
 * The original release of nys_petitions allowed for blank form
 * control entries, such as email, address, or name. Additionally,
 * a large difference in the number of records between the
 * nys_petitions and flagging tables makes the gathering of
 * statistics nearly impossible.  This function is designed to
 * address those deficiencies.
 *
 * First, the flagging table is backed up to a new table -
 * flag_backup.  Next, all suspect records in flagging are
 * copied to a new table - flag_archive.  Suspect records are
 * identified by user ID (must be zero, indicating an anonymous
 * flag), flag type (must be "sign petition"), and timestamp
 * (must pre-date the 2016-10-21 release of the new version of
 * the nys_petitions module, or 1477086406).  These two tables
 * are for data retention protection only, and should be cleaned
 * up/removed once the results have been verified.
 *
 * After backing up and archiving, all target records are deleted
 * from flagging.  Flagging records will be recreated through a
 * bulk INSERT..SELECT from nys_petitions.  To create new records
 * for the accumulator, the function will iterate through all target
 * records from nys_petitions (based solely on timestamp), calling
 * an accumulator API function for each.  The new accumulator and
 * flagging records will each show the original timestamp.
 *
 */
function nys_petitions_update_clean_anonymous_petitions() {

  // Initialize return status.
  $ret = '';
  nyslog("Entering " . __FUNCTION__);

  // Make sure this update has not run previously.  Running it a
  // second time could be destructive.
  $has_run = variable_get('nys_petitions_update_7101_complete', false);
  if ($has_run) {
    $ret = "FATAL: Update nys_petitions_update_7101() has already run!\n " .
      "If you are absolutely positive this update needs to run again, delete " .
      "the Drupal variable 'nys_petitions_update_7101_complete'.";
    print "$ret\n";
    throw new DrupalUpdateException($ret);
  }

  // Internal status flag.
  $update_success = true;

  // Reference to the timestamp.  Records must have been created
  // before this date in order to be targeted for rebuilding.
  // date('Y-m-d H:i:s e', 1477086406) = '2016-10-21 17:46:46 America/New_York'.
  $ts_cutoff = 1477086406;

  // Make sure the flagging table has been fully backed up.
  $is_flagging_saved = (int) variable_get('nys_petitions_update_save_flagging', 0);
  $is_petitions_saved = (int) variable_get('nys_petitions_update_save_petitions', 0);
  $all_tables_saved = $is_flagging_saved && $is_petitions_saved;

  if (!$all_tables_saved) {
    if (!$is_flagging_saved) {
      try {
        // Create the backup table if it does not exist.
        if (!db_table_exists('nysbackup_flagging')) {
          db_query('CREATE TABLE nysbackup_flagging LIKE flagging');
        }

        // Get the expected row count for the copy.
        $source_rows = db_query('SELECT COUNT(*) FROM flagging')->fetchCol()[0];
        nyslog("Found $source_rows rows for backup in flagging");

        // Clear the backup table, and execute the copy.
        db_query('TRUNCATE nysbackup_flagging');
        db_query('INSERT INTO nysbackup_flagging SELECT * FROM flagging');

        // Check the expected row count.
        $backup_rows = db_query('SELECT COUNT(*) FROM nysbackup_flagging')->fetchCol()[0];
        nyslog("Found $backup_rows rows in flagging backup");
        if ($source_rows != $backup_rows) {
          $msg = 'Backup of flagging table did not show expected record count! (' .
            $source_rows . ' source vs ' . $backup_rows . ' backed up)';
          $ret .= "$msg\n";
          nyslog($msg);
          throw new DrupalUpdateException($msg);
        }
      }
      catch (Exception $e) {
        $ret .= 'Backup of flagging table backup failed: ' . $e->getMessage() . "\n";
        $update_success = false;
      }

      if ($update_success) {
        variable_set('nys_petitions_update_save_flagging', 1);
        $is_flagging_saved = true;
      }
    }

    if (!$is_petitions_saved) {
      try {
        // Create the backup table if it does not exist.
        if (!db_table_exists('nysbackup_petitions')) {
          db_query('CREATE TABLE nysbackup_petitions LIKE nys_petitions');
        }

        // Get the expected row count for the copy.
        $source_rows = db_query('SELECT COUNT(*) FROM nys_petitions')->fetchCol()[0];
        nyslog("Found $source_rows rows for backup in nys_petitions");

        // Clear the backup table, and execute the copy.
        db_query('TRUNCATE nysbackup_petitions');
        db_query('INSERT INTO nysbackup_petitions SELECT * FROM nys_petitions');

        // Check the expected row count.
        $backup_rows = db_query('SELECT COUNT(*) FROM nysbackup_petitions')->fetchCol()[0];
        nyslog("Found $backup_rows rows nys_petitions backup");

        if ($source_rows != $backup_rows) {
          $msg = 'Backup of nys_petitions table did not show expected record count! (' .
            $source_rows . ' source vs ' . $backup_rows . ' backed up)';
          $ret .= "$msg\n";
          nyslog($msg);
          throw new DrupalUpdateException($msg);
        }
      }
      catch (Exception $e) {
        $ret .= 'Backup of nys_petitions table backup failed: ' . $e->getMessage() . "\n";
        $update_success = false;
      }

      if ($update_success) {
        variable_set('nys_petitions_update_save_petitions', 1);
        $is_petitions_saved = true;
      }
    }

    if ($update_success) {
      $all_tables_saved = $is_flagging_saved && $is_petitions_saved;
      $ret .= "Tables have been backed up.\n";
      nyslog("Backup successfully completed");
    }
  }

  // We need to target petition records in the flagging table.  Fetch the
  // flag type identifier.
  $fid_type = (int) (db_query("SELECT fid FROM flag WHERE name=:n",
    array(':n' => 'sign_petition'))
    ->fetchCol()[0]);

  // Ready to do actual work?
  if ($all_tables_saved) {
    // In the first iteration of code, records in nys_petitions were not
    // deleted when a user created an account.  Go back and remove those
    // records if they point to a valid user.
    $query = "DELETE np.* FROM nys_petitions np INNER JOIN flagging f " .
      "ON np.fid=f.flagging_id WHERE uid > 0";
    $delete_result = db_query($query)->rowCount();
    nyslog("Deleted $delete_result ex-anonymous rows from nys_petitions");

    // Remove all flagging records that are associated with petitions
    // and were generated by anonymous users.
    $query = "DELETE f.* FROM flagging f INNER JOIN node n ON " .
      "f.entity_type='node' AND f.entity_id=n.nid WHERE f.uid=0 AND " .
      "n.type='petition'";
    $delete_result = db_query($query)->rowCount();
    nyslog("Deleted $delete_result anonymous rows from flagging");

    // Bulk INSERT all current nys_petitions target records into flagging.
    $query = "INSERT INTO flagging SELECT fid, :fidtype, :etype, pid, " .
      ":uid, session_id, timestamp FROM nys_petitions";
    $insert_result = db_query($query,
      array(':fidtype' => $fid_type,
        ':etype' => 'node',
        ':uid' => '0',
        /*':ts' => $ts_cutoff,*/
        ))->rowCount();
    nyslog("INSERTed $insert_result contrived rows into flagging from nys_petitions");

    // Reset the flag counters to avoid people freaking out.
    $query = "UPDATE flag_counts fc LEFT JOIN (SELECT f.fid, f.entity_type, " .
      "f.entity_id, COUNT(f.flagging_id) AS newcount FROM flagging f GROUP BY " .
      "f.fid, f.entity_type, f.entity_id) src ON fc.entity_id = src.entity_id " .
      "AND fc.entity_type = src.entity_type AND fc.fid = src.fid SET fc.`count` " .
      "= IFNULL(src.newcount,0)";
    $update_result = db_query($query)->rowCount();
    nyslog("UPDATE of flag_counts complete ($update_result rows)");

    // Load the records from nys_petitions.
    $query = "SELECT * FROM nys_petitions WHERE timestamp < :ts ORDER BY sid";
    $petition_rows = db_query($query, array(':ts' => $ts_cutoff));

    // A pointer to allow for continuation of update after an interruption.
    $row_pointer = (int) variable_get('nys_petitions_update_7101_pointer', 0);

    // Fake an account object to pass in the anonymous uid.
    $acct_obj = (object) ['uid' => 0];
    $total_count = 0;
    $accum_count = 0;

    while ($single_row = $petition_rows->fetchObject()) {
      $total_count++;
      // Only act on rows not already rebuilt.
      if ($row_pointer < $single_row->sid) {
        // Generate a fake flag object for the accumulator to act on.
        $new_flag = (object) [
          'flag_name' => 'sign_petition',
          'flagging_id' => $single_row->fid,
          'entity_id' => $single_row->pid,
        ];
        nyslog("Generating new accumulator record for petition row {$single_row->sid}");
        nyslog("new_flag=\n".var_export($new_flag,1));
        $accum_count++;

        // Call the accumulator processing function.
        _nys_accumulator_process_flag(true, $acct_obj, $new_flag);

        // on success, write the pointer.
        variable_set('nys_petitions_update_7101_pointer', $single_row->sid);
      }
    }
    nyslog("Total petition count: $total_count, records generated: $accum_count");

    // All done!
    $update_success = true;
  }

  // If everything is spiffy, clean up.
  if ($update_success) {
    variable_set('nys_petitions_update_7101_complete', TRUE);
    variable_del('nys_petitions_update_save_flagging');
    variable_del('nys_petitions_update_save_petitions');
    variable_del('nys_petitions_update_7101_pointer');
    $ret .= "Update 7101 for nys_petitions is complete.  Once data has been " .
      "verified, tables `nysbackup_flagging` and `nysbackup_petitions` may " .
      "be deleted.";
  }
  else {
    $ret .= "Something went wrong.  Restore the flagging table from flag_backup " .
      "or flag_archive, and re-run this update.";
  }

  return $ret;
}
