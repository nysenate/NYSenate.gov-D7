<?php

/**
 * @file
 * Functions providing for various accumulator data updates.
 */

/**
 * See issue #10240.
 *
 * Updates accumulator records for any petition signings by
 * unauthenticated users.  This function is destructive and
 * should only be run as part of a planned upgrade process.
 *
 * The original format did not present adequate information
 * for building a new contact in Bluebird.  The new format
 * leverages much more information from the nys_petitions
 * table.  This function will scan the older records, attempt
 * to match them to nys_petitions records, and create new
 * accumulator records.
 *
 * Note that some records cannot be reformatted due to a lack
 * of identifying information.  This function tests for the
 * presence of the "user_email" field inside the msg_info
 * JSON.  If it is present, and a match can be found in either
 * nys_petitions or a fall-back search of users, the replacement
 * is created.
 *
 * If the creation is successful, it will be added to the
 * accumulator as a new record, with the original record being
 * deleted.  This is handled within a transaction set to ensure
 * data retention.
 */
function _nys_accumulator_update_petition_entries() {

  // Query for all potential records to rewrite - anonymous petition signings.
  $main_results = db_select('accumulator', 'a', array('fetch' => PDO::FETCH_OBJ))
    ->fields('a')
    ->condition('msg_type', 'petition')
    ->condition('msg_action', 'sign')
    ->condition('user_id', '0')
    ->execute();

  // Iterate through results, rebuilding each record, if possible.  Note that
  // each rewrite is followed by the original record being deleted.  Both
  // actions are encapsulated in a transaction.
  foreach ($main_results as $one_result) {
    $old_info = json_decode($one_result->msg_info);
    if ($old_info->user_email) {

      // Scan nys_petitions for a matching record.
      $nysp_value = db_select('nys_petitions', 'b')
        ->fields('b', array('fid'))
        ->condition('email', $old_info->user_email)
        ->condition('pid', $old_info->petition_id)
        ->execute()
        ->fetchField();

      // If an original form record is found, we can try to rewrite the record.
      // Reproduce the accumulator flag processing here.
      if ((int) $nysp_value) {
        try {
          // Every record gets a transaction.  Transaction will include one
          // new record, and one deletion.
          $transaction = db_transaction();

          // Initialize the user object, options array, and key response data
          // points.
          $user       = user_load(0);
          $msg_type   = $one_result->msg_type;
          $msg_action = $one_result->msg_action;

          // Need to set the option flag to indicate a petition.
          $options = array('flagging' => (object) ['flagging_id' => $nysp_value]);

          // Prep the new response.
          $response = array_merge(
            _nys_accumulator_init_response(),
            array('msg_action' => $msg_action, 'msg_type' => $msg_type)
          );

          // Set the user data.
          nys_accumulator_populate_user_info($user, $response, $options);

          // Resolve the target shortname and district number.
          nys_accumulator_retrieve_senator_and_district(0, $response, $old_info->user_district, $old_info->user_shortname);

          // Retrieve additional entity info (e.g., bill data).
          $entity_info_callback = "nys_accumulator_retrieve_{$msg_type}_info";
          if (function_exists($entity_info_callback)) {
            $entity_info_callback($old_info->petition_id, $response);
          }

          // Restore the original "created_at" timestamp.
          $response['created_at'] = $one_result->created_at;
          $response['user_is_verified'] = 0;

          // Insert the new record.
          nyslog("sending new record for insert:\n" . var_export($response, 1));
          nys_accumulator_action_insert($response);

          // Delete the old record.
          nyslog("deleting original record #{$one_result->id}");
          db_delete('accumulator')
            ->condition('id', $one_result->id)
            ->execute();
        }
        catch (Exception $e) {
          print "Failed to convert record {$one_result->id}: " . (string) $e . "<br />" . chr(10) . chr(13);
          if ($transaction) {
            $transaction->rollback();
          }
        }
        finally {
          // Done, close the transaction.
          if ($transaction) {
            print "Done processing record {$one_result->id}<br />" . chr(10) . chr(13);
            unset($transaction);
          }
        }

      }
    }
  }
}
