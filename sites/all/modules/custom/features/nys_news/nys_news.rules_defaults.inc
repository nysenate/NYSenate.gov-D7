<?php

/**
 * @file
 * nys_news.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_news_default_rules_configuration() {
  $items = array();
  $items['rules_featured_articles'] = entity_import('rules_config', '{ "rules_featured_articles" : {
      "LABEL" : "Featured Articles",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_featured" } },
        { "data_is" : { "data" : [ "node:field-featured" ], "value" : "1" } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cdiv class=\\u0022alert-box alert\\u003E\\r\\n\\u003Cstrong\\u003EWarning:\\u003C\\/strong\\u003E If you have previously set a different Article to \\u0022Featured for Associated Senator\\u0022 you need to unset that article for it to show up in Newsroom Feed again.\\r\\n\\u003C\\/div\\u003E",
            "type" : "warning"
          }
        }
      ]
    }
  }');
  return $items;
}
