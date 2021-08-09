<?php

/**
 * @file
 * Hooks provided by the NYS Bill Notifications module.
 */

/**
 * @defgroup nys_bill_notifications_api_hooks NYS Bill Notifications API Hooks
 * @{
 * Used to hook into bill notification creation and handling.
 */

/**
 * Create an array defining a test which can be applied to an OpenLeg
 * update block.  A commented sample structure is shown below.
 *
 * In short, $all_tests is an array of test definitions, with the keys being
 * the names of the tests.  Each definition is an array mimicking the object
 * structure expected in the decoded JSON.  A value of boolean TRUE indicates
 * a simple existence test, while an array indicates targeting a sub-property.
 * Anything else is considered a value equality test, leveraging basic pattern
 * matching through fnmatch().
 *
 * If a key begins with '#', it will be considered metadata for the test.
 * Currently, the system is aware of:
 *    #callback: sets a custom-named formatter for the test results
 *    #priority: used to determine an event's importance in the context
 *               of primary event detection. (higher=greater priority).
 *
 * @return array An array of test definitions.
 */
function hook_ol_update_test() {
  return [
     // The 'name' of the test
     'STATE' => [
       // The property 'action' must exist
       'action' => TRUE,
       // The property 'table' must exist and equal 'bill'
       'table' => 'bill',
       // The sub-property 'status' must exist under the property 'fields'
       'fields' => ['status' => TRUE],
     ],
  ];
}

/**
 * Enables the ability to alter subscribers to a bill notification.
 *
 * Application of changes can be limited through examination of the first
 * two parameters.  The print number will uniquely identify the bill triggering
 * the alert, using the format "<session_year>-<print_number>".  The tid is
 * the taxonomy ID of the bill's lineage root.  The array of all subscribers
 * is in the form:
 *   [
 *    [ 'bwid' => 'PK value',
 *      'tid' => 'taxonomy id',
 *      'uid' => 'user id',
 *      'email' => 'email' ],
 *    ...,
 *   ]
 *
 * The array is passed by reference to allow for persistent modifications.
 *
 * @param string $print_number
 * @param int $tid
 * @param array $all_subs
 */
function hook_nys_bill_notifications_subscribers_alter($print_number, $tid, array &$all_subs) {
  // Delete the first subscriber
  array_shift($all_subs);

  // Add a new email as an ad hoc subscriber
  $all_subs[] = ['bwid' => -1, 'tid' => 0, 'uid' => 0, 'email' => 'some@email.com'];

  // Add an existing user as an ad hoc subscriber
  $user = user_load(123456);
  $all_subs[] = ['bwid' => -1, 'tid' => 0, 'uid' => $user->uid, 'email' => $user->mail];
}

/**
 * @} End of "defgroup hooks".
 */
