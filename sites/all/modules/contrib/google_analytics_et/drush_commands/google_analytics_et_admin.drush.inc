<?php
/**
 * @file
 * Google Analytics Event Tracking Module Drush Admin.
 *
 * Utilizes Drush to administrate the google analytics event tracking.
 */

/**
 * Implements hook_drush_help().
 */
function google_analytics_et_admin_drush_help($section) {
  switch ($section) {
    case 'drush:gaet-add-et':
      return dt("Add an event tracker to a css selector.");
    case 'drush:gaet-delete-et':
      return dt("delete all event trackers attched to specified css selector.");
    case 'drush:gaet-override-et':
      return dt("Override all event trackers defined in code. This turns off the event tracking defined by all modules.");
    case 'drush:gaet-get-override-status':
      return dt("Checks wither or not the hook google_analytics_et_api is being overridden.");
  }
}

/**
 * Implements hook_drush_command().
 */
function google_analytics_et_admin_drush_command() {
  $items = array();

  $items['gaet-add-et'] = array(
    'description' => "adds an event tracking rule to the list.",
    'arguments' => array(
      'event' => 'The Javascript event that Google Analytics is supposed to track',
      'selector' => 'The CSS selector to use in the event tracking rule',
      'category' => 'The intended Category that Google is to file this event under.',
      'action' => 'The action the calls this event',
      'label' => 'Optional label for the event',
      'value' => 'Optional values (Integer)',
      'noninteraction' => 'Should this event be used in calculating the bounce rate (Bool)',
    ),
    'examples' => array(
      'drush addet "p" "body" "clicked" "somebody clicked a p body" 0 FALSE' => 'Add a comedac click event.',
    ),
    'aliases' => array('addet'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['gaet-delete-et'] = array(
    'description' => "deletes an event tracking rule from the list.",
    'examples' => array(
      'drush delet "p"' => 'remove all event tracking with "p" as the selector.',
    ),
    'aliases' => array('delet'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['gaet-override-et'] = array(
    'description' => "Toggels the override event tracking option.",
    'examples' => array(
      'drush oret' => 'Toggle the override event tracking option TRUE|FALSE. (if for some reason nothing is set, this sets it to true.)',
    ),
    'aliases' => array('oret'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['gaet-get-override-status'] = array(
    'description' => "Checks the status of the override event tracking option.",
    'examples' => array(
      'drush getet' => 'Returns TRUE|FALSE|"not set" depending on the override eventtracking status.',
    ),
    'aliases' => array('getet'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Drush command callback for gaet-add-et.
 *
 * Adds an event to be tracked by a click event on the given CSS selector.
 *
 * @param string $event
 *   The Javascript event that Google Analytics is going to track.
 * @param string $selector
 *   The CSS string that defines the CSS selector of the elements that will
 *   respond to the click event.
 * @param string $category
 *   The name you supply for the group of objects you want to track.
 * @param string $action
 *   A string that is uniquely paired with each category, and commonly used
 *   to define the type of user interaction for the web object.
 * @param string $label
 *   (optional) An optional string to provide additional dimensions to the
 *   event data.
 * @param int $value
 *   (optional) An integer that you can use to provide numerical data about
 *   the user event.
 * @param string|bool $nonineration
 *   (optional) A boolean that when set to true, indicates that the event
 *   hit will not be used in bounce-rate calculation
 */
function drush_google_analytics_et_admin_gaet_add_et($event, $selector, $category, $action, $label = '', $value = 0, $noninteraction = TRUE) {
  $selector_array = array(
    'event' => $event,
    'selector' => $selector,
    'category' => $category,
    'action' => $action,
    'label' => $label,
    'value' => $value,
    'noninteraction' => $noninteraction,
  );

  if (_drush_google_analytics_et_admin_gaet_add_et_input_validation($selector_array)) {
    google_analytics_et_add_event_tracker($selector_array);
    foreach ($selector_array as $key => $value) {
      drush_print('   | ' . str_pad($key . ' ', 16, "-", STR_PAD_RIGHT) . ' | ' . $value);
    }
    drush_print(dt("Done!"));
  }
  else {
    drush_print(dt("An Error Occured! \nOne or more data types was incorect."));
  }
}

/**
 * Drush command callback for gaet-del-et
 */
function drush_google_analytics_et_admin_gaet_delete_et($selector) {
  google_analytics_et_remove_event_tracker($selector);

  drush_print(dt($selector . " deleted!"));
}

/**
 * Validates the user input.
 *
 * Doesn't do any xss filtering or detection, only checks to see if the input
 * types are correct.
 */
function _drush_google_analytics_et_admin_gaet_add_et_input_validation($selector_array) {
  $validattion = FALSE;

  foreach ($selector_array as $key => $value) {
    switch ($key) {
      case 'event':
      case 'selector':
      case 'category':
      case 'action':
      case 'label':
        if (is_string($value)) {
          $validation = TRUE;
        }
        else {
          drush_set_error('NOT_STRING', dt("!key should be a string.", array('!key' => $key)));
        }

        break;

      case 'value':
        if (is_numeric($value)) {
          $validation = TRUE;
        }
        else {
          drush_set_error('NOT_NUMBER', dt("!key should be a number.", array('!key' => $key)));
        }

        break;

      case 'noninteraction':
        if (is_bool($value)) {
          $validation = TRUE;
        }
        else {
          drush_set_error('NOT_BOOLEAN', dt("!key should be a boolean.", array('!key' => $key)));
        }

        break;

    }
  }

  return $validation;
}

/**
 * Toggles the override status, TRUE|FALSE
 */
function drush_google_analytics_et_admin_gaet_override_et() {
  $output = dt("Done!") . "\n";

  google_analytics_et_override_event_tracking();

  $status = google_analytics_et_get_event_trackering_override_status();
  $output .= _google_analytics_et_admin_parse_override_status($status);

  return drush_print($output);
}

/**
 * Gets the override status and displays it in drush.
 */
function drush_google_analytics_et_admin_gaet_get_override_status() {
  $status = google_analytics_et_get_event_trackering_override_status();

  $output = _google_analytics_et_admin_parse_override_status($status);

  return drush_print($output);
}

/**
 * Parse the override status into a human readable sentance. For display in
 * drush.
 */
function _google_analytics_et_admin_parse_override_status($status) {
  switch ($status) {
    case TRUE:
      $output = dt('Google Analytics Event Tracking is Being Overwritten.');
      break;

    case FALSE:
      $output = dt('Google Analytics Event Tracking is Not Being Overritten.');
      break;

  }

  return $output;
}
