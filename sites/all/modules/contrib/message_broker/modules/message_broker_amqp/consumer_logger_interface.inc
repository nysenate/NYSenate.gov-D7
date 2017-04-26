<?php

/**
 * @file
 * Interface for a Logger that reports consuming infos.
 */

/**
 * Represents a logger that outputs info and error strings while consuming
 * message broker messages.
 */
interface ConsumerLoggerInterface {

  /**
   * Logs an info message.
   *
   * @param string $message
   *   Message to log.
   */
  public function logInfo($message);

  /**
   * Logs an error message.
   *
   * @param string $message
   *   Message to log.
   */
  public function logError($message);
}
