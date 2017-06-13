<?php
/**
 * @file
 * nys_committees.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nys_committees_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'committees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Committees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '60';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'semanticviews_default';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_taxonomy_term';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'committees' => 'committees',
  );

  /* Display: Senators Committees Page Block */
  $handler = $view->new_display('block', 'Senators Committees Page Block', 'senators_committees');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_committee_types',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  $handler->display->display_options['row_options']['skip_blank'] = 0;
  $handler->display->display_options['row_options']['semantic_html'] = array(
    'name' => array(
      'element_type' => 'div',
      'class' => '',
    ),
    'tid' => array(
      'element_type' => 'div',
      'class' => '',
    ),
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Committee Type */
  $handler->display->display_options['fields']['field_committee_types']['id'] = 'field_committee_types';
  $handler->display->display_options['fields']['field_committee_types']['table'] = 'field_data_field_committee_types';
  $handler->display->display_options['fields']['field_committee_types']['field'] = 'field_committee_types';
  $handler->display->display_options['fields']['field_committee_types']['label'] = '';
  $handler->display->display_options['fields']['field_committee_types']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_committee_types']['element_label_colon'] = FALSE;
  $export['committees'] = $view;

  return $export;
}
