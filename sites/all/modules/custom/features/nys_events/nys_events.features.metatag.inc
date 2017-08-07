<?php
/**
 * @file
 * nys_events.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function nys_events_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:session.
  $config['node:session'] = array(
    'instance' => 'node:session',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => 'NY Senate Session | [node:field-date:value:long]',
      ),
      'description' => array(
        'value' => 'Official floor proceedings of the NY State Senate for [node:field-date:long]',
      ),
      'abstract' => array(
        'value' => 'Official floor proceedings of the NY State Senate for [node:field-date:long]',
      ),
      'itemtype' => array(
        'value' => 'Event',
      ),
      'itemprop:name' => array(
        'value' => 'NY Senate Session |[node:field-date:long]',
      ),
      'itemprop:description' => array(
        'value' => 'Proceedings of the NY State Session for [node:field_date].',
      ),
      'itemprop:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_session_share.png',
      ),
      'og:type' => array(
        'value' => 'activity',
      ),
      'og:title' => array(
        'value' => 'Floor Proceedings - [node:field-date:value:long] - The New York State Senate',
      ),
      'og:description' => array(
        'value' => 'Floor proceedings of the NY State Senate for [node:field-date:value:long]',
      ),
      'og:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_session_share.png',
      ),
      'og:image:secure_url' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/ny_senate_session_share.png',
      ),
      'og:image:type' => array(
        'value' => 'image/png',
      ),
      'og:image:width' => array(
        'value' => 5000,
      ),
      'og:image:height' => array(
        'value' => 5000,
      ),
      'og:latitude' => array(
        'value' => 42.652835,
      ),
      'og:longitude' => array(
        'value' => -73.757339,
      ),
      'og:locality' => array(
        'value' => 'Albany',
      ),
      'og:region' => array(
        'value' => 'NY',
      ),
      'twitter:card' => array(
        'value' => 'summary_large_image',
      ),
      'twitter:creator' => array(
        'value' => '@nysenate',
      ),
      'twitter:title' => array(
        'value' => 'NY Senate - Floor Proceedings - [node:field-date:value:long]',
      ),
      'twitter:description' => array(
        'value' => 'Floor proceedings of the NY State Session for [node:field-date:value:long].',
      ),
      'twitter:image:width' => array(
        'value' => 5000,
      ),
      'twitter:image:height' => array(
        'value' => 5000,
      ),
      'og:street_address' => array(
        'value' => 'State St. and Washington Ave',
      ),
      'og:postal_code' => array(
        'value' => 12210,
      ),
      'og:country_name' => array(
        'value' => 'United States of America',
      ),
      'twitter:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_session_share.png',
      ),
    ),
  );

  return $config;
}
