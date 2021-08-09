<?php

/**
 * @file
 * Drush integration functions for the nys_picture module.
 */

/**
 * Implements hook_drush_command().
 */
function nys_picture_drush_command() {
  $items = array();

  $items["enhanced-styles-update"] = array(
    "description" => "Updates Enhanced Images added since the last run. The enhanced-styles-update command iterates thru all image styles with `_webp` in their names. Image files in an image style directory added or modified since the last run are converted to webp.",
    'arguments'   => array(
      'arg1'    => dt('An optional style name to limit the update to.'),
    ),
    "options"     => array(
      "all-dates" => "Update from the beginning of time.",
      "update-from" => "Timestamp indicating beginning of desired block of updates. (defaults to time of last run)",
      "report-only" => "Does not update. Dumps commands only.",
      "show-args" => "Displays the arguments sent to imagemagick convert.",
    ),
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-update',
      'Argument example 1' => 'drush enhanced-styles-update your_enhanced_style_name',
      'Argument example 2' => 'drush enhanced-styles-update --all-dates',
      'Argument example 3' => 'drush enhanced-styles-update --update-from=2008-09-15T15:53:00',
      'Argument example 4' => 'drush enhanced-styles-update report-only',
      'Argument example 5' => 'drush enhanced-styles-update report-only --show-args',
    ),
    'aliases' => array('esu'),
  );

  $items["enhanced-styles-stop"] = array(
    "description" => "Stops an update, report or populate Run.",
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-stop',
    ),
    'aliases' => array('ess'),
  );

  $items["enhanced-styles-monitor"] = array(
    "description" => "Shows status of last or current run.",
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-monitor',
    ),
    'aliases' => array('esm'),
  );

  $items["identify"] = array(
    "description" => "Use Identify to view an image files properties using the Imagemagick identify command.",
    'arguments'   => array(
      'arg1'    => dt('Filename or path to image file.'),
    ),
    'examples' => array(
      'Argument example 1' => 'drush identify sample.png',
      'Argument example 2' => 'drush identify styles/thumbnail/public/sample.png',
    ),
    'aliases' => array('iid'),
  );

  $items["iconvert"] = array(
    "description" => "Use Imagemagick's convert function. All imagemagick file names and options must be passed to this command in a single set of quotes.",
    'arguments'   => array(
      'arg1'    => dt('The complete set of imagemagick convert options. Encased in quotes.'),
    ),
    'examples' => array(
      'Argument example' => 'drush iconvert \'image.png -youroptions image2.png\'',
    ),
    'aliases' => array('icv', 'ic', 'cv'),
  );

  $items["enhanced-styles-summary-report"] = array(
    "description" => "Create an Enhanced Style Usage Summary Report. Shows the file types and quantity of files for each style. Use the --all option to report on All image styles.",

    "options"     => array(
      "all" => "All Image Styles, Enhanced and Un-Enhanced.",
    ),
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-summary-report',
      'Argument example' => 'drush enhanced-styles-summary-report --all',
    ),
    'aliases' => array('essr'),
  );

  $items["enhanced-style-report"] = array(
    "description" => "Creates a report for all enhanced image styles or a single image style. Pass in a valid style or any string to choose a style. An Imagemagick Identify data is displayed for each file, including mime type, size and bit depth etc. \r\nexample_file.jpg JPEG 200x125 200x125+0+0 8-bit sRGB 29.8KB 0.000u 0:00.000",
    'arguments'   => array(
      'arg1'    => dt('A valid style or an invalid style to choose a style'),
    ),
    'examples' => array(
      'Standard example' => 'drush enhanced-style-report',
      'Argument example 1' => 'drush enhanced-style-report 400x240_smartphone_webp',
      'Argument example 2' => 'drush enhanced-style-report --all 400x240',
      'Argument example 3' => 'drush enhanced-style-report choose',
    ),
    'aliases' => array('esr'),
  );

  $items["enhanced-file-report"] = array(
    "description" => "Create a report on an Image File. Imagemagick Identify data is displayed for the public file in each style, including mime type, size etc. \r\nexample_file.jpg JPEG 200x125 200x125+0+0 8-bit sRGB 29.8KB 0.000u 0:00.000\r\n  thumbnail/public/example_file.jpg JPEG 64x64 64x64+0+0 8-bit sRGB 3.5KB 0.000u 0:00.009",
    'arguments'   => array(
      'arg1'    => dt('A public image file name or path to a local image file. The image file for each style is derived from this image.'),
    ),
    'examples' => array(
      'Standard example' => 'drush enhanced-file-report',
      'Argument example 1' => 'drush enhanced-file-report your_public_image_file.png',
      'Argument example 2' => 'drush enhanced-file-report new-senate-seal-760_6_1.png',
    ),
    'aliases' => array('efr'),
  );

  $items["enhanced-styles-survey-content"] = array(
    "description" => "Which Content Types have images or pictures. Displays a report showing the display type and format for each image field in every content type. This identifies content types with image field displays that are formatted `image` or `picture`.",

    'examples' => array(
      'Standard example' => 'enhanced-styles-survey-content',
    ),
    'aliases' => array('essc'),
  );

  $items["enhanced-styles-survey-views"] = array(
    "description" => "Which Views have images or pictures. Displays a report showing the display type and format for each image field in every view. This identifies views with image field displays that are formatted `image` or `picture`.",
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-survey-views',
    ),
    'aliases' => array('essv'),
  );

  $items["enhanced-styles-files"] = array(
    "description" => "Lists Managed image files. Pass in --all for a complete list",
    "options"     => array(
      "all" => "Displays all managed image files.",
      "audit" => "Reports on managed image files.",
    ),
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-files',
      'Argument example 1' => 'drush enhanced-styles-files --all',
      'Argument example 2' => 'drush enhanced-styles-files --audit',
    ),
    'aliases' => array('esf'),
  );

  $items["enhanced-styles-delete"] = array(
    "description" => "Delete one or more files. Pass in full or partial path starting at the drupal files directory. Pass in --all with a base image file name to delete all derived versions with the same name.",
    'arguments'   => array(
      'arg1'    => dt('Target full or partial path.'),
    ),
    "options"     => array(
      "all" => "All Image Styles, Enhanced and Un-Enhanced.",
    ),
    'examples' => array(
      'Argument example' => 'drush enhanced-styles-delete path/to/deleted_file.png',
    ),
    'aliases' => array('esd'),
  );

  $items["enhanced-styles-copy"] = array(
    "description" => "Copies a file. For the source file pass in full or partial path starting at the drupal files directory. For the destination file pass in a path starting at the drupal files directory.",
    'arguments'   => array(
      'arg1'    => dt('Source full or partial path.'),
      'arg2'    => dt('Destination full or partial path.'),
    ),
    'examples' => array(
      'Standard example' => 'drush enhanced-styles-copy path/to/source/source.png path/to/destination/dest.png',
    ),
    'aliases' => array('esc', 'escp'),
  );

  $items["enhanced-styles-rename"] = array(
    "description" => "Renames a file. For the source file pass in full or partial path starting at the drupal files directory. For the destination file pass in a path starting at the drupal files directory.
",
    'arguments'   => array(
      'arg1'    => dt('Old Name or Path.'),
      'arg2'    => dt('New Name or Path.'),
    ),
    'examples' => array(
      'Argument example' => 'drush enhanced-styles-rename path/old_file_name.png path/new_file_name.png',
    ),
    'aliases' => array('esmv'),
  );

  $items["enhanced-styles-touch"] = array(
    "description" => "Touches a file. For the source file pass in full or partial path starting at the drupal files directory. Pass in --force or --new to touch a file that does not exist already.",
    'arguments'   => array(
      'arg1'    => dt('Name of file or path to file to touch.'),
    ),
    "options"     => array(
      "new" => "Create file if no file exists.",
      "force" => "Create file if no file exists.",
    ),
    'examples' => array(
      'Argument example' => 'drush enhanced-styles-touch file_to_touch.png',
    ),
    'aliases' => array('est'),
  );

  $items["enhanced-styles-time"] = array(
    "description" => "Displays the modification time for a file.",
    'arguments'   => array(
      'arg1'    => dt('Name of file or path to file to display time for.'),
    ),
    'examples' => array(
      'Example' => 'drush enhanced-styles-time',
    ),
    'aliases' => array('estm'),
  );

  $items["enhanced-styles-view"] = array(
    "description" => "Views an image file url. Pass in the name of a base image as an argument. Pass in --all to open all the derived images with the same name in your browser.",
    'arguments'   => array(
      'arg1'    => dt('File name or path to view'),
    ),
    "options"     => array(
      "all" => "All Image Styles, Enhanced and Un-Enhanced.",
    ),
    'examples' => array(
      'Argument example' => 'drush image_to_view.png',
    ),
    'aliases' => array('esv'),
  );

  return $items;
}

