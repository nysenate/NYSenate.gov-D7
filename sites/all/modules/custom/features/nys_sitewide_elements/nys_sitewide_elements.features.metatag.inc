<?php

/**
 * @file
 * nys_sitewide_elements.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function nys_sitewide_elements_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'description' => array(
        'value' => '',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'fb:admins' => array(
        'value' => '',
      ),
      'fb:app_id' => array(
        'value' => '1567632026803489',
      ),
      'itemtype' => array(
        'value' => '',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'itemprop:description' => array(
        'value' => '',
      ),
      'itemprop:image' => array(
        'value' => '',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:determiner' => array(
        'value' => '',
      ),
      'og:description' => array(
        'value' => '',
      ),
      'og:updated_time' => array(
        'value' => '',
      ),
      'og:see_also' => array(
        'value' => '',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:secure_url' => array(
        'value' => '',
      ),
      'og:image:type' => array(
        'value' => '',
      ),
      'og:image:width' => array(
        'value' => '',
      ),
      'og:image:height' => array(
        'value' => '',
      ),
      'og:latitude' => array(
        'value' => '',
      ),
      'og:longitude' => array(
        'value' => '',
      ),
      'og:locality' => array(
        'value' => '',
      ),
      'og:region' => array(
        'value' => '',
      ),
      'og:email' => array(
        'value' => '',
      ),
      'og:phone_number' => array(
        'value' => '',
      ),
      'og:fax_number' => array(
        'value' => '',
      ),
      'og:locale' => array(
        'value' => '',
      ),
      'og:locale:alternate' => array(
        'value' => '',
      ),
      'article:author' => array(
        'value' => '',
      ),
      'article:publisher' => array(
        'value' => '',
      ),
      'article:section' => array(
        'value' => '',
      ),
      'article:tag' => array(
        'value' => '',
      ),
      'article:published_time' => array(
        'value' => '',
      ),
      'article:modified_time' => array(
        'value' => '',
      ),
      'article:expiration_time' => array(
        'value' => '',
      ),
      'profile:first_name' => array(
        'value' => '',
      ),
      'profile:last_name' => array(
        'value' => '',
      ),
      'profile:username' => array(
        'value' => '',
      ),
      'profile:gender' => array(
        'value' => '',
      ),
      'og:audio' => array(
        'value' => '',
      ),
      'og:audio:secure_url' => array(
        'value' => '',
      ),
      'og:audio:type' => array(
        'value' => '',
      ),
      'book:author' => array(
        'value' => '',
      ),
      'book:isbn' => array(
        'value' => '',
      ),
      'book:release_date' => array(
        'value' => '',
      ),
      'book:tag' => array(
        'value' => '',
      ),
      'og:video:secure_url' => array(
        'value' => '',
      ),
      'og:video:width' => array(
        'value' => '',
      ),
      'og:video:height' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => '',
      ),
      'video:actor' => array(
        'value' => '',
      ),
      'video:actor:role' => array(
        'value' => '',
      ),
      'video:director' => array(
        'value' => '',
      ),
      'video:writer' => array(
        'value' => '',
      ),
      'video:duration' => array(
        'value' => '',
      ),
      'video:release_date' => array(
        'value' => '',
      ),
      'video:tag' => array(
        'value' => '',
      ),
      'video:series' => array(
        'value' => '',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:site' => array(
        'value' => '',
      ),
      'twitter:site:id' => array(
        'value' => '',
      ),
      'twitter:creator' => array(
        'value' => '',
      ),
      'twitter:creator:id' => array(
        'value' => '',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title]',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:image:width' => array(
        'value' => '',
      ),
      'twitter:image:height' => array(
        'value' => '',
      ),
      'twitter:image0' => array(
        'value' => '',
      ),
      'twitter:image1' => array(
        'value' => '',
      ),
      'twitter:image2' => array(
        'value' => '',
      ),
      'twitter:image3' => array(
        'value' => '',
      ),
      'twitter:player' => array(
        'value' => '',
      ),
      'twitter:player:width' => array(
        'value' => '',
      ),
      'twitter:player:height' => array(
        'value' => '',
      ),
      'twitter:player:stream' => array(
        'value' => '',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => '',
      ),
      'twitter:app:country' => array(
        'value' => '',
      ),
      'twitter:app:name:iphone' => array(
        'value' => '',
      ),
      'twitter:app:id:iphone' => array(
        'value' => '',
      ),
      'twitter:app:url:iphone' => array(
        'value' => '',
      ),
      'twitter:app:name:ipad' => array(
        'value' => '',
      ),
      'twitter:app:id:ipad' => array(
        'value' => '',
      ),
      'twitter:app:url:ipad' => array(
        'value' => '',
      ),
      'twitter:app:name:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:id:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:url:googleplay' => array(
        'value' => '',
      ),
      'twitter:label1' => array(
        'value' => '',
      ),
      'twitter:data1' => array(
        'value' => '',
      ),
      'twitter:label2' => array(
        'value' => '',
      ),
      'twitter:data2' => array(
        'value' => '',
      ),
      'twitter:image' => array(
        'value' => '',
      ),
      'og:video:url' => array(
        'value' => '',
      ),
      'og:street_address' => array(
        'value' => '',
      ),
      'og:postal_code' => array(
        'value' => '',
      ),
      'og:country_name' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => 'The New York State Senate',
      ),
      'description' => array(
        'value' => 'NYSenate.gov is designed to increase public participation in the legislative process. By facilitating efficient communication between individual New Yorkers and the senators who represent them, lawmakers are able to craft a better set of laws by which we are governed.',
      ),
      'keywords' => array(
        'value' => 'government, legislation, bills, laws, new york, public policy',
      ),
      'rating' => array(
        'value' => 'general',
      ),
      'image_src' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/dsc_0419.jpg',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'geo.position' => array(
        'value' => '42.651401,-73.757339',
      ),
      'geo.placename' => array(
        'value' => 'New York State Capitol',
      ),
      'geo.region' => array(
        'value' => 'US-NY',
      ),
      'icbm' => array(
        'value' => '42.651401,-73.7611643',
      ),
      'itemtype' => array(
        'value' => 'Organization',
      ),
      'itemprop:name' => array(
        'value' => 'The New York State Senate',
      ),
      'itemprop:description' => array(
        'value' => 'Connect with elected members of the New York State Legislature. Review changes to the laws of New York, and share your reaction with your representative.',
      ),
      'itemprop:image' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/dsc_0419.jpg',
      ),
      'og:type' => array(
        'value' => 'government',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'og:title' => array(
        'value' => 'The New York State Senate',
      ),
      'og:determiner' => array(
        'value' => 'auto',
      ),
      'og:description' => array(
        'value' => 'Connect with elected members of the New York State Legislature. Review changes to the laws of New York, and share your reaction with your representative.',
      ),
      'og:updated_time' => array(
        'value' => '[site:current-date:year_only]-[site:current-date:month_only]-[site:current-date:day_only]',
      ),
      'og:see_also' => array(
        'value' => 'http://www.ny.gov,http://assembly.state.ny.us',
      ),
      'og:image' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/dsc_0419.jpg',
      ),
      'og:image:secure_url' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/dsc_0419.jpg',
      ),
      'og:image:type' => array(
        'value' => 'image/jpeg',
      ),
      'og:image:width' => array(
        'value' => 1280,
      ),
      'og:image:height' => array(
        'value' => 510,
      ),
      'og:latitude' => array(
        'value' => 42.651401,
      ),
      'og:longitude' => array(
        'value' => -73.7611643,
      ),
      'og:street_address' => array(
        'value' => 'State Street and Washington Avenue',
      ),
      'og:locality' => array(
        'value' => 'Albany',
      ),
      'og:region' => array(
        'value' => 'NY',
      ),
      'og:postal_code' => array(
        'value' => 11224,
      ),
      'og:country_name' => array(
        'value' => 'United States of America',
      ),
      'og:phone_number' => array(
        'value' => '+1 (518) 455-2800',
      ),
      'twitter:card' => array(
        'value' => 'summary_large_image',
      ),
      'twitter:site' => array(
        'value' => '@nysenate',
      ),
      'twitter:site:id' => array(
        'value' => 20419776,
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => 'The New York State Senate',
      ),
      'twitter:description' => array(
        'value' => 'Connect with elected members of the New York State Legislature. Review changes to the laws of New York, and share your reaction with your representative.',
      ),
      'twitter:image' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/dsc_0419.jpg',
      ),
      'twitter:image:width' => array(
        'value' => 1280,
      ),
      'twitter:image:height' => array(
        'value' => 510,
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'itemprop:description' => array(
        'value' => '[node:summary]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'og:image' => array(
        'value' => '[node:field_image_main]',
      ),
      'og:image:width' => array(
        'value' => 1200,
      ),
      'og:image:height' => array(
        'value' => 1200,
      ),
      'article:published_time' => array(
        'value' => '[node:created:custom:c]',
      ),
      'article:modified_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:summary]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_image_main]',
      ),
    ),
  );

  // Exported Metatag config instance: node:article.
  $config['node:article'] = array(
    'instance' => 'node:article',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '',
      ),
      'itemprop:description' => array(
        'value' => '',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:width' => array(
        'value' => '',
      ),
      'og:image:height' => array(
        'value' => '',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:image' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node:event.
  $config['node:event'] = array(
    'instance' => 'node:event',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '',
      ),
      'itemprop:description' => array(
        'value' => '',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:width' => array(
        'value' => '',
      ),
      'og:image:height' => array(
        'value' => '',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:image' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node:petition.
  $config['node:petition'] = array(
    'instance' => 'node:petition',
    'disabled' => FALSE,
    'config' => array(
      'og:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_petitions_share.png',
      ),
      'og:image:secure_url' => array(
        'value' => 'https://www.nysenate.gov/sites/default/files/ny_senate_petitions_share.png',
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
        'value' => 'NYS Petition: [node:title]',
      ),
      'twitter:image:width' => array(
        'value' => 1200,
      ),
      'twitter:image:height' => array(
        'value' => 1200,
      ),
      'twitter:image' => array(
        'value' => 'http://www.nysenate.gov/sites/default/files/ny_senate_petitions_share.png',
      ),
    ),
  );

  // Exported Metatag config instance: node:press_release.
  $config['node:press_release'] = array(
    'instance' => 'node:press_release',
    'disabled' => FALSE,
    'config' => array(
      'description' => array(
        'value' => '',
      ),
      'itemprop:description' => array(
        'value' => '',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:width' => array(
        'value' => '',
      ),
      'og:image:height' => array(
        'value' => '',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:image' => array(
        'value' => '',
      ),
      'twitter:image:width' => array(
        'value' => 1200,
      ),
      'twitter:image:height' => array(
        'value' => 1200,
      ),
    ),
  );

  // Exported Metatag config instance: node:resolution.
  $config['node:resolution'] = array(
    'instance' => 'node:resolution',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => 'NY Senate Resolution | [site:name]',
      ),
      'description' => array(
        'value' => '[node:field_ol_name]',
      ),
      'abstract' => array(
        'value' => '[node:field_ol_name]',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'og:description' => array(
        'value' => '[node:field_ol_name]',
      ),
      'og:image' => array(
        'value' => '/sites/default/files/ny_senate_resolutions_share2.jpg',
      ),
      'og:image:secure_url' => array(
        'value' => '/sites/default/files/ny_senate_resolutions_share2.jpg',
      ),
      'og:image:type' => array(
        'value' => 'image/jpg',
      ),
      'og:image:width' => array(
        'value' => 1200,
      ),
      'og:image:height' => array(
        'value' => 1200,
      ),
      'og:latitude' => array(
        'value' => 42.652835,
      ),
      'og:longitude' => array(
        'value' => -73.757339,
      ),
      'og:street_address' => array(
        'value' => 'State St. and Washington Ave',
      ),
      'og:locality' => array(
        'value' => 'Albany',
      ),
      'og:region' => array(
        'value' => 'NY',
      ),
      'og:postal_code' => array(
        'value' => 12210,
      ),
      'og:country_name' => array(
        'value' => 'United States of America',
      ),
      'twitter:creator' => array(
        'value' => '@nysenate',
      ),
      'twitter:title' => array(
        'value' => 'Resolution: [node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_ol_name]',
      ),
      'twitter:image' => array(
        'value' => '/sites/default/files/ny_senate_resolutions_share2.jpg',
      ),
      'twitter:image:width' => array(
        'value' => 1000,
      ),
      'twitter:image:height' => array(
        'value' => 1000,
      ),
      'twitter:image:alt' => array(
        'value' => 'New York Senate Resolution',
      ),
    ),
  );

  // Exported Metatag config instance: node:senator.
  $config['node:senator'] = array(
    'instance' => 'node:senator',
    'disabled' => FALSE,
    'config' => array(
      'og:title' => array(
        'value' => 'Senator [node:title]',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'description' => array(
        'value' => '[term:description]',
      ),
      'itemprop:description' => array(
        'value' => '[term:description]',
      ),
      'itemprop:name' => array(
        'value' => '[term:name]',
      ),
      'og:description' => array(
        'value' => '[term:description]',
      ),
      'og:title' => array(
        'value' => '[term:name]',
      ),
      'twitter:description' => array(
        'value' => '[term:description]',
      ),
      'twitter:title' => array(
        'value' => '[term:name]',
      ),
    ),
  );

  return $config;
}
