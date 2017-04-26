-- SUMMARY --
This is a module for developers that want to use a message broker in combination
with drupal. It allows you to send and receive messages
without caring about the underlying technical challenges. 

Features
- supports the open standard AMQP and products like RabbitMQ
- simplifies debugging and testing using a special dummy implementation
- provides an infrastructure for running message broker clients (via drush)
- helps developing a fault tolerant and high performance environment for your 
  web applications

-- REQUIREMENTS --
- PHP 5.3
- eventually you will need an AMQP compliant message broker

-- DOCUMENTATION --
Please have a look at http://drupal.org/node/1828146 for an extensive 
documentation.
 
This project has been sponsored by sirup° Agentur für Neue Medien.
http://www.sirup.com
