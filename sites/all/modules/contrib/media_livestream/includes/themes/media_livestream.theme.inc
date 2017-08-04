<?php

/**
 * @file
 * The media_livestream/includes/themes/media_livestream.theme.inc file.
 *
 * Theme and preprocess functions for Media: Livestream.
 */

/**
 * Preprocess function for theme('media_livestream_video').
 */
function media_livestream_preprocess_media_livestream_video(&$variables) {
  // Build the URI.
  $wrapper = file_stream_wrapper_get_instance_by_uri($variables['uri']);
  $parameters = $wrapper->get_parameters();
  $protocol = 'https:';

  // Set the title.
  switch ($parameters['type']) {
    case 'video':
      $variables['video_id'] = check_plain($parameters['video_id']);
      $variables['video_title'] = check_plain($parameters['video_title']);
      break;

    case 'channel':
      $variables['video_id'] = check_plain($parameters['channel_id']);
      $variables['video_title'] = check_plain($parameters['channel_title']);
      break;

  }
  //$variables['title'] = $variables['video_title'];
  $variables['channel_id'] = check_plain($parameters['channel_id']);
  $variables['channel_title'] = check_plain($parameters['channel_title']);

  // Make the file object available.
  $file_object = file_uri_to_object($variables['uri']);

  // Build the base query string.
  $query = array(
    'wmode' => 'direct',
    'mute' => 'false',
    'layout' => '4',
  );

  // Autoplay.
  if (($variables['options']['autoplay_channel'] && $parameters['type'] == 'channel') || ($variables['options']['autoplay_video'] && $parameters['type'] == 'video')) {
    $query['autoPlay'] = 'true';
  }

  // Mute.
  if ($variables['options']['mute']) {
    $query['mute'] = 'true';
  }

  // Layout.
  if ($variables['options']['layout']) {
    $query['layout'] = $variables['options']['layout'];
  }

  // Add some options directly to the template variables.
  foreach (array('width', 'height') as $themevar) {
    $variables[$themevar] = $variables['options'][$themevar];
  }

  // Do something useful with the overridden attributes from
  // the file object. We ignore alt and style for now.
  if (isset($variables['options']['attributes']['class'])) {
    if (is_array($variables['options']['attributes']['class'])) {
      $variables['classes'] = array_merge($variables['classes_array'], $variables['options']['attributes']['class']);
    }
    else {
      // Provide nominal support for Media 1.x.
      $variables['classes'][] = $variables['options']['attributes']['class'];
    }
  }

  // Add template variables for accessibility.
  $variables['alternative_content'] = t('Video of @title', array('@title' => $variables['video_title']));

  // If the field is configured to use a specific protocol, use it.
  // Otherwise use a protocol-relative URL.
  if ($variables['options']['protocol_specify']) {
    $protocol = $variables['options']['protocol'];
  }

  // Build the iframe's src URL, with playback options set via query string.
  if (empty($variables['video_id']) || $variables['channel_id'] == $variables['video_id']) {
    $variables['video_id'] = $variables['channel_id'];
    $url = "{$protocol}//cdn.livestream.com/embed/{$variables['channel_id']}";
  }
  else {
    $url = "{$protocol}//cdn.livestream.com/embed/{$variables['channel_id']}?clip={$variables['video_id']}";
  }
  $variables['url'] = url($url, array('query' => $query, 'external' => TRUE));

  // Rewrite some stuff, else livestream will bounce.
  $variables['url'] = str_replace('&', '&amp;', $variables['url']);
}
