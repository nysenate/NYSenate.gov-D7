<?php

/**
 * @file
 * Definition of amqp specific exception types.
 */

/**
 * An exception a consumer should throw to indicate that a message is acknowledged
 * negatively (was not processed successfully).
 */
class NackException extends Exception {
}
