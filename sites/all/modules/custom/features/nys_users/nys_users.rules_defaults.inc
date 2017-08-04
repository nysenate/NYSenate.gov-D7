<?php
/**
 * @file
 * nys_users.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_users_default_rules_configuration() {
  $items = array();
  $items['rules_assign_consituent_role'] = entity_import('rules_config', '{ "rules_assign_consituent_role" : {
      "LABEL" : "Assign Consituent Role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "registration" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "7" : "7" } } } }
      ]
    }
  }');
  $items['rules_redirect_to_account_instructions'] = entity_import('rules_config', '{ "rules_redirect_to_account_instructions" : {
      "LABEL" : "Redirect to Account Instructions",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "6" : "6" } }
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "almost-there" } } ]
    }
  }');
  return $items;
}
