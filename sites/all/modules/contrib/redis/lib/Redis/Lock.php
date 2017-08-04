<?php

/**
 * Lock backend singleton handling.
 */
class Redis_Lock {
    /**
     * @var Redis_Lock_BackendInterface
     */
    private static $instance;

    /**
     * Get actual lock backend.
     * 
     * @return Redis_Lock_BackendInterface
     */
    public static function getBackend()
    {
        if (!isset(self::$instance)) {

            $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_LOCK);

            self::$instance = new $className(
                Redis_Client::getClient(),
                Redis_Client::getDefaultPrefix('lock')
            );
        }

        return self::$instance;
    }
}