/**
 * Drush enhanced-styles-update ('esu').
 */
function drush_nys_picture_enhanced_styles_update($arg1 = '') {
  // See if the retina_images module is installed.
  if (module_exists('retina_images')) {
    print "Disable the retina_images module to use pictures.\r\n";
    print "Retinification is achieved by media queries in the <picture> <source> elements.\r\n";
    return;
  }

  // See if previous or currently running.
  if (nys_picture_update_run_completed() == FALSE && nys_picture_recent_update_activity() == TRUE) {
    $last_activity = date("F j, Y, g:i:s a", nys_picture_variable_get('nys_picture_current_timestamp', 0));
    $last_file = nys_picture_variable_get('nys_picture_current_image_file', '');
    print "\r\n\r\nThere appears to be an update run in progress \r\n";
    print "Last Activity:";
    print "At: $last_activity \r\n";
    print "File $last_file.\r\n\r\n";
    print "You can monitor the activity of that run with the\r\n`enhanced-styles-monitor` (esm) drush command.\r\n\r\n";
    print "You can stop that run with the \r\n`enhanced-styles-stop` (ess) drush command. \r\n\r\n";
    return;
  }

  print "+" . str_pad('-', 75, '-', STR_PAD_BOTH) . "+\r\n";
  print "|" . str_pad('ENHANCED IMAGE UPDATES STARTED', 75, ' ', STR_PAD_BOTH) . "|\r\n";
  print '| ' . str_pad(date("F j, Y, g:i:s a", time()), 74, ' ', STR_PAD_BOTH) . "|\r\n";
  print "+" . str_pad('-', 75, '-', STR_PAD_BOTH) . "+\r\n";

  // Start a run.
  variable_set('nys_picture_run_start_time', time());

  $enhanced_image_styles = nys_picture_enhanced_image_styles();

  // See if a style was supplied.
  if (!empty($arg1)) {
    // A style was specified.
    if (array_key_exists($arg1, $enhanced_image_styles)) {
      nys_picture_update_enhanced_style($arg1, $enhanced_image_styles[$arg1]);
    }
    else {

      foreach ($enhanced_image_styles as $style_name => $style_data) {
        $options[$style_name] = $style_data['name'];
      }

      print "A valid style was not specified.\r\n\r\n";

      $choice = drush_choice($options, dt('Which style?'));

      if ($choice) {
        nys_picture_update_enhanced_style($choice, $enhanced_image_styles[$choice]);
      }

    }
  }
  else {
    // No style was specified so iterate.
    foreach ($enhanced_image_styles as $style_name => $style_data) {
      if (!nys_picture_variable_exists('nys_picture_stop_requested')) {
        nys_picture_update_enhanced_style($style_name, $style_data);
      }
      else {
        print "Stop Requested -- ??Styles\r\n";
        break;
      }
    }
  }

  // Don't mark the run completed unless it completed naturally.
  if (!nys_picture_variable_exists('nys_picture_stop_requested')) {
    variable_set('nys_picture_last_run_start_time', variable_get('nys_picture_run_start_time', time()));
  }
  else {
    // If an artificial stop was requested clear the flag for next time.
    variable_del('nys_picture_stop_requested');
  }

  print "+" . str_pad('-', 75, '-', STR_PAD_BOTH) . "+\r\n";
  print "|" . str_pad('ENHANCED IMAGE UPDATES ENDED', 75, ' ', STR_PAD_BOTH) . "|\r\n";
  print '| ' . str_pad(date("F j, Y, g:i:s a", time()), 74, ' ', STR_PAD_BOTH) . "|\r\n";
  print "+" . str_pad('-', 75, '-', STR_PAD_BOTH) . "+\r\n";

  nys_utils_set_cron_lastrun('enhanced_styles_update');
}

/**
 * Drush enhanced-styles-stop ('ess')
 */
function drush_nys_picture_enhanced_styles_stop($arg1 = '') {
  if (nys_picture_update_run_completed() == FALSE && nys_picture_recent_update_activity() == TRUE) {
    variable_set('nys_picture_stop_requested', TRUE);
    drush_log('Picture Run Stop Requested');
    drush_print('Picture Run Stop Requested');
  }
  else {
    print "\r\n\r\nThere is no running update job at this time.\r\n\r\n";
    print "Use the drush `enhanced-styles-monitor` (esm) command for details on the last run.\r\n\r\n\r\n";
  }
}

/**
 * Drush enhanced-styles-monitor ('esm').
 *
 * Status of last or current live run.
 */
