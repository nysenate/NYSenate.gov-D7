<?php
/**
 * @file helper.inc
 */

/**
 * given an age, return a textual output of the age range, in groups of five
 * years
 */
function nys_dashboard_age_to_age_range($age = 0) {

  if (empty($age)) {
    return '';
  }

  $modulo = $age % 5;

  $age_range_start = ($age - $modulo);
  $age_range_end = $age_range_start + 5;

  return "$age_range_start-$age_range_end";
}

function nys_dashboard_gender_render($int) {
  if (!isset($int)) {
    return '';
  }

  if ($int == 0) {
    return 'Female';
  }
  elseif ($int == 1) {
    return 'Male';
  }
}

function nys_dashboard_senator_constituents_get_query_args($input) {
  $getvars = [
    'namesearch',
    'agesearch',
    'gender',
    'fb',
  ];

  $queryArgs = [];
  foreach ($getvars as $var) {
    if ($input[$var] != "" && $input[$var] != 'all') {
      $queryArgs[$var] = $input[$var];
    }
  }

  if (!empty($input['zipsearch']) && $input['zipsearch'] != "Zip Code" && is_numeric($input['zipsearch'])) {
    $queryArgs['zipsearch'] = $input['zipsearch'];
  }
  return $queryArgs;
}
