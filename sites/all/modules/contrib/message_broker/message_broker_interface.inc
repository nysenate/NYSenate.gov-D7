<?php

/**
 * @file
 * Definition of generic message broker interface.
 */

/**
 * Represents the message broker, that may be implemented via AQMP or any
 * other protocol.
 */
interface MessageBrokerInterface {

  /**
   * Sends a message to the message broker.
   *
   * @param string $body
   *   Message body.
   * @param string $destination
   *   Destination of message.
   * @param array $options
   *   Further messasge options.
   */
  public function sendMessage($body, $destination, array $options = array());
}
