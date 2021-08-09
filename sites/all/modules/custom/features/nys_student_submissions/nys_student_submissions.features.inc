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
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
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
      "submission_text" : { "value" : "", "format" : "source_html" },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_CLOSED",
      "roles" : {
        "1" : "1",
        "6" : "6",
        "21" : "21",
        "2" : 0,
        "8" : 0,
        "9" : 0,
        "3" : 0,
        "10" : 0,
        "11" : 0,
        "13" : 0,
        "14" : 0,
        "7" : 0,
        "19" : 0,
        "20" : 0,
        "17" : 0,
        "18" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cdiv class=\\u0022c-questionnaire--head\\u0022\\u003E\\r\\n\\u003Ch2 class=\\u0022nys-article-title\\u0022\\u003ENew York State Senate Earth Day\\u0026nbsp;2021 Poster Celebration\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--head-meta\\u0022\\u003E\\r\\n\\u003Cp class=\\u0022c-news--pub-date\\u0022\\u003E\\u003Cspan class=\\u0022date-display-single\\u0022\\u003EFebruary 2, 2021\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul class=\\u0022nys-associated-topics\\u0022\\u003E\\r\\n\\t\\u003Cli\\u003E\\u003Ca href=\\u0022\\/issues\\/earth-day\\u0022\\u003EEarth Day\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-block c-block--img\\u0022\\u003E[[{\\u0022fid\\u0022:\\u00221830683\\u0022,\\u0022view_mode\\u0022:\\u0022full\\u0022,\\u0022fields\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022,\\u0022format\\u0022:\\u0022full\\u0022,\\u0022alignment\\u0022:\\u0022left\\u0022,\\u0022field_file_image_alt_text[und][0][value]\\u0022:false,\\u0022field_file_image_title_text[und][0][value]\\u0022:false},\\u0022type\\u0022:\\u0022media\\u0022,\\u0022field_deltas\\u0022:{\\u00221\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022,\\u0022format\\u0022:\\u0022full\\u0022,\\u0022alignment\\u0022:\\u0022left\\u0022,\\u0022field_file_image_alt_text[und][0][value]\\u0022:false,\\u0022field_file_image_title_text[und][0][value]\\u0022:false}},\\u0022link_text\\u0022:null,\\u0022attributes\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022}}]]\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe Earth Day Celebration is for school children in grades K-6 from every corner of New York State. The Senate\\u2019s goal is to encourage children to develop an awareness of the environment and its resources. Teaching children about the importance of recycling and waste reduction is critical as we face the environmental challenges of the 21st Century.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EOUR Theme: Reduce, Reuse, Recycle.\\u003C\\/strong\\u003E The Senate\\u2019s focus is to emphasize the importance of recycling and waste reduction, to encourage the exchange of ideas about recycling and waste reduction among schools, children and adults and to stimulate creative thinking about solutions to problems concerning recycling and waste reduction. We are asking students to create a poster that could be used as part of this campaign.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EDeadline:\\u003C\\/strong\\u003E All submissions must be uploaded to the website by \\u003Cstrong\\u003EApril 20, 2021\\u003C\\/strong\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EInstructions for Teachers:\\u003C\\/strong\\u003E Please fill out your class and school information first, and then enter ALL your students on this form. Entries should be photographed and submitted electronically, preferably in jpeg or pdf format. Please enter each student individually, we can not accept a single pdf with all your students grouped together. Thank you.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EInstructions for Parents of Homeschoolers:\\u0026nbsp;\\u003C\\/strong\\u003EPlease enter parent name and email in teacher fields, select the elementary school associated with your place of residence, and\\u0026nbsp; choose \\u0022Homeschool\\u0022 for grade. You may optionally enter your child\\u0027s grade next to their name.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Chr\\u003E",
        "format" : "source_html"
      }
    },
    "weight" : "0",
    "paths" : []
  }');
  $items['hannon_photo_contest'] = entity_import('entityform_type', '{
    "type" : "hannon_photo_contest",
    "label" : "Photo Contest Entry Form",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Submit your Contest Entry",
      "submit_confirm_msg" : "Your Submission to Senator Hannon\\u0027s 2018 Hometown Photo Contest has been received. Only one submission per student is permitted.",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Thank you for submitting to this year\\u0027s photo contest.",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EThank you for your submission\\u0026nbsp;to Senator Hannon\\u0027s 2018 Hometown photo contest.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe deadline for the contest is March 1, 2018. Once the contest has ended, we will reach out to those participants whose photos have been selected for First Place, Second Place, Third Place and Honorable Mention. One photographer\\u2019s photo will also be named \\u201cBest in Show.\\u201d\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EYour final submission:\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "6" : "6",
        "17" : "17",
        "1" : 0,
        "2" : 0,
        "8" : 0,
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
      "instruction_pre" : { "value" : "", "format" : "source_html" }
    },
    "weight" : "0",
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/hannon-photo-contest",
        "alias" : "senators\\/kemp-hannon\\/photo-contest",
        "language" : "und"
      }
    }
  }');
  $items['new_york_senate_youth_leadership'] = entity_import('entityform_type', '{
    "type" : "new_york_senate_youth_leadership",
    "label" : "New York Senate Youth Leadership Recognition Award Nomination Form",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Your submission has been received, thank you.",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "2" : "2",
        "6" : "6",
        "17" : "17",
        "1" : 0,
        "8" : 0,
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
        "value" : "\\u003Cdiv class=\\u0022c-questionnaire--head\\u0022\\u003E\\r\\n\\u003Ch2 class=\\u0022nys-article-title\\u0022\\u003ENew York Senate Youth Leadership Recognition Award Nomination Form\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--head-meta\\u0022\\u003E\\r\\n\\u003Cp class=\\u0022c-news--pub-date\\u0022\\u003E\\u003Cspan class=\\u0022date-display-single\\u0022\\u003EFebruary 9, 2018\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul class=\\u0022nys-associated-topics\\u0022\\u003E\\r\\n\\t\\u003Cli\\u003E\\u003Ca href=\\u0022\\/issues\\/youth-leadership\\u0022\\u003EYouth Leadership\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-block c-block--img\\u0022\\u003E\\u003Cimg alt=\\u0022\\u0022 height=\\u0022377\\u0022 src=\\u0022\\/sites\\/default\\/files\\/760x377_2016-ylp_0_18_new.jpg\\u0022 width=\\u0022760\\u0022\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EThe New York State Senate Youth Leadership Recognition Awards\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EFebruary is Youth Leadership Month making it the perfect time to highlight the New York State Senate\\u2019s Youth Leadership Recognition Awards program. The award recognizes and honors outstanding students who will become our future leaders. \\u0026nbsp;Do you know a successful high school student whose accomplishments make your school proud? \\u0026nbsp;Today is your chance to recognize that student for their achievements and the great work they do to benefit their community.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou and\\/or your staff can nominate a student by filling out the online nomination form, attaching a recommendation letter and the student\\u2019s brief statement about their accomplishment(s). Nominations may come from teachers, administrators, counselors, or other school faculty. \\u0026nbsp;We are looking for well-rounded candidates who excel not only academically, but through leadership in extracurricular and volunteer activities.\\u0026nbsp; There are 4 categories to choose from including Academics, Athletics, Arts and Community Service.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe Senator will present the selected students with a certificate of recognition and share their story on their website. Participating schools are invited to nominate a maximum of five junior or senior students for the program. All nominations must be submitted online by April 11, 2018.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cimg alt=\\u0022\\u0022 height=\\u0022147\\u0022 src=\\u0022https:\\/\\/www.nysenate.gov\\/sites\\/default\\/files\\/2016_ylra_0_3.jpg\\u0022 title=\\u0022\\u0022 width=\\u0022720\\u0022\\u003E\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n",
        "format" : "source_html"
      }
    },
    "weight" : "0",
    "paths" : []
  }');
  $items['participatory_budgeting'] = entity_import('entityform_type', '{
    "type" : "participatory_budgeting",
    "label" : "Participatory Budgeting",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Thank you, your submission has been saved. ",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EThank you for your participation. If you have signed up to volunteer, our volunteer coordinator or a district staff member will follow up with you.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can review all submitted projects on the \\u003Ca href=\\u0022\\/senators\\/jesse-hamilton\\/pb-projects\\u0022\\u003EDistrict 20 Participatory Budgeting page\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EPlease note that:\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul\\u003E\\r\\n\\t\\u003Cli\\u003ENominations are subject to criteria for eligibility. \\u003Ca href=\\u0022\\/senators\\/jesse-hamilton\\/pb\\u0022\\u003EFull list of criteria\\u0026gt;\\u0026gt;\\u003C\\/a\\u003E\\u0026nbsp;\\u003C\\/li\\u003E\\r\\n\\t\\u003Cli\\u003ENominations that have completed initial review will appear on the map within two business days.\\u003C\\/li\\u003E\\r\\n\\t\\u003Cli\\u003EAcceptance of a nomination is not a guarantee of funding.\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Ch2 class=\\u0022nys-title\\u0022\\u003EYour Completed Submission:\\u003C\\/h2\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
        "format" : "source_html"
      },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "6" : "6",
        "17" : "17",
        "1" : 0,
        "2" : 0,
        "8" : 0,
        "9" : 0,
        "3" : 0,
        "10" : 0,
        "11" : 0,
        "13" : 0,
        "14" : 0,
        "7" : 0,
        "19" : 0,
        "20" : 0,
        "18" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cdiv class=\\u0022c-questionnaire--head\\u0022\\u003E\\r\\n\\u003Ch1 class=\\u0022nys-article-title\\u0022\\u003EParticipatory Budgeting Volunteer \\u0026amp;\\u0026nbsp;Project Nomination Form\\u003C\\/h1\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--head-meta\\u0022\\u003E\\r\\n\\u003Cp class=\\u0022c-news--pub-date\\u0022\\u003E\\u003Cspan class=\\u0022date-display-single\\u0022\\u003EMay 17, 2018\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul class=\\u0022nys-associated-topics\\u0022\\u003E\\r\\n\\t\\u003Cli\\u003E\\u003Ca href=\\u0022\\/issues\\/participatory-budgeting\\u0022\\u003EParticipatory Budgeting\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-block c-block--img\\u0022\\u003E\\u003Cimg alt=\\u0022\\u0022 height=\\u0022377\\u0022 src=\\u0022\\/sites\\/default\\/files\\/pb_flyer_web_banner_aug_v1.jpg\\u0022 width=\\u0022760\\u0022\\u003E\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cp\\u003EIf you would like to volunteer or\\u0026nbsp;nominate a project for consideration, please fill out the form below.\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca class=\\u0022c-paragraph--more-link a-left\\u0022 href=\\u0022\\/senators\\/jesse-hamilton\\/pb-projects\\u0022\\u003EView all the proposed projects\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EPlease Note:\\u003C\\/strong\\u003E\\u0026nbsp;We are no longer accepting new nominations for PB projects. If you have any input regarding existing proposals, please contact Raul Rothblatt at\\u0026nbsp;\\u003Ca href=\\u0022mailto:RaulNYSenate@gmail.com\\u0022\\u003ERaulNYSenate@gmail.com\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n",
        "format" : "source_html"
      }
    },
    "weight" : "0",
    "paths" : {
      "submit" : {
        "source" : "eform\\/submit\\/participatory-budgeting",
        "alias" : "senators\\/jesse-hamilton\\/pb-form",
        "language" : "und"
      },
      "confirm" : {
        "source" : "eform\\/participatory-budgeting\\/confirm",
        "alias" : "senators\\/jesse-hamilton\\/pb-confirm",
        "language" : "und"
      }
    }
  }');
  $items['school_submissions'] = entity_import('entityform_type', '{
    "type" : "school_submissions",
    "label" : "Thanksgiving",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Submit",
      "submit_confirm_msg" : "Thank you! Your submission to the Thanksgiving Day Showcase has been received.",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_CLOSED",
      "roles" : {
        "1" : "1",
        "2" : "2",
        "6" : "6",
        "21" : "21",
        "8" : 0,
        "9" : 0,
        "3" : 0,
        "10" : 0,
        "11" : 0,
        "13" : 0,
        "14" : 0,
        "7" : 0,
        "19" : 0,
        "20" : 0,
        "17" : 0,
        "18" : 0
      },
      "resubmit_action" : "disallow",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cdiv class=\\u0022c-questionnaire--head\\u0022\\u003E\\r\\n\\u003Ch1 class=\\u0022nys-article-title\\u0022\\u003E2020 What are you thankful for this year?\\u003C\\/h1\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--head-meta\\u0022\\u003E\\r\\n\\u003Cp class=\\u0022c-news--pub-date\\u0022\\u003E\\u003Cspan class=\\u0022date-display-single\\u0022\\u003ESeptember\\u0026nbsp;24, 2020\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul class=\\u0022nys-associated-topics\\u0022\\u003E\\r\\n\\t\\u003Cli\\u003E\\u003Ca href=\\u0022\\/issues\\/thanksgiving\\u0022\\u003EThanksgiving\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--body\\u0022\\u003E\\r\\n\\u003Cdiv class=\\u0022c-block c-block--img\\u0022\\u003E[[{\\u0022fid\\u0022:\\u00221819076\\u0022,\\u0022view_mode\\u0022:\\u0022full\\u0022,\\u0022fields\\u0022:{\\u0022format\\u0022:\\u0022full\\u0022,\\u0022alignment\\u0022:\\u0022left\\u0022,\\u0022field_file_image_alt_text[und][0][value]\\u0022:false,\\u0022field_file_image_title_text[und][0][value]\\u0022:false},\\u0022type\\u0022:\\u0022media\\u0022,\\u0022field_deltas\\u0022:{\\u00221\\u0022:{\\u0022format\\u0022:\\u0022full\\u0022,\\u0022alignment\\u0022:\\u0022left\\u0022,\\u0022field_file_image_alt_text[und][0][value]\\u0022:false,\\u0022field_file_image_title_text[und][0][value]\\u0022:false}},\\u0022link_text\\u0022:null,\\u0022attributes\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022}}]]\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cp\\u003EPlease submit your essay, poetry or art work for inclusion in our Thanksgiving Day Showcase by November 23,\\u0026nbsp;2020. Submissions are limited to grades K-6.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003ENote:\\u003C\\/strong\\u003E Teachers may submit multiple students from a single grade on this form.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n",
        "format" : "source_html"
      }
    },
    "weight" : "0",
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/school-submissions",
        "alias" : "questionnaires\\/what-are-you-thankful",
        "language" : "und"
      }
    }
  }');
  $items['summer_reading'] = entity_import('entityform_type', '{
    "type" : "summer_reading",
    "label" : "Summer Reading Program",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Thank you for participating in the NYS Senate\\u0027s Summer Reading Program",
      "your_submissions" : "Your Submissions",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "\\u003Cp\\u003ECongratulations and thank you for participating in the NYS Senate\\u0027s Summer Reading Program. Your child will receive a \\u003Cem\\u003ECertificate of Achievement\\u003C\\/em\\u003E for reading three(3) books this summer from his\\/her New York State Senator. Based on the address you entered, we have looked up your State Senator for you, which is displayed below.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp class=\\u0022label-above header\\u0022\\u003EYour completed submission:\\u003C\\/p\\u003E\\r\\n",
        "format" : "source_html"
      },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "6" : "6",
        "21" : "21",
        "2" : 0,
        "8" : 0,
        "9" : 0,
        "3" : 0,
        "10" : 0,
        "11" : 0,
        "13" : 0,
        "14" : 0,
        "7" : 0,
        "19" : 0,
        "20" : 0,
        "17" : 0,
        "18" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cdiv class=\\u0022c-questionnaire--head\\u0022\\u003E\\r\\n\\u003Ch1 class=\\u0022nys-article-title\\u0022\\u003ENew York State Senate Summer Reading Program\\u003C\\/h1\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--head-meta\\u0022\\u003E\\r\\n\\u003Cp class=\\u0022c-news--pub-date\\u0022\\u003E\\u003Cspan class=\\u0022date-display-single\\u0022\\u003EApril 28, 2021\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul class=\\u0022nys-associated-topics\\u0022\\u003E\\r\\n\\t\\u003Cli\\u003E\\u003Ca href=\\u0022\\/issues\\/earth-day\\u0022\\u003ESummer Reading Program\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-block c-block--img\\u0022\\u003E[[{\\u0022fid\\u0022:\\u00221815317\\u0022,\\u0022view_mode\\u0022:\\u0022full\\u0022,\\u0022fields\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022,\\u0022format\\u0022:\\u0022full\\u0022,\\u0022alignment\\u0022:\\u0022left\\u0022,\\u0022field_file_image_alt_text[und][0][value]\\u0022:false,\\u0022field_file_image_title_text[und][0][value]\\u0022:false},\\u0022type\\u0022:\\u0022media\\u0022,\\u0022field_deltas\\u0022:{\\u00221\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022,\\u0022format\\u0022:\\u0022full\\u0022,\\u0022alignment\\u0022:\\u0022left\\u0022,\\u0022field_file_image_alt_text[und][0][value]\\u0022:false,\\u0022field_file_image_title_text[und][0][value]\\u0022:false}},\\u0022link_text\\u0022:null,\\u0022attributes\\u0022:{\\u0022class\\u0022:\\u0022media-element file-full media-wysiwyg-align-left\\u0022,\\u0022data-delta\\u0022:\\u00221\\u0022}}]]\\u003C\\/div\\u003E\\r\\n\\r\\n\\u003Cdiv class=\\u0022c-news--body\\u0022\\u003E\\r\\n\\u003Cp\\u003EWelcome to the New York State Senate\\u0027s 2021 Summer Reading Program!\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EParents and guardians from across New York State are invited to enter their children\\u0027s summer reading activity. By filling in the information below, including three books read by your child this summer, he\\/she will receive a \\u003Cem\\u003ECertificate of Achievement\\u003C\\/em\\u003E from their NYS Senator.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe deadline for submissions is \\u003Cstrong\\u003ESeptember 1, 2021\\u003C\\/strong\\u003E. More resources and facts about summer reading can be found at:\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cul\\u003E\\r\\n\\t\\u003Cli\\u003ENew York\\u0027s Libraries: \\u003Ca href=\\u0022http:\\/\\/www.summerreadingnys.org\\/\\u0022 rel=\\u0022noreferrer noopener\\u0022 target=\\u0022_blank\\u0022\\u003Ehttp:\\/\\/www.summerreadingnys.org\\/\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\t\\u003Cli\\u003EScholastic\\u0027s \\u003Cem\\u003EKids and Families Reading Report\\u003C\\/em\\u003E: \\u003Ca href=\\u0022http:\\/\\/www.scholastic.com\\/readingreport\\/summer-reading.htm\\u0022 rel=\\u0022noreferrer noopener\\u0022 target=\\u0022_blank\\u0022\\u003Ewww.scholastic.com\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C\\/ul\\u003E\\r\\n\\r\\n\\u003Ch2\\u003ESummer Reading Form\\u003C\\/h2\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n",
        "format" : "source_html"
      }
    },
    "weight" : "0",
    "paths" : {
      "submit" : {
        "source" : "eform\\/submit\\/summer-reading",
        "alias" : "nyread",
        "language" : "und"
      },
      "confirm" : {
        "source" : "eform\\/summer-reading\\/confirm",
        "alias" : "nyread-confirmation",
        "language" : "und"
      }
    }
  }');
  return $items;
}
