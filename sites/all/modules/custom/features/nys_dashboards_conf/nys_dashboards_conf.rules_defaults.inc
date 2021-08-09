<?php

/**
 * @file
 * nys_dashboards_conf.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_dashboards_conf_default_rules_configuration() {
  $items = array();
  $items['rules_mass_private_message'] = entity_import('rules_config', '{ "rules_mass_private_message" : {
      "LABEL" : "Mass Private Message",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "privatemsg_rules" ],
      "USES VARIABLES" : {
        "users" : { "label" : "users", "type" : "list\\u003Cuser\\u003E" },
        "body" : { "label" : "body", "type" : "text" },
        "subject" : { "label" : "subject", "type" : "text" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "current_user" : "current_user" },
            "DO" : [
              { "privatemsg_rules_new" : {
                  "USING" : {
                    "recipient" : [ "current-user" ],
                    "author" : [ "site:current-user" ],
                    "subject" : "xyz",
                    "body" : [ "body" ]
                  },
                  "PROVIDE" : { "thread_id" : { "message" : "message" } }
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
