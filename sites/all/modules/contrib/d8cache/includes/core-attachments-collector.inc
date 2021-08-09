<?php

/**
 * @file
 * Attachment Collector functions for the D8 caching system backport.
 */

/* -----------------------------------------------------------------------
 * Public API
 */

if (!function_exists('drupal_add_attachment')) {

  /**
   * Adds attachments in a way that they can be collected for render caching.
   *
   * This allows collecting attachments that are added out-of-band within a
   * local scope to store them into #attached for render caching.
   * If you want to call this from a legacy function that both works when
   * called via #attached and when called directly, ensure to check
   * drupal_has_attachments_collector() first as not doing so can lead to
   * an endless recursion.
   * This is essentially a short wrapper around drupal_process_attached().
   *
   * @param string $key
   *   The key within #attached, like 'js', 'css' to add to.
   * @param mixed $value
   *   The value to store as attachment.
   * @param bool $dependency_check
   *   This parameter is passed on to drupal_process_attached() and can be used
   *   for checking dependency chains for drupal_add_library().
   *
   * @return bool
   *   FALSE if there were any missing library dependencies; TRUE if all library
   *   dependencies were met.
   *
   * @see drupal_process_attached()
   */
  function drupal_add_attachment($key, $value, $dependency_check = FALSE) {
    $elements = array();
    $elements['#attached'] = array();
    $elements['#attached'][$key][] = $value;
    return _drupal_process_attached_supplement($elements, JS_DEFAULT, $dependency_check);
  }

}

if (!function_exists('drupal_has_attachments_collector')) {

  /**
   * Returns whether there is an active attachments collector.
   *
   * @return bool
   *   TRUE if Drupal is collecting attachments, FALSE otherwise.
   */
  function drupal_has_attachments_collector() {
    static $drupal_static_fast;

    if (!isset($drupal_static_fast)) {
      $drupal_static_fast = array();
      $drupal_static_fast['render_listeners'] = &drupal_static('drupal_render:render_listeners', array());
      $drupal_static_fast['collect_attachments'] = &drupal_static('drupal_process_attached:collect_attachments', TRUE);
    }

    if ($drupal_static_fast['collect_attachments'] !== FALSE && !empty($drupal_static_fast['render_listeners'])) {
      return TRUE;
    }

    return FALSE;
  }

}

if (!class_exists('DrupalAttachmentsCollector', FALSE)) {

  /**
   * Provices a way to collect attachments added during the rendering process.
   *
   * Attachments added via drupal_add_js() / drupal_add_css() or that are early
   * rendered as part of a template have been lost in the past and that made
   * caching of anything that is not the whole page difficult.
   * The AttachmentsCollector solves this problem by routing all adding of
   * attachments through drupal_process_attached(), which is then storing the
   * attachments in the registered storage of listeners - if any.
   * To create an attachments collector the following code shows an example:
   *
   * @code
   * // Register a listener.
   * $attachments_collector = new DrupalAttachmentsCollector();
   * // Render the render array.
   * $rendered = drupal_render($build);
   * // Store the attachments.
   * $attachments = $attachments_collector->getAttachments();
   * // Unregister the listener.
   * unset($attachments_collector);
   * // Now store the attachments in the render array to cache.
   * $build_to_cache['#markup'] = $rendered;
   * $build_to_cache['#attached'] = $attachments;
   * @endcode
   */
  class DrupalAttachmentsCollector {

    /**
     * The collected attachments.
     *
     * @var array
     */
    protected $attachments = array();

    /**
     * Constructs a DrupalAttachmentsCollector object.
     *
     * This will register a listener that listens for attachments created via:
     * - drupal_add_js()
     * - drupal_add_css()
     * - drupal_add_library()
     * - drupal_add_html_head()
     * - drupal_add_http_header()
     * and everything that is processed with drupal_process_attached().
     */
    public function __construct() {
      $key = spl_object_hash($this);

      $render_listeners = &drupal_static('drupal_render:render_listeners', array());
      $render_listeners[$key] = array();

      $this->attachments = &$render_listeners[$key];
    }

    /**
     * Returns the collected attachments.
     *
     * The returned values can be put into the '#attached' property of an
     * render array.
     *
     * @code
     * $build['#attached'] = $attachments_collector->getAttachments();
     *
     * // The structure of the render array looks like this:
     * $build['#attached'] = array(
     *   'js' => array(
     *      array('data' => 'somefile.js'),
     *      array('data' => 'anotherfile.js'),
     *   ),
     * );
     * @endcode
     *
     * @return array
     *   Returns the collected attachments as an #attached array in the form of
     *   key:value.
     */
    public function getAttachments() {
      return $this->attachments;
    }

    /**
     * Destructs the DrupalAttachmentsCollector object.
     *
     * This will unregister the listener that listens for attachments.
     */
    public function __destruct() {
      $key = spl_object_hash($this);

      $render_listeners = &drupal_static('drupal_render:render_listeners', array());
      unset($render_listeners[$key]);
    }

    /**
     * Implements __sleep().
     *
     * This disallows serializing the attachments collector as it relies on
     * state.
     */
    public function __sleep() {
      throw new Exception('An attachments collector cannot be serialized.');
    }

  }

}

/* -----------------------------------------------------------------------
 * Helper functions
 */

/**
 * Overrides drupal_process_attached().
 */
function _drupal_process_attached_supplement($elements, $group = JS_DEFAULT, $dependency_check = FALSE, $every_page = NULL) {
  static $drupal_static_fast;

  if (!isset($drupal_static_fast)) {
    $drupal_static_fast = array();
    $drupal_static_fast['render_listeners'] = &drupal_static('drupal_render:render_listeners', array());
    $drupal_static_fast['collect_attachments'] = &drupal_static('drupal_process_attached:collect_attachments', TRUE);
  }
  $render_listeners = &$drupal_static_fast['render_listeners'];
  $collect_attachments = &$drupal_static_fast['collect_attachments'];

  // If we are collecting attachments and have at least one listener in the
  // active render listeners, then put all attachments from $elements into the
  // storage of all listeners.
  if ($collect_attachments && !empty($render_listeners)) {
    foreach ($render_listeners as $listener_id => $listener_storage) {
      foreach ($elements['#attached'] as $key => $value) {
        if (!isset($render_listeners[$listener_id][$key])) {
          $render_listeners[$listener_id][$key] = array();
        }
        $render_listeners[$listener_id][$key] = array_merge($render_listeners[$listener_id][$key], $value);
      }
    }
  }

  // Protect against accidental recursion.
  $old_collect_attachments = $collect_attachments;
  $collect_attachments = FALSE;

  // Add additional types of attachments specified in the render() structure.
  // Libraries, JavaScript and CSS have been added already, as they require
  // special handling.
  foreach ($elements['#attached'] as $callback => $options) {
    if (function_exists($callback)) {
      foreach ($elements['#attached'][$callback] as $args) {
        call_user_func_array($callback, $args);
      }
    }
  }

  // Restore old value.
  $collect_attachments = $old_collect_attachments;

  return TRUE;
}
