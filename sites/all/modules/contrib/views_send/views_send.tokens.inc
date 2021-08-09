<?php

/**
 * @file
 * Token integration for the Views Send module.
 */

/**
 * Implements hook_token_info().
 *
 * These token are used by Rules and not in the Views form.
 */
function views_send_token_info() {
  $data = array();
  foreach (_views_send_email_message_property_info() as $key => $info) {
    $data[$key] = array(
      'name' => $info['label'],
      'description' => ''
    );
  }
  $type = array(
    'name' => t('Views Send e-mail message'),
    'description' => t('Tokens for Views Send e-mail message.'),
    'needs-data' => 'views_send_email_message',
  );
  return array(
    'types' => array('views_send_email_message' => $type),
    'tokens' => array('views_send_email_message' => $data),
  );
}

/**
 * Implementation hook_tokens().
 *
 * These token replacements are used by Rules and not in the Views form.
 */
function views_send_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'views_send_email_message' && !empty($data['views_send_email_message'])) {
    foreach ($tokens as $name => $original) {
      $replacements[$original] = $data['views_send_email_message']->{$name};
    }
  }
  return $replacements;
}