function drush_nys_picture_enhanced_styles_monitor($arg1 = '') {

  // If a run is not in progress.
  if (nys_picture_update_run_completed()) {
    nys_picture_enhanced_styles_monitor('report');
    return 0;
  }

  print "Type Control C to quit. \r\n";
  sleep(2);

  // Erases from current cursor to the top of screen.
  echo "\033[1J";
  // Moves the cursor to the top of screen.
  echo "\033[H";

  do {
    // Render the status.
    print nys_picture_enhanced_styles_monitor('monitor');

    // Every 5 Seconds.
    sleep(5);

    // Erases from current cursor to the top of screen.
    echo "\033[1J";
    // Moves the cursor to the top of screen.
    echo "\033[H";

    if (nys_picture_update_run_completed()) {
      nys_picture_enhanced_styles_monitor('report');
      return TRUE;
    }

  } while (TRUE);

}

/**
 * Drush identify ('iid')
 */
function drush_nys_picture_identify($arg1 = '') {
  // If the supplied path is valid identify the item.
  $realpath = nys_picture_get_realpath($arg1);
  if ($realpath !== FALSE) {
    print "\r\n\r\n";
    print nys_picture_identify($realpath);
    print "\r\n\r\n";
  }

}

/**
 * Drush iconvert ('icv', 'ic', 'cv')
 */
function drush_nys_picture_iconvert($arg1 = '') {
  if (empty($arg1)) {
    print "\r\n\r\nSupply all the imagemagick arguments as a single argument enclosed in quote marks.\r\n";
    print "You must supply imagemagick's file arguments with complete paths.\r\n\r\n";
    $base_path = drupal_realpath('public://');
    print "Example: drush iconvert \'$base_path/your_input_file.jpg $base_path/your_output_file.png\'\r\n\r\n";
    return;
  }

  if (defined('PANTHEON_ENVIRONMENT')) {
    $convert_path = variable_get('imagemagick_convert', '/usr/bin/convert');
  }
  else {
    $convert_path = variable_get('imagemagick_convert', '/usr/local/bin/convert');
  }

  $status = '';
  $error = '';
  _imagemagick_convert_exec(array(escapeshellarg($arg1)), $status, $error, $convert_path);

  if (empty($error)) {
    return $status;
  }

}

/**
 * Drush enhanced-styles-summary-report ('essr')
 */
function drush_nys_picture_enhanced_styles_summary_report() {
  print "+-----------------------------------------------------------------+\r\n";
  print "|                     IMAGE STYLES SUMMARY REPORT                 |\r\n";
  print "+-----------------------------------------------------------------+\r\n";

  // Factoid the number of managed image files.
  $managed_image_files_count = db_query("SELECT COUNT(*) FROM `file_managed` WHERE type = 'image' AND uri = CONCAT('public://', `filename`)")->fetchField();

  print "| " . str_pad("Number of Original Managed Image Files", 50) . " | " . str_pad($managed_image_files_count, 10) . " |\r\n";

  print "+-----------------------------------------------------------------+\r\n";
  print "| DERIVED IMAGE STYLES                                            |\r\n";
  print "+-----------------------------------------------------------------+\r\n";

  if (drush_get_option('all', FALSE)) {
    $styles_array = image_styles();
  }
  else {
    $styles_array = nys_picture_enhanced_image_styles();
  }

  foreach ($styles_array as $style_name => $style_data) {
    print nys_picture_enhanced_styles_summary_report($style_name) . "\r\n";
    print "+-----------------------------------------------------------------+\r\n";

  }

  print "\r\n\r\n\r\n";

}

/**
 * Drush enhanced-style-report ('esr')
 */
function drush_nys_picture_enhanced_style_report($arg1 = '') {
  print "+====================================================================================================================================+\r\n";
  print "|                                                         IMAGE STYLE REPORT                                                         |\r\n";
  print "+====================================================================================================================================+\r\n";

  $enhanced_image_styles = nys_picture_enhanced_image_styles();

  // See if a style was supplied.
  if (!empty($arg1)) {
    // A style was specified.
    if (array_key_exists($arg1, $enhanced_image_styles)) {
      nys_picture_enhanced_style_report($arg1);
    }
    else {

      foreach ($enhanced_image_styles as $style_name => $style_data) {
        $options[$style_name] = $style_data['name'];
      }

      print "A valid style was not specified.\r\n\r\n";

      $choice = drush_choice($options, dt('Which style?'));

      if ($choice) {
        nys_picture_enhanced_style_report($choice);
      }

    }
  }
  else {
    // No style was specified so iterate.
    foreach ($enhanced_image_styles as $style_name => $style_data) {
      nys_picture_enhanced_style_report($style_name);
    }
  }

  print "+====================================================================================================================================+\r\n";

}

/**
 * Drush enhanced-file-report ('efr')
 */
function drush_nys_picture_enhanced_file_report($arg1 = '') {
  print "+------------------------------------------------------------------------------------------------------------------------------------+\r\n";
  print "|                       IMAGE FILE REPORT                                                                                            |\r\n";
  print "+------------------------------------------------------------------------------------------------------------------------------------+\r\n";

  if (!empty($arg1)) {
    $path = 'public://';
    $real_path = drupal_realpath($path);
    $full_path = $real_path . '/' . $arg1;
    $real_path_length = strlen($real_path);

    if (file_exists($full_path)) {
      $files_array = rglob($full_path);

      if (count($files_array) > 0) {
        foreach ($files_array as $file_full_path) {

          $image_info_raw = nys_picture_identify($file_full_path);
          $image_info = substr($image_info_raw, $real_path_length + 1);
          if (strncasecmp($image_info, 'styles/', strlen('styles/')) == 0) {
            print "  ";
            print substr($image_info, strlen('styles/'));
          }
          else {
            print $image_info;
          }

        }

      }
    }
  }
  else {
    print "No valid image file name was supplied.\r\n";
    print "Enter a valid file name.\r\n";
  }

  print "+------------------------------------------------------------------------------------------------------------------------------------+\r\n";
}

/**
 * Drush enhanced-styles-survey-content ('essc')
 */
