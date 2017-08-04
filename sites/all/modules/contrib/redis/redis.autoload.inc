<?php

/**
 * @file
 * Redis module autoloader.
 */

/**
 * Autoloader micro optimization, work with constant as much as we can.
 */
define('REDIS_ROOT', dirname(__FILE__) . '/lib');

/**
 * Redis module specific autoloader, compatible with spl_register_autoload().
 */
function redis_autoload($class_name) {
  if ('Redis' === substr($class_name, 0, 5)) {
    $filename = REDIS_ROOT . '/' . str_replace('_', '/', $class_name) . '.php';
    return @include_once $filename;
  }
  return FALSE;
}

// Register our custom autoloader.
spl_autoload_register('redis_autoload');
