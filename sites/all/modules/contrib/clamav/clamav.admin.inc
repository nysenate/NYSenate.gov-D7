<?php
/**
 * @file
 * Admin-pages for managing the ClamAV module.
 */

/**
 * Admin settings page for ClamAV
 */
function clamav_admin_settings($form, &$form_state) {
  // Load the include helper so that the form can test connectivity to ClamAV
  // and report success/failure.
  module_load_include('inc', 'clamav');

  $form = array();

  $form['clamav_enabled'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable ClamAV anti-virus scans'),
    '#default_value' => variable_get('clamav_enabled', TRUE),
  );

  $form['scan_mechanism_wrapper'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Scan mechanism'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['scan_mechanism_wrapper']['clamav_mode'] = array(
    '#type'    => 'radios',
    '#title'   => t('Select scan method'),
    '#options' => array(
      CLAMAV_USE_EXECUTABLE         => t('Executable'),
      CLAMAV_USE_DAEMON             => t('Daemon mode (over TCP/IP)'),
      CLAMAV_USE_DAEMON_UNIX_SOCKET => t('Daemon mode (over Unix socket)'),
    ),
    '#default_value' => variable_get('clamav_mode', CLAMAV_DEFAULT_MODE),
  );

  // Wrapper for each of the scan mechanisms.
  $form['scan_mechanism_wrapper']['scan_mechanisms'] = array();


  // Executable-mode.
  $form['scan_mechanism_wrapper']['scan_mechanisms']['executable'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Executable mode configuration'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="clamav_mode"]' => array('value' => CLAMAV_USE_EXECUTABLE),
      ),
    ),
  );
  $form['scan_mechanism_wrapper']['scan_mechanisms']['executable']['clamav_executable_path'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Executable path'),
    '#default_value' => variable_get('clamav_executable_path', CLAMAV_DEFAULT_PATH),
    '#maxlength'     => 255,
    '#description'   => t("Full path to the 'clamscan' utility."),
  );
  $form['scan_mechanism_wrapper']['scan_mechanisms']['executable']['clamav_executable_parameters'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Executable parameters'),
    '#default_value' => variable_get('clamav_executable_parameters', CLAMAV_DEFAULT_PARAMS),
    '#maxlength'     => 255,
    '#description'   => t("Extra options for the 'clamscan' utility (e.g. --no-summary). See man clamscan."),
  );


  // Daemon-mode (over TCP/IP).
  $form['scan_mechanism_wrapper']['scan_mechanisms']['daemon'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Daemon mode configuration (over TCP/IP)'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="clamav_mode"]' => array('value' => CLAMAV_USE_DAEMON),
      ),
    ),
  );
  $form['scan_mechanism_wrapper']['scan_mechanisms']['daemon']['clamav_daemon_host'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Hostname'),
    '#default_value' => variable_get('clamav_daemon_host', CLAMAV_DEFAULT_HOST),
    '#maxlength'     => 255,
    '#description'   => t('The hostname for the Clam-AV daemon.  Defaults to localhost.'),
  );
  $form['scan_mechanism_wrapper']['scan_mechanisms']['daemon']['clamav_daemon_port'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Port'),
    '#default_value' => variable_get('clamav_daemon_port', CLAMAV_DEFAULT_PORT),
    '#size'          => 6,
    '#maxlength'     => 8,
    '#description'   => t('The port for the Clam-AV daemon.  Defaults to port 3310.  Must be between 0 and 65535.'),
  );


  // Daemon-mode (over unix socket).
  $form['scan_mechanism_wrapper']['scan_mechanisms']['daemon_unix_socket'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Daemon mode configuration (over Unix socket)'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="clamav_mode"]' => array('value' => CLAMAV_USE_DAEMON_UNIX_SOCKET),
      ),
    ),
  );
  $form['scan_mechanism_wrapper']['scan_mechanisms']['daemon_unix_socket']['clamav_daemon_unix_socket'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Unix socket path'),
    '#default_value' => variable_get('clamav_daemon_unix_socket', CLAMAV_DEFAULT_UNIX_SOCKET),
    '#maxlength'     => 255,
    '#description'   => t('The path to the ClamAV unix socket. Defaults to /var/clamav/clamd.'),
  );


  // Outage action: behaviour when ClamAV is unavailable.
  $form['outage_actions_wrapper'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Outage behaviour'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
   );
  $form['outage_actions_wrapper']['clamav_unchecked_files'] = array(
    '#type'  => 'radios',
    '#title' => t('Action when ClamAV is not available'),
    '#options' => array(
      CLAMAV_BLOCK_UNCHECKED => t('Block unchecked files'),
      CLAMAV_ALLOW_UNCHECKED => t('Allow unchecked files'),
    ),
    '#default_value' => variable_get('clamav_unchecked_files', CLAMAV_DEFAULT_UNCHECKED),
    '#description'   => t('Scans may fail - for example: if ClamAV is not running, or the path to the executable is invalid.  Choose whether files should be blocked or allowed when a scan cannot be completed.'),
  );

  // Stream-wrappers to scan.
  $form['schemes'] = array(
    '#type'        => 'fieldset',
    '#title'       => 'Scannable schemes / stream wrappers',
    '#collapsible' => TRUE,
    '#collapsed  ' => TRUE,
    '#description' => t('By default only !local schemes are scannable.',
      array('!local' => l('STREAM_WRAPPERS_LOCAL',
        'https://api.drupal.org/api/drupal/includes!stream_wrappers.inc/7')
      )
    ),
  );

  $local_schemes = clamav_scheme_options('local');
  $remote_schemes = clamav_scheme_options('remote');

  if (count($local_schemes)) {
    $form['schemes']['clamav_local_schemes'] = array(
      '#type'          => 'checkboxes',
      '#title'         => t('Local schemes'),
      '#options'       => $local_schemes,
      '#default_value' => clamav_scheme_options_defaults('local'),
    );
  }
  if (count($remote_schemes)) {
    $form['schemes']['clamav_remote_schemes'] = array(
      '#type'          => 'checkboxes',
      '#title'         => t('Remote schemes'),
      '#options'       => $remote_schemes,
      '#default_value' => clamav_scheme_options_defaults('remote'),
    );
  }


  // Verbosity of error-reporting.
  $form['verbosity_wrapper'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Verbosity'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['verbosity_wrapper']['clamav_verbose'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Verbose'),
    '#default_value' => variable_get('clamav_verbose', CLAMAV_VERBOSE_DEFAULT),
    '#description'   => t('Log all scanned files, including files which pass the virus-check.'),
  );


  $form['#submit'][] = "clamav_settings_submit";
  return system_settings_form($form);
}

