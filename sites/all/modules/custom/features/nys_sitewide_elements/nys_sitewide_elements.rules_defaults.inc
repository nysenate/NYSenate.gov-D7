<?php
/**
 * @file
 * nys_sitewide_elements.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_sitewide_elements_default_rules_configuration() {
  $items = array();
  $items['rules_account_create'] = entity_import('rules_config', '{ "rules_account_create" : {
      "LABEL" : "Account Create",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "constituent" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "message" },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created User" } }
          }
        }
      ]
    }
  }');
  $items['rules_on_follow_bill'] = entity_import('rules_config', '{ "rules_on_follow_bill" : {
      "LABEL" : "On Follow Bill",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "follow" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_follow_this_bill" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "flagging-user" ], "roles" : { "value" : { "7" : "7" } } } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "message" },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        }
      ]
    }
  }');
  return $items;
}
