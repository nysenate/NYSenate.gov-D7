<?php

/**
 * @file
 * nys_cms.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function nys_cms_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Help text for internal users';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'dashboard_help_text';
  $fe_block_boxes->body = '<p>Please visit&nbsp;<a href="http://webforum.nysenate.gov">http://webforum.nysenate.gov</a>&nbsp;for&nbsp;announcements, best practices, release notes&nbsp;and frequently asked questions.</p>

<p>You can also create a feature request by navigating to&nbsp;<a href="http://webforum.nysenate.gov/c/feature-requests">http://webforum.nysenate.gov/c/feature-requests</a>&nbsp;and clicking "New Topic".</p>

<p>[[{"fid":"1712001","view_mode":"media_original","fields":{"format":"media_original","field_file_image_alt_text[und][0][value]":false,"field_file_image_title_text[und][0][value]":false},"type":"media","link_text":null,"field_deltas":{"1":{"format":"media_original","field_file_image_alt_text[und][0][value]":false,"field_file_image_title_text[und][0][value]":false}},"attributes":{"height":"1944","width":"2592","style":"width: 250px; height: 188px;","class":"media-element file-media-original","data-delta":"1"}}]]</p>

<p>Need help immediately? You can always call the STS Help Line at x2011</p>
';

  $export['dashboard_help_text'] = $fe_block_boxes;

  return $export;
}
