<?php

abstract class Redis_AbstractBackend implements Redis_BackendInterface
{
    /**
     * Key components name separator
     */
    const KEY_SEPARATOR = ':';

    /**
     * @var string
     */
    private $prefix;

    /**
     * @var string
     */
    private $namespace;

    /**
     * @var mixed
     */
    private $client;

    /**
     * Default constructor
     *
     * @param mixed $client
     *   Redis client
     * @param string $namespace
     *   Component namespace
     * @param string $prefix
     *   Component prefix
     */
    public function __construct($client, $namespace = null, $prefix = null)
    {
        $this->client = $client;
        $this->prefix = $prefix;

        if (null !== $namespace) {
            $this->namespace = $namespace;
        }
    }

    final public function setClient($client)
    {
        $this->client = $client;
    }

    final public function getClient()
    {
        return $this->client;
    }

    final public function setPrefix($prefix)
    {
        $this->prefix = $prefix;
    }

    final public function getPrefix()
    {
        return $this->prefix;
    }

    final public function setNamespace($namespace)
    {
        $this->namespace = $namespace;
    }

    final public function getNamespace()
    {
        return $this->namespace;
    }

    /**
     * Get prefixed key
     *
     * @param string|string[] $parts
     *   Arbitrary number of strings to compose the key
     *
     * @return string
     */
    public function getKey($parts = array())
    {
        $key = array();

        if (null !== $this->prefix) {
            $key[] = $this->prefix;
        }
        if (null !== $this->namespace) {
            $key[] = $this->namespace;
        }

        if ($parts) {
            if (is_array($parts)) {
                foreach ($parts as $part) {
                    if ($part) {
                        $key[] = $part;
                    }
                }
            } else {
                $key[] = $parts;
            }
        }

        return implode(self::KEY_SEPARATOR, array_filter($key));
    }
}
