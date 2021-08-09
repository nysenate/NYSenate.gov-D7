<?php

/**
 * @file
 * NYS Subscriptions Manage Subscriptions Form inc.
 */

module_load_include('inc', 'nys_subscriptions', 'nys_subscriptions');

/**
 * Subscriptions Manage Subscriptions page.
 *
 *   $tid             The tid of the bills parent taxonomy term.
 *                        A tid is required to validate the user
 *   $email_address   The email address of the subscriber.
 *   $key             The key for th eemail address and tid.
 */
function nys_subscriptions_manage_subscriptions_form($form, &$form_state, $email_address_key) {
  // UNSubscribe List.
  $unsubscribe_options = array();
  // UNSubscribe Selections - No nids should be selected.
  $unsubscribe_default_values = array();

  // UNSubscribe List.
  $resubscribe_options = array();
  // RESubscribe Selections - The nids that should be selected.
  $resubscribe_default_values = array();

  // Email address.
  $email = '';

  drupal_add_js(drupal_get_path('module', 'nys_subscriptions') . '/nys_subscriptions.manage_subscriptions.js');

  // Get all subscriptions.
  $results = db_query("SELECT * FROM `nys_subscriptions` WHERE `confirmation_timestamp` > 0 AND `email_address_key` = :email_address_key ORDER BY `unsubscribe_timestamp` ASC", array(":email_address_key" => $email_address_key))->fetchAll();
  foreach ($results as $subscription) {
    if ($subscription->unsubscribe_timestamp == 0) {
      // Currently Subscribed.
      $nid = $subscription->nid;
      $subscription_key = $subscription->subscription_key;
      $unsubscribe_options[$subscription_key] = l(ucwords(strtolower(nys_subscriptions_get_bill_title($nid))), drupal_get_path_alias('node/' . $nid));
       $email = $subscription->email;
    }
    elseif ($subscription->unsubscribe_timestamp > 0) {
      // Currently UNSubscribed.
      $nid = $subscription->nid;
      $subscription_key = $subscription->subscription_key;
      $resubscribe_options[$subscription_key] = l(nys_subscriptions_get_bill_title($nid), drupal_get_path_alias('node/' . $nid));
      $email = $subscription->email;

      // If it was in the last 5 seconds select it.
      if ((time() - $subscription->unsubscribe_timestamp) < 5) {
        $resubscribe_default_values[] = $subscription_key;
      }
    }
  }

  // The data is loaded display the form.
  $form = array();

  $form['email']['markup'] = array(
    '#type'   => 'markup',
    '#markup' => '<H1 class="nys-article-title">Bill Alert Subscription Settings</H1>',
  );

  $form['key'] = array('#type' => 'hidden', '#value' => $email_address_key);

  /*
   * UNsubscribe Fieldset.
   */
  if (count($unsubscribe_options) > 0) {
/*    $form['unsubscribe'] = array(
      '#type' => 'fieldset',
      '#title' => t('Unsubscribe from alerts for individual bills'),
      '#weight' => 1,
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );*/
    $form['unsubscribe']['markup'] = array(
      '#type'   => 'markup',
      '#markup' => '<hr><p>' . print_r($email, TRUE) . ' is currently subscribed to receive status alerts for the following bills. You can unsubscribe below:</p>',
    );
    $form['unsubscribe']['all_none'] = array(
      '#type'   => 'markup',
      '#markup' => '<p><input type="checkbox" name="unsubscribe" id="all-edit-unsubscribe" onClick="select_subscriptions(\'edit-unsubscribe\');">  Select all</p>',
    );

    $form['unsubscribe']['unsubscribe_list'] = array(
      '#title' => '',
      '#type' => 'checkboxes',
      '#description' => '',
      '#options' => $unsubscribe_options,
      '#default_value' => $unsubscribe_default_values,
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['unsubscribe']['unsubscribe'] = array(
      '#type' => 'submit',
      '#value' => 'Unsubscribe',
      '#submit' => array('nys_subscriptions_signup_form_unsubscribe_submit'),
    );

    $form['unsubscribe']['markup_2'] = array(
      '#type'   => 'markup',
      '#markup' => '',
    );
  }
  if (count($unsubscribe_options) == 0) {

    $form['unsubscribe']['markup'] = array(
      '#type'   => 'markup',
      '#markup' => '<hr><p><strong>' . print_r($email, TRUE) . '</strong> is not currently subscribed to alerts for any bills.</p><hr>',
    );

  }

  /*
   * Resubscribe Fieldset.
   */
  if (count($resubscribe_options) > 0) {
    $form['resubscribe'] = array(
      '#type' => 'fieldset',
      '#title' => t('Resume Old Subscriptions'),
      '#weight' => 2,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['resubscribe']['all_none'] = array(
      '#type'   => 'markup',
      '#markup' => '<p><input type="checkbox" name="resubscribe" id="all-edit-resubscribe" onClick="select_subscriptions(\'edit-resubscribe\');">  Check all</p><hr />',
    );

    $form['resubscribe']['resubscribe_list'] = array(
      '#title' => '',
      '#type' => 'checkboxes',
      '#description' => '',
      '#options' => $resubscribe_options,
      '#default_value' => $resubscribe_default_values,
    );

    $form['resubscribe']['markup_3'] = array(
      '#type'   => 'markup',
      '#markup' => '',
    );

    $form['resubscribe']['resubscribe'] = array(
      '#type' => 'submit',
      '#value' => 'Resume selected alert subscription(s)',
      '#submit' => array('nys_subscriptions_signup_form_resubscribe_submit'),
    );
  }

  /*
   * Global Unsubscribe Fieldset.
   */
  $form['global_unsubscribe'] = array(
    '#type' => 'fieldset',
    '#title' => t('Unsubscribe Forever'),
    '#weight' => 3,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['global_unsubscribe']['markup_3'] = array(
    '#type'   => 'markup',
    '#markup' => '<p>Selecting this option blocks all future emails from the NY State Senate bill alert service.</p>',
  );
  $form['global_unsubscribe']['markup_4'] = array(
    '#type'   => 'markup',
    '#markup' => '<hr>',
  );

  $form['global_unsubscribe']['global_unsubscribe'] = array(
    '#type' => 'submit',
    '#value' => 'Block all bill alert emails',
    '#submit' => array('nys_subscriptions_signup_form_global_unsubscribe_submit'),
  );

  return $form;

}

/**
 * Submit function for UNSubscribe().
 */
function nys_subscriptions_signup_form_unsubscribe_submit($form, &$form_state) {
  // Get the subscription data.
  $email_address_key = (isset($form_state['values']['key']) ? $form_state['values']['key'] : FALSE);
  $unsubscribe_list  = (isset($form_state['values']['unsubscribe_list']) ? $form_state['values']['unsubscribe_list'] : FALSE);
  if ($unsubscribe_list !== FALSE) {
    foreach ($unsubscribe_list as $subscription_key => $unsubscribe_value) {
      if (strlen($unsubscribe_value) > 10) {
        nys_subscriptions_subscription_unsubscribe($subscription_key);
      }
    }
  }
}

/**
 * Submit function for RESubscribe().
 */
function nys_subscriptions_signup_form_resubscribe_submit($form, &$form_state) {
  // Get the subscription data.
  $email_address_key = (isset($form_state['values']['key']) ? $form_state['values']['key'] : FALSE);
  $resubscribe_list  = (isset($form_state['values']['resubscribe_list']) ? $form_state['values']['resubscribe_list'] : FALSE);
  if ($resubscribe_list !== FALSE) {
    foreach ($resubscribe_list as $subscription_key => $resubscribe_value) {
      if (strlen($resubscribe_value) > 10) {
        nys_subscriptions_subscription_resubscribe($subscription_key);
      }
    }
  }
}

/**
 * Submit function for UNSubscribe().
 */
function nys_subscriptions_signup_form_global_unsubscribe_submit($form, &$form_state) {
  // Get the subscription data.
  $subscription_key = $form_state['values']['key'];
  // Confirm the Nuclear Global Delete.
  drupal_goto("subscriptions/global-unsubscribe/$subscription_key/");
}
