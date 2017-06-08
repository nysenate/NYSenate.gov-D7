<?php
/**
 * @file
 * nys_student_submissions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nys_student_submissions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nys_student_submissions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function nys_student_submissions_default_entityform_type() {
  $items = array();
  $items['earth_day'] = entity_import('entityform_type', '{
    "type" : "earth_day",
    "label" : "Earth Day",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Submit FINAL",
      "submit_confirm_msg" : "Your Earth Day submission has been successfully submitted, thank you!",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "Your Earth Day Competition Submissions",
      "preview_page" : 1,
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EThank you for your submissions to the Earth Day 2017 Poster Competition.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "6" : "6",
        "8" : "8",
        "17" : "17",
        "1" : 0,
        "2" : 0,
        "9" : 0,
        "3" : 0,
        "10" : 0,
        "11" : 0,
        "13" : 0,
        "14" : 0,
        "7" : 0,
        "18" : 0,
        "19" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cdiv class=\\u0022c-questionnaire--head\\u0022\\u003E\\r\\n\\u003Ch2 class=\\u0022nys-article-title\\u0022\\u003ENew York State Senate Earth Day Competition 2017 Poster Contest\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--head-meta\\u0022\\u003E\\r\\n\\u003Cp class=\\u0022c-news--pub-date\\u0022\\u003E\\u003Cspan class=\\u0022date-display-single\\u0022\\u003EFebruary 6, 2017\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul class=\\u0022nys-associated-topics\\u0022\\u003E\\r\\n\\t\\u003Cli\\u003E\\u003Ca href=\\u0022\\/issues\\/earth-day\\u0022\\u003EEarth Day\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-block c-block--img\\u0022\\u003E\\u003Cimg alt=\\u0022\\u0022 height=\\u0022377\\u0022 src=\\u0022\\/sites\\/default\\/files\\/earth_day_2017_banner.jpg\\u0022 width=\\u0022760\\u0022\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe Earth Day Competition is for school children in grades K-6 from every corner of New York State. The Senate\\u2019s goal is to encourage children to develop an awareness of the environment and its resources. Teaching children about the importance of recycling and waste reduction is critical as we face the environmental challenges of the 21st Century.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022\\/sites\\/default\\/files\\/earth-day-competition-poster-contest.pdf\\u0022\\u003E\\u003Cimg alt=\\u0022Earth Day Poster\\u0022 src=\\u0022\\/sites\\/default\\/files\\/styles\\/400x240\\/public\\/earth-day-2017-gen.jpg\\u0022 style=\\u0022float:left;padding-right:6px;width:200px;\\u0022\\u003E\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EOUR Theme: Reduce, Reuse, Recycle.\\u003C\\/strong\\u003E The Senate\\u2019s focus is to emphasize the importance of recycling and waste reduction, to encourage the exchange of ideas about recycling and waste reduction among schools, children and adults and to stimulate creative thinking about solutions to problems concerning recycling and waste reduction. We are asking students to create a poster that could be used as part of this campaign.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EDeadline:\\u003C\\/strong\\u003E All submissions must be uploaded to the website by \\u003Cstrong\\u003EMarch 31, 2017\\u003C\\/strong\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EInstructions:\\u003C\\/strong\\u003E Please fill out your class and school information first, and then enter ALL your students on this form. Entries should be photographed and submitted electronically, preferably in jpeg or pdf format. Please enter each student individually, we can not accept a single pdf with all your students grouped together. Thank you.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Chr\\u003E",
        "format" : "source_html"
      }
    },
    "weight" : "0",
    "paths" : []
  }');
  $items['school_submissions'] = entity_import('entityform_type', '{
    "type" : "school_submissions",
    "label" : "2016 What are you thankful for this year?",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "2" : "2",
        "6" : 0,
        "8" : 0,
        "9" : 0,
        "3" : 0,
        "10" : 0,
        "11" : 0,
        "13" : 0,
        "14" : 0,
        "7" : 0,
        "16" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003EPlease submit your essay, poetry or art work for inclusion in our Thanksgiving Day Showcase by November 21, 2016.\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/school-submissions",
        "alias" : "questionnaires\\/what-are-you-thankful-2016",
        "language" : "und"
      }
    }
  }');
  return $items;
}
