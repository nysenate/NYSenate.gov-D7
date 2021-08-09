<?php

/**
 * @file
 * API documentation for the HTML Purifier module.
 */

/**
 * Implements hook_htmlpurifier_info().
 */
function hook_htmlpurifier_info() {
  return array(
      'htmlpurifier_basic' => array(
        'name' => 'HTML Purifier Basic',
        'description' => 'A simple and sane configuration',
        'allowed' => array(
          'URI.DisableExternalResources',
          'URI.DisableResources',
          'URI.Munge',
          'Attr.EnableID',
          'HTML.Allowed',
          'HTML.ForbiddenElements',
          'HTML.ForbiddenAttributes',
          'HTML.SafeObject',
          'Output.FlashCompat',
          'AutoFormat.RemoveEmpty',
          'AutoFormat.Linkify',
          'AutoFormat.AutoParagraph',
        ),
        'weight' => -20,
    ),
  );
}

/**
 * Implements hook_htmlpurifier_info_alter().
 */
function hook_htmlpurifier_info_alter(&$infos) {
  unset($infos['htmlpurifier_basic']['allowed']['URI.Munge']);
}

/**
 * Implements hook_htmlpurifier_html_definition_alter().
 *
 * Allows modules to alter the HTML Definition used by HTML Purifier.
 *
 * @param HTMLPurifier_HTMLDefinition $html_definition
 *   The HTMLPurifier definition object to alter.
 */
function hook_htmlpurifier_html_definition_alter($html_definition) {
  // Allow to use the 'data-type' attribute on images.
  $html_definition->addAttribute('img', 'data-type', 'Text');
}