function drush_nys_picture_enhanced_styles_survey_content() {
  $display_settings_image_style = '';
  $fallback_image_style = '';

  // Print header.
  print "+" . str_pad("-", 251, "-") . '+' . "\r\n";
  print "|" . str_pad("CONTENT TYPE DISPLAYS - IMAGE AND PICTURE FIELDS", 251, " ", STR_PAD_RIGHT) . '|' . "\r\n";
  print "+" . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . "\r\n";
  print "| ";
  print str_pad('Bundle', 33) . ' | ';
  print str_pad('Display Mode', 33) . ' | ';
  print str_pad('Entity Type', 33) . ' | ';
  print str_pad('Field Name', 33) . ' | ';
  print str_pad('Display Type', 33) . ' | ';
  print str_pad('Image Style - Picture Mapping', 33) . " |";
  print str_pad('Picture Fallback Style', 34) . " |\r\n";

  print "+" . str_pad("-", 35, "-")  . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . "\r\n";

  $result = db_query('SELECT * FROM field_config_instance ORDER BY bundle');

  foreach ($result as $record) {
    $bundle = $record->bundle;
    $entity_type = $record->entity_type;
    $field_name = $record->field_name;
    $data = unserialize($record->data);

    foreach ($data['display'] as $display_index => $display) {
      $display_type = ($display['type'] ?? '');
      if ($display_type == 'image') {
        if (empty($display['settings']) || empty($display['settings']['image_style'])) {
          $display_settings_image_style = 'STYLE NOT SET';
        }
        else {
          $display_settings_image_style = $display['settings']['image_style'];
        }
      }
      elseif ($display_type == 'picture') {
        if (empty($display['settings']) || empty($display['settings']['picture_mapping'])) {
          $display_settings_image_style = 'PICTURE MAPPING NOT SET';
        }
        else {
          $display_settings_image_style = $display['settings']['picture_mapping'];
          $fallback_image_style = $display['settings']['fallback_image_style'];
        }
      }

      print "| ";
      print str_pad($bundle, 33) . ' | ';
      print str_pad($display_index, 33) . ' | ';
      print str_pad($entity_type, 33) . ' | ';
      print str_pad($field_name, 33) . ' | ';
      print str_pad($display_type, 33) . ' | ';
      print str_pad($display_settings_image_style, 33) . ' | ';
      print str_pad($fallback_image_style, 33) . ' | ';
      print "\r\n";
      print "+" . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . "\r\n";

    }

  }

}

/**
 * Drush enhanced-styles-survey-views ('essv')
 */
function drush_nys_picture_enhanced_styles_survey_views() {
  // Print header.
  print "+" . str_pad("-", 280, "-") . '+' . "\r\n";
  print "|" . str_pad("VIEW DISPLAYS - IMAGE AND PICTURE FIELDS", 280, " ", STR_PAD_RIGHT) . '|' . "\r\n";
  print "+" . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 10, "-") . '+' . str_pad("-", 42, "-") . '+' . str_pad("-", 44, "-") . '+' . str_pad("-", 17, "-") . '+' . str_pad("-", 10, "-") . '+' . str_pad("-", 14, "-") . '+' . str_pad("-", 22, "-") . '+' . str_pad("-", 42, "-") . '+' . "\r\n";
  print "| ";
  print str_pad('View Machine Name', 33) . ' | ';
  print str_pad('View Human Name', 33) . ' | ';
  print str_pad('vid', 8) . ' | ';
  print str_pad('id', 40) . ' | ';
  print str_pad('display_title', 42) . ' | ';
  print str_pad('display_plugin', 15) . ' | ';
  print str_pad('position', 8) . ' | ';
  print str_pad('Display Type', 12) . ' | ';
  print str_pad('Style or Mapping', 20) . ' | ';
  print str_pad('Picture Fallback', 40) . " |\r\n";

  print "+" . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 10, "-") . '+' . str_pad("-", 42, "-") . '+' . str_pad("-", 44, "-") . '+' . str_pad("-", 17, "-") . '+' . str_pad("-", 10, "-") . '+' . str_pad("-", 14, "-") . '+' . str_pad("-", 22, "-") . '+' . str_pad("-", 42, "-") . '+' . "\r\n";

  $result = db_query('SELECT views_view.name, views_view.human_name,
                      views_view.vid, id, display_title, display_plugin, position, display_options
                      FROM `views_view`, `views_display`
                      WHERE views_view.vid = views_display.vid');

  foreach ($result as $record) {

    // Get the display_options;.
    $display_options = unserialize($record->display_options);

    $fields = ($display_options['fields'] ?? array());

    if (count($fields)) {

      foreach ($fields as $field_name => $field_data) {

        if ((isset($field_data['type']) && $field_data['type'] == 'picture') || (isset($field_data['settings']) && isset($field_data['settings']['image_style']))) {

          print "| ";
          print str_pad($record->name, 33) . ' | ';
          print str_pad($record->human_name, 33) . ' | ';
          print str_pad($record->vid, 8) . ' | ';
          print str_pad($record->id, 40) . ' | ';
          print str_pad($record->display_title, 42) . ' | ';
          print str_pad($record->display_plugin, 15) . ' | ';
          print str_pad($record->position, 8) . ' | ';

          // Print display type and settings.
          if (isset($field_data['type']) && $field_data['type'] == 'picture') {
            print str_pad("picture", 12) . ' | ';
            print str_pad($field_data['settings']['picture_mapping'], 20) . ' | ';
            print str_pad($field_data['settings']['fallback_image_style'], 40) . ' | ';

          }
          if (isset($field_data['settings']) && isset($field_data['settings']['image_style'])) {
            print str_pad("image", 12) . ' | ';
            print str_pad($field_data['settings']['image_style'], 20) . ' | ';
            print str_pad($field_data['settings']['image_link'], 40) . ' | ';
          }
          print "\r\n";
        }

      }

    }

  }

  print "+" . str_pad("-", 35, "-") . '+' . str_pad("-", 35, "-") . '+' . str_pad("-", 10, "-") . '+' . str_pad("-", 42, "-") . '+' . str_pad("-", 44, "-") . '+' . str_pad("-", 17, "-") . '+' . str_pad("-", 10, "-") . '+' . str_pad("-", 14, "-") . '+' . str_pad("-", 22, "-") . '+' . str_pad("-", 42, "-") . '+' . "\r\n";

}

/**
 * Drush enhanced-styles-files ('esf')   --all --audit.
 *
 * Displays a list of managed image files.
 * Audits looking for missing image files.
 */
function drush_nys_picture_enhanced_styles_files() {
  if (drush_get_option('audit', FALSE) == FALSE) {
    // File List Report.
    if (drush_get_option('all', FALSE) == TRUE) {
      $query = "SELECT `filename` FROM `file_managed` WHERE type = 'image' AND uri = CONCAT('public://', `filename`) ORDER BY `filename`";
    }
    else {
      $query = "SELECT `filename` FROM `file_managed` WHERE type = 'image' AND uri = CONCAT('public://', `filename`) ORDER BY `filename` LIMIT 500";
    }

    print "+-----------------------------------------------------------------+\r\n";
    print "|                          MANAGED FILES                          |\r\n";
    print "+-----------------------------------------------------------------+\r\n";

    // Factoid the number of managed image files.
    $managed_image_files_count = db_query("SELECT COUNT(*) FROM `file_managed` WHERE type = 'image' AND uri = CONCAT('public://', `filename`)")->fetchField();

    print "| " . str_pad("Number of Original Managed Image Files", 50) . " | " . str_pad($managed_image_files_count, 10) . " |\r\n";
    print "+-----------------------------------------------------------------+\r\n";

    $results = db_query($query);
    foreach ($results as $result) {
      print "$result->filename\r\n";
    }

    print "+-----------------------------------------------------------------+\r\n";

  }
  else {
    // Missing Files Audit Report.
    $query = "SELECT * FROM `file_managed` WHERE type = 'image' ORDER BY `filename`";

    $missing_files_array = array();

    $results = db_query($query);
    foreach ($results as $result) {

      if (file_exists(drupal_realpath($result->uri)) == FALSE) {
        $missing_files_array[] = $result->filename;
      }

    }

    if (count($missing_files_array)) {

      print "+-----------------------------------------------------------------+\r\n";
      print "|                          MISSING FILES                          |\r\n";
      print "+-----------------------------------------------------------------+\r\n";

      foreach ($missing_files_array as $missing_file) {
        print $missing_file;
        print "\r\n";
      }

      print "+-----------------------------------------------------------------+\r\n";

    }
    else {
      print "+-----------------------------------------------------------------+\r\n";
      print "|                       NO MISSING FILES                          |\r\n";
      print "+-----------------------------------------------------------------+\r\n";

    }

    print "\r\naudit\r\n";
  }

}

