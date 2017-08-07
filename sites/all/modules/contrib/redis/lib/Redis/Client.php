<?php

// It may happen we get here with no autoloader set during the Drupal core
// early bootstrap phase, at cache backend init time.
if (!interface_exists('Redis_Client_FactoryInterface')) {
    require_once dirname(__FILE__) . '/Client/FactoryInterface.php';
    require_once dirname(__FILE__) . '/Client/Manager.php';
}

/**
 * This static class only reason to exist is to tie Drupal global
 * configuration to OOP driven code of this module: it will handle
 * everything that must be read from global configuration and let
 * other components live without any existence of it
 */
class Redis_Client
{
    /**
     * Cache implementation namespace.
     */
    const REDIS_IMPL_CACHE = 'Redis_Cache_';

    /**
     * Lock implementation namespace.
     */
    const REDIS_IMPL_LOCK = 'Redis_Lock_';

    /**
     * Cache implementation namespace.
     */
    const REDIS_IMPL_QUEUE = 'Redis_Queue_';

    /**
     * Path implementation namespace.
     */
    const REDIS_IMPL_PATH = 'Redis_Path_';

    /**
     * Client factory implementation namespace.
     */
    const REDIS_IMPL_CLIENT = 'Redis_Client_';

    /**
     * @var Redis_Client_Manager
     */
    private static $manager;

    /**
     * @var string
     */
    static protected $globalPrefix;

    /**
     * Get site default global prefix
     *
     * @return string
     */
    static public function getGlobalPrefix()
    {
        // Provide a fallback for multisite. This is on purpose not inside the
        // getPrefixForBin() function in order to decouple the unified prefix
        // variable logic and custom module related security logic, that is not
        // necessary for all backends. We can't just use HTTP_HOST, as multiple
        // hosts might be using the same database. Or, more commonly, a site
        // might not be a multisite at all, but might be using Drush leading to
        // a separate HTTP_HOST of 'default'. Likewise, we can't rely on
        // conf_path(), as settings.php might be modifying what database to
        // connect to. To mirror what core does with database caching we use
        // the DB credentials to inform our cache key.
      if (null === self::$globalPrefix) {
            if (isset($GLOBALS['db_url']) && is_string($GLOBALS['db_url'])) {
                // Drupal 6 specifics when using the cache_backport module, we
                // therefore cannot use \Database class to determine database
                // settings.
              self::$globalPrefix = md5($GLOBALS['db_url']);
            } else {
                require_once DRUPAL_ROOT . '/includes/database/database.inc';
                $dbInfo = Database::getConnectionInfo();
                $active = $dbInfo['default'];
                self::$globalPrefix = md5($active['host'] . $active['database'] . $active['prefix']['default']);
            }
        }

        return self::$globalPrefix;
    }

    /**
     * Get global default prefix
     *
     * @param string $namespace
     *
     * @return string
     */
    static public function getDefaultPrefix($namespace = null)
    {
        $ret = null;

        if (!empty($GLOBALS['drupal_test_info']['test_run_id'])) {
            $ret = $GLOBALS['drupal_test_info']['test_run_id'];
        } else {
            $prefixes = variable_get('cache_prefix', null);

            if (is_string($prefixes)) {
                // Variable can be a string which then considered as a default
                // behavior.
                $ret = $prefixes;
            } else if (null !== $namespace && isset($prefixes[$namespace])) {
                if (false !== $prefixes[$namespace]) {
                    // If entry is set and not false an explicit prefix is set
                    // for the bin.
                    $ret = $prefixes[$namespace];
                } else {
                    // If we have an explicit false it means no prefix whatever
                    // is the default configuration.
                    $ret = '';
                }
            } else {
                // Key is not set, we can safely rely on default behavior.
                if (isset($prefixes['default']) && false !== $prefixes['default']) {
                    $ret = $prefixes['default'];
                } else {
                    // When default is not set or an explicit false this means
                    // no prefix.
                    $ret = '';
                }
            }
        }

        if (empty($ret)) {
            $ret = Redis_Client::getGlobalPrefix();
        }

        return $ret;
    }

    /**
     * Get client manager
     *
     * @return Redis_Client_Manager
     */
    static public function getManager()
    {
        global $conf;

        if (null === self::$manager) {

            $className = self::getClass(self::REDIS_IMPL_CLIENT);
            $factory = new $className();

            // Build server list from conf
            $serverList = array();
            if (isset($conf['redis_servers'])) {
                $serverList = $conf['redis_servers'];
            }

            if (empty($serverList) || !isset($serverList['default'])) {

                // Backward configuration compatibility with older versions
                $serverList[Redis_Client_Manager::REALM_DEFAULT] = array();

                foreach (array('host', 'port', 'base', 'password', 'socket') as $key) {
                    if (isset($conf['redis_client_' . $key])) {
                        $serverList[Redis_Client_Manager::REALM_DEFAULT][$key] = $conf['redis_client_' . $key];
                    }
                }
            }

            self::$manager = new Redis_Client_Manager($factory, $serverList);
        }

        return self::$manager;
    }

    /**
     * Find client class name
     *
     * @return string
     */
    static public function getClientInterfaceName()
    {
        global $conf;

        if (!empty($conf['redis_client_interface'])) {
            return $conf['redis_client_interface'];
        } else if (class_exists('Predis\Client')) {
            // Transparent and abitrary preference for Predis library.
            return  $conf['redis_client_interface'] = 'Predis';
        } else if (class_exists('Redis')) {
            // Fallback on PhpRedis if available.
            return $conf['redis_client_interface'] = 'PhpRedis';
        } else {
            throw new Exception("No client interface set.");
        }
    }

    /**
     * For unit test use only
     */
    static public function reset(Redis_Client_Manager $manager = null)
    {
        self::$manager = $manager;
    }

    /**
     * Get the client for the 'default' realm
     *
     * @return mixed
     *
     * @deprecated
     */
    public static function getClient()
    {
        return self::getManager()->getClient();
    }

    /**
     * Get specific class implementing the current client usage for the specific
     * asked core subsystem.
     * 
     * @param string $system
     *   One of the Redis_Client::IMPL_* constant.
     * @param string $clientName
     *   Client name, if fixed.
     * 
     * @return string
     *   Class name, if found.
     *
     * @deprecated
     */
    static public function getClass($system)
    {
        $class = $system . self::getClientInterfaceName();

        if (!class_exists($class)) {
            throw new Exception(sprintf("Class '%s' does not exist", $class));
        }

        return $class;
    }
}

