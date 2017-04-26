<?php
/**
 * @file
 * Contains PasswordPolicy.
 */

/**
 * Defines a class used for managing Password Policies.
 */
class PasswordPolicy {
  public $name;
  public $config;
  public $items;
  public $cache;

  /**
   * Constructor for PasswordPolicy.
   *
   * @param object $policy
   *   Database object as returned by ctools_export_crud_load().
   */
  public function __construct($policy = NULL) {
    if ($policy == NULL) {
      ctools_include('export');
      $policy = ctools_export_crud_new('password_policy');
    }

    $this->name = $policy->name;
    $this->config = isset($policy->config) ? unserialize($policy->config) : array();

    // Load all constraint objects.
    $this->loadPlugins();
  }

  /**
   * Creates the administration form for this policy.
   */
  public function adminForm(&$form, &$form_state) {
    // Condition settings.
    $form['condition_title'] = array(
      '#type' => 'item',
      '#title' => t('Conditions'),
    );
    $form['condition'] = array(
      '#type' => 'vertical_tabs',
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'password_policy') . '/password_policy.js'),
      ),
    );

    // Constraint settings.
    $form['constraint_title'] = array(
      '#type' => 'item',
      '#title' => t('Constraints'),
    );
    $form['constraint'] = array(
      '#type' => 'vertical_tabs',
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'password_policy') . '/password_policy.js'),
      ),
    );

    // Item settings.
    $form['item_title'] = array(
      '#type' => 'item',
      '#title' => t('Other settings'),
    );
    $form['item'] = array(
      '#type' => 'container',
    );

    foreach ($this->items as $item) {
      $parent = $item->isType('condition') ? 'condition' : ($item->isType('constraint') ? 'constraint' : 'item');
      $form[$parent]  = $form[$parent] + $item->adminForm($form, $form_state);
    }

    return $form;
  }

  /**
   * Form submit callback for policy administration form.
   *
   * Collects configuration from all plugins into a single configuration
   * variable.
   */
  public function adminFormSubmit($form, &$form_state) {
    foreach ($this->items as $item) {
      $item->adminFormSubmit($form, $form_state);
    }
    $form_state['item']->config = serialize($this->config);
  }

  /**
   * Collects messages generated from all plugins.
   *
   * @return string[]
   *   Messages.
   */
  public function messages() {
    $items = array();
    foreach ($this->activeConstraints() as $constraint) {
      $items = array_merge($items, $constraint->messages());
    }
    return $items;
  }

  /**
   * Checks password versus each of the policy's active constraints.
   *
   * @param string $password
   *   Password.
   * @param object $account
   *   User account.
   *
   * @return array
   *   Failure messages for failed constraints.
   */
  public function check($password, $account) {
    $errors = array();
    foreach ($this->activeConstraints() as $constraint) {
      if (!$constraint->check($password, $account)) {
        $errors = array_merge($errors, $constraint->failMessages($password, $account));
      }
    }
    return $errors;
  }

  /**
   * Returns all constraints that are active.
   *
   * @return PasswordPolicyConstraint[]
   *   Active constraints.
   */
  public function activeConstraints() {
    $constraints = array();
    foreach ($this->getItems('constraint') as $constraint) {
      // Any constraint with non-default configuration is "active"
      if ($constraint->info['config'] != $constraint->config) {
        $constraints[] = $constraint;
      }
    }
    return $constraints;
  }

  /**
   * Returns whether all active conditions match.
   *
   * @param object $account
   *   User object.
   *
   * @return bool
   *   TRUE if all conditions match, FALSE otherwise.
   */
  public function match($account) {
    foreach ($this->getItems('condition') as $condition) {
      // Any condition with non-default configuration is "active"
      if ($condition->info['config'] != $condition->config) {
        if (!$condition->match($account)) {
          return FALSE;
        }
      }
    }
    return TRUE;
  }

  /**
   * Runs cron for each of the items that is a cron item.
   */
  public function cron() {
    foreach ($this->getItems('cron') as $item) {
      if ($item->isActive()) {
        $item->cron();
      }
    }
  }

  /**
   * Runs init for each of the items that is a cron item.
   *
   * @param object $account
   *   User object.
   */
  public function init($account) {
    foreach ($this->getItems('init') as $item) {
      $item->init($account);
    }
  }

  /**
   * Loads all Password Policy plugins.
   */
  private function loadPlugins() {
    ctools_include('plugins');
    foreach (ctools_get_plugins('password_policy', 'constraint') as $info) {
      $this->loadPlugin($info);
    }
    foreach (ctools_get_plugins('password_policy', 'condition') as $info) {
      $this->loadPlugin($info);
    }
    foreach (ctools_get_plugins('password_policy', 'item') as $info) {
      $this->loadPlugin($info);
    }
  }

  /**
   * Loads a Password Policy plugin.
   *
   * @param object $info
   *   Password Policy plugin information.
   */
  private function loadPlugin($info) {
    if (!isset($this->config[$info['name']])) {
      $this->config[$info['name']] = array();
    }
    $this->items[$info['name']] = PasswordPolicyConstraint::factory($info, $this);
  }

  /**
   * Gets all items of a particular type.
   *
   * @param string $type
   *   Item type.
   *
   * @return PasswordPolicyItem[]
   *   Items.
   */
  private function getItems($type) {
    $this->cache[$type] = isset($this->cache[$type]) ? $this->cache[$type] : array();
    if (empty($this->cache[$type])) {
      foreach ($this->items as $item) {
        if ($item->isType($type)) {
          $this->cache[$type][] = $item;
        }
      }
    }
    return $this->cache[$type];
  }

  /**
   * Retrieves policy by name.
   *
   * @param string $name
   *   Policy name.
   *
   * @return PasswordPolicy
   *   Policy.
   */
  public static function policy($name) {
    ctools_include('export');
    $info = ctools_export_crud_load('password_policy', $name);
    if ($info) {
      return new PasswordPolicy($info);
    }
  }

  /**
   * Retrieves all policies.
   *
   * @return array
   *   Associative array where keys are policy names and values are
   *   password policies (i.e. PasswordPolicy objects).
   */
  public static function allPolicies() {
    ctools_include('export');
    $policies = array();
    $infos = ctools_export_crud_load_all('password_policy');
    foreach ($infos as $name => $info) {
      $policies[$name] = new PasswordPolicy($info);
    }
    return $policies;
  }

  /**
   * Retrieves all enabled policies.
   *
   * @return PasswordPolicy[]
   *   Enabled policies.
   */
  public static function enabledPolicies() {
    ctools_include('export');
    $policies = array();
    $infos = ctools_export_crud_load_all('password_policy');
    foreach ($infos as $name => $info) {
      if (empty($info->disabled)) {
        $policies[$name] = new PasswordPolicy($info);
      }
    }
    return $policies;
  }

  /**
   * Retrieves all policies that match the current account.
   *
   * @param object $account
   *   User object.
   *
   * @return PasswordPolicy[]
   *   Policies matching account.
   */
  public static function matchedPolicies($account) {
    $policies = array();
    foreach (PasswordPolicy::enabledPolicies() as $policy) {
      if ($policy->match($account)) {
        $policies[] = $policy;
      }
    }
    return $policies;
  }

}
