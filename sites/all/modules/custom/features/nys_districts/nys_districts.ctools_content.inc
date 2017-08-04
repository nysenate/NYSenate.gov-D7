<?php
/**
 * @file
 * nys_districts.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function nys_districts_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'district_map';
  $content->admin_title = 'District Map';
  $content->admin_description = 'District Map Embed';
  $content->category = '';
  $content->settings = array(
    'admin_title' => 'District Map',
    'title' => '',
    'body' => '<div class="c-block"><iframe class="iframe-delta-0" frameborder="0" height="414" id="iframe-0" name="iframe-0" scrolling="no" src="%term:field-map-url" transparency="0" width="100%">Your browser does not support iframes. But You can use the following link. &amp;amp;amp;amp;amp;amp;amp;amp;amp;lt;a href=&amp;amp;amp;amp;amp;amp;amp;quot;%term:field-map-url&amp;amp;amp;amp;amp;amp;amp;quot; title=&amp;amp;amp;amp;amp;amp;amp;quot;&amp;amp;amp;amp;amp;amp;amp;quot;&amp;amp;amp;amp;amp;amp;amp;amp;amp;gt;Link&amp;amp;amp;amp;amp;amp;amp;amp;amp;lt;/a&amp;amp;amp;amp;amp;amp;amp;amp;amp;gt;</iframe></div>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['district_map'] = $content;

  return $export;
}
