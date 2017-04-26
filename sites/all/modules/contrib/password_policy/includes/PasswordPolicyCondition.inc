<?php
/**
 * @file
 * Contains PasswordPolicyCondition.
 */

/**
 * Class PasswordPolicyCondition.
 *
 * This class is used for conditionally executing policies.
 */
class PasswordPolicyCondition extends PasswordPolicyItem {
  protected $ppType = array('item', 'condition');

  /**
   * Checks whether condition matches.
   *
   * That is, check whether the condition is met for the given account.
   *
   * @param object $account
   *   User object.
   *
   * @return bool
   *   TRUE if the condition matches, FALSE otherwise.
   */
  public function match($account) {
    $func = $this->func('condition callback');
    if ($func) {
      return $func($account, $this);
    }
    return TRUE;
  }

}
