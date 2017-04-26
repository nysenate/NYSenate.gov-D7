<?php
/**
 * @file
 * Basic class for field validation validator.
 *
 * All field validation validator classes should inherit this basic class.
 */

abstract class field_validation_validator {
  // Variables associated with validation.
  protected $entity_type;
  protected $entity;
  protected $field;
  protected $instance;
  protected $langcode;
  protected $items;
  protected $delta;
  protected $item;
  protected $value;
  protected $rule;
  protected $errors;

  /**
   * Save arguments locally.
   */
  function __construct($entity_type = 'node', $entity = NULL, $field = '', $instance = NULL, $langcode = 'und', $items = array(), $delta = 0, $item = array(), $value = '', $rule = NULL, &$errors = array()) {
    $this->entity_type = $entity_type;
    $this->entity = $entity;
    $this->field = $field;
    $this->instance = $instance;
    $this->langcode = $langcode;
    $this->items = $items;
    $this->delta = $delta;
    $this->item = $item;
    $this->value = $value;
    $this->rule = $rule;
    $this->errors = &$errors;
  }

  /**
   * Validate field. 
   */
  public function validate() {}

  /**
   * Provide settings option
   */
  function settings_form(&$form, &$form_state) {
    $default_settings = $this->get_default_settings($form, $form_state);
    //print debug($default_settings);
    $form['settings']['bypass'] = array(
      '#title' => t('Bypass validation'),
      '#type' => 'checkbox',
      '#default_value' => isset($default_settings['bypass']) ? $default_settings['bypass'] : FALSE,
    );
    $roles_options = user_roles();
    $form['settings']['roles'] = array(
      '#title' => t('Roles'),
      '#description' => t("Only the checked roles will be able to bypass this validation rule."),
      '#type' => 'checkboxes',
      '#options' => $roles_options,
      '#default_value' => isset($default_settings['roles']) ? $default_settings['roles'] : array(),
      '#states' => array(
        'visible' => array(
          ':input[name="settings[bypass]"]' => array('checked' => TRUE),
        ), 
      ),
    );
    $form['settings']['errors'] = array(
      '#title' => t('Set errors using field API'),
      '#description' => t("There are two methods to set error: using form_set_error provided by form api, using errors provided by field api. form_set_error does not work correctly when a sub form embed into another form. errors does not work correctly when current field does not support hook_field_widget_error."),
      '#type' => 'checkbox',
      '#default_value' => isset($default_settings['errors']) ? $default_settings['errors'] : FALSE,
    );
  }

  /**
   * Return error message string for the validation rule.
   */
  public function get_error_message() {
    $error_message = $this->rule->error_message;
    return $error_message;
  }
  
  /**
   * Return error element for the validation rule.
   */
  public function get_error_element() {
    $error_element = $this->rule->field_name . '][' . $this->langcode . '][' . $this->delta . '][' . $this->rule->col;
    // Support free tagging.
    if (!empty($this->field['type']) && $this->field['type'] == 'taxonomy_term_reference') {
      $error_element = $this->rule->field_name . '][' . $this->langcode;
    }
    return  $error_element;
  }
  
  /**
   * Return default settingsfor the validator.
   */
  public function get_default_settings(&$form, &$form_state) {
    $rule = isset($form_state['item']) ? $form_state['item'] : new stdClass();
    $default_settings = isset($rule->settings) ? $rule->settings : array();
    $default_settings = isset($form_state['values']['settings']) ? $form_state['values']['settings'] : $default_settings;
    return  $default_settings;
  }
  
  /**
   * Set error message.
   */
  public function set_error($tokens = array()) {
    $error_element = $this->get_error_element();
    $error_message = t($this->get_error_message());
    $tokens += array(
      '[entity-type]' => $this->rule->entity_type, 
      '[bundle]' => $this->rule->bundle, 
      '[field-name]' => $this->instance['label'], 
      '[value]' => $this->value, 
    );
    $error_message = field_filter_xss(strtr($error_message, $tokens));
    //We support two methods to set error: using form_set_error provided by form api, using errors provided by field api.
    //form_set_error does not work correctly when a sub form embed into another form; 
    //errors does not work correctly when current field does not support hook_field_widget_error.
    if (empty($this->rule->settings['errors'])) {
      form_set_error($error_element, $error_message);
    }
    else{
      $this->errors[$this->rule->field_name][$this->langcode][$this->delta][] = array(
        'error' => $this->rule->col,
        'message' => $error_message,
      );
    }
  }
  
  /**
   * Provide token help info for error message.
   */
  public function token_help() {
    return array(
      '[entity-type]' => t('Machine name of entity type'), 
      '[bundle]' => t('Machine name of bundle'), 
      '[field-name]' => t('User readable name of current field'), 
      '[value]' => t('Current value to be validated on'),  
    );
  }
  
  /**
   * Bypass validation.
   */
  public function bypass_validation() {
    global $user;
    if (!empty($this->rule->settings['bypass']) && !empty($this->rule->settings['roles'])) {
      $roles = array_filter($this->rule->settings['roles']);
      $user_roles = array_keys($user->roles);
      foreach ($roles as $role) {
        if (in_array($role, $user_roles)) {
          return TRUE;
        }
      }
    }
    return FALSE;
  }
}