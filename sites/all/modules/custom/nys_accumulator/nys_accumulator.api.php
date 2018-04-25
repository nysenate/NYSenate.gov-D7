<?php

/**
 * @file
 * Hooks provided by the NYS Accumulator module.
 */

/**
 * @defgroup nys_accumulator_api_hooks NYS Accumulator API Hooks
 * @{
 * Functions to modify accumulator behavior.
 *
 * List of hooks and functions invoked.
 * - Handling users:
 *   - nys_accumulator_retrieve_user_info()
 * @}
 */

/**
 * Provides access to an accumulator message record prior to insertion.
 *
 * @param array $row
 *   The row information to be inserted.
 *
 * @return array
 *   The modified row.
 */
function hook_nys_accumulator_preinsert($row) {
  return $row;
}

/**
 * Provide user information for anonymous users.
 *
 * @param object $user
 *   The user object.
 * @param array $response
 *   The response array, including user info so far.
 * @param array $options
 *   Any overrides or flags to apply.
 *
 * @return array
 *   An array with keys for user info:
 *    - user_id
 *    - user_name
 *    - user_address
 *    - user_city
 *    - user_state
 *    - user_zipcode
 *    - user_district_id
 *
 * @ingroup nys_accumulator_user
 */
function hook_nys_accumulator_user_info($user, $response, $options) {
  $petition_row = db_select('nys_petitions', 'a')
    ->fields('a')
    ->condition('email', $response['msg_info']['user_info']['email'])
    ->execute()
    ->fetchAssoc();
  if (empty($petition_row['email'])) {
    return $response;
  }
  $user_info = array(
    'id' => $petition_row['sid'],
    'first_name' => $petition_row['first_name'],
    'last_name' => $petition_row['last_name'],
    'address' => $petition_row['addr_street'],
    'city' => $petition_row['addr_city'],
    'state' => $petition_row['addr_state'],
    'zipcode' => $petition_row['addr_zip'],
    'district_id' => $petition_row['district_id'],
  );
  $response['msg_info']['user_info'] = array_merge(
    $response['msg_info']['user_info'],
    $user_info
  );

  return $response;
}

/**
 * @} End of "addtogroup hooks".
 */
