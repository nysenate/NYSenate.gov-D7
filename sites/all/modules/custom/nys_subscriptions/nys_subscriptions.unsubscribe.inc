<?php

/**
 * @file
 * NYS Bill Subscriptions UnSubscribe Form inc.
 */

module_load_include('inc', 'nys_subscriptions', 'nys_subscriptions');

/**
 * UNsubscribe REsubscribe form.
 *
 * This form unsubscribes you from the subscription idendified by $key.
 * The form shown IS a Confirmation of an Un-Subscription and
 * a Reubsubscribe Form.
 */
function nys_subscriptions_unsubscribe_form($form, &$form_state, $key) {
  // Get the subscription data.
  $subscription = nys_subscriptions_subscription_lookup($key);
  if ($subscription === FALSE) {
    return array();
  }

  // Unsubscribes the subscription identified by $key.
  nys_subscriptions_subscription_unsubscribe($key);

    $email_address = $subscription->email;
    $bill = entity_metadata_wrapper(node, $subscription->nid);
    $bill_print_no = $bill->field_ol_print_no->value();
    $bill_session= $bill->field_ol_session->value();

    drupal_set_message($email_address . ' will no longer receive status alerts for ' . $bill_print_no . '. Subscribe again at any time using the "Subscribe" button on this page.');
    drupal_goto('legislation/bills/'. $bill_session . '/' . $bill_print_no);
}

/**
 * UNsubsubscribe / REsubscribe Submit handler.
 */
function nys_subscriptions_unsubscribe_form_submit($form, &$form_state) {
  // Get the subscription data.
  $subscription_key = $form_state['values']['key'];

  // UNsubscribes the subscription idendified by $subscription_key.
  nys_subscriptions_subscription_resubscribe($subscription_key);

  // REsubscription confirmation page.
  drupal_goto('subscriptions/status-message/Your+Subscription+has+been+reinstated./');
}
