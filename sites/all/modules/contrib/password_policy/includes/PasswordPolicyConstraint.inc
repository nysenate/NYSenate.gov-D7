<?php
/**
 * @file
 * Contains PasswordPolicyConstraint.
 */

/**
 * Class PasswordPolicyConstraint.
 *
 * This class is to test individual policy constraints.
 */
class PasswordPolicyConstraint extends PasswordPolicyItem {
  protected $ppType = array('item', 'constraint');

  /**
   * Constructs PasswordPolicyConstraint object.
   *
   * @param array $info
   *   Ctools plugin info.
   * @param object $policy
   *   Database object as returned by ctools_export_crud_load().
   */
  public function __construct(array $info, &$policy) {
    if (isset($info['default'])) {
      $info['prime value'] = $info['name'];
      $info['config'] = array($info['name'] => $info['default']);
    }
    parent::__construct($info, $policy);
  }

  /**
   * Gets messages for active constraint.
   *
   * @return string[]
   *   Messages.
   */
  public function messages() {
    $mes_temp = is_array($this->info['message']) ? $this->info['message'] : array($this->info['message']);
    $messages = array();
    foreach ($mes_temp as $id => $message) {
      // Only show messages for constraints that have been configured.
      if ($this->config != $this->info['config']) {
        $args = array();
        foreach ($this->config as $key => $value) {
          $args['@' . $key] = $value;
        }
        $messages[$id] = format_string($message, $args);
      }
    }
    return $messages;
  }

  /**
   * Gets messages indicating password failed to meet constraint.
   *
   * @param string $password
   *   Password.
   * @param object $account
   *   Account object.
   *
   * @return string[]
   *   Failure messages.
   */
  public function failMessages($password, $account) {
    return $this->messages();
  }

  /**
   * Checks whether constraint is met.
   *
   * @param string $password
   *   Password.
   * @param object $account
   *   User object.
   *
   * @return bool
   *   TRUE if the constraint is met, FALSE otherwise.
   */
  public function check($password, $account) {
    $func = $this->func('constraint callback');
    if ($func) {
      return $func($password, $account, $this);
    }
    return TRUE;
  }

}
