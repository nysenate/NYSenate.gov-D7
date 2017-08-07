<?php
/**
 * @file
 * Hooks provided by Google Analytics Event Tracking API
 */

/**
 * Defines selectors and events to track through google analytics.
 *
 * Returns an array with all nessesary information to track an event with
 * google analytics.
 * http://code.google.com/apis/analytics/docs/tracking/eventTrackerGuide.html
 * Each member of the array should be an associative array with the following,
 * keys:
 *   event :
 *     - (String) - A javascript event. ie: mousedown | mousemove | mouseover
 *       Note: to track clicks it is best to use the [mousedown] event and not
 *       the [click] event
 *   selector :
 *     - (String) - A CSS selector for the DOM element that will be tracked.
 *   category :
 *     - (String) - For internal use. Does not effect functionallity. Used
 *       for catigorization in google analytics.
 *       Available tokens: !text, !href, !currentPage
 *         - !text : inserts text from DOM element into parameter.
 *         - !href : inserts text from the href attriute from the DOM element
 *         - !currentPage : inserts the url of the current page
 *         Note : if a token is used then only one token can be used. For
 *         example: `!url !text` will not work nor will `home !text`.
 *   action :
 *     - (String) - For internal use. Does not effect functionallity.
 *   label :
 *     - (String) - For internal use. Does not effect functionallity.
 *   value :
 *     - (Number) - For internal use. Does not effect functionallity. Does
 *       effect statistics.
 *   noninteraction :
 *     - (Bool) - For internal use. Does not effect functionallity. Does
 *       effect statistics.
 *   options :
 *     - (Array) - Options Array holds values for extra options that deal with
 *       how the event tracking occurs.
 *       Available options: "track one event"
 *       Usage: options = array("track one event" => TRUE);
 *
 * @return array
 *   A multidimentional array in the format:
 *   array(
 *     array(
 *       'event' => string('mousedown | mousemove | mouseover | etc'),
 *       'selector' => String('#main-menu li a, or other valid css selector'),
 *       'category' => String(!text, !href, !currentPage, or custom string),
 *       'action' => String!text, !href, !currentPage, or custom string(),
 *       'label' => String(!text, !href, !currentPage, or custom string),
 *       'value' => Number(Weight of event),
 *       'noninteraction' => Bool(TRUE | FALSE),
 *     ),
 *   );
 */
function hook_google_analytics_et_google_analytics_et_api() {
  $selectors = array(
    array(
      'event' => 'mousedown',
      'selector' => '#main-menu li a',
      'category' => 'main navigation',
      'action' => 'click',
      'label' => '!text',
      'value' => 0,
      'noninteraction' => TRUE,
      'options' => array(),
    ),
    array(
      'event' => 'mousedown',
      'selector' => 'a#logo',
      'category' => 'Home Link',
      'action' => 'click',
      'label' => 'Logo',
      'value' => 0,
      'noninteraction' => TRUE,
      'options' => array(
        'trackOnce' => TRUE
        ),
    ),
    array(
      'event' => 'mousedown',
      'selector' => 'div#site-name a[rel="home"]',
      'category' => 'Home Link',
      'action' => 'click',
      'label' => 'Site Name',
      'value' => 0,
      'noninteraction' => TRUE,
      'options' => array(),
    ),
    array(
      'event' => 'mouseover',
      'selector' => 'div',
      'category' => 'test',
      'action' => 'click',
      'label' => '!test',
      'value' => 0,
      'noninteraction' => TRUE,
      'options' => array(),
    ),
  );

  return $selectors;
}

/**
 * Define the settings used in the google analytics event tracker
 *
 * @return array settings array.
 */
function hook_google_analytics_et_settings_info() {
  $settings = array();

  $settigns['debug'] = TRUE;

  return $settigns;
}
