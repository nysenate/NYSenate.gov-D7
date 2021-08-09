<?php
/**
 * @file nys_registration.drush.inc.php
 */

/**
 * Implements hook_drush_command().
 *
 * @return array
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function nys_registration_drush_command() {
  $items = [];

  $items['user-purge'] = [
    "description" => "Removes aged unconfirmed accounts",
    "options" => [
      "min-days" => "Minimum age of unconfirmed accounts to be deleted.",
      "max-users" => "Maximum number of records to select for deletion.",
      "count-only" => "Discovers user accounts to be deleted, but does not delete.",
      "show-count" => "Shows the final number of deleted records per table. (raw mode only)",
      "optimize" => "Run 'OPTIMIZE TABLE' on each table touched.  (raw mode only)",
      "use-raw" => "Raw mode, which uses direct queries rather than Drupals API.  SEE HELP NOTES!",
    ],
  ];

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * @param $section
 *
 * @return array|mixed|string|null
 */
function nys_registration_drush_help($section) {
  switch ($section) {
    case 'drush:user-purge':
      return dt('Removes unconfirmed accounts older than a specified window (defaults to 7 days).  Unconfirmed accounts are those which have not received a login since registration for the specified time.  Use --count-only to determine how many user accounts will be targeted by the process.  Use --max-users to limit the number of deletions in any given run.  
      
When using raw mode (see below), the core tables (users, sessions, users_roles, url_alias, and redirect) will always show the number of records deleted.  If the --verbose option is provided, every table will report its tally.  The --show-count option will dump an array of [\'table_name\' => number_of_records, ...], and includes all tables touched.  Use the --optimize option to run "OPTIMIZE TABLE" on each table affected.
      
In "normal" mode, this command will leverage the Drupal API to delete users (e.g., user_delete_multiple()).  In "raw" mode, i.e., with the --use-raw option specified, direct queries will be used instead.  While this has massive performance benefits for bulk deletion of accounts, there are significant disadvantages compared to the API-based process.  Some things to keep in mind when using raw mode:
      
       -- All targeted records will be deleted from `users` first.  Most other tables 
          are cleaned as orphans, based on their uid field not existing in `users`. 
       -- `sessions`, `redirect`, and `url_alias` will be cleaned.  For the last two,
          uid is detected in the redirect and source fields, respectively.
       -- Custom field data and revision tables will be cleaned, as detected by field_info_instances().
       -- Tables related to the location module will be cleaned.  Meaning, `location_instance` will be 
          cleaned based on uid, then all other `location*` tables will be cleaned based on unmatched 
          lid values compared to `location_instance`.
       -- Any other processes relying on hook_entity_delete() or hook_user_delete() will *NOT* be executed.
          This means that other related entities (such as flagging, voting_api, etc.) will remain in the
          database as orphans.
');
  }

  return NULL;
}

/**
 * Handler for user-purge drush command.
 */
function drush_nys_registration_user_purge() {
  drush_log("User purge starting at " . date("Y-m-d H:i:s", time()), 'status');
  $lifetime = variable_get('nys_registration_unconfirmed_lifetime', 0);
  $days = (int) drush_get_option('min-days', $lifetime);
  $count_only = (boolean) drush_get_option('count-only', FALSE);
  $max_users = drush_get_option('max-users', 0);
  $use_raw = drush_get_option('use-raw', 0);

  if ($use_raw) {
    $ret = _raw_drush_nys_registration_user_purge($days, $max_users, $count_only);
  }
  else {
    $ret = _std_drush_nys_registration_user_purge($days, $max_users, $count_only);
  }

  $msg = "User Purge complete (" . ($ret ? "success" : "failed") . ') at ' .
    date("Y-m-d H:i:s", time());
  drush_log($msg, 'completed');
}

/**
 * @param null $days The minimum age (in days) for an account to be selected.
 * @param null $limit The maximum number of users to select (order by user id)
 *
 * @return SelectQuery
 */
function _drush_nys_registration_build_selection_query($days = NULL, $limit = NULL) {
  $days = (int) ($days ?: NYS_REGISTRATION_DEFAULT_UNCONFIRMED_LIFETIME);
  $limit = (int) ($limit ?: 0);

  // build the selection query
  $timestamp = time() - ($days * 86400);
  $query = db_select('users', 'u')
    ->fields('u', ['uid'])
    ->where('u.uid > 0')
    ->where('u.login = 0')
    ->where('u.status = 1')
    ->where('u.created < ' . $timestamp)
    ->groupBy('u.uid')
    ->having("GROUP_CONCAT(r.name) NOT LIKE '%senator%'");
  if ($limit) {
    $query->orderBy('u.uid')->range(0, $limit);
  }
  $query->join('users_roles', 'ur', 'u.uid=ur.uid');
  $query->join('role', 'r', 'ur.rid=r.rid');

  return $query;
}

/**
 * Retrieve drush command line options.  Returns a default FALSE.
 *
 * @param $name
 *
 * @return false|mixed
 */
function _raw_drush_nys_registration_get_static_option($name) {
  static $options;
  if (!($options[$name] ?? NULL)) {
    $options[$name] = drush_get_option($name, FALSE);
  }
  return $options[$name];
}

/**
 * Runs a delete query, returning the affected number of rows.  Also handles
 * reporting of activity.
 *
 * @param $query string SQL DELETE query to run
 * @param $name string The name/index of query being run
 * @param $indent int Indent level for reporting
 *
 * @return int
 */
function _raw_drush_nys_registration_run_delete($query, $name, $indent = 1) {
  $name = $name ?: '<unknown>';
  $indent = ((int) $indent) ?: 0;
  $need_verbose = ($indent > 1);
  $optimize = _raw_drush_nys_registration_get_static_option('optimize');
  $count = (int) db_query($query, [], ['return' => DATABASE::RETURN_AFFECTED]);
  if ($count && $optimize) {
    db_query('OPTIMIZE TABLE ' . $name);
  }
  if (!$need_verbose || _raw_drush_nys_registration_get_static_option('verbose')) {
    $msg = str_repeat(' --', $indent) . " Cleared {$name} ... {$count} record" .
      ($count == 1 ? '' : 's') . ($optimize ? ' ... optimized' : '');
    drush_log($msg, 'status');
  }
  return $count;
}

/**
 * Creates the array of deletion queries to run, in the form:
 * [
 *   'section_name' => [
 *     'indent' => (int),
 *     'items' => ['table_name' => 'query', ... ],
 *   ],
 *   ...
 * ]
 *
 * @param $query SelectQuery The original selection query for users.
 *
 * @return array[]
 */
function _raw_drush_nys_registration_build_delete_queries($query) {
  $queries = [
    'core' => [
      'indent' => 1,
      'items' => [
        'users' => "DELETE t FROM users t INNER JOIN " .
          "(" . (string) $query . ") tt ON t.uid=tt.uid",
        'sessions' => "DELETE t FROM sessions t LEFT JOIN users u " .
          "ON t.uid=u.uid WHERE t.uid > 0 AND u.uid IS NULL",
        'roles' => "DELETE t FROM users_roles t LEFT JOIN users u " .
          "ON t.uid = u.uid WHERE u.uid IS NULL",
        'url_alias' => "DELETE t FROM url_alias t LEFT JOIN users u " .
          "ON SUBSTRING_INDEX(SUBSTRING(t.source, 6), '/', 1) = u.uid " .
          "WHERE t.source LIKE 'user/%' AND u.uid IS NULL",
        'redirect' => "DELETE t FROM redirect t LEFT JOIN users u " .
          "ON SUBSTRING_INDEX(SUBSTRING(t.redirect, 6), '/', 1) = u.uid " .
          "WHERE t.redirect LIKE 'user/%' AND u.uid IS NULL",
      ],
    ],
    'fields' => ['indent' => 2, 'items' => []],
    'revisions' => ['indent' => 2, 'items' => []],
    'locations' => [
      'indent' => 2,
      'items' => [
        'location_instance' => "DELETE t FROM location_instance t LEFT JOIN users u " .
          "ON t.uid = u.uid WHERE t.uid > 0 AND u.uid IS NULL",
      ],
    ],
  ];

  // Add the queries for custom field data and revision tables.
  foreach (array_keys(field_info_instances('user', 'user')) as $name) {
    $table = "field_data_{$name}";
    $queries['fields']['items'][$table] =
      "DELETE t FROM {$table} t LEFT JOIN users u ON t.entity_id=u.uid " .
      "WHERE u.uid IS NULL AND t.entity_type='user' AND t.bundle='user'";
    $table = "field_revision_{$name}";
    $queries['revisions']['items'][$table] =
      "DELETE t FROM {$table} t LEFT JOIN users u ON t.entity_id=u.uid " .
      "WHERE u.uid IS NULL AND t.entity_type='user' AND t.bundle='user'";
  }

  // Add the queries for tables related to locations.
  $loc_tables = [
    'location',
    'location_contact_name',
    'location_email',
    'location_fax',
    'location_instance',
    'location_phone',
  ];
  foreach ($loc_tables as $table) {
    $queries['locations']['items'][$table] =
      "DELETE t FROM {$table} t LEFT JOIN location_instance li " .
      "ON t.lid=li.lid WHERE li.lid IS NULL";
  }

  return $queries;
}

/**
 * Run the raw-mode version of user purge.  This builds manual queries to
 * simulate deletion through Drupal's API.
 *
 * @param null $days Minimum age of accounts (in days) to be selected.
 * @param null $limit Maximum number of users to select (ordered by uid)
 * @param boolean $count_only If true, just return expected count of users.
 *
 * @return bool FALSE if canceled, or if an exception occurs.
 */
function _raw_drush_nys_registration_user_purge($days = NULL, $limit = NULL, $count_only = FALSE) {
  // Get the selection query.
  $query = _drush_nys_registration_build_selection_query($days, $limit);

  // Get the count and report it.
  $original_count = $query->countQuery()->execute()->fetchField();
  drush_log("Current settings will target {$original_count} users for deletion, using raw queries.", 'ok');

  if (_raw_drush_nys_registration_get_static_option('optimize')) {
    drush_log('Every touched table will be optimized.', 'ok');
  }

  $ret = TRUE;

  // If count only is requested, return.
  if ($count_only) {
    return $ret;
  }

  drush_log("THIS OPERATION WILL USE MANUAL QUERIES TO SIMULATE THE DRUPAL API DELETE PROCESS", 'warning');
  drush_log("IT IS IMPORTANT TO UNDERSTAND THIS CAN LEAVE ORPHAN ENTITIES BEHIND, AND IS NOT REVERSIBLE!", 'warning');

  // permission, not forgiveness
  if (drush_confirm("Are you SURE you want to do this?")) {

    // Run the queries
    $count = [];
    $queries = _raw_drush_nys_registration_build_delete_queries($query);
    try {
      foreach ($queries as $section => $cfg) {
        drush_log("Running $section queries ...", 'status');
        foreach ($cfg['items'] as $name => $query) {
          $count[$name] = _raw_drush_nys_registration_run_delete($query, $name, $cfg['indent']);
        }
      }

      // buh-bye
      $ret = TRUE;
    } catch (Exception $e) {
      // uh-oh
      $ret = FALSE;
      drush_log("FAILED: " . $e->getMessage(), 'error');
    }

    if (drush_get_option('show-count', FALSE)) {
      drush_log("Final counts: " . var_export($count, 1), 'status');
    }
  }
  else {
    // canceled by user
    $ret = FALSE;
  }

  return $ret;
}

/**
 * Runs the standard-mode user-purge.  This leverages Drupal's API to remove
 * entities via user_delete().
 *
 * @param null $days Minimum age (in days) of accounts to be selected.
 * @param null $limit Maximum number of users to select
 * @param boolean $count_only If true, return count and exit.
 *
 * @return bool FALSE if canceled by user, or an exception occurs.
 */
function _std_drush_nys_registration_user_purge($days = NULL, $limit = NULL, $count_only = FALSE) {
  // Get the selection query.
  $query = _drush_nys_registration_build_selection_query($days, $limit);

  // Get the count and report it.
  $original_count = $query->countQuery()->execute()->fetchField();
  drush_log("Current settings will target {$original_count} users for deletion, using standard process.", 'ok');

  $ret = $count_only ? TRUE : drush_confirm("Are you SURE you want to continue?");

  if ($ret && !$count_only) {
    $result = $query->execute();
    $success = $fail = 0;
    while ($uid = $result->fetchField()) {
      try {
        user_delete($uid);
        $success++;
      } catch (Exception $e) {
        $fail++;
        $ret = FALSE;
      }
      if (!(($success + $fail) % 100)) {
        drush_log("Processed " . ($success + $fail) . " accounts", 'ok');
      }
    }
    drush_log("User Purge removed $success accounts, failed to remove $fail.", 'ok');
  }

  return $ret;
}
