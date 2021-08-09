<?php
/**
 * Created by PhpStorm.
 * User: bowens
 * Date: 04/04/16
 * Time: 21:34
 *


public static function register_autoloader() {
  spl_autoload_register(['SendGrid/Client', 'autoloader']);
  //spl_autoload_register(__NAMESPACE__ . '\Client::autoloader');
}

public function autoloader($class) {
  // Check that the class starts with 'SendGrid'
  if ($class == 'SendGrid' || stripos($class, 'SendGrid\\') === 0) {
    $file = str_replace('\\', '/', $class);

    if (file_exists(dirname(__FILE__) . '/' . $file . '.php')) {
      require_once(dirname(__FILE__) . '/' . $file . '.php');
    }
  }
}*/
