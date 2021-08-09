<?php

/**
 * @file
 * The media_ustream/includes/themes/media_ustream.theme.inc file.
 *
 * Theme and preprocess functions for Media: UStream.
 */

/**
 * Preprocess function for theme('media_ustream_video').
 */
function media_ustream_preprocess_media_ustream_video(&$variables) {
  // Build the URI.
  $wrapper = file_stream_wrapper_get_instance_by_uri($variables['uri']);
  $parameters = $wrapper->get_parameters();
  $variables['video_id'] = check_plain($parameters['video_id']);
  $link_to_media = $wrapper->interpolateUrl();

  // Make the file object available.
  $file_object = file_uri_to_object($variables['uri']);

  // Build the base query string.
  $query = array(
    // Enables hardware acceleration.
    'wmode' => 'direct',
  );

  // The 'ub', 'lc', 'oc', and 'uc' GET args are hex color strings
  // which set the color of the UI controls.
  if (!empty($variables['options']['custom_color']) && $variables['options']['player_color'] == 'colorpicker') {
    $query['ub'] = str_replace('#', '', $variables['options']['custom_color']);
  }
  elseif ($variables['options']['player_color']) {
    $query['ub'] = $variables['options']['player_color'];
  }
  else {
    $query['ub'] = '';
  }

  // The lc, oc and uc options only work on the old style player.
  // This discovery makes some work done on the color select js
  // already obselete, so that requires some work. (ax out multi
  // field stuff and only bind to our custom_color field.)
  // (and while we'r at it, isn't this availble in the media module?)
  // Ustream did not schedule a date yet for phasing out
  // the old embed completely, but i'm sure they will at some point.
  // If you Really need an old style player and want to set colors
  // in a dynamic way, then please provide a patch.
  $query['lc'] = $query['ub']; // Upper side of the player.
  $query['oc'] = $query['ub']; // Link color on embed config page.
  $query['uc'] = $query['ub']; // Play and other buttons.

  // This enables the old (2) player or the new one (3).
  // No need to set the default, the default is 3 - new.
  if (!$variables['options']['new_player']) {
    $query['v'] = 2;
  }

  // If this is a recoded video, and "autoplay_recorded" is enabled, set the autoplay flag.
  // Ditto for live channels.
  if (($parameters['recorded'] && $variables['options']['autoplay_recorded'])
      || (!$parameters['recorded'] && $variables['options']['autoplay_live'])) {
    $query['autoplay'] = 1;
  }

  // Add some options directly to the template variables.
  foreach (array('width', 'height') as $themevar) {
    $variables[$themevar] = $variables['options'][$themevar];
  }

  // Do something useful with the overridden
  // attributes from the file object.
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
  $variables['title'] = check_plain($file_object->filename);

  // Build the iframe's src URL, with playback options set via query string
  // and construct the video / channel title for alternative content.
  if ($parameters['recorded']) {
    $url = "//www.ustream.tv/embed/recorded/{$variables['video_id']}?html5ui=1";
    $link_title = t('Video of @title', array('@title' => $variables['title']));
  }
  else {
    $url = "//www.ustream.tv/embed/{$variables['video_id']}?html5ui=1";
    $link_title = t('Channel @title on Ustream', array('@title' => $variables['title']));
  }
  $variables['url'] = url($url, array('query' => $query, 'external' => TRUE));
  $variables['alternative_content'] = l($link_title, $link_to_media);
}
