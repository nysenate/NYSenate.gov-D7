<?php

require_once dirname(__FILE__) . '/../../message_broker_interface.inc';

/**
 * @file
 * Dummy implementation of MessageBrokerInterface.
 */

/**
 * Dummy implementation of the MessageBrokerInterface.
 */
class DummyMessageBroker implements MessageBrokerInterface {

  protected $consumers;
  protected $queues;
  protected $exchanges;

  /**
   * Creates the dummy message broker implementation.
   *
   * @param array $config
   *   Configuration.
   * @param array $consumers
   *   Consumers.
   */
  public function __construct($config, $consumers) {
    $this->exchanges = $config['exchanges'];
    $this->queues = $config['queues'];
    $this->consumers = $consumers;
  }

  /**
   * Finds exchange information by name.
   *
   * @param string $exchange_name
   *   Name of exchange.
   *
   * @return mixed
   *   Exchange array or FALSE.
   */
  protected function findExchangeByName($exchange_name) {
    foreach ($this->exchanges as $exchange) {
      if ($exchange['name'] == $exchange_name) {
        return $exchange;
      }
    }

    return FALSE;
  }

  /**
   * Sends a message to the message broker.
   *
   * @param string $body
   *   Message body.
   * @param string $destination
   *   Message destination.
   * @param array $options
   *   Message options.
   */
  public function sendMessage($body, $destination, array $options = array()) {
    if (!is_string($body)) {
      throw new InvalidArgumentException('The message body must be a string! ' .
              'Serialize your data to json, xml or anything you prefer.');
    }

    $exchange = $this->findExchangeByName($destination);

    if ($exchange === FALSE) {
      throw new MessageBrokerException('The specified exchange name is not known' .
              ', check your json configuration file!');
    }

    drupal_set_message(t('Message sent to exchange "@exchange" with routing key "@key"',
            array('@exchange' => $destination, '@key' => $options['routing_key'])));

    $queues = $this->getQueuesForMessage($options['routing_key'],
            $exchange['name'], $exchange['type']);

    foreach ($queues as $queue_name) {
      foreach ($this->consumers as $consumer_name => $consumer) {
        if ($consumer['queue'] == $queue_name) {
          $this->callConsumer($body, $consumer, $consumer_name);
        }
      }
    }
  }

  /**
   * Consume message using the specified consumer.
   *
   * @param string $body
   *   Message body.
   * @param array $consumer
   *   Consumer info array.
   * @param string $queue_name
   *   Name of queue.
   */
  protected function callConsumer($body, $consumer, $queue_name) {
    $message = new stdClass();
    $message->body = $body;
    $acked = FALSE;
    $invalid_message = FALSE;

    try {
      drupal_set_message(t('Start consuming a message with "@consumer"',
              array('@consumer' => $queue_name)));
      call_user_func($consumer['callback'], $message, function() use(&$acked) {
        $acked = TRUE;
      });
    }
    catch (InvalidMessageException $e) {
      if (!$acked) {
        $acked = TRUE;
        watchdog_exception('dummy_message_broker', $e);
        watchdog('dummy_message_broker', 'Invalid message catched, body: ' .
                $body);
      }

      $invalid_message = TRUE;

      if (isset($consumer['invalidMessageHandler'])) {
        call_user_func($consumer['invalidMessageHandler'], $message, $e);
      }
    }
    catch (Exception $e) {
      watchdog(WATCHDOG_ERROR, 'An exception was raised while consuming a ' .
              'message by the "!queue". Message: !message',
              array('!queue' => $queue_name, '!message' => $body));
      watchdog_exception('dummy_message_broker', $e);
    }

    if (!$acked) {
      watchdog('dummy_message_broker', 'A message was not processed successfully,' .
               'because it was not acked by the consumer "!queue"! Message: !message',
          array('!queue' => $queue_name, '!message' => $body));
      drupal_set_message(t('A message was not processed successfully, it was not acked by the consumer "@consumer"', array('@consumer' => $queue_name)), 'warning');
    }
    elseif (!$invalid_message) {
      drupal_set_message(t('Message was processed successfully by consumer "@consumer"', array('@consumer' => $queue_name)));
    }
  }

  /**
   * Matches a routing key with a given pattern.
   *
   * @param string $routing_key
   *   Routing key.
   * @param string $pattern
   *   Routing pattern.
   *
   * @return bool
   *   TRUE if routing key matches the given pattern.
   * @throws MessageBrokerException
   */
  protected function matchRoutingKey($routing_key, $pattern) {
    if ($pattern == '#') {
      return TRUE;
    }

    $routing_elements = explode('.', $routing_key);
    $pattern_elements = explode('.', $pattern);
    $matches = TRUE;

    if (empty($routing_elements)) {
      return FALSE;
    }

    foreach ($pattern_elements as $pos => $pattern) {
      if ($pattern == '#') {
        if ($pos == count($pattern_elements) - 1) {
          // We allow the hash at the end, other positions are not supported
          // at the moment.
          $matches = $matches && TRUE;
          break;
        }
        else {
          throw new MessageBrokerException('Pattern matching with "#" hashes within the pattern is not implemented yet!');
        }
      }

      $matches = $matches && ($pattern == '*' || $pattern == $routing_elements[$pos]);
    }

    return $matches;
  }

  /**
   * Finds all queues that are routed to the specified exchange.
   *
   * @param string $routing_key
   *   Routing key.
   * @param string $from_exchange
   *   Source exchange name.
   * @param string $exchange_type
   *   Type of exchange source.
   *
   * @return array
   *   Array of queue names.
   * @throws MessageBrokerException
   */
  protected function getQueuesForMessage($routing_key, $from_exchange,
          $exchange_type) {
    $queues = array();

    if ($exchange_type == 'direct') {
      // Search for all queues which are bound to the exchange
      // and have the same routing key.
      foreach ($this->queues as $queue) {
        foreach ($queue['bindings'] as $binding) {
          if ($binding['exchange'] == $from_exchange &&
                  $routing_key == $binding['routing_key']) {
            $queues[] = $queue['name'];
          }
        }
      }
    }
    elseif ($exchange_type == 'topic') {
      // Search for all queues which are bound to the exchange.
      foreach ($this->queues as $queue) {
        foreach ($queue['bindings'] as $binding) {
          if ($binding['exchange'] == $from_exchange &&
                  $this->matchRoutingKey($routing_key, $binding['routing_key'])) {
            $queues[] = $queue['name'];
          }
        }
      }
    }
    elseif ($exchange_type == 'fanout') {
      // Search all queues which are bound to the exchange.
      foreach ($this->queues as $queue) {
        foreach ($queue['bindings'] as $binding) {
          if ($binding['exchange'] == $from_exchange) {
            $queues[] = $queue['name'];
          }
        }
      }
    }
    elseif ($exchange_type == 'headers') {
      throw new MessageBrokerException('Exchange type "headers" is not implemented!');
    }
    else {
      throw new MessageBrokerException('Uknown exchange type "' . $exchange_type . '" of exchange with name "' . $from_exchange . '"');
    }

    return $queues;
  }

}
