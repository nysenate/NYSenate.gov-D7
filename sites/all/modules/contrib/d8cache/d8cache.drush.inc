<?php

/**
 * @file
 * Drush hooks for d8cache.
 */

/**
 * Implements hook_drush_command().
 */
function d8cache_drush_command() {

  $commands['invalidate-cache-tags'] = array(
    'description' => 'Invalidates the specified cache tags.',
    'aliases' => array('ict'),
    'arguments' => array(
      'tags' => 'A list of tags seperated by ",".',
    ),
    'examples' => array(
      'drush ict rendered' => 'Invalidate the "rendered" cache tag.',
      'drush ict node:1,node:2' => 'Invalidate the "node:1" and "node:2" cache tags.',
    ),
  );

  return $commands;
}

/**
 * Drush command logic.
 *
 * Implements drush_[COMMAND_NAME]().
 */
function drush_d8cache_invalidate_cache_tags($tags = '') {
  $tags = array_map('trim', explode(',', $tags));
  $tags = array_filter($tags);
  if (!empty($tags)) {
    drupal_invalidate_cache_tags($tags);
    drush_log(dt('Succesfully invalidated the following cache tags: !tags', array('!tags' => implode(',', $tags))), 'success');
  }
  else {
    $error = dt('The list of cache tags to invalidate must not be empty.');
    drush_log($error, 'error');
  }
}
