<?php
/**
 * @file
 * nys_sitewide_elements.features.media_wysiwyg.inc
 */

/**
 * Implements hook_media_wysiwyg_defaults().
 */
function nys_sitewide_elements_media_wysiwyg_defaults() {
  $media_wysiwyg = array();

  // WYSIWYG view mode for image files.
  $media_wysiwyg['image_wysiwyg_view_mode'] = 'none';

  // Restricted view modes for image files.
  $media_wysiwyg['image_teaser_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_full_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_preview_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_media_link_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_media_original_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_wysiwyg_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_media_landscape_image_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_media_portrait_image_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_default_restrict_wysiwyg'] = TRUE;

  return $media_wysiwyg;
}
