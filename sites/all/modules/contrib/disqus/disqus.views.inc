<?php

/**
 * @file
 * Views integration with the Disqus module.
 */

/**
 * Implements hook_views_data_alter().
 */
function disqus_views_data_alter(&$data) {
  // Number of Disqus comments made on the given node.
  $data['node']['disqus_comment_count'] = array(
    'field' => array(
      'title' => t('Disqus Comment Count'),
      'help' => t('The number of Disqus comments made on the post. Note that this will not work in the preview.'),
      'handler' => 'views_handler_field_node_disqus_comment_count',
    ),
  );
}

/**
 * Field handler to present the number of Disqus comments on a node.
 */
class views_handler_field_node_disqus_comment_count extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function query() {
    // Override parent::query() without altering query.
  }

  /**
   * When rendering the field.
   */
  function render($values) {
    // Ensure Disqus comments are available on the node user has access to edit this node.
    $node = node_load($values->nid);
    if (user_access('view disqus comments') && isset($node->disqus)) {
      // Extract the Disqus values.
      $disqus = $node->disqus;
      // Build a renderable array for the link.
      $content = array(
        '#theme' => 'link',
        '#text' => t('Comments'),
        '#path' => $disqus['identifier'],
        '#options' => array(
          'fragment' => 'disqus_thread',
          'attributes' => array(
            // Identify the node for Disqus with the unique identifier:
            // http://docs.disqus.com/developers/universal/#comment-count
            'data-disqus-identifier' => $disqus['identifier'],
          ),
          'html' => FALSE,
        ),
      );

      /**
       * This attaches disqus.js, which will look for the DOM variable
       * disqusComments which is set below. When found, the disqus javascript
       * api replaces the html element with the attribute:
       * "data-disqus-identifier" and replaces the element with the number of
       * comments on the node.
       */
      $content['#attached'] = array(
        'js' => array(
          array('data' => drupal_get_path('module', 'disqus') . '/disqus.js'),
          array(
            'data' => array('disqusComments' => $disqus['domain']),
            'type' => 'setting',
          ),
        ),
      );
      return drupal_render($content);
    }
  }
}