/**
 * Delete a file.
 */
function drush_nys_picture_enhanced_styles_delete($arg1 = '') {

  if (drush_get_option('all', FALSE)) {
    if (!empty($arg1)) {
      $path = 'public://';
      $real_path = drupal_realpath($path);
      $full_path = $real_path . '/' . $arg1;

      if (file_exists($full_path)) {
        $files_array = rglob($full_path);

        if (count($files_array) > 0) {
          foreach ($files_array as $filename) {
            $success = unlink($filename);
            if ($success === FALSE) {
              print "\r\n\r\nCould not delete file $filename \r\n\r\n";
            }
            else {
              print "\r\n\r\nFile $filename Deleted.\r\n\r\n";
            }
          }
        }
      }
    }
  }
  else {
    // Delete a single file.
    $filename = nys_picture_get_realpath($arg1);
    $success = unlink($filename);
    if ($success === FALSE) {
      print "\r\n\r\nCould not delete file $filename\r\n\r\n";
    }
    else {
      print "\r\n\r\nFile $filename Deleted.\r\n\r\n";
    }
  }

}

/**
 * Copy a file.
 */
function drush_nys_picture_enhanced_styles_copy($arg1 = '', $arg2 = '') {
  $source = nys_picture_get_realpath($arg1);
  if (empty($arg2)) {
    print "Destination path empty.\r\n";
    print "  Examples:\r\n";
    print "  destination_file.png\r\n";
    print "  styles/thumbnail/public/source_file.png\r\n\r\n\r\n";
    return;
  }

  $dest = drupal_realpath('public://') . '/' . $arg2;

  if (!file_exists($dest)) {
    $touch_success = touch($dest);
    if ($touch_success == FALSE) {
      print "\r\nPre copy create failed to create destination file $dest.\r\n";
      return;
    }
  }

  $success = copy($source, $dest);
  if ($success === FALSE) {
    print "\r\n\r\nCould not copy file.\r\n  source: $source\r\n  destination: $dest\r\n \r\n\r\n";
  }
  else {
    print "\r\n\r\nFile $arg1  Copied.\r\n\r\n";
  }
}

/**
 * Rename a file.
 */
function drush_nys_picture_enhanced_styles_rename($arg1 = '', $arg2 = '') {
  $oldname = nys_picture_get_realpath($arg1);
   if (empty($arg2)) {
    print "\r\n\r\nDestination file path empty.\r\n";
    print "  Examples:\r\n";
    print "  destination_file.png\r\n";
    print "  styles/thumbnail/public/destination_file.png\r\n\r\n\r\n";
    return;
  }

  $newname = drupal_realpath('public://') . '/' . $arg2;

  $success = rename($oldname, $newname);
  if ($success === FALSE) {
    print "\r\n\r\nCould not rename file.\r\n  oldname: $oldname\r\n  newname: $newname\r\n \r\n\r\n";
  }
  else {
    print "\r\n\r\nFile $arg1 Renamed.\r\n\r\n";
  }
}

/**
 * Touch a file.
 */
function drush_nys_picture_enhanced_styles_touch($arg1 = '') {
  $filename = nys_picture_get_realpath($arg1);
  if ($filename === FALSE && !empty($arg1) && (drush_get_option('new', FALSE) == TRUE || drush_get_option('force', FALSE) == TRUE)) {
    $filename = drupal_realpath('public://') . '/' . $arg1;
  }

  $success = touch($filename);
  if ($success === FALSE) {
    print "\r\n\r\nCould not touch file $filename.\r\n\r\n";
    if (drush_get_option('new', FALSE) == TRUE || drush_get_option('force', FALSE) == TRUE) {
        print "\r\n\r\nTry adding the --new or --force option to the drush command for non-existing files.\r\n\r\n";

    }
  }
  else {
    print "\r\n\r\nFile $filename Touched.\r\n\r\n";
  }
}

/**
 * Get the last modification time of a file.
 */
function drush_nys_picture_enhanced_styles_time($arg1 = '') {
  // If the supplied path is valid identify the item.
  $realpath = nys_picture_get_realpath($arg1);
  if ($realpath !== FALSE) {
    if (file_exists($realpath)) {
      print "\r\n\r\n";
      $timestamp = filectime($realpath);
      print date("c", $timestamp) . "  $timestamp \r\n";
      print "\r\n\r\n";
    }
    else {
      print "\r\n\r\n";
      print "The File $arg1 Can Not Be Found.";
      print "\r\n\r\n";
    }
  }
}

/**
 * View an image file in your browser.
 */
function drush_nys_picture_enhanced_styles_view($arg1 = '') {
  if (drush_get_option('all', FALSE)) {
    if (!empty($arg1)) {
      $path = 'public://';
      $real_path = drupal_realpath($path);
      $full_path = $real_path . '/' . $arg1;
      $real_path_length = strlen($real_path);

      if (file_exists($full_path)) {
        $files_array = rglob($full_path);

        if (count($files_array) > 0) {
          foreach ($files_array as $full_file_name) {
            // Create a drupal url.
            $local_url = 'public://' . substr($full_file_name, $real_path_length + 1);
            // Convert the drupal url to a web accessible url.
            $web_accesible_url = file_create_url($local_url);
            // Open the web accessible url in your web browser.
            if ($web_accesible_url != FALSE) {
              picture_enhanced_styles_view($web_accesible_url);
            }
            else {
              print "Web accessible url could not be created for $local_url";
            }
          }
        }
      }
    }
  }
  else {
    if (!empty($arg1)) {
      // Determine the url to open.
      // Create a drupal url.
      $local_url = 'public://' . $arg1;
      // Convert the drupal url to a web accessible url.
      $web_accesible_url = file_create_url($local_url);
      // Open the web accessible url in your web browser.
      if ($web_accesible_url != FALSE) {
        picture_enhanced_styles_view($web_accesible_url);
      }
      else {
        print "Web accessible url could not be created for ($local_url";
      }
    }
    else {
      print "\r\n\r\nFile Path Is Empty\r\n";
      print "  Examples:\r\n";
      print "  source_file.png\r\n";
      print "  styles/thumbnail/public/source_file.png\r\n\r\n\r\n";
    }
  }
}

