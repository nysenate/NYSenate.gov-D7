<?php
/**
 * @file Token related hooks.
 */

/**
 * Implements hook_token_info().
 */
function entityform_token_info() {
  $type = array(
    'name' => t('Entityform Types'),
    'description' => t('Tokens related to entityform types.'),
    'needs-data' => 'entityform_type',
  );
  $tokens['submit_url'] = array(
    'name' => t('Submission URL'),
    'description' => t('Submit URL for Entityform type.'),
  );

  return array(
    'types' => array('entityform_type' => $type),
    'tokens' => array('entityform_type' => $tokens),
  );
}

/**
 * Implements hook_tokens().
 */
function entityform_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $return = array();
  if ($type == 'entityform_type' && !empty($data['entityform_type'])) {
    $entityform_type = $data['entityform_type'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'submit_url':
          $return[$original] = url(_entityform_type_get_submit_url($entityform_type->type), array(
            'absolute' => TRUE));
          break;

      }
    }
  }

  return $return;
}
