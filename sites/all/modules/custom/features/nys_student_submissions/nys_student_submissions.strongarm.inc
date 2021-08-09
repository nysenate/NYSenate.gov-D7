<?php

/**
 * @file
 * nys_student_submissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nys_student_submissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ip_geoloc_marker_dimensions';
  $strongarm->value = '25 x 30';
  $export['ip_geoloc_marker_dimensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ip_geoloc_marker_directory';
  $strongarm->value = 'sites/all/themes/nysenate/images/p_budget';
  $export['ip_geoloc_marker_directory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ip_geoloc_participatory_budgeting_map_color_mappings';
  $strongarm->value = array(
    'map' => array(
      'field_pbudg_category' => array(
        0 => array(
          'color' => 'facilities-small',
          'differentiator_value' => array(
            'tid' => '59858',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        1 => array(
          'color' => 'tree-small',
          'differentiator_value' => array(
            'tid' => '59859',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        2 => array(
          'color' => 'housing',
          'differentiator_value' => array(
            'tid' => '59860',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        3 => array(
          'color' => 'playground-small',
          'differentiator_value' => array(
            'tid' => '59861',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        4 => array(
          'color' => 'health-small',
          'differentiator_value' => array(
            'tid' => '59862',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        5 => array(
          'color' => 'safety-small',
          'differentiator_value' => array(
            'tid' => '59863',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        6 => array(
          'color' => 'education-small',
          'differentiator_value' => array(
            'tid' => '59864',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        7 => array(
          'color' => 'street-sidewalk-small',
          'differentiator_value' => array(
            'tid' => '59865',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        8 => array(
          'color' => 'transit-small',
          'differentiator_value' => array(
            'tid' => '59866',
          ),
          'special char' => '',
          'special char class' => '',
        ),
      ),
    ),
    'page' => array(
      'field_pbudg_category' => array(
        0 => array(
          'color' => 'facilities-small',
          'differentiator_value' => array(
            'tid' => '59980',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        1 => array(
          'color' => 'tree-small',
          'differentiator_value' => array(
            'tid' => '59975',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        2 => array(
          'color' => 'housing',
          'differentiator_value' => array(
            'tid' => '59974',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        3 => array(
          'color' => 'playground-small',
          'differentiator_value' => array(
            'tid' => '59976',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        4 => array(
          'color' => 'health-small',
          'differentiator_value' => array(
            'tid' => '59977',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        5 => array(
          'color' => 'safety-small',
          'differentiator_value' => array(
            'tid' => '59982',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        6 => array(
          'color' => 'education-small',
          'differentiator_value' => array(
            'tid' => '59981',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        7 => array(
          'color' => 'street-sidewalk-small',
          'differentiator_value' => array(
            'tid' => '59979',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        8 => array(
          'color' => 'transit-small',
          'differentiator_value' => array(
            'tid' => '59978',
          ),
          'special char' => '',
          'special char class' => '',
        ),
      ),
    ),
    'pbudget_map' => array(
      'field_pbudg_category' => array(
        0 => array(
          'color' => 'facilities-small',
          'differentiator_value' => array(
            'tid' => '61141',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        1 => array(
          'color' => 'tree-small',
          'differentiator_value' => array(
            'tid' => '61142',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        2 => array(
          'color' => 'housing',
          'differentiator_value' => array(
            'tid' => '61143',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        3 => array(
          'color' => 'playground-small',
          'differentiator_value' => array(
            'tid' => '61144',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        4 => array(
          'color' => 'health-small',
          'differentiator_value' => array(
            'tid' => '61145',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        5 => array(
          'color' => 'safety-small',
          'differentiator_value' => array(
            'tid' => '61146',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        6 => array(
          'color' => 'education-small',
          'differentiator_value' => array(
            'tid' => '61147',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        7 => array(
          'color' => 'street-sidewalk-small',
          'differentiator_value' => array(
            'tid' => '61148',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        8 => array(
          'color' => 'transit-small',
          'differentiator_value' => array(
            'tid' => '61149',
          ),
          'special char' => '',
          'special char class' => '',
        ),
      ),
    ),
  );
  $export['ip_geoloc_participatory_budgeting_map_color_mappings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ip_geoloc_participatory_budgeting_map__color_mappings';
  $strongarm->value = array(
    'page' => array(
      'field_pbudg_category' => array(
        0 => array(
          'color' => 'tree-small',
          'differentiator_value' => array(
            'tid' => '59975',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        1 => array(
          'color' => 'playground-small',
          'differentiator_value' => array(
            'tid' => '59976',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        2 => array(
          'color' => 'facilities-small',
          'differentiator_value' => array(
            'tid' => '59980',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        3 => array(
          'color' => 'housing',
          'differentiator_value' => array(
            'tid' => '59974',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        4 => array(
          'color' => 'health-small',
          'differentiator_value' => array(
            'tid' => '59977',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        5 => array(
          'color' => 'safety-small',
          'differentiator_value' => array(
            'tid' => '59982',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        6 => array(
          'color' => 'education-small',
          'differentiator_value' => array(
            'tid' => '59981',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        7 => array(
          'color' => 'street-sidewalk-small',
          'differentiator_value' => array(
            'tid' => '59979',
          ),
          'special char' => '',
          'special char class' => '',
        ),
        8 => array(
          'color' => 'transit-small',
          'differentiator_value' => array(
            'tid' => '59978',
          ),
          'special char' => '',
          'special char class' => '',
        ),
      ),
    ),
  );
  $export['ip_geoloc_participatory_budgeting_map__color_mappings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_locpick_macro';
  $strongarm->value = '[gmap center=40.658417,-73.959442 |zoom=13 |width=100%|height=400px]';
  $export['location_locpick_macro'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_usegmap';
  $strongarm->value = 1;
  $export['location_usegmap'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_participatory_budgeting_categories_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_participatory_budgeting_categories_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_participatory_budgeting_categories';
  $strongarm->value = array(
    'priority' => '0.5',
    'status' => '0',
  );
  $export['xmlsitemap_settings_taxonomy_term_participatory_budgeting_categories'] = $strongarm;

  return $export;
}
