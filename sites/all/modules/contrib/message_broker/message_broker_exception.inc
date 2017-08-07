<?php

/**
 * @file
 * Definition of all exception types used by the module.
 */

/**
 * General exception which is thrown by the module in case something went wrong.
 */
class MessageBrokerException extends Exception {
}

/**
 * An exception a consumer should throw to indicate that a message is invalid.
 * This message broker module will catch the exception, ack the
 * message and call a invalidMessageHandler.
 */
class InvalidMessageException extends Exception {
}

/**
 * An exception a consumer should throw to indicate a critical
 * error. This means that application is not able
 * to proceed at this state.
 * The message broker infrastructure catches these exceptions,
 * terminates the process, allowing you to restart the process.
 */
class CriticalErrorException extends Exception {
}
