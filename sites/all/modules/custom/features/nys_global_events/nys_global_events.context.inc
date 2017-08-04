<?php
/**
 * @file
 * nys_global_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nys_global_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_calendars_day';
  $context->description = '';
  $context->tag = 'Calendars';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
        'events/*' => 'events/*',
        'events/day' => 'events/day',
        'calendar-page' => 'calendar-page',
        'calendar-page/*' => 'calendar-page/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-calendar_downloads' => array(
          'module' => 'nys_blocks',
          'delta' => 'calendar_downloads',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'views-a032bdd6c1dfa3fb6227ac24bc48b1b6' => array(
          'module' => 'views',
          'delta' => 'a032bdd6c1dfa3fb6227ac24bc48b1b6',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendars');
  $export['global_calendars_day'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_calendars_month';
  $context->description = '';
  $context->tag = 'Calendars';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/month' => 'events/month',
        'events/month/*' => 'events/month/*',
        'calendar-page/month' => 'calendar-page/month',
        'calendar-page/month/*' => 'calendar-page/month/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-calendar_downloads' => array(
          'module' => 'nys_blocks',
          'delta' => 'calendar_downloads',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendars');
  $export['global_calendars_month'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_calendars_week';
  $context->description = '';
  $context->tag = 'Calendars';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/week' => 'events/week',
        'events/week/*' => 'events/week/*',
        'calendar-page/week' => 'calendar-page/week',
        'calendar-page/week/*' => 'calendar-page/week/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nys_blocks-calendar_downloads' => array(
          'module' => 'nys_blocks',
          'delta' => 'calendar_downloads',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'views-a032bdd6c1dfa3fb6227ac24bc48b1b6' => array(
          'module' => 'views',
          'delta' => 'a032bdd6c1dfa3fb6227ac24bc48b1b6',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendars');
  $export['global_calendars_week'] = $context;

  return $export;
}
