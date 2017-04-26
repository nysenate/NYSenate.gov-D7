<?php
/**
 * @file
 * Contains PasswordPolicyItem.
 */

/**
 * Class PasswordPolicyItem.
 *
 * This class is used for item Ctools plugin type.
 */
class PasswordPolicyItem {
  protected $ppType = array('item');
  public $info;
  public $policy;
  public $config;

  /**
   * Constructs a PasswordPolicyItem object.
   *
   * @param object $info
   *   Ctools plugin object.
   * @param object $policy
   *   Policy database object as returned by ctools_export_crud_load().
   */
  public function __construct($info, &$policy) {
    $this->info = $info;
    // We want to have a local config but have it be a ref to the policy one
    // that way we only have to make updates once.
    $this->config = &$policy->config[$info['name']];
    $this->config = array_merge($info['config'], $this->config);
    $this->policy = $policy;
  }

  /**
   * Checks whether item is of a given type.
   *
   * @param string $type
   *   Type name.
   *
   * @return bool
   *   TRUE if the item is the type, FALSE otherwise.
   */
  public function isType($type) {
    return in_array($type, $this->ppType);
  }

  /**
   * Gets function of item by name.
   *
   * @param string $function_name
   *   The identifier of the function.
   *
   * @return string|null
   *   The actual name of the function to call, or NULL if the function does
   *   not exist.
   */
  protected function func($function_name) {
    return ctools_plugin_get_function($this->info, $function_name);
  }

  /**
   * Form constructor for adminForm().
   */
  public function adminForm($form, &$form_state) {
    $func = $this->func('admin form callback');
    if ($func) {
      return $func($form, $form_state, $this);
    }
    return array();
  }

  /**
   * Form submission handler for adminForm().
   */
  public function adminFormSubmit($form, &$form_state) {
    foreach ($this->info['config'] as $id => $default) {
      if (isset($form_state['values'][$id])) {
        $this->config[$id] = $form_state['values'][$id];
      }
    }
  }

  /**
   * Determines whether item is active.
   *
   * @return bool
   *   TRUE if item is active, FALSE otherwise.
   */
  public function isActive() {
    if (isset($this->info['prime value'])) {
      return (bool) $this->config[$this->info['prime value']];
    }
    else {
      return TRUE;
    }
  }

  /**
   * Creates item.
   *
   * @param object $info
   *   Ctools plugin object.
   * @param object $policy
   *   Policy database object as returned by ctools_export_crud_load().
   *
   * @return PasswordPolicyItem
   *   Item.
   */
  public static function factory($info, &$policy) {
    $class = $info['class'];
    return new $class($info, $policy);
  }

}
