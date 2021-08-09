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

  // WYSIWYG view mode for document files.
  $media_wysiwyg['document_wysiwyg_view_mode'] = 'default';

  // Restricted view modes for document files.
  $media_wysiwyg['document_wysiwyg_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['document_default_restrict_wysiwyg'] = FALSE;

  // WYSIWYG view mode for image files.
  $media_wysiwyg['image_wysiwyg_view_mode'] = 'wysiwyg';

  // Restricted view modes for image files.
  $media_wysiwyg['image_teaser_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_full_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_preview_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_media_link_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_media_original_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_wysiwyg_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['image_landscape_inline_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_media_landscape_image_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_media_portrait_image_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_media_signature_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_portrait_inline_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_square_image_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_default_restrict_wysiwyg'] = TRUE;

  return $media_wysiwyg;
}
