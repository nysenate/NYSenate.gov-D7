<?php
/**
 * @file
 * Hooks provided by the Disqus module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Modify user data prepared for use with Disqus SSO.
 *
 * @param array $data
 *  - id: User's ID. Used by disqus to uniquely identify the user.
 *  - username: Display name.
 *  - email: Email address.
 *  - url: Link to the user's site profile page.
 *  - avatar: URI of the user's picture.
 */
function hook_disqus_user_data_alter(&$data) {
  global $user;

  // Integrate with the Real Name module.
  if (isset($user->realname)) {
    $data['username'] = $user->realname;
  }
}

/**
 * @} End of "addtogroup hooks".
 */
