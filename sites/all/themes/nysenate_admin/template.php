<?php

/**
 * @file
 * This file contains the main theme functions hooks and overrides.
 */

/**
 * Override or insert variables into the html template.
 */
function nysenate_admin_preprocess_html(&$vars) {
  /* Commented until such time as we have a need for custom admin style. */
  /*
    $ny_adminimal_path = drupal_get_path('theme', 'nysenate_admin');

    // Add custom styles.
    drupal_add_css($ny_adminimal_path . '/css/nysenate_admin.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 1));
  */
}
