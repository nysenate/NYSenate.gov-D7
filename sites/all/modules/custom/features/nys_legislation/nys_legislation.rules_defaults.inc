<?php
/**
 * @file
 * nys_legislation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_legislation_default_rules_configuration() {
  $items = array();
  $items['nys_legislation_resolutions_imports_order'] = entity_import('rules_config', '{ "nys_legislation_resolutions_imports_order" : {
      "LABEL" : "Resolutions imports order",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "rules_scheduler" ],
      "ACTION SET" : [
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : ""
            },
            "PROVIDE" : { "variable_added" : { "feed_url" : "Feed URL " } }
          }
        },
        { "php_eval" : { "code" : "set_time_limit(0);\\r\\n$start = time();\\r\\n\\r\\n\\/\\/Variables declaration\\r\\n$timeout = 60;\\r\\n$limit = 50;\\r\\n\\r\\n\\/\\/Get where the next batch of bills to import should start\\r\\n$last_item = variable_get(\\u0027resolutions_importer_last_item\\u0027);\\r\\nif(!$last_item) $last_item =1;\\r\\n\\r\\n\\/\\/Retrieve sources\\r\\n$sources = array();\\r\\n$sources[] = feeds_source(\\u0027custom_resolutions_json_importer\\u0027, 0);\\r\\n$sources[] = feeds_source(\\u0027custom_resolutions_json_milestones_importer\\u0027, 0);\\r\\n\\r\\n\\/\\/Get total bills in the source\\r\\n$text = file_get_contents($feed_url.\\u0027\\u0026limit=1\\u0026offset=1\\u0027);\\r\\n$needle = \\u0022total\\u0022;\\r\\n$index1 =  strpos($text , $needle);\\r\\n$index2 =  strpos($text , \\u0022,\\u0022,$index1); \\r\\n$bills_count = substr($text, $index1+9, $index2 - $index1-9);\\r\\n\\r\\n\\/\\/The chicken of the chicken rice\\r\\n\\/\\/We\\u0027ll be importing while we have enough time to spend on that\\r\\nwhile((time() - $start) \\u003C $timeout){\\r\\n  \\/\\/Control wether the last_item has passed the bills total\\r\\n  if($last_item \\u003E= $bills_count)\\r\\n    $last_item = 0;\\r\\n  \\/\\/Build the url to import source from\\r\\n  $current_url = $feed_url.\\u0027\\u0026limit=\\u0027.$limit.\\u0027\\u0026offset=\\u0027.$last_item;\\r\\n  \\/\\/Assign source url and execute every importer\\r\\n  foreach($sources as $source){\\r\\n    $config = $source-\\u003EgetConfig();\\r\\n    if($config[\\u0027FeedsHTTPFetcher\\u0027][\\u0027source\\u0027] != $current_url){\\r\\n      $config[\\u0027FeedsHTTPFetcher\\u0027][\\u0027source\\u0027] = $current_url;\\r\\n      $source-\\u003EsetConfig($config);\\r\\n      $source-\\u003Esave();\\r\\n    }\\/\\/endif\\r\\n    while (FEEDS_BATCH_COMPLETE != $source-\\u003Eimport());\\r\\n  }\\r\\n  \\/\\/Get offset variable for next iteration\\r\\n  $last_item += $limit;\\r\\n}\\r\\n\\r\\n\\/\\/Save last item for next import process offset\\r\\nvariable_set(\\u0027resolutions_importer_last_item\\u0027, $last_item);" } },
        { "schedule" : {
            "component" : "rules_imports_order",
            "date" : "+1 day",
            "identifier" : "resolutions_imports_order"
          }
        }
      ]
    }
  }');
  $items['rules_imports_order'] = entity_import('rules_config', '{ "rules_imports_order" : {
      "LABEL" : "imports order",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "rules_scheduler" ],
      "ACTION SET" : [
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : ""
            },
            "PROVIDE" : { "variable_added" : { "feed_url" : "Feed URL " } }
          }
        },
        { "php_eval" : { "code" : "set_time_limit(0);\\r\\n$start = time();\\r\\n\\r\\n\\/\\/Variables declaration\\r\\n$timeout = 60;\\r\\n$limit = 50;\\r\\n\\r\\n\\/\\/Get where the next batch of bills to import should start\\r\\n$last_item = variable_get(\\u0027bills_importer_last_item\\u0027);\\r\\nif(!$last_item) $last_item =1;\\r\\n\\r\\n\\/\\/Retrieve sources\\r\\n$sources = array();\\r\\n$sources[] = feeds_source(\\u0027custom_bills_json_importer\\u0027, 0);\\r\\n$sources[] = feeds_source(\\u0027custom_bills_json_actions_importer\\u0027, 0);\\r\\n$sources[] = feeds_source(\\u0027custom_bills_json_votes_importer\\u0027, 0);\\r\\n$sources[] = feeds_source(\\u0027custom_bills_json_past_committees_importer_2\\u0027, 0);\\r\\n$sources[] = feeds_source(\\u0027bills_json_milestones_importer\\u0027, 0);\\r\\n\\r\\n\\/\\/Get total bills in the source\\r\\n$text = file_get_contents($feed_url.\\u0027\\u0026limit=1\\u0026offset=1\\u0027);\\r\\n$needle = \\u0022total\\u0022;\\r\\n$index1 =  strpos($text , $needle);\\r\\n$index2 =  strpos($text , \\u0022,\\u0022,$index1); \\r\\n$bills_count = substr($text, $index1+9, $index2 - $index1-9);\\r\\n\\r\\n\\/\\/The chicken of the chicken rice\\r\\n\\/\\/We\\u0027ll be importing while we have enough time to spend on that\\r\\nwhile((time() - $start) \\u003C $timeout){\\r\\n  \\/\\/Control wether the last_item has passed the bills total\\r\\n  if($last_item \\u003E= $bills_count)\\r\\n    $last_item = 0;\\r\\n  \\/\\/Build the url to import source from\\r\\n  $current_url = $feed_url.\\u0027\\u0026limit=\\u0027.$limit.\\u0027\\u0026offset=\\u0027.$last_item;\\r\\n  \\/\\/Assign source url and execute every importer\\r\\n  foreach($sources as $source){\\r\\n    $config = $source-\\u003EgetConfig();\\r\\n    if($config[\\u0027FeedsHTTPFetcher\\u0027][\\u0027source\\u0027] != $current_url){\\r\\n      $config[\\u0027FeedsHTTPFetcher\\u0027][\\u0027source\\u0027] = $current_url;\\r\\n      $source-\\u003EsetConfig($config);\\r\\n      $source-\\u003Esave();\\r\\n    }\\/\\/endif\\r\\n    while (FEEDS_BATCH_COMPLETE != $source-\\u003Eimport());\\r\\n  }\\r\\n  \\/\\/Get offset variable for next iteration\\r\\n  $last_item += $limit;\\r\\n}\\r\\n\\r\\n\\/\\/Save last item for next import process offset\\r\\nvariable_set(\\u0027bills_importer_last_item\\u0027, $last_item);" } },
        { "schedule" : {
            "component" : "rules_imports_order",
            "date" : "+1 day",
            "identifier" : "importers_order"
          }
        }
      ]
    }
  }');
  return $items;
}
