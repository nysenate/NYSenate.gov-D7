<?php

/**
 * @file
 * Contains MediaInternetLivestreamHandler.
 */

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaInternetLivestreamHandler extends MediaInternetBaseHandler {
  /**
   * Call the Livestream API to fetch the video information.
   *
   * See http://developer.livestream.tv/data_api/docs
   *
   * @return
   *   Array of properties.
   */
  static public function getVideoProperties($cid, $vid) {
    // e.g. http://xproshowcasex.api.channel.livestream.com/2.0/clipdetails.json?id=pla_1145907244544877845
    $response = drupal_http_request('http://x'.$cid.'x.' . MEDIA_LIVESTREAM_REST_CHANNEL_API . 'clipdetails.json?id='.$vid);
    return drupal_json_decode($response->data);
  }

  /**
   * Call the Livestream API to fetch the channel information.
   *
   * See http://developer.livestream.tv/data_api/docs
   *
   * @return
   *   Array of properties.
   */
  static public function getChannelProperties($cid) {
    // e.g. http://api.livestream.tv/json/channel/api-test-show/getInfo
    $response = drupal_http_request('http://x'.$cid.'x.' . MEDIA_LIVESTREAM_REST_CHANNEL_API . 'info.json');
    return drupal_json_decode($response->data);
  }

  /**
   * Check if a Livestream video/channel id is valid.
   *
   * @param $id - The video or channel ID.
   * @param $type - A string, either 'live' or 'recorded'.
   *
   * @return
   *   Boolean.
   *
   * @throws
   *   MediaInternetValidationException - When the ID is invalid.
   */
  static public function validId($cid, $vid, $type) {
    switch($type) {
      case 'video':
        $video_properties = self::getVideoProperties($cid, $vid);
        if (empty($video_properties['channel']['item'][0])) {
          self::showError();
          return FALSE;
        }
        break;

      case 'channel':
        $video_properties = self::getChannelProperties($cid);
        if (empty($video_properties) || !empty($video_properties['error'])) {
          self::showError();
          return FALSE;
        }
        break;

    }
    return $video_properties;
  }
  /**
   * Check if a Livestream id is already stored in the DB.
   *
   * @param $id - The video or channel ID.
   * @param $type - A string, either 'live' or 'recorded'.
   *
   * @return
   *   Boolean.
   */
  static public function knownId($condition) {
    $file_query = new EntityFieldQuery;
    $results = $file_query->entityCondition('entity_type', 'file')
      ->propertyCondition('uri', "livestream://$condition")
      ->execute();

    return (bool)$results;
  }

  /**
   * Parse the embed code provided by the user.
   */
  public function parse($embedCode) {
    $embedCode = trim($embedCode);
    $match = FALSE;

    // The Livestream short code.
    if (!$match && preg_match('@livestre\.am/([0-9a-zA-Z\-]+)$@i', $embedCode, $matches)) {
      $headers = media_livestream_get_short_code($matches[0]);
      $embedCode = $headers['url'];
    }

    // This one checks for a channel.
    // E.g. livestream.com/channelname.
    if (!$match && preg_match('@livestream\.com/([0-9a-zA-Z\-]+)$@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'channel';
      $channel_id = $matches[1];
      $video_id = $matches[1];
    }
    // This one checks for a channel iframe.
    // E.g. livestream.com/embed/channelname. (And no clip (id) set).
    elseif (!$match && preg_match('@livestream\.com/embed/([0-9a-zA-Z\-]+)?((?!clip|clipId).)*$@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'channel';
      $channel_id = $matches[1];
      $video_id = $matches[1];
    }

    // This one works for 'video' and 'share' on a new style link.
    // E.g. livestream.com/channelname/video(or)share/clip(id).
    elseif (!$match && preg_match('@livestream\.com/([0-9a-zA-Z\-]+).*/(video|share).*((clipId|clip)=([^\&\'" ]+))@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'video';
      $channel_id = $matches[1];
      $video_id = $matches[5];
    }

    // This one matches the new iframe embed for videos.
    // E.g. livestream.com/embed/channelname/clip(id).
    elseif (!$match && preg_match('@livestream\.com/(embed)/([0-9a-zA-Z\-]+).*((clipId|clip)=([^\&\'" ]+))@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'video';
      $channel_id = $matches[2];
      $video_id = $matches[5];
    }

    // This one also checks for a channel, but this link is almost never used, but it does exist.
    // E.g. livestream.com/channelname/share.
    elseif (!$match && preg_match('@livestream\.com/([0-9a-zA-Z\-]+)/(share)@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'channel';
      $channel_id = $matches[1];
      $video_id = $matches[1];
    }

    // This one matches the old flash embed for videos.
    // E.g. livestream.com/grid/LSPlayer.swf?channel=channelname/clip(id).
    elseif (!$match && preg_match('@livestream\.com/(grid)/LSPlayer.swf\?(channel)=([0-9a-zA-Z\-]+)&amp;(clipId|clip)=([^\&\'" ]+)@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'video';
      $channel_id = $matches[3];
      $video_id = $matches[5];
    }

    // This one matches the old flash embed for channels.
    // E.g. livestream.com/grid/LSPlayer.swf?channel=channelname.
    elseif (!$match && preg_match('@livestream\.com/grid/LSPlayer\.swf.?channel=([0-9a-zA-Z\-]+)@i', $embedCode, $matches)) {
      $match = TRUE;
      $this->type = 'channel';
      $channel_id = $matches[1];
      $video_id = $matches[1];
    }

    // We have a match!
    if ($match) {
      switch ($this->type) {
        case 'channel':
          if ($result = self::knownId($video_id)) {
            return file_stream_wrapper_uri_normalize('livestream://' . $video_id);
          }
          elseif (self::validId($video_id, FALSE, 'channel')) {
            $properties = self::getChannelProperties($video_id);
            $this->cid = $cid = $video_id;
            $this->title = $properties['channel']['title'];
            $file_string = $cid;
          }
          break;

        case 'video':
          if ($result = self::knownId($channel_id . '/' . $video_id)) {
            return file_stream_wrapper_uri_normalize('livestream://' . $video_id . '/' . $matches[5]);
          }
          if (self::validId($channel_id, $video_id, 'video')) {
            $properties = self::getVideoProperties($channel_id, $video_id);
            $this->cid = $cid = $channel_id;
            $this->vid = $vid = $video_id;
            $this->title = $this->video_title = $properties['channel']['item'][0]['title'] . ' - ' . $properties['channel']['title'];
            $file_string = $cid . '/' . $vid;
          }
          break;

      }

      // And then finally, return the normalized file uri.
      return file_stream_wrapper_uri_normalize('livestream://' . $file_string);
    }
    // If we don not have a match, set some useful info.
    // People should never reach this, but if they do:
    else {
      return self::showError();
    }
  }

  /**
   * Throws an error when a link does not exist and provides possible useful info.
   */
  public function showError() {
    // Get the embed code the user tried to post.
    if (!empty($GLOBALS['_POST']['embed_code'])) {
      $embedCode = $GLOBALS['_POST']['embed_code'];
    }
    else {
      $embedCode = t('UNKNOWN');
    }

    // Help link.
    $link = l("Media: Livestream's README", 'sites/all/modules/media_livestream/README.txt');

    throw new MediaInternetValidationException(
      "Media: Livestream cannot save <b>$embedCode</b>, due to limitations in the Livestream's API.
      <br /><br />Please refer to $link under the URL FORMATS heading for more information.");

    return FALSE;
  }

  public function claim($embedCode) {
    if ($this->parse($embedCode)) {
      return TRUE;
    }
  }

  public function getFileObject() {
    $uri = $this->parse($this->embedCode);
    $file = file_uri_to_object($uri, TRUE);
    $file->filename = truncate_utf8($this->title, 255);

    return $file;
  }

  /**
   * Returns information about the media. See http://www.oembed.com/.
   *
   * @return
   *   False, not supported (yet) by Livestream.
   */
  public function getOEmbed() {
    return FALSE;
  }
}

