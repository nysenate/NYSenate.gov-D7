<?php

/**
 * @file
 * NYS Subscriptions Global UnSubscribe and confirmation Form inc.
 */

module_load_include('inc', 'nys_subscriptions', 'nys_subscriptions');

/**
 * Subscriptions Global UnSubscribe and confirmation Form.
 *
 *  $key is required.
 */
function nys_subscriptions_global_unsubscribe_form($form, &$form_state, $key) {

  $form = array();

  $form['key'] = array('#type' => 'hidden', '#value' => $key);

  $form['subscribe_form']['markup_1'] = array(
    '#type'   => 'markup',
    '#markup' => '<h3>Unsubscribe from all notification subscriptions </h3>
     <p>Are you sure you want to unsubscribe from the notifications for ALL bills.</p>',
  );

  $form['subscribe_form']['markup_2'] = array(
    '#type'   => 'markup',
    '#markup' => '<br /><br />',
  );

  $form['unsubscribe'] = array(
    '#type' => 'submit',
    '#value' => 'Unsubscribe from all',
    '#submit' => array('nys_subscriptions_global_unsubscribe_form_submit'),
  );

  $form['referrer'] = array('#type' => 'hidden', '#value' => $_SERVER['HTTP_REFERER']);

  return $form;
}

/**
 * Subscriptions Global UnSubscribe and confirmation Form Submit handler.
 */
function nys_subscriptions_global_unsubscribe_form_submit($form, &$form_state) {
  // Get the subscriber data.
  $subscriber_key = $form_state['values']['key'];

  // Add Subscriber to the nuclear SendGrid global unsubsubscribe list.
  nys_subscriptions_nuclear_sendgrid_unsubscribe($subscriber_key);

  // REsubscription confirmation page.
  drupal_goto('subscriptions/status-message/We+will+no+longer+send+any+type+of+bill+notification+emails+to+your+email+address./');

}
