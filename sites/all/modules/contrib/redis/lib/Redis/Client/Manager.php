<?php

/**
 * Client pool manager for multi-server configurations
 */
class Redis_Client_Manager
{
    /**
     * Redis default host
     */
    const REDIS_DEFAULT_HOST = '127.0.0.1';

    /**
     * Redis default port
     */
    const REDIS_DEFAULT_PORT = 6379;

    /**
     * Redis default socket (will override host and port)
     */
    const REDIS_DEFAULT_SOCKET = null;

    /**
     * Redis default database: will select none (Database 0)
     */
    const REDIS_DEFAULT_BASE = null;

    /**
     * Redis default password: will not authenticate
     */
    const REDIS_DEFAULT_PASSWORD = null;

    /**
     * Default realm
     */
    const REALM_DEFAULT = 'default';

    /**
     * Client interface name (PhpRedis or Predis)
     *
     * @var string
     */
    private $interfaceName;

    /**
     * @var array[]
     */
    private $serverList = array();

    /**
     * @var mixed[]
     */
    private $clients = array();

    /**
     * @var Redis_Client_FactoryInterface
     */
    private $factory;

    /**
     * Default constructor
     *
     * @param Redis_Client_FactoryInterface $factory
     *   Client factory
     * @param array $serverList
     *   Server connection info list
     */
    public function __construct(Redis_Client_FactoryInterface $factory, $serverList = array())
    {
        $this->factory = $factory;
        $this->serverList = $serverList;
    }

    /**
     * Get client for the given realm
     *
     * @param string $realm
     * @param boolean $allowDefault
     *
     * @return mixed
     */
    public function getClient($realm = self::REALM_DEFAULT, $allowDefault = true)
    {
        if (!isset($this->clients[$realm])) {
            $client = $this->createClient($realm);

            if (false === $client) {
                if (self::REALM_DEFAULT !== $realm && $allowDefault) {
                    $this->clients[$realm] = $this->getClient(self::REALM_DEFAULT);
                } else {
                    throw new InvalidArgumentException(sprintf("Could not find client for realm '%s'", $realm));
                }
            } else {
                $this->clients[$realm] = $client;
            }
        }

        return $this->clients[$realm];
    }

    /**
     * Build connection parameters array from current Drupal settings
     *
     * @param string $realm
     *
     * @return boolean|string[]
     *   A key-value pairs of configuration values or false if realm is
     *   not defined per-configuration
     */
    private function buildOptions($realm)
    {
        $info = null;

        if (isset($this->serverList[$realm])) {
            $info = $this->serverList[$realm];
        } else {
            return false;
        }

        $info += array(
            'host'     => self::REDIS_DEFAULT_HOST,
            'port'     => self::REDIS_DEFAULT_PORT,
            'base'     => self::REDIS_DEFAULT_BASE,
            'password' => self::REDIS_DEFAULT_PASSWORD,
            'socket'   => self::REDIS_DEFAULT_SOCKET
        );

        return array_filter($info);
    }

    /**
     * Get client singleton
     */
    private function createClient($realm)
    {
        $info = $this->buildOptions($realm);

        if (false === $info) {
            return false;
        }

        return $this->factory->getClient($info);
    }
}
