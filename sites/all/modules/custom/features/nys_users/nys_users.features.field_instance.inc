<?php
/**
 * @file
 * nys_users.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nys_users_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_address'.
  $field_instances['user-user-field_address'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'location_settings' => array(
          'display' => array(
            'hide' => array(
              'additional' => 0,
              'city' => 0,
              'contact_name' => 'contact_name',
              'coords' => 'coords',
              'country' => 'country',
              'country_name' => 'country_name',
              'email' => 'email',
              'fax' => 'fax',
              'locpick' => 'locpick',
              'map_link' => 'map_link',
              'name' => 'name',
              'phone' => 'phone',
              'postal_code' => 0,
              'province' => 0,
              'province_name' => 'province_name',
              'street' => 0,
            ),
          ),
          'form' => array(
            'fields' => array(
              'additional' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -98,
              ),
              'city' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -97,
              ),
              'contact_name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -93,
              ),
              'country' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'us',
                'weight' => -94,
              ),
              'delete_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'email' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -90,
              ),
              'fax' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -89,
              ),
              'is_primary' => array(
                'default' => 0,
              ),
              'latitude' => array(
                'default' => 0,
              ),
              'lid' => array(
                'default' => FALSE,
              ),
              'locpick' => array(
                'collect' => 0,
                'default' => FALSE,
                'nodiff' => TRUE,
                'weight' => -92,
              ),
              'longitude' => array(
                'default' => 0,
              ),
              'name' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -100,
              ),
              'phone' => array(
                'collect' => 0,
                'default' => '',
                'weight' => -91,
              ),
              'postal_code' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -95,
              ),
              'province' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 4,
                'default' => 'New York',
                'weight' => -96,
                'widget' => 'select',
              ),
              're_geocode_location' => array(
                'default' => FALSE,
                'nodiff' => TRUE,
              ),
              'source' => array(
                'default' => 0,
              ),
              'street' => array(
                '#parents' => array(
                  0 => 'field_address',
                  1 => 'und',
                  2 => 0,
                ),
                'collect' => 1,
                'default' => '',
                'weight' => -99,
              ),
            ),
          ),
        ),
        'street' => '',
        'additional' => '',
        'city' => '',
        'province' => 'NY',
        'postal_code' => '',
        'country' => 'us',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'location_cck',
        'settings' => array(),
        'type' => 'location_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_address',
    'label' => 'Address',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'location_cck',
      'settings' => array(),
      'type' => 'location',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'user-user-field_agree_to_terms'.
  $field_instances['user-user-field_agree_to_terms'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_agree_to_terms',
    'label' => 'Please agree to the New York State Senate\'s terms of participation before creating an account. You can read about our <a href="/privacy-policy">Privacy Policy</a> and <a href="/legal">Terms of Participation</a> for further details.',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-field_dateofbirth'.
  $field_instances['user-user-field_dateofbirth'] = array(
    'bundle' => 'user',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_dateofbirth',
    'label' => 'Date of Birth',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-120:+0',
      ),
      'type' => 'date_popup',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'user-user-field_district'.
  $field_instances['user-user-field_district'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_district',
    'label' => 'District',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_first_name'.
  $field_instances['user-user-field_first_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'user-user-field_gender_user'.
  $field_instances['user-user-field_gender_user'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_gender_user',
    'label' => 'Gender',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'user-user-field_last_name'.
  $field_instances['user-user-field_last_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
    'required' => 1,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_ldap_username'.
  $field_instances['user-user-field_ldap_username'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_ldap_username',
    'label' => 'LDAP Username',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'user-user-field_senator_inbox_access'.
  $field_instances['user-user-field_senator_inbox_access'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the senators whose inboxes this user can control.  Note: this user will also need the Legislative Correspondent role.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_senator_inbox_access',
    'label' => 'Senator Inbox Access',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'user-user-field_senator_management'.
  $field_instances['user-user-field_senator_management'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_senator_management',
    'label' => 'Senator Management',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'user-user-field_top_issue'.
  $field_instances['user-user-field_top_issue'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_top_issue',
    'label' => 'Top Issue',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field_user_receive_emails'.
  $field_instances['user-user-field_user_receive_emails'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Would you like to receive email notifications when your Senator sends you a message?',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_user_receive_emails',
    'label' => 'Receive Emails',
    'required' => 0,
    'settings' => array(
      'custom_add_another' => '',
      'custom_remove' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 17,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Date of Birth');
  t('District');
  t('First Name');
  t('Gender');
  t('LDAP Username');
  t('Last Name');
  t('Please agree to the New York State Senate\'s terms of participation before creating an account. You can read about our <a href="/privacy-policy">Privacy Policy</a> and <a href="/legal">Terms of Participation</a> for further details.');
  t('Receive Emails');
  t('Select the senators whose inboxes this user can control.  Note: this user will also need the Legislative Correspondent role.');
  t('Senator Inbox Access');
  t('Senator Management');
  t('Top Issue');
  t('Would you like to receive email notifications when your Senator sends you a message?');

  return $field_instances;
}
