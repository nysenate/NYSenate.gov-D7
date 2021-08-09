<?php

/**
 * Client proxy, client handling class tied to the bare mininum.
 */
interface Redis_Client_FactoryInterface {
  /**
   * Get the connected client instance.
   *
   * @param array $options
   *   Options from the server pool configuration that may contain:
   *     - host
   *     - port
   *     - database
   *     - password
   *     - socket
   *
   * @return mixed
   *   Real client depends from the library behind.
   */
  public function getClient($options = array());

  /**
   * Get underlaying library name used.
   * 
   * This can be useful for contribution code that may work with only some of
   * the provided clients.
   * 
   * @return string
   */
  public function getName();
}
