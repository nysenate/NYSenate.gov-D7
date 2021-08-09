<?php

/**
 * @file
 * Create a Livestream Stream Wrapper class for the Media/Resource module.
 */

/**
 * Create an instance like this:
 * Video:
 * $livestream = new MediaLivestreamStreamWrapper('livestream://[channel_id]/[video_id]');
 * Channel:
 * $livestream = new MediaLivestreamStreamWrapper('livestream://[channel_id]');
 */
class MediaLivestreamStreamWrapper extends MediaReadOnlyStreamWrapper {

  /**
   * Returns the Livestream mime type.
   */
  static function getMimeType($uri, $mapping = NULL) {
    return 'video/livestream';
  }

  /**
   *  Returns an array that describes the Livestream video/channel.
   *  @param $url
   *    The URL to parse: livestream://[channel_id]/[video_id]
   *                  OR: livestream://[channel_id].
   *  @return
   *    An array of two keys:
   *      channel_title: The channel's title.
   *      channel_id: The channels's unique identifier.
   *      video_id: The video's unique identifier.
   *      type: The type, channel or video.
   *    or FALSE if the $url is malformed.
   */
  protected function _parse_url($url) {
    $path = explode('://', $url);
    $parts = explode('/',  $path[1]);
    $total = count($parts);

    if ($total > 6 || $path[0] != 'livestream') {
      return FALSE;
    }
    $params = array();

    $params['channel_id'] = $parts[0];
    if (!empty($parts[1])) {
      $params['video_id'] = $parts[1];
      $video_properties = MediaInternetLivestreamHandler::getVideoProperties($params['channel_id'], $params['video_id']);
      $params['type'] = 'video';
    }
    else {
      $video_properties = MediaInternetLivestreamHandler::getChannelProperties($params['channel_id']);
      $params['type'] = 'channel';
    }

    if (!empty($video_properties['channel']['item'][0]['title'])) {
      $params['video_title'] = $video_properties['channel']['item'][0]['title'];
    }
    $params['channel_title'] = $video_properties['channel']['title'];

    return $params;
  }

  /**
   * Returns a url in the format "http://livestream.tv/recorded/123456" or "http://livestream.tv/channel/123456".
   */
  function interpolateUrl() {
    $parameters = $this->get_parameters();
    if (!empty($parameters['video_id'])) {
      return "http://livestream.com/embed/{$parameters['channel_id']}/?clipId={$parameters['video_id']}";
    }
    else {
      return "http://livestream.com/embed/{$parameters['channel_id']}}";
    }
  }

  /**
   * Returns a url to the original image.
   */
  function getOriginalThumbnailPath() {

    switch ($this->parameters['type']) {
      case 'video':
        $properties = MediaInternetLivestreamHandler::getVideoProperties($this->parameters['channel_id'], $this->parameters['video_id']);
        break;

      case 'channel':
        $properties = MediaInternetLivestreamHandler::getChannelProperties($this->parameters['channel_id']);
        break;

    }

    if (!empty($this->parameters['video_id'])) {
      $path = $properties['channel']['item'][0]['thumbnail']['@url'];
    }
    else {
      $path = $properties['channel']['image']['url'];
    }

    // TODO: add empty image for channels without a thumbnail.

    return $path;
  }

  /**
   * Returns a url to the local saved image.
   */
  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();

    switch ($parts['type']) {
      case 'video':
        $video_title = check_plain($parts['video_title']) . ' - ' . check_plain($parts['channel_title']);
        $video_id = check_plain($parts['video_id']) . check_plain($parts['channel_id']);
        break;

      case 'channel':
        $video_id = check_plain($parts['channel_id']);
        $video_title = check_plain($parts['channel_title']);
        break;

    }

    // If transliteration module is installed USE IT.
    if (function_exists('transliteration_clean_filename')) {
      $video_title = transliteration_clean_filename($video_title, NULL);
    }
    else {
      $video_title = $video_id;
    }

    // And make sure it 'fits'.
    $video_title = truncate_utf8($video_title, 255);

    $local_path = file_default_scheme() . '://media-livestream/' . $video_title . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      $response = drupal_http_request($this->getOriginalThumbnailPath());
      if (!isset($response->error)) {
        file_save_data($response->data, $local_path, FILE_EXISTS_REPLACE);
      }
      else {
        @copy($this->getOriginalThumbnailPath(), $local_path);
      }
    }
    return $local_path;
  }
}
