<?php

/**
 * @file
 * Administration forms for the Disqus module.
 */

/**
 * Menu callback; Displays the administration settings for Disqus.
 */
function disqus_admin_settings() {
  $form = array();
  $form['disqus_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Shortname'),
    '#description' => t('The website shortname that you registered Disqus with. If you registered http://example.disqus.com, you would enter "example" here.'),
    '#default_value' => variable_get('disqus_domain', ''),
  );
  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 50,
  );
  // Visibility settings.
  $form['visibility'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visibility'),
    '#group' => 'settings',
  );
  $types = node_type_get_types();
  $options = array();
  foreach ($types as $type) {
    $options[$type->type] = $type->name;
  }
  $form['visibility']['disqus_nodetypes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Types'),
    '#description' => t('Apply comments to only the following node types.'),
    '#default_value' => variable_get('disqus_nodetypes', array()),
    '#options' => $options,
  );
  $form['visibility']['disqus_location'] = array(
    '#type' => 'select',
    '#title' => t('Location'),
    '#description' => t('Display the Disqus comments in the given location. When "Block" is selected, the comments will appear in the <a href="@disquscomments">Disqus Comments block</a>.', array('@disquscomments' => url('admin/structure/block'))),
    '#default_value' => variable_get('disqus_location', 'content_area'),
    '#options' => array(
      'content_area' => t('Content Area'),
      'block' => t('Block'),
    ),
  );
  $form['visibility']['disqus_weight'] = array(
    '#type' => 'select',
    '#title' => t('Weight'),
    '#description' => t('When the comments are displayed in the content area, you can change the position at which they will be shown.'),
    '#default_value' => variable_get('disqus_weight', 50),
    '#options' => drupal_map_assoc(array(-100, -75, -50, -25, 0, 25, 50, 75, 100)),
    '#states' => array(
      'visible' => array(
        'select[name="disqus_location"]' => array('value' => 'content_area'),
      ),
    ),
  );
  // Enable by default settings.
  $form['default_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default options'),
    '#group' => 'settings',
  );
  $form['default_options']['disqus_nodetypes_default'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Types'),
    '#description' => t('Select disqus comments by default to only the following node types.'),
    '#default_value' => variable_get('disqus_nodetypes_default', array_keys($options)),
    '#options' => $options,
  );
  // Behavior settings.
  $form['behavior'] = array(
    '#type' => 'fieldset',
    '#title' => t('Behavior'),
    '#group' => 'settings',
  );
  $form['behavior']['disqus_localization'] = array(
    '#type' => 'checkbox',
    '#title' => t('Localization support'),
    '#description' => t("When enabled, overrides the language set by Disqus with the language provided by the site."),
    '#default_value' => variable_get('disqus_localization', FALSE),
  );
  $form['behavior']['disqus_inherit_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inherit User Credentials'),
    '#description' => t("When enabled and a user is logged in, the Disqus 'Post as Guest' login form will be pre-filled with the user's name and email address."),
    '#default_value' => variable_get('disqus_inherit_login', TRUE),
  );
  $form['behavior']['disqus_developer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Testing'),
    '#description' => t('When enabled, uses the <a href="http://docs.disqus.com/help/2/">disqus_developer</a> flag to tell Disqus that you are in a testing environment. Threads will not display on the public community page with this set.'),
    '#default_value' => variable_get('disqus_developer', FALSE),
  );
  // Advanced settings.
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#group' => 'settings',
    '#description' => t('Use these settings to configure the more advanced uses of Disqus. You can find more information about these in the <a href="@applications">Applications</a> section of Disqus. To enable some of these features, you will require a <a href="@addons">Disqus Add-on Package</a>. Your user access token can be found on the application specific page.', array(
      '@applications' => 'http://disqus.com/api/applications/',
      '@addons' => 'http://disqus.com/addons/',
    )),
  );
  $form['advanced']['disqus_useraccesstoken'] = array(
    '#type' => 'textfield',
    '#title' => t('User Access Token'),
    '#default_value' => variable_get('disqus_useraccesstoken', ''),
  );
  $form['advanced']['disqus_publickey'] = array(
    '#type' => 'textfield',
    '#title' => t('Public Key'),
    '#default_value' => variable_get('disqus_publickey', ''),
  );
  $form['advanced']['disqus_secretkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret Key'),
    '#default_value' => variable_get('disqus_secretkey', ''),
  );
  $form['advanced']['api'] = array(
    '#weight' => 4,
    '#type' => 'fieldset',
    '#title' => t('Disqus API Settings'),
    '#description' => t('These setting pertain to the official Disqus PHP API. You will need to install the <a href="@libraries">libraries module</a> and upload the <a href="@disqusapi">api files</a> to /sites/all/libraries/disqusapi to enable api functionality.', array(
      '@libraries' => 'http://drupal.org/project/libraries',
      '@disqusapi' => 'https://github.com/disqus/disqus-php',
    )),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  if(module_exists('libraries') && $library = libraries_detect('disqusapi')) {
    if($library['installed']) {
      $form['advanced']['api']['disqus_api_update'] = array(
        '#type' => 'checkbox',
        '#title' => t('Update Threads'),
        '#description' => t('Update node titles and links via the disqus api when saving. (Requires your user access token.)'),
        '#default_value' => variable_get('disqus_api_update', FALSE),
        '#states' => array(
          'enabled' => array(
            'input[name="disqus_useraccesstoken"]' => array('empty' => FALSE),
          ),
        ),
      );
      $form['advanced']['api']['disqus_api_delete'] = array(
        '#type' => 'select',
        '#title' => t('Close/Remove Threads'),
        '#description' => t('Action to take when deleting a node. (Requires your user access token.)'),
        '#default_value' => variable_get('disqus_api_delete', 'no_action'),
        '#options' => array(
          DISQUS_API_NO_ACTION => t('No Action'),
          DISQUS_API_CLOSE => t('Close Thread'),
          DISQUS_API_REMOVE => t('Remove Thread'),
        ),
        '#states' => array(
          'enabled' => array(
            'input[name="disqus_useraccesstoken"]' => array('empty' => FALSE),
          ),
        ),
      );
    }
  }
  $form['advanced']['sso'] = array(
    '#weight' => 5,
    '#type' => 'fieldset',
    '#title' => t('Single Sign-on'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(
        'input[name="disqus_publickey"]' => array('empty' => FALSE),
        'input[name="disqus_secretkey"]' => array('empty' => FALSE),
      ),
    ),
  );
  $form['advanced']['sso']['disqus_sso'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Single Sign-On'),
    '#description' => t('Provide <a href="@sso">Single Sign-On</a> access to your site.', array(
      '@sso' => 'http://disqus.com/api/sso/',
    )),
    '#default_value' => variable_get('disqus_sso', FALSE),
  );
  $form['advanced']['sso']['disqus_use_site_logo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Site Logo'),
    '#description' => t('Pass the site logo to Disqus for use as SSO login button.'),
    '#default_value' => variable_get('disqus_use_site_logo', TRUE),
    '#states' => array(
      'disabled' => array(
        'input[name="disqus_sso"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['advanced']['sso']['disqus_logo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Custom Logo'),
    '#upload_location' => 'public://images',
    '#default_value' => variable_get('disqus_logo', ''),
    '#states' => array(
      'disabled' => array(
        'input[name="disqus_sso"]' => array('checked' => FALSE),
      ),
      'visible' => array(
        'input[name="disqus_use_site_logo"]' => array('checked' => FALSE),
      ),
    ),
  );

  // Make sure the validation is called to handle the custom sso logo.
  $form['#submit'][] = 'disqus_admin_settings_submit';
  return system_settings_form($form);
}

/**
 * Form callback; Make sure we process the sso logo and set it to a permanent status.
 */
function disqus_admin_settings_submit($form, &$form_state) {
  $old_logo = variable_get('disqus_logo', '');
  $new_logo = (isset($form_state['values']['disqus_logo'])) ? $form_state['values']['disqus_logo'] : '';
  // Ignore if the file hasn't changed.
  if ($new_logo != $old_logo) {
    // Remove the old file and usage if previously set.
    if ($old_logo != '') {
      $file = file_load($old_logo);
      file_usage_delete($file, 'disqus', 'disqus');
      file_delete($file);
    }
    // Update the new file and usage.
    if ($new_logo != '') {
      $file = file_load($new_logo);
      file_usage_add($file, 'disqus', 'disqus', 0);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
    }
  }
}
