<?php
/**
 * @file
 * nys_legislation.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function nys_legislation_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:bill.
  $config['node:bill'] = array(
    'instance' => 'node:bill',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => 'NY State [node:field_ol_chamber] Bill [node:title]',
      ),
      'description' => array(
        'value' => '[node:field_ol_summary]',
      ),
      'canonical' => array(
        'value' => '[site:url]/legislation/bills/[node:field_ol_session]/[node:field_ol_base_print_no]',
      ),
      'og:title' => array(
        'value' => 'NY State [node:field_ol_chamber] Bill [node:title]',
      ),
      'og:description' => array(
        'value' => '[node:field_ol_summary]',
      ),
      'og:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_bill_share2.png',
      ),
      'og:image:secure_url' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/ny_senate_bill_share2.png',
      ),
      'og:image:type' => array(
        'value' => 'image/png',
      ),
      'og:image:width' => array(
        'value' => 1200,
      ),
      'og:image:height' => array(
        'value' => 1200,
      ),
      'twitter:card' => array(
        'value' => 'summary_large_image',
      ),
      'twitter:creator' => array(
        'value' => '@nysenate',
      ),
      'twitter:title' => array(
        'value' => 'NY State [node:field_ol_chamber] Bill [node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_ol_summary]',
      ),
      'twitter:image:width' => array(
        'value' => 1200,
      ),
      'twitter:image:height' => array(
        'value' => 1200,
      ),
      'twitter:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_bill_share2.png',
      ),
    ),
  );

  return $config;
}
