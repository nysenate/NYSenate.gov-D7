<?php

/**
 * @file
 * nys_cms.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nys_cms_default_rules_configuration() {
  $items = array();
  $items['rules_check_for_all_caps'] = entity_import('rules_config', '{ "rules_check_for_all_caps" : {
      "LABEL" : "Style Enforcement: All Caps",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_presave--article" : { "bundle" : "article" },
        "node_presave--press_release" : { "bundle" : "press_release" },
        "node_presave--in_the_news" : { "bundle" : "in_the_news" },
        "node_presave--petition" : { "bundle" : "petition" },
        "node_presave--promotional_banner" : { "bundle" : "promotional_banner" }
      },
      "IF" : [
        { "NOT text_matches" : { "text" : [ "node:title" ], "match" : "[a-z]", "operation" : "regex" } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003EWarning:\\u003C\\/strong\\u003E the title of this piece of content includes words typeset in ALL CAPS. This style is inconsistent with \\u003Ca href=\\u0022http:\\/\\/webforum.nysenate.gov\\/t\\/do-not-use-all-caps-in-headlines\\/136\\u0022\\u003Ebest practices\\u003C\\/a\\u003E, and it is not supported well by NYSenate.gov\\u0027s header typeface. For readability purposes, please consider posting in \\u003Ca href=\\u0022http:\\/\\/www.titlecase.com\\u0022\\u003Etitle case\\u003C\\/a\\u003E instead. If you would like assistance bulk converting all of your content headlines to title case, please send a request to \\u003Ca href=\\u0022mailto:helpline@nysenate.gov?Subject=Bulk%20headline%20conversion%20request\\u0022\\u003Ehelpline@nysenate.gov\\u003C\\/a\\u003E.",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_content_recommendation_add_committee_header_image'] = entity_import('rules_config', '{ "rules_content_recommendation_add_committee_header_image" : {
      "LABEL" : "Content Recommendation: Add Committee Header Image",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_presave--committees" : { "bundle" : "committees" } },
      "IF" : [ { "data_is_empty" : { "data" : [ "term:field-image-hero" ] } } ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003EDid you know?\\u003C\\/strong\\u003E Committee pages can have \\u0022hero\\u0022 images (just like the front page of nysenate.gov). We\\u0027re showing you this notification because you have not chosen one for this committee. \\u003Ca href=\\u0022http:\\/\\/webforum.nysenate.gov\\/t\\/committee-hero-images\\/173\\u0022\\u003ELearn more.\\u003C\\/a\\u003E ",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_content_recommendation_add_committee_mission_statement'] = entity_import('rules_config', '{ "rules_content_recommendation_add_committee_mission_statement" : {
      "LABEL" : "Content Recommendation: Add Committee Mission Statement",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "taxonomy" ],
      "ON" : { "taxonomy_term_presave--committees" : { "bundle" : "committees" } },
      "IF" : [ { "data_is_empty" : { "data" : [ "term:description" ] } } ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003EDid you know?\\u003C\\/strong\\u003E Committee pages can have a mission statement. This should be a tweet-length sentence that helps constituents understand the mission of a this committee. We\\u0027re showing you this notification because a mission is not currently designated for this committee. ",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_prompt_user_to_add_issues'] = entity_import('rules_config', '{ "rules_prompt_user_to_add_issues" : {
      "LABEL" : "Prompt user to add issues",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_presave--press_release" : { "bundle" : "press_release" },
        "node_presave--petition" : { "bundle" : "petition" },
        "node_presave--article" : { "bundle" : "article" },
        "node_presave--event" : { "bundle" : "event" },
        "node_presave--public_hearing" : { "bundle" : "public_hearing" },
        "node_presave--video" : { "bundle" : "video" }
      },
      "IF" : [ { "data_is_empty" : { "data" : [ "node:field-issues" ] } } ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003EWarning:\\u003C\\/strong\\u003E no \\u003Ca href=\\u0022\\/explore-issues\\u0022\\u003Eissues\\u003C\\/a\\u003E have been associated with this piece of content. Add up to three issue tags to help users discover this content.",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  return $items;
}
