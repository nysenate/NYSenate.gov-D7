<?php

/**
 * Client based Redis component
 */
interface Redis_BackendInterface
{
    /**
     * Set client
     *
     * @param mixed $client
     */
    public function setClient($client);

    /**
     * Get client
     *
     * @return mixed
     */
    public function getClient();

    /**
     * Set prefix
     *
     * @param string $prefix
     */
    public function setPrefix($prefix);

    /**
     * Get prefix
     *
     * @return string
     */
    public function getPrefix();

    /**
     * Set namespace
     *
     * @param string $namespace
     */
    public function setNamespace($namespace);

    /**
     * Get namespace
     *
     * @return string
     */
    public function getNamespace();

    /**
     * Get full key name using the set prefix
     *
     * @param string ...
     *   Any numer of strings to append to path using the separator
     *
     * @return string
     */
    public function getKey();
}
