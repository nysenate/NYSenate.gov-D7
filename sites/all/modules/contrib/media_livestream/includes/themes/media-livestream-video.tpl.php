<?php

/**
 * @file
 * The media_livestream/includes/themes/media-livestream-video.tpl.php file.
 *
 * Template file for theme('media_livestream_video').
 *
 * Variables available:
 *  $uri - The media uri for the Livestream video.
 *    (e.g., livestream://123456).
 *  $video_id - The unique identifier of the Livestream video.
 *    (e.g., 123456).
 *  $id - The file entity ID (fid).
 *  $url - The full url including query options for the Livestream iframe.
 *  $width - The width value set in Media: Livestream file display options.
 *  $height - The height value set in Media: Livestream file display options.
 *  $title - The title of the Livestream video.
 *  $alternative_content - Text to display for browsers that don't support
 *  iframes.
 */

?>
<div class="<?php print $classes; ?> media-livestream-<?php print $video_id; ?>">
  <iframe
    class="media-livestream-player"
    width="<?php print $width; ?>"
    height="<?php print $height; ?>"
    title="<?php print $video_title; ?>"
    src="<?php print $url; ?>"
    style="border: 0">
    <?php print $alternative_content; ?>
  </iframe>
</div>
