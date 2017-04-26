<?php
/**
 * @file
 * nys_users.default_password_policy.inc
 */

/**
 * Implements hook_default_password_policy().
 */
function nys_users_default_password_policy() {
  $export = array();

  $password_policy = new stdClass();
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'NY Senate';
  $password_policy->config = 'a:14:{s:10:"alpha_case";a:1:{s:10:"alpha_case";i:1;}s:11:"alpha_count";a:1:{s:11:"alpha_count";s:0:"";}s:9:"blacklist";a:2:{s:9:"blacklist";s:8:"password";s:26:"blacklist_match_substrings";i:1;}s:10:"char_count";a:1:{s:10:"char_count";s:1:"8";}s:11:"consecutive";a:1:{s:22:"consecutive_char_count";s:0:"";}s:5:"delay";a:1:{s:5:"delay";s:0:"";}s:15:"drupal_strength";a:1:{s:15:"drupal_strength";s:0:"";}s:9:"int_count";a:1:{s:9:"int_count";s:0:"";}s:14:"past_passwords";a:1:{s:14:"past_passwords";s:1:"1";}s:12:"symbol_count";a:2:{s:12:"symbol_count";s:0:"";s:20:"symbol_count_symbols";s:30:"!@#$%^&*()_+=-|}{"?:><,./;\'\\[]";}s:8:"username";a:1:{s:8:"username";i:0;}s:7:"authmap";a:1:{s:11:"authmodules";a:0:{}}s:4:"role";a:1:{s:5:"roles";a:12:{i:1;i:0;i:2;i:0;i:6;i:0;i:8;i:0;i:9;i:0;i:3;i:0;i:10;i:0;i:11;i:0;i:13;i:0;i:14;i:0;i:7;i:0;i:16;i:0;}}s:6:"expire";a:6:{s:14:"expire_enabled";i:0;s:12:"expire_limit";s:8:"6 months";s:22:"expire_warning_message";s:48:"Your password has expired. Please change it now.";s:25:"expire_warning_email_sent";s:8:"-14 days";s:28:"expire_warning_email_message";s:0:"";s:28:"expire_warning_email_subject";s:94:"[user:name], your password on [site:name] shall expire in [password_expiration_date:interval] ";}}';
  $export['NY Senate'] = $password_policy;

  return $export;
}
