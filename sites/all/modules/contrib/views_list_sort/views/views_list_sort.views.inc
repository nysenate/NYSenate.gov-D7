<?php

/**
 * Implements hook_views_data_alter() from Views.
 */
function views_list_sort_views_data_alter(&$data) {
  foreach (field_info_fields() as $field) {
    // Skip fields not stored in database.
    if ($field['storage']['type'] !== 'field_sql_storage') {
      continue;
    }

    // We're only concerned with "List (text)" fields.
    if ($field['type'] !== 'list_text') {
      continue;
    }

    // Override sort handler.
    $data["field_data_{$field['field_name']}"]["{$field['field_name']}_value"]['sort']['handler'] = 'views_list_sort_handler_sort_allowed_values';
  }
}