/**
 * Return a list of all remote (non-local) schemes.
 *
 * @return
 *   Array of scheme names.
 */
function clamav_get_remote_schemes() {
  $all_schemes = array_keys(file_get_stream_wrappers());
  $local_schemes = array_keys(file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL));
  $remote_schemes = array_diff($all_schemes, $local_schemes);
  return $remote_schemes;
}

/**
 * Provide an array of checkbox options for all stream wrappers.
 *
 * @param string $type
 *   Type of schemes; either 'local' or 'remote'.
 *
 * @return
 *   Associative array of options to display keyed by scheme names.
 */
function clamav_scheme_options($type) {
  switch ($type) {
    case 'local':
      $schemes = array_keys(file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL));
      break;

    case 'remote':
      $schemes = clamav_get_remote_schemes();
      break;

    default:
      $schemes = array();
  }
  $options = array();
  foreach ($schemes as $scheme) {
    $options[$scheme] = $scheme . '://';
  }
  return $options;
}

/**
 * Return defaults for scheme checkboxes.
 *
 * @param string $type
 *   Type of schemes; either 'local' or 'remote'.
 *
 * @return
 *   Array of schemes which should be selected by default.
 */
function clamav_scheme_options_defaults($type) {
  switch ($type) {
    case 'local':
      $schemes = array_keys(file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL));
      break;

    case 'remote':
      $schemes = clamav_get_remote_schemes();
      break;

    default:
      $schemes = array();
  }
  $defaults = array();
  foreach ($schemes as $scheme) {
    if (clamav_scheme_is_scannable($scheme)) {
      $defaults[] = $scheme;
    }
  }
  return $defaults;
}

/**
 * Form submission handler for the clamav_admin_settings form.
 */
function clamav_settings_submit($form, &$form_state) {
  // Process per-scheme settings.
  $overridden_schemes = array();
  if (isset($form['schemes']['clamav_local_schemes'])) {
    // Any options which were un-checked are overridden.
    foreach ($form_state['values']['clamav_local_schemes'] as $scheme => $val) {
      if ($val === 0) {
        $overridden_schemes[$scheme] = $scheme;
      }
    }
    unset($form_state['values']['clamav_local_schemes']);
  }
  if (isset($form['schemes']['clamav_remote_schemes'])) {
    // Any options which were checked are overridden.
    foreach ($form_state['values']['clamav_remote_schemes'] as $scheme => $val) {
      if ($val !== 0) {
        $overridden_schemes[$scheme] = $scheme;
      }
    }
    unset($form_state['values']['clamav_remote_schemes']);
  }
  variable_set('clamav_overridden_schemes', $overridden_schemes);
}