/**
 * Drush non-cached variable_get()
 */
function nys_picture_variable_get($name, $default = '') {

  $blob = db_query("SELECT `value` FROM `variable` WHERE `name` = :name", array(':name' => $name))->fetchField();
  if ($blob != 'NULL' && !empty($blob)) {
    return unserialize($blob);
  }
  else {
    return $default;
  }
}

/**
 * Loads the variable directly from the database.
 */
function nys_picture_variable_exists($variable_name) {

  $num_variables = db_query("SELECT COUNT(*) FROM `variable` WHERE `name` = :name", array(':name' => $variable_name))->fetchField();
  if ($num_variables > 0) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Gets the real path to the file.
 *
 * Warns if empty and shows valid examples.
 * Gets the real path to the file, and checks for existence.
 * returns a valid path or FALSE after informing the user.
 */
function nys_picture_get_realpath($arg1 = '') {
  // If $arg1 is empty.
  if (empty($arg1)) {
    print "\r\n\r\nFile Path Is Empty\r\n";
    print "  Examples:\r\n";
    print "  source_file.png\r\n";
    print "  public://source_file.png\r\n";
    print "  private://source_file.png\r\n";
    print '  ' . drupal_realpath('public://') . '/source_file.png' . "\r\n";
    print "  styles/thumbnail/public/source_file.png\r\n\r\n\r\n";
    return FALSE;
  }

  if (strncasecmp($arg1, 'public://', strlen('public://')) == 0 || strncasecmp($arg1, 'private://', strlen('public://')) == 0) {
    // Determine if its  a public or private url.
    $full_path = drupal_realpath($arg1);
    if ($full_path !== FALSE) {
      return $full_path;
    }
    else {
      print "\r\n\r\nA local file could not be found at the url provided.\r\n\r\n";
      return FALSE;
    }
  }
  elseif (substr($arg1, 0, 1) == '/') {
    // The first character of the arg is a slash.
    // Potentially it's a complete path.
    // If the file exists thats it.
    if (file_exists($arg1)) {
      return $arg1;
    }
    else {
      print "\r\n\r\nThe file `$arg1` does not exist.\r\n\r\n";
      return FALSE;
    }
  }
  elseif (strpos($arg1, '/') === FALSE) {
    // Potentially it's file name, theres no slashes in it.
    $complete_path = drupal_realpath('public://') . '/' . $arg1;
    if (file_exists($complete_path)) {
      return $complete_path;
    }
    else {
      print "\r\n\r\nThe file `$complete_path` does not exist.\r\n\r\n";
      return FALSE;
    }
  }
  elseif (strpos($arg1, '/') > 0) {
    // Its a potential relative path name, It contains a slash.
    $complete_path = drupal_realpath('public://') . '/' . $arg1;
    if (file_exists($complete_path)) {
      return $complete_path;
    }
    else {
      print "\r\n\r\nThe file `$complete_path` does not exist.\r\n\r\n";
      return FALSE;
    }
  }

  return FALSE;
}

/**
 * Print and view the url.
 *
 * Possible enhancement open a browser window using the url.
 * See drush_start_browser().
 */
function picture_enhanced_styles_view($url = '') {
  print $url . "\r\n";
}

/**
 * See if an optimized image style is in the $image_style_name.
 *
 * @param string $image_style_name
 *   The machine name of the style.
 *
 * @return string
 *   Returns style or FALSE if no optimized style ~ webp in $image_style_name.
 */
function nys_picture_optimized_style_format($image_style_name) {
  // Determine if its a webp image style.
  $webp_pos = stripos($image_style_name, '_webp');
  if ($webp_pos !== FALSE) {
    return 'image/webp';
  }

  // Determine if its a jp2 image style.
  $jp2_pos = stripos($image_style_name, '_jp2');
  if ($jp2_pos !== FALSE) {
    return 'image/jp2';
  }

  // Determine if its a jxr image style.
  $jxr_pos = stripos($image_style_name, '_jxr');
  if ($jxr_pos !== FALSE) {
    return 'image/jxr';
  }

  return NULL;

}

/**
 * Builds an array of enhanced image styles.
 *
 * A subset of image_styles().
 */
function nys_picture_enhanced_image_styles() {
  $styles_array = image_styles();
  $enhanced_styles_array = array();
  foreach ($styles_array as $style_name => $style_data) {
    if (nys_picture_optimized_style_format($style_name)) {
      // If its an enhanced style add it to the array.
      $enhanced_styles_array[$style_name] = $style_data;
    }
  }
  return $enhanced_styles_array;
}

/**
 * Recursively builds an array of files in the hierarchy below given pattern.
 */
function rglob($pattern, $flags = 0) {
  $files = glob($pattern, $flags);

  foreach (glob(dirname($pattern) . '/*', GLOB_ONLYDIR | GLOB_NOSORT) as $dir) {
    $files = array_merge($files, rglob($dir . '/' . basename($pattern), $flags));
  }
  return $files;
}

/**
 * Was the last run completed successfully.
 *
 * At the end of every successful run the runs start time .
 * Is placed into 'nys_picture_last_run_start_time'.
 */
function nys_picture_update_run_completed() {
  if (nys_picture_variable_get('nys_picture_last_run_start_time', 0) == nys_picture_variable_get('nys_picture_run_start_time', 0)) {
    return TRUE;
  }

  return FALSE;

}

/**
 * Any update activity in the last minute.
 */
function nys_picture_recent_update_activity() {

  $one_minute_ago = time() - 60;

  if (variable_get('nys_picture_current_timestamp', 0) >= $one_minute_ago) {
    return TRUE;
  }

  return FALSE;

}

/**
 * Returns the results of an image magic identify command.
 */
function nys_picture_identify($complete_path) {

  if (defined('PANTHEON_ENVIRONMENT')) {
    $identify_path = variable_get('imagemagick_identify', '/usr/bin/identify');
  }
  else {
    $identify_path = variable_get('imagemagick_identify', '/usr/local/bin/identify');
  }

  $status = '';
  $error = '';
  _imagemagick_convert_exec(escapeshellarg($complete_path), $status, $error, $identify_path);

  if (empty($error)) {
    return $status;
  }

  print "EROR= $error\r\n";
  return FALSE;
}

/**
 * Returns the mime type from an image magic identify command.
 */
function nys_picture_mime_type_identify($complete_path) {

    $image_info = nys_picture_identify($complete_path);
    if ($image_info !== FALSE) {
      $raw_data = substr($image_info, strlen($complete_path));
      $image_info_array = explode(' ', $raw_data);
      if (count($image_info_array) > 0) {
        return $image_info_array[1];
      }
    }

    return FALSE;
}

/**
 * Produces a summary report of the total number of images count for each style.
 *
 * By default the enhanced styles are reported.
 */
function nys_picture_enhanced_styles_summary_report($style_name) {
  $file_count = 0;
  $output = '';
  $path = 'public://';
  $real_path = drupal_realpath($path);

  $derivative_path = $real_path . '/styles/' . $style_name . '/' . 'public';

  $files_array = glob($derivative_path . '/*.*');
  $number_of_files = count($files_array);

  $mime_types_array = array();

  foreach ($files_array as $complete_file_path) {
    $file_count++;

    // File names with Parenthesis in them are unidentifiable.
    if ((strpos($complete_file_path, '(', strlen($real_path)) !== FALSE) || (strpos($complete_file_path, ')', strlen($real_path)) !== FALSE)) {
      break;
    }

    // File names with Quotes in them are unidentifiable.
    if ((strpos($complete_file_path, "'", strlen($real_path)) !== FALSE) || (strpos($complete_file_path, '"', strlen($real_path)) !== FALSE) ||
        (strpos($complete_file_path, '$', strlen($real_path)) !== FALSE) || (strpos($complete_file_path, '`', strlen($real_path)) !== FALSE) ||
        (strpos($complete_file_path, '~', strlen($real_path)) !== FALSE)) {
      break;
    }

    $mime_type = nys_picture_mime_type_identify($complete_file_path);

    if ($mime_type !== FALSE && !empty($mime_type) && is_string($mime_type) && array_key_exists($mime_type, $mime_types_array)) {
      // Add to it.
      $mime_types_array[$mime_type]++;
    }
    else {
      // Add it.
      $mime_types_array[$mime_type] = 1;
    }
  }

  foreach ($mime_types_array as $mime_type => $quantity) {
    $output .= "\r\n|     " . str_pad($mime_type, 46) . " | " . str_pad($quantity, 10) . " |";
  }

  return "| " . str_pad($style_name, 50) . " | " . str_pad($number_of_files, 10) . " |$output";

}

/**
 * Report The Details of a Single Style.
 */
function nys_picture_enhanced_style_report($style_name) {
  print "+------------------------------------------------------------------------------------------------------------------------------------+\r\n";
  print "|";
  print str_pad($style_name, 132, ' ', STR_PAD_BOTH);
  print "|\r\n";
  print "+------------------------------------------------------------------------------------------------------------------------------------+\r\n";

  $path = 'public://';
  $real_path = drupal_realpath($path);
  $full_path = $real_path . '/styles/' . $style_name . "/*.*";
  $real_path_length = strlen($real_path);

  $files_array = rglob($full_path);

  if (count($files_array) > 0) {
    foreach ($files_array as $file_full_path) {

      // If file does not ends with public/modules/image/sample.png.
      if (strpos($file_full_path, 'public/modules/image/sample.png') === FALSE) {

        $image_info_raw = nys_picture_identify($file_full_path);
        $image_info = substr($image_info_raw, $real_path_length + 1);
        if (strncasecmp($image_info, 'styles/', strlen('styles/')) == 0) {
          print "|  ";
          print substr($image_info, strlen('styles/'));
        }
        else {
          print $image_info;
        }

      }

    }

  }

  print "+------------------------------------------------------------------------------------------------------------------------------------+\r\n";

}

/**
 * Live Monitoring of the update process.
 *
 * Pass in 'monitor' for a repeating monitor mode.
 * Pass in 'report' for a single status run mode.
 */
function nys_picture_enhanced_styles_monitor($mode = 'monitor') {

  print "+------------------------------------------------------------------------------+\r\n";

  if ($mode == 'monitor') {
    print "|                                 UPDATE STATUS                                |\r\n";
  }
  elseif ($mode == 'report') {
    print "|                                 RUN COMPLETED                                |\r\n";
  }

  print "+-------------------------------+----------------------------------------------+\r\n";
  print "| Description                   | Data                                         |\r\n";
  print "+-------------------------------+----------------------------------------------+\r\n";

  print '| ';
  print str_pad('Previous Update Run Started', 30);
  print '| ';
  print str_pad(date("F j, Y, g:i:s a", nys_picture_variable_get('nys_picture_last_run_start_time', 0)), 45);
  print "|\r\n";

  print '| ';
  print str_pad('Update Run Started', 30);
  print '| ';
  print str_pad(date("F j, Y, g:i:s a", nys_picture_variable_get('nys_picture_run_start_time', 0)), 45);
  print "|\r\n";

  print '| ';
  print str_pad('Current Style', 30);
  print '| ';
  print str_pad(nys_picture_variable_get('nys_picture_current_style', ''), 45);
  print "|\r\n";

  print '| ';
  print str_pad('Time Processed', 30);
  print '| ';
  print str_pad(date("F j, Y, g:i:s a", nys_picture_variable_get('nys_picture_current_timestamp', 0)), 45);
  print "|\r\n";

  print '| ';
  print str_pad('Current Image File', 30);
  print '| ';
  print str_pad(nys_picture_variable_get('nys_picture_current_image_file', ''), 45);
  print "|\r\n";

  print "+-------------------------------+----------------------------------------------+\r\n";
  if ($mode == 'monitor') {
    print "Type Control C to quit.\r\n";
  }

}

/**
 * Helper function.
 *
 * Processes one style directory.
 */
function nys_picture_update_enhanced_style($style_name, $style_data) {
  // Set current style variable.
  variable_set('nys_picture_current_style', $style_name);

  // Get the start time of interest.
  if (drush_get_option('all-dates', FALSE) == TRUE) {
    // If the --all-dates option is set.
    $last_run_start_time = 0;
  }
  elseif (!empty(drush_get_option('update-from', ''))) {
    $supplied_timestamp = strtotime(drush_get_option('update-from', ''));
    if ($supplied_timestamp !== FALSE) {
      $last_run_start_time = $supplied_timestamp;
    }
    else {
      print "The Supplied Time Was Not In A Valid Format\r\n";
      print "ISO 8601 Time Example: 2008-09-15T15:53:00\r\n";
      return;
    }

  }
  else {
    $last_run_start_time = variable_get('nys_picture_last_run_start_time', 0);
  }

  // Get a path to the desired source directory.
  $path = 'public://';
  $real_path = drupal_realpath($path);

  $style_path = $real_path . '/styles/' . $style_name . '/*.*';

  $flags = 0;
  $file_array = rglob($style_path, $flags);

  if ($file_array !== FALSE && is_array($file_array) and count($file_array) > 0) {
    foreach ($file_array as $image_file_path) {

      if (nys_picture_variable_exists('nys_picture_stop_requested')) {
        print "Stop Requested -- ??Style\r\n";
        break;
      }

      // If the file is newer than the prevoius runs start time.
      if (filemtime($image_file_path) > $last_run_start_time) {
        $path_parts = pathinfo($image_file_path);
        $filename = $path_parts['filename'] . '.' . $path_parts['extension'];
        if (strcasecmp($filename, 'sample.png') != 0) {
          // If the file is not enhanced.
          // Ie type is jpeg, gif, png, tiff etc then enhance it.
          // If the file is not webp convert it.
          // Make sure the file is not webp already.
          $mime_type = nys_picture_mime_type_identify($image_file_path);
          if ($mime_type !== FALSE && strcasecmp(nys_picture_mime_type_identify($image_file_path), 'webp') != 0) {
            // Before the webp derivative is made.
            // Rename the old file to a different name.
            // Create the derivative image.
            nys_picture_process_webp_image($style_data, $real_path, $filename, $image_file_path);

          }
        }
      }
    }
  }
}

/**
 * Convert to webp locally with imagemagick.
 *
 * Determine the paths to the $source.
 * And $destination files and convert the $destination.
 * Find the source location if not in the root directory.
 */
function nys_picture_process_webp_image($style, $path, $file_name, $destination) {
  // Check if the source file is in the root.
  $source = $path . '/' . $file_name;
  if (file_exists($source) !== FALSE) {
    // The source file is in the root directory.
      return nys_picture_image_style_create_derivative($style, $source, $destination);
  }

  // Get the source path from the `file_managed` table.
  $results = db_query("SELECT `uri` FROM `file_managed` WHERE `filename` = :filename", array(':filename' => $file_name));
  foreach ($results as $row) {
    $source = drupal_realpath($row->uri);
      if (file_exists($source) !== FALSE) {
            return nys_picture_image_style_create_derivative($style, $source, $destination);
      }
  }

  // Array of path components to try.
  $path_components = [
    'events/attachments',
    'events/main_image',
    'events/social',
    'article/attachment',
    'article/hero-image',
    'article/main-image',
    'in-the-news/attachment',
    'in-the-news/hero-image',
    'in-the-news/main-image',
    'press-release/attachment',
    'press-release/hero-image',
    'press-release/main-image',
    'press-release/social',
    'open-data',
    'senators/headshots',
    'senators/hero',
    'senators/about',
    'senators/presskit',
    'initiative/attachment',
    'initiative/main_image',
    'student-programs/attachments',
    'student-programs',
    'homepage_hero',
    'pictures',
    'slider-images',
    'webform',
    'webforms',
    'students/earthday/2017',
    'students/earthday/2018',
    'students/earthday/2019',
    'students/earthday/2020',
    'students/hannon-photo/2017',
    'students/hannon-photo/2018',
    'students/hannon-photo/2019',
    'students/thanksgiving/2017',
    'students/thanksgiving/2018',
    'students/thanksgiving/2019',
    'students/thanksgiving/2020',
    'articles/attachments',
    'default_images',
    'filefield_paths',
    'images',
    'in_the_news/main_image',
    'news/image_main',
    'poll/images',
    ];

  // Iterate over the array of $path_components.
  foreach ($path_components as $component) {
    $source = $path . '/' . $component . '/' . $file_name;
    if (file_exists($source) !== FALSE) {
      return nys_picture_image_style_create_derivative($style, $source, $destination);
    }
  }

  // If the source file could not be found.
  return FALSE;
}


/**
 * Creates a Resize option for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_image_resize_effect(array $data, stdClass $image, array &$args) {
  $args[] = '-resize ' . (int) $data['width'] . 'x' . (int) $data['height'] . '!';
  return TRUE;
}

/**
 * Creates a Rotate option for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_image_rotate_effect(array $data, stdClass $image, array &$args) {
  $background = $data['bgcolor'] ?? NULL;
  $degrees = $data['degrees'] ?? 0;

  if (!isset($background)) {
    $background = 'transparent';
  }
  // image_rotate_effect() converts the #hexadecimal color representation into
  // a decimal value (integer). Convert it back into a hexadecimal color.
  elseif (is_int($background)) {
    $background = '#' . str_pad(dechex($background), 6, 0, STR_PAD_LEFT);
  }
  else {
    $background = strtr($background, array('0x' => '#'));
  }
  $args[] = '-background ' . escapeshellarg($background) . ' -rotate ' . (float) $degrees;
  return TRUE;
}

/**
 * Creates a Crop option for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_image_crop_effect(array $data, stdClass $image, array &$args) {
  // Set sane default values.
  $data += array(
    'anchor' => 'center-center',
  );

  list($x, $y) = explode('-', $data['anchor']);
  $x = image_filter_keyword($x, $image->info['width'], $data['width']);
  $y = image_filter_keyword($y, $image->info['height'], $data['height']);

  $args[] = sprintf('-crop %dx%d%+d%+d!', $data['width'], $data['height'], $x, $y);

  return TRUE;
}

/**
 * Creates a Desaturate option for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_image_desaturate_effect(array $data, stdClass $image, array &$args) {
  $args[] = '-colorspace GRAY';
  return TRUE;
}

/**
 * Creates a Scale option for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_image_scale_effect(array $data, stdClass $image, array &$args) {
  $dimensions = $image->info;

  $width = $data['width'];
  $height = $data['height'];
  $upscale = $data['upscale'];

  // Scale the dimensions - if they don't change then just return success.
  if (!image_dimensions_scale($dimensions, $width, $height, $upscale)) {
    return TRUE;
  }

  // We have the scaled dimensions so resize.
  $args[] = '-resize ' . (int) $dimensions['width'] . 'x' . (int) $dimensions['height'] . '!';
  return TRUE;

}

/**
 * Creates Scale and Crop options for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_image_scale_and_crop_effect(array $data, stdClass $image, array &$args) {

  // Calculate the image Scale and Crop dimensions.
  $scale = max($data['width'] / $image->info['width'], $data['height'] / $image->info['height']);
  $x = ($image->info['width'] * $scale - $data['width']) / 2;
  $y = ($image->info['height'] * $scale - $data['height']) / 2;

  // Add a Resize option to Scale the image.
  $width = (int) round($image->info['width'] * $scale);
  $height = (int) round($image->info['height'] * $scale);
  $args[] = '-resize ' . (int) $width . 'x' . (int) $height . '!';

  // Add a Crop option to Crop the image and restrict overflow.
  $aspect = $image->info['height'] / $image->info['width'];
  if (empty($data['height'])) {
    $data['height'] = $data['width'] / $aspect;
  }
  if (empty($data['width'])) {
    $data['width'] = $data['height'] * $aspect;
  }

  $data['width'] = (int) round($data['width']);
  $data['height'] = (int) round($data['height']);
  $args[] = sprintf('-crop %dx%d%+d%+d!', $data['width'], $data['height'], $x, $y);
  return TRUE;

}

/**
 * Creates Default NYS Crop options for Imagemagick.
 *
 * @param array $data
 *   Options from a form.
 * @param object $image
 *   The toolkit image  object.
 * @param array $args
 *   An array of arguments to pass to imagemagick convert.
 *
 * @return bool
 *   TRUE if successful.
 */
function nys_picture_default_effect(array $data, stdClass $image, array &$args) {
  // Do nothing for now.
  return FALSE;
}
