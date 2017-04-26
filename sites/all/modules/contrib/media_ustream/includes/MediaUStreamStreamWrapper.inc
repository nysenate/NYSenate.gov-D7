<?php

/**
 * @file
 * Create a UStream Stream Wrapper class for the Media/Resource module.
 */

/**
 * Create an instance like this:
 * $ustream = new MediaUStreamStreamWrapper('ustream://[recorded OR live]/[video-id]');
 */
class MediaUStreamStreamWrapper extends MediaReadOnlyStreamWrapper {

  /**
   * Returns the UStream mime type.
   */
  static function getMimeType($uri, $mapping = NULL) {
    return 'video/ustream';
  }

  /**
   *  Returns an array that describes the UStream video/channel.
   *  @param $url
   *    The URL to parse: ustream://live/[video_id] OR ustream://recorded/[video_id].
   *  @return
   *    An array of two keys:
   *      recorded: A boolean: TRUE if this is a recorded video, FALSE if it's a live channel feed.
   *      video_id: The video's unique identifier.
   *    or FALSE if the $url is malformed.
   */
  protected function _parse_url($url) {
    $path = explode('://', $url);
    $parts = explode('/',  $path[1]);
    $total = count($parts);
    if ($total != 2 || $path[0] != 'ustream') {
      return FALSE;
    }
    $params = array();
    $params['recorded'] = ($parts[0] == 'recorded');
    $params['video_id'] = $parts[1];

    return $params;
  }

  /**
   * Returns a url in the format
   * "http://ustream.tv/recorded/123456"
   * or "http://ustream.tv/channel/123456".
   */
  function interpolateUrl() {
    $parameters = $this->get_parameters();
    if ($parameters) {
      $type = $parameters['recorded'] ? 'recorded' : 'channel';
      return "http://ustream.tv/$type/{$parameters['video_id']}";
    }
  }

  /**
   * Returns a url to the original image.
   */
  function getOriginalThumbnailPath() {
    if ($this->parameters['recorded']) {
      $video_properties = MediaInternetUStreamHandler::getVideoProperties($this->parameters['video_id']);
      $path = $video_properties['results']['imageUrl']['medium'];
    }
    else {
      $video_properties = MediaInternetUStreamHandler::getChannelProperties($this->parameters['video_id']);
      if ($video_properties['results']['imageUrl']) {
        $path = $video_properties['results']['imageUrl']['medium'];
      }
      else {
        // This channel has no picture of its own, so use our placeholder image.
        global $base_insecure_url;
        // $base_insecure_url is important because it explicitly uses
        // http:// rather than https://, which $base_url will use if
        // the site it set up to use https:// for logged in users.

        // TODO: / NOTE: It'd be really nice if the Media module had a 'no thumbnail
        // available' image which we could use instead of this poor-man's placeholder.
        $path = $base_insecure_url . '/' . drupal_get_path('theme', 'bartik') . '/logo.png';
      }
    }
    return $path;
  }

  /**
   * Returns a url to the local saved image.
   */
  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();

    $local_path = file_default_scheme() . '://media-ustream/' . check_plain($parts['video_id']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      $response = drupal_http_request($this->getOriginalThumbnailPath());
      if (empty($response->error)) {
        file_unmanaged_save_data($response->data, $local_path, TRUE);
      }
      else {
        @copy($this->getOriginalThumbnailPath(), $local_path);
      }
    }
    return $local_path;
  }
}
