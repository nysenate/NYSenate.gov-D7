<?php
/**
 * @file
 * Provides preprocess functions for Views view_fields theming.
 */

/**
 * Implements template_preprocess_views_view_fields.
 */
function nysenate_preprocess_views_view_fields(&$variables) {
  if (($variables['view']->name == 'senator_contact_blocks') && (!isset($variables['fields']['office_contacts']))) {
    // This sets up office contacts field collection for template output.
    $senator_nid = $variables['view']->args[0];
    $senator_node = node_load($senator_nid);
    /** @var bool|array $fc_fields */
    $fc_fields = field_get_items('node', $senator_node, 'field_office_contacts');
    $office_contact_ids = array();

    if (is_array($fc_fields)) {
      foreach ($fc_fields as $fc_field) {
        array_push($office_contact_ids, $fc_field['value']);
      }
    }

    $office_contacts = array();
    for ($x = 0; $x < count($office_contact_ids); $x++) {
      $office_contacts[$x]['office_contact_name'] = field_collection_item_load($office_contact_ids[$x])->field_office_contact_name[LANGUAGE_NONE][0]['value'];
      $office_contacts[$x]['office_contact_title'] = field_collection_item_load($office_contact_ids[$x])->field_office_contact_title[LANGUAGE_NONE][0]['value'];
      $office_contacts[$x]['office_contact_phone'] = field_collection_item_load($office_contact_ids[$x])->field_office_contact_phone[LANGUAGE_NONE][0]['value'];
      $office_contacts[$x]['office_contact_email'] = field_collection_item_load($office_contact_ids[$x])->field_office_contact_email[LANGUAGE_NONE][0]['value'];
    }

    $variables['fields']['office_contacts'] = $office_contacts;
  }

  if ($variables['view']->name == 'senator_dashboard_petitions_and_questionnaires' && isset($variables['view']->filter['type']->value['petition'])) {
    $variables['total_percent'] = ($variables['row']->petition_count < 1) ? 1 : 100;
    $variables['petition_anon_percent'] = round((($variables['row']->petition_anon_count < 1) ? 0 : $variables['row']->petition_anon_count) / (($variables['row']->petition_count < 1) ? 100 : $variables['row']->petition_count) * 100, 2);
    $variables['petition_percent'] = 100 - $variables['petition_anon_percent'];
    $variables['percent'] = ($variables['row']->petition_count < 1) ? 1 : (($variables['row']->constituent_count < 1) ? 1 : round(($variables['row']->constituent_count / $variables['row']->petition_count) * 100, 2));
    $variables['constituent_anon_percent'] = round((($variables['row']->constituent_anon_count < 1) ? 0 : $variables['row']->constituent_anon_count) / (($variables['row']->constituent_count < 1) ? 100 : $variables['row']->constituent_count) * 100, 2);
    $variables['constituent_percent'] = 100 - $variables['constituent_anon_percent'];
  }
}
