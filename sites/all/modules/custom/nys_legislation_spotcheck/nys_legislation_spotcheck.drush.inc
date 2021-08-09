<?php

/**
 * @file
 * File nys_legislation_spotcheck.drush.inc
 */

require_once 'nys_legislation_spotcheck.inc';

/**
 * Implements hook_drush_command().
 */
function nys_legislation_spotcheck_drush_command() {
  $items = [];

  $items['spotcheck-dump'] = [
    'description' => dt(
      'Dump a session of legislative data to OpenLegislation, triggering a Spotcheck report to be run'
    ),
    'arguments'   => [
      'arg1' => dt(
        'A required content type that will be dumped ('
        . SpotcheckContentType::getTypesStr() . ')'
      ),
    ],
    'options'     => [
      'year'  => dt(
        'An optional year indicating the year to be dumped (defaults to the current year.)  '
        .
        'For session based data (i.e. bill), any even numbered year inputs will be subtracted by 1, '
        .
        'converting the year to its corresponding session year.  ' .
        'If no data is found for the provided year, no dump will be sent.'
      ),
      'print' => dt(
        'The dump will be written to stdout instead of sent to ' .
        'the configured OpenLegislation instance.'
      ),
      'part'  => dt(
        'If a positive integer is passed in, ' .
        'only the part with that number will be sent.'
      ),
    ],
    'examples'    => [
      'drush spotcheck-dump agenda'               => dt(
        'Sends a dump of agendas for the current year'
      ),
      'drush spotcheck-dump bill'                 => dt(
        'Sends a dump of bills for the current session'
      ),
      'drush spotcheck-dump calendar --year=2015' => dt(
        'Sends a dump of calendars from 2015'
      ),
      'drush spotcheck-dump bill --print'         => dt(
        'Write the current session bill dump to stdout.'
      ),
      'drush spotcheck-dump bill --part=2'        => dt(
        'Send only part 2 of the current session bill dump.'
      ),
    ],
  ];

  return $items;
}

/**
 * Callback function for drush spotcheck-dump.
 *
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters converted to "_" characters
 * (my_command)
 *
 * @param $arg1 string specify content type to dump
 */
function drush_nys_legislation_spotcheck_spotcheck_dump($arg1) {
  $content_type = SpotcheckContentType::getSpotcheckContentType($arg1);
  if (!$content_type) {
    drush_log(
      "Invalid content type $arg1.  Try (" . SpotcheckContentType::getTypesStr()
      . ')', 'failed'
    );
    return;
  }

  $params = [];

  $year = drush_get_option('year', date('Y'));
  if (!ctype_digit($year)) {
    drush_log(
      "'year' parameter must be an integer value.  Got '$year'", 'failed'
    );
    return;
  }
  $params['year'] = intval($year);

  $params['print'] = drush_get_option('print', FALSE) === TRUE;

  $part = drush_get_option('part');
  if ($part !== NULL) {
    if (!is_numeric($part) || $part <= 0) {
      drush_log(
        "Invalid 'part' parameter.  " .
        "Requires positive int value. Got '$part''",
        'failed'
      );
      return;
    }
    $params['part'] = intval($part);
  }

  $params['lawid'] = drush_get_option('lawid');

  nys_legislation_spotcheck_handle_spotcheck_dump($content_type, $params);
  drush_log('success', 'ok');
  nys_utils_set_cron_lastrun('legislation_spotcheck');
}
