<?php

/**
 * @file
 * API documentation for the message broker module.
 */

/**
 * Registers consumers in the message broker.
 *
 * Specify the queues you want to consume and your callback.
 * The given callback is called with two parameters: body and ack, a callable
 * method you use to ack the incoming message.
 * Optional, you can specify an invalidMessageHandler that reveives invalid
 * messages.
 *
 * @param string $self_name
 *   Name of this drupal instance.
 *
 * @return array
 *   Consumers to register.
 */
function hook_message_broker_consumers($self_name) {
  $consumers = array();

  $consumers['consumer_' . $self_name] = array(
    'queue' => 'foo' . $self_name,
    'callback' => 'mymodule_consume_message',
    'invalidMessageHandler' => 'mymodule_log_invalid_message');

  return $consumers;
}

/**
 * Consumes one message.
 *
 * @param mixed $message
 *   The message to consume.
 * @param callable $ack
 *   Call this method for acking the message.
 */
function mymodule_consume_message($message, $ack) {
  // Process and ack message.
  $ack();
}

/**
 * Invalid message callback function.
 *
 * This callback is executed whenever a consumer throws an
 * InvalidMessageException. The message broker module catches
 * these exceptions, acks the message and allows to handle the invalid data on
 * your own.
 *
 * @param mixed $message
 *   Invalid message.
 *
 * @param InvalidMessageException $invalid_message_exception
 *   The exception that was raised.
 */
function mymodule_log_invalid_message($message, InvalidMessageException $invalid_message_exception) {
  // Log message for instance to a file.
}

/**
 * Registers a message broker implementation.
 *
 * Describe the implementation via a title, description and a factoryMethod.
 * The latter one shall return an instance that implements the
 * MessageBrokerInterface.
 *
 * @return array
 *   Implementations.
 */
function hook_message_broker_implementation() {
  $implementations = array();

  $implementations['foo'] = array(
    'title' => t('Foo'), 'factoryMethod' => 'mymodule_create_implementation',
    'description' => t('A message broker implementation'));

  return $implementations;
}

/**
 * Creates an instance of the MessageBrokerInterface.
 *
 * @param array $consumers
 *   The registered consumers.
 * @param string $self_name
 *   Name of this drupal instance.
 */
function mymodule_create_implementation($consumers, $self_name) {
  // Return instance of MessageBrokerInterface.
}
