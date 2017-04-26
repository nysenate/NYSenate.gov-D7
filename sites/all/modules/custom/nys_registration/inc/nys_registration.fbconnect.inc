<?php
/**
 * Facebook OAuth callback for initiating a Facebook connection.
 */
function nys_registration_fboauth_action_connect($app_id, $access_token) {
  global $user;

  $fbuser = fboauth_graph_query('me', $access_token);
  $uid = fboauth_uid_load($fbuser->id);
  // If the user isn't logged in.
  if (!$user->uid) {
    // See if they are connected to FB & is an association between FB & Drupal.
    if ($uid && ($account = user_load($uid))) {
      fboauth_login_user($account);
    }
    // No association between FB & this Drupal site, yet.
    // So lets check & see if the FB address matches a Drupal email address.
    else {
      if (!empty($fbuser->email)) {
        // Just use the e-mail from the users table.
        $account = user_load_by_mail($fbuser->email);

        if (isset($account)) {
          if(!$account->uid){
            // if no user account available, redirect to account create
            // redirect to reguster form, populated with fb data
            $form_data = nys_registration_fb_populate_fields($fbuser);
            ctools_include('object-cache');
            $fbdata = ctools_object_cache_get('nys_registration','fbuser');
            if($fbdata){
              drupal_goto('registration/nojs/form/start');
            }           
          }
          // Logins will be denied if the user's account is blocked.
          elseif(fboauth_login_user($account)) {
            // If the Facebook e-mail address matches an existing account, bind them
            // together and log in as that account.
            fboauth_save($account->uid, $fbuser->id);
            drupal_set_message(t("You've connected your account with Facebook."));
          }
        } 
      }
      // Email not provided by Facebook.
      else {
        drupal_set_message(t("Facebook didn't provide an e-mail address " .
          "to be associated with your account, so we can't compare it " .
          "with the e-mail addresses in this system."));
        return;
      }
      // Done if no e-mail address provided by facebook.
    }
  }
  else {
    // The user is already logged in to Drupal.
    // So just associate the two accounts.
    fboauth_save($user->uid, $fbuser->id);
    drupal_set_message(t("You've connected your account with Facebook."));
  }
}

/**
 * Populate fields with mapped data
 */
function nys_registration_fb_populate_fields($fb){
  $dob = new DateTime($fb->birthday);
  $fbuser = array(
    'fb_uid' => $fb->id,
    'fb_email' => $fb->email,
    'fb_firstname' => $fb->first_name,
    'fb_lastname' => $fb->last_name,
    'fb_verified' => $fb->verified,
    'fb_gender' => $fb->gender,
    'fb_dob' => date_format($dob, 'Y-m-d H:i:s')
  );
  ctools_include('object-cache');
  ctools_object_cache_set('nys_registration','fbuser', $fbuser);

  return;
}
