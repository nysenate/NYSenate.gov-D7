<?php

/**
 * @file
 * Hooks provided by Session API.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allows modules to act upon Session IDs being deleted.
 *
 * @param array $outdated_sids
 *   An array with all the expired Session IDs that will be deleted.
 */
function hook_session_api_cleanup($outdated_sids) {
  // Delete flags associated with outdated sessions.
  db_delete('flagging')->condition('sid', $outdated_sids)->execute();
}

/**
 * @} End of "addtogroup hooks".
 */
