<?php

/**
 * @file
 * Contains MediaInternetUStreamHandler.
 */

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaInternetUStreamHandler extends MediaInternetBaseHandler {
  /**
   * Call the UStream API to fetch the video information.
   *
   * See http://developers.ustream.tv/broadcasting-api/
   *
   * @return
   *   Array of properties.
   */
  static public function getVideoProperties($id, $refresh = FALSE) {
    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:cid:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    // e.g. https://api.ustream.tv/videos/VIDEO_ID.FORMAT
    $response = drupal_http_request(MEDIA_USTREAM_REST_API . '/videos/' . $id . '.json');
    $data = drupal_json_decode($response->data);
    // Save our result to the cache array for our current key.
    $ids[$id] = $data;
    // Save our result to cache.
    cache_set('media_ustream:vid:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 604800)); // 604800 = 1 week.
    return $data;
  }

  /**
   * Call the UStream API to fetch the channel information.
   *
   * See http://developers.ustream.tv/broadcasting-api/
   *
   * @return
   *   Array of properties.
   */
  static public function getChannelProperties($id, $refresh = FALSE) {
    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:cid:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    // e.g. https://api.ustream.tv/channels/CHANNEL_ID.FORMAT
    $response = drupal_http_request(MEDIA_USTREAM_REST_API . '/channels/' . $id . '.json');
    $data = drupal_json_decode($response->data);
    $ids[$id] = $data;
    cache_set('media_ustream:cid:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 3600)); // 3600 = 1 hour.
    return $data;
  }

  /**
   * Call the UStream API to fetch the user information.
   *
   * See http://developers.ustream.tv/broadcasting-api/
   *
   * @return
   *   Array of properties.
   */
  static public function getUserProperties($id, $refresh = FALSE) {
    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:upid:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    // e.g. http://api.ustream.tv/json/user/[username]/getInfo
    $response = drupal_http_request(MEDIA_USTREAM_REST_API . '/json/user/' . $id . '.json');
    $data = drupal_json_decode($response->data);
    $ids[$id] = $data;
    cache_set('media_ustream:upid:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 3600));
    return $data;
  }

  /**
   * Call the UStream API to fetch the user ID.
   *
   * See http://developers.ustream.tv/broadcasting-api/
   *
   * @return
   *   Array with at least false or an array key with the uid.
   */
  static public function getUserID($username, $refresh = FALSE) {
    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:uid:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    // e.g. http://api.ustream.tv/json/user/[username]/getInfo
    $response = drupal_http_request(MEDIA_USTREAM_REST_API . '/json/user/' . $username . '/getUserId');
    $data = drupal_json_decode($response->data);
    $ids[$id] = $data;
    cache_set('media_ustream:uid:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 3600));
    return $data;
  }

  /**
   * Call the UStream API to fetch the user channel list.
   *
   * See http://developers.ustream.tv/broadcasting-api/
   *
   * @return
   *   Array with user channels.
   */
  static public function getUserChannels($id, $refresh = FALSE) {
    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:ucid:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    // e.g. https://api.ustream.tv/users/self/channels.FORMAT
    $response = drupal_http_request(MEDIA_USTREAM_REST_API . '/users/self/channels.json');
    $data = drupal_json_decode($response->data);
    $ids[$id] = $data;
    cache_set('media_ustream:ucid:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 3600));
    return $data;
  }

  /**
   * Check if a UStream video/channel id is valid.
   *
   * @param $id - The video or channel ID.
   * @param $type - A string, either 'live', 'recorded', 'user', or 'channeloruser'.
   *
   * @return
   *   array $properties.
   *
   * @throws
   *   MediaInternetValidationException - When the ID is invalid.
   */
  static public function validId($id, $type, $refresh = FALSE) {
    $ids = &drupal_static(__FUNCTION__, array(), array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:id:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    // Now lets validate per type.
    switch ($type) {
      case 'recorded':
        $properties = self::getVideoProperties($id);
        if (!empty($properties['error'])) {
          throw new MediaInternetValidationException(
              "The UStream video ID '$id' does not exist,
               is set to private, or has been deleted.");
        }
        break;

      case 'live':
        $properties = self::getChannelProperties($id);
        if (!empty($properties['error']) || $properties['channel']['title'] == NULL) {
          throw new MediaInternetValidationException(
              "The UStream channel ID '$id' does not exist,
               is set to private, or has been deleted.");
        }
        break;

      case 'user':
        $properties = self::getUserProperties($id);
        if (!empty($properties['error'])) {
          throw new MediaInternetValidationException(
              "The UStream user ID '$id' does not exist,
              is set to private, or has been deleted.");
        }
        break;

      case 'channeloruser':
        // Check if this is a channel.
        $properties = self::getChannelProperties(check_plain($id));
        // If we have an error, it isn't a channel and
        // we need to check for user channels.
        if (!empty($properties['error'])) {
          // Grab the clean oembed.
          $oembed = self::getViaOEmbed(check_plain($id));
          // Unknown user and channel, we will abort.
          if (!isset($oembed) || !empty($oembed['error'])) {
            throw new MediaInternetValidationException(
              "The UStream user or channel ID '$id' does not
               exist, is set to private, or has been deleted.");
          }
          // We need the last part of the author_url.
          $path = explode('/user/', $oembed['author_url']);
          // If this is not a channel, check if it's a user with channels.
          $user = self::getUserProperties($path[1]);
          // If it indeed IS a known user, continue, else trow an error.
          if (empty($user['error'])) {
            // Fetch user channels.
            $channels = self::getUserChannels(check_plain($user['channel']['id']));
            // Then fetch the user channel details.
            if (!$channels['error']) {
              // Search the channels for the current channel title.
              foreach($channels['channel'] as $key => $channel) {
                // TODO: This might work on all channels
                // sometimes the channel name isnt the same as the
                // listed name. Seen this on only 1 channel now.
                // But does need more testing/confirmation.
                if ($oembed['title'] == $channel['title']) {
                  $properties = self::getChannelProperties(check_plain($channels['channel'][$key]['id']));
                  // Add this as a value, because [0] wont do.
                  $properties['channel']['title'] = check_plain($channel['title']);
                  break;

                }
              }
            }
          }
          // Don't think this is ever called, because you
          // need at least one (1) channel as a user, but
          // still not sure, so i'll keep it in for now.
          else {
            throw new MediaInternetValidationException(
                      "The UStream user or channel ID '$id' does not
                      exist, is set to private, or has been deleted.");
          }
        }
        break;

    }
    // If we have a result, cache and return it, else return false.
    if (!empty($properties) && empty($properties['error'])) {
      // Now set the cache with our newly validated properties per id.
      $ids[$id] = $properties;
      cache_set('media_ustream:id:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 3600));
      return $properties;
    }
    return FALSE;
  }

  /**
   * Check if a UStream id is already stored in the DB.
   *
   * @param $id - The video or channel ID.
   * @param $type - A string, either 'live', 'recorded', 'user', or 'channeloruser'.
   *
   * @return
   *   Boolean.
   */
  static public function knownId($id, $type) {
    if ($type == 'channeloruser') {
      // TODO: PDO-dify this. (can EntityFieldQuery do this?)
      $result = db_query("SELECT fid FROM {file_managed}
                          WHERE REPLACE(filename, ' ', '') = '$id'");
      $data = $result->fetchAll();
      if (!empty($data[0])) {
        return $data[0]->fid;
      }
      return FALSE;
    }

    $file_query = new EntityFieldQuery;
    $result = $file_query->entityCondition('entity_type', 'file')
      ->propertyCondition('uri', "ustream://$type/$id")
      ->execute();

    if (!empty($result['file'])) {
      return key($result['file']);
    }
    return FALSE;
  }

  /**
   * Public function parse().
   */
  public function parse($embedCode) {
    $embedCode = trim($embedCode);

    // Patterns.
    $recorded_patterns = array(
      // Matches the URL for the video page.
      '@ustream\.tv/recorded/(\d+)@i'             => 'recorded',
      // Matches the URL from the embed code for recorded videos.
      '@ustream\.tv/embed/recorded/([^"\&\?]+)@i' => 'recorded',
      // Channel.
      '@ustream\.tv/channel/([a-zA-Z0-9_\-]+)@i'  => 'live',
      // Channel embed.
      '@ustream\.tv/embed/([^"\&\?]+)@i'          => 'live',
      // Matches the URL for the user page.
      '@ustream\.tv/user/([a-zA-Z0-9_\-]+)@i'     => 'user',
      // User channel or promoted channel.
      '@ustream\.tv/([a-zA-Z0-9_\-]+)$@i'         => 'channeloruser',
    );

    foreach ($recorded_patterns as $pattern => $type) {
      preg_match($pattern, $embedCode, $matches);
      // If a match was found, check if it's a video that's already saved,
      // locally before calling the API to see if it's a valid video id.
      if (!empty($matches[1])) {
        if ($fid = self::knownId(check_plain($matches[1]), $type)) {
          // No need to do anything, we already know this $embedCode.
          // Grab the file id, load the file and return normalized string.
          $existing_file = file_load($fid);
          $parts = explode('://', $existing_file->uri);
          // We already know the file exists so [1] Will be available.
          $file_uri = $parts[1];
        }
        // And if we do not know the id, try validating the id.
        // The validId() function also caches the result.
        elseif ($properties = self::validId(check_plain($matches[1]), $type)) {
          if (empty($properties['error'])) {
            $this->title = $properties['channel']['title'];
            $file_uri = $type . '/' . check_plain($properties['channel']['id']);
            if ($type == 'channeloruser') {
              $file_uri = 'live/' . check_plain($properties['channel']['id']);
            }
          }
        }

        // If we have a $file_uri, Use it.
        if (isset($file_uri)) {
          return file_stream_wrapper_uri_normalize('ustream://' . $file_uri);
        }
        else {
          // If the code ever gets to this point, something is really Wrong.
          // @TODO: rework this, add 'advanced help' support and
          // drop the readme in a form so we can add a (back) button
          // that redirects to something useful or something.
          // Maybe an inline modal would do the trick, triggered by the link
          // that only shows a small popup with the formats section.
          if (module_exists('help')) {
            $link = l("Media: UStream's README",
                      'help/media_ustream/README.txt');
          }
          else {
            $link = l("Media: UStream's README",
                      'sites/all/modules/media_ustream/README.txt');
          }
          $code = check_plain($matches[0]);
          drupal_set_message("Media: UStream cannot save $code, due to
                              limitations in UStream's API. Please refer to
                              $link under the URL FORMATS heading for more
                              information.", 'error', FALSE);
        }
      }
    }
  }

  /**
   * Function claim().
   */
  public function claim($embedCode) {
    if ($this->parse($embedCode)) {
      return TRUE;
    }
  }

  /**
   * Function getFileObject().
   */
  public function getFileObject() {
    if (empty($this->fileObject)) {
      $uri = $this->parse($this->embedCode);
      $this->fileObject = file_uri_to_object($uri, TRUE);
    }
    if (empty($this->fileObject->fid) && !empty($this->title)) {
      $this->fileObject->filename = truncate_utf8($this->title, 255);
    }
    return $this->fileObject;
  }

  /**
   * Returns information about the media. See http://www.oembed.com/.
   *
   * This function is only used for the special ustream channels which are
   * formatted like "www.ustream.tv/[channel]. We need it because UStream's
   * developer API is deficienct, and can't handle every [channel].
   */
  static public function getViaOEmbed($uri) {
    $id = $uri;
    $ids = &drupal_static(__FUNCTION__, array());
    if (!$refresh && isset($ids[$id])) {
      return $ids[$id];
    }
    elseif (!$refresh && $cache = cache_get('media_ustream:oembed:' . $id, 'cache_media_xml')) {
      $ids[$id] = $cache->data;
      return $ids[$id];
    }
    $oembed_url = 'http://www.ustream.tv/oembed?url=http%3A//ustream.tv/' . $uri . '&format=json';
    $response = drupal_http_request($oembed_url);
    $data = drupal_json_decode($response->data);
    if (empty($response->error)) {
      $ids[$id] = $data;
      cache_set('media_ustream:oembed:' . $id, $ids[$id], 'cache_media_xml', variable_get('media__xml_cache_expire', 3600));
      return $data;
    }
    return NULL;
  }
}
