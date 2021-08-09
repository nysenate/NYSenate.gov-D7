<?php

/**
 * @file
 * NYS Subscriptions Signup Form inc. Signup For a subscription.
 */

module_load_include('inc', 'nys_subscriptions', 'nys_subscriptions');

/**
 * Subscriptions Notification Subscription Signup Form.
 */

/**
 * Subscriptions Notification Subscription Signup form().
 */
function nys_subscriptions_signup_form($form, &$form_state, $tid, $nid) {
  $form = array();

  $form['signup_form']['markup_1'] = array(
    '#type'   => 'markup',
    '#markup' => t('Enter your email address below.'),
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('e mail address'),
  );

  $form['signup_form']['markup_2'] = array(
    '#type'   => 'markup',
    '#markup' => t('We will send you a confirmation email.'),
  );

  $form['subscribe'] = array(
    '#type' => 'submit',
    '#value' => 'Subscribe',
    '#submit' => array('nys_subscriptions_signup_form_submit'),
    '#validate' => array('nys_subscriptions_signup_form_validate'),
  );

  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => 'Cancel',
    '#submit' => array('nys_subscriptions_signup_form_cancel'),
    '#validate' => array('nys_subscriptions_signup_form_cancel_validate'),
  );

  $form['tid'] = array('#type' => 'hidden', '#value' => $tid);
  $form['nid'] = array('#type' => 'hidden', '#value' => $nid);

  return $form;

}

/**
 * Subscriptions Notification Subscription Signup Cancel Validate.
 */
function nys_subscriptions_signup_form_cancel_validate($form, &$form_state) {

}

/**
 * Subscriptions Notification Subscription Signup Cancel Submit.
 */
function nys_subscriptions_signup_form_cancel($form, &$form_state) {
  // Get the referring nid.
  $nid = $form_state['values']['nid'];
  // Go back to node nid.
  drupal_goto("node/$nid /");
}

/**
 * Subscriptions Notification Subscription Signup Validate.
 */
function nys_subscriptions_signup_form_validate($form, &$form_state) {
  // Validate the email address format.
  if (!filter_var($form_state['values']['email'], FILTER_VALIDATE_EMAIL)) {
    form_set_error('email', t('Invalid Email Address'));
  }

}

/**
 * Subscriptions Notification Subscription Signup Submit.
 */
function nys_subscriptions_signup_form_submit($form, &$form_state) {
  // Get the entered email address.
  $email_address = $form_state['values']['email'];

  // Get the tid and nid.
  $tid = $form_state['values']['tid'];
  $nid = $form_state['values']['nid'];

  $why = 2;
  nys_subscriptions_subscription_signup($tid, $nid, $email_address, $why);

  // Send the confirmation email.
  $info = ['tid' => $tid, 'nid' => $nid, 'email' => $email_address];
  drupal_mail(
    'nys_subscriptions_confirmation',  // module
    'confirmation',                    // key
    '',                                // to (irrelevant with SendGrid API mail)
    language_default(),                // language
    ['confirmation' => $info]          // params
  );

  // Tell them to confirm.
  drupal_goto('subscriptions/status-message/Your+Subscription+has+been+added.++You+will+receive+a+confirmation+email./');
}
