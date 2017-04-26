<?php

/**
 * @file
 *
 * Contains all Field API related code for the nys_bill_vote module.
 */

/**
 * Implementation of hook_field_info().
 */
function nys_bill_vote_field_info() {
  return array(
    'nys_bill_vote' => array(
      'label' => t("Bill vote"),
      'description' => t('Store a simple Aye/Nay for this piece of content.'),
      'default_widget' => 'nys_bill_vote_exposed',
      'default_formatter' => 'nys_bill_vote_formatter_default',
      'settings' => array(
        'axis' => 'nys_bill_vote_aye_nay',
      ),
    ),
  );
}


/**
 * Implementation of hook_field_settings_form().
 */
function nys_bill_vote_field_settings_form($field, $instance) {
  $form['axis'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => 'Voting Tag',
    '#options' => nys_bill_vote_get_tags(),
    '#description' => t('The tag this rating will affect. Enter a property on which that this rating will affect, such as <em>quality</em>, <em>satisfaction</em>, <em>overall</em>, etc.'),
    '#default_value' => isset($field['settings']['axis']) ? $field['settings']['axis'] : '',
    '#disabled' => field_has_data($field),
  );

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function nys_bill_vote_form_field_ui_field_edit_form_alter(&$form, $form_state) {
  $field = $form['#field'];
  if ($field['type'] == 'nys_bill_vote') {
    // Multiple values is not supported with nys_bill_vote.
    $form['field']['cardinality']['#access'] = FALSE;
    $form['field']['cardinality']['#value'] = 1;
    $form['instance']['default_value_widget']['#access'] = FALSE;
  }
}

/**
 * Implementation of hook_field_widget_info().
 */
function nys_bill_vote_field_widget_info() {
  return array(
    'nys_bill_vote_exposed' => array(
      'label' => t('Aye / Nay'),
      'field types' => array('nys_bill_vote'),
      'behaviors' => array('multiple values' => FIELD_BEHAVIOR_NONE),
    ),
  );
}

/**
 * Implements hook_field_formatter_info().
 */
function nys_bill_vote_field_formatter_info() {
  return array(
    'nys_bill_vote_formatter_default' => array(
      'label' => t('Default'),
      'field types' => array('nys_bill_vote'),
    ),
  );
}

/**
 * Implementation of hook_field_formatter_view().
 */
function nys_bill_vote_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  list($entity_id, $entity_vid, $bundle) = entity_extract_ids($entity_type, $entity);
  $settings = array(
    'entity_type' => $entity_type,
    'entity_id' => $entity_id,
    'axis' => $field['settings']['axis'],
  );

  $element[0] = drupal_get_form('nys_bill_vote_exposed_formatter', $settings);
  return $element;
}
