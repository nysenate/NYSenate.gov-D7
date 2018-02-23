<?php
/**
 * @file
 * nys_senators.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_senators_default_rules_configuration() {
  $items = array();
  $items['rules_senator_bill_message'] = entity_import('rules_config', '{ "rules_senator_bill_message" : {
      "LABEL" : "Senator Bill Message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--senator" : { "bundle" : "senator" } },
      "IF" : [
        { "list_count_is" : {
            "list" : [ "node:field-featured-legislation" ],
            "op" : "\\u003E",
            "value" : "5"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Senator [node:title] has featured more than 5 bills. Only the first 5 are featured on Senator\\u0027s Home and Legislation pages. The quotes from all featured bills will show on bill pages sponsored by Senator [node:title]." } }
      ]
    }
  }');
  return $items;
}
