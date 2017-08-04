<?php

require_once 'consumer_logger_interface.inc';

/**
 * @file
 * Drush implementation of ConsumerLoggerInterface.
 */

/**
 * DrushConsumerLogger that prints messages to the console.
 */
class DrushConsumerLogger implements ConsumerLoggerInterface {

  /**
   * Logs an info message.
   *
   * @param string $message
   *   The message to log.
   */
  public function logInfo($message) {
    drush_print($message);
  }

  /**
   * Logs an error message.
   *
   * @param string $message
   *   The message to log.
   */
  public function logError($message) {
    return drush_print('Error (' . date('d.m.Y H:i') . '): ' . $message);
  }

}
