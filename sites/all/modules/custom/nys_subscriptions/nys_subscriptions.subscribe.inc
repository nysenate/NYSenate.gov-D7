<?php

/**
 * @file
 * NYS Subscriptions Subscribe Form inc.
 */

module_load_include('inc', 'nys_subscriptions', 'nys_subscriptions');

/**
 * Subscription Confirmation Form.
 */
function nys_subscriptions_subscribe_form($form, &$form_state, $key) {
  $form = array();
  // Get the subscription data.
  $subscription = nys_subscriptions_subscription_lookup($key);

  if ($subscription === FALSE) {
    // No Subscription could be found.
    $form['subscribe_form']['markup_1'] = array(
      '#type'   => 'markup',
      '#markup' => '<h3>No subscription on file</h3>',
    );

    return $form;
  }

  nys_subscriptions_subscription_confirmation($key);

  $email_address = $subscription->email;
  $bill = entity_metadata_wrapper(node, $subscription->nid);
  $bill_print_no = $bill->field_ol_print_no->value();
  $bill_session= $bill->field_ol_session->value();

  drupal_set_message('Success! ' .$email_address . ' will now receive updates for ' . $bill_print_no . '.');
  drupal_goto('legislation/bills/'. $bill_session . '/' . $bill_print_no);
  // return $form;

}
