<?php

/**
 * Because those objects will be spawned during boostrap all its configuration
 * must be set in the settings.php file.
 *
 * You will find the driver specific implementation in the Redis_Cache_*
 * classes as they may differ in how the API handles transaction, pipelining
 * and return values.
 */
class Redis_Cache
    implements DrupalCacheInterface
{
    /**
     * Default lifetime for permanent items.
     * Approximatively 1 year.
     */
    const LIFETIME_PERM_DEFAULT = 31536000;

    /**
     * Uses EVAL scripts to flush data when called
     *
     * This remains the default behavior and is safe until you use a single
     * Redis server instance and its version is >= 2.6 (older version don't
     * support EVAL).
     */
    const FLUSH_NORMAL = 0;

    /**
     * This mode is tailored for sharded Redis servers instances usage: it
     * will never delete entries but only mark the latest flush timestamp
     * into one of the servers in the shard. It will proceed to delete on
     * read single entries when invalid entries are being loaded.
     */
    const FLUSH_SHARD = 3;

    /**
     * Same as the one above, plus attempt to do pipelining when possible.
     *
     * This is supposed to work with sharding proxies that supports
     * pipelining themselves, such as Twemproxy.
     */
    const FLUSH_SHARD_WITH_PIPELINING = 4;

    /**
     * Computed keys are let's say arround 60 characters length due to
     * key prefixing, which makes 1,000 keys DEL command to be something
     * arround 50,000 bytes length: this is huge and may not pass into
     * Redis, let's split this off.
     * Some recommend to never get higher than 1,500 bytes within the same
     * command which makes us forced to split this at a very low threshold:
     * 20 seems a safe value here (1,280 average length).
     */
    const KEY_THRESHOLD = 20;

    /**
     * @var Redis_Cache_BackendInterface
     */
    protected $backend;

    /**
     * @var string
     */
    protected $bin;

    /**
     * When the global 'cache_lifetime' Drupal variable is set to a value, the
     * cache backends should not expire temporary entries by themselves per
     * Drupal signature. Volatile items will be dropped accordingly to their
     * set lifetime.
     *
     * @var boolean
     */
    protected $allowTemporaryFlush = true;

    /**
     * When in shard mode, the backend cannot proceed to multiple keys
     * operations, and won't delete keys on flush calls.
     *
     * @var boolean
     */
    protected $isSharded = false;

    /**
     * When in shard mode, the proxy may or may not support pipelining,
     * Twemproxy is known to support it.
     *
     * @var boolean
     */
    protected $allowPipeline = false;

    /**
     * Default TTL for CACHE_PERMANENT items.
     *
     * See "Default lifetime for permanent items" section of README.txt
     * file for a comprehensive explaination of why this exists.
     *
     * @var int
     */
    protected $permTtl = self::LIFETIME_PERM_DEFAULT;

    /**
     * Maximum TTL for this bin from Drupal configuration.
     *
     * @var int
     */
    protected $maxTtl = 0;

    /**
     * Flush permanent and volatile cached values
     *
     * @var string[]
     *   First value is permanent latest flush time and second value
     *   is volatile latest flush time
     */
    protected $flushCache = null;

    /**
     * Is this bin in shard mode
     *
     * @return boolean
     */
    public function isSharded()
    {
        return $this->isSharded;
    }

    /**
     * Does this bin allow pipelining through sharded environment
     *
     * @return boolean
     */
    public function allowPipeline()
    {
        return $this->allowPipeline;
    }

    /**
     * Does this bin allow temporary item flush
     *
     * @return boolean
     */
    public function allowTemporaryFlush()
    {
        return $this->allowTemporaryFlush;
    }

    /**
     * Get TTL for CACHE_PERMANENT items.
     *
     * @return int
     *   Lifetime in seconds.
     */
    public function getPermTtl()
    {
        return $this->permTtl;
    }

    /**
     * Get maximum TTL for all items.
     *
     * @return int
     *   Lifetime in seconds.
     */
    public function getMaxTtl()
    {
        return $this->maxTtl;
    }

    /**
     * {@inheritdoc}
     */
    public function __construct($bin)
    {
        $this->bin = $bin;

        $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_CACHE);
        $this->backend = new $className(Redis_Client::getClient(), $bin, Redis_Client::getDefaultPrefix($bin));

        $this->refreshCapabilities();
        $this->refreshPermTtl();
        $this->refreshMaxTtl();
    }

    /**
     * Find from Drupal variables the clear mode.
     */
    public function refreshCapabilities()
    {
        if (0 < variable_get('cache_lifetime', 0)) {
            // Per Drupal default behavior, when the 'cache_lifetime' variable
            // is set we must not flush any temporary items since they have a
            // life time.
            $this->allowTemporaryFlush = false;
        }

        if (null !== ($mode = variable_get('redis_flush_mode', null))) {
            $mode = (int)$mode;
        } else {
            $mode = self::FLUSH_NORMAL;
        }

        $this->isSharded = self::FLUSH_SHARD === $mode || self::FLUSH_SHARD_WITH_PIPELINING === $mode;
        $this->allowPipeline = self::FLUSH_SHARD !== $mode;
    }

    /**
     * Find from Drupal variables the right permanent items TTL.
     */
    protected function refreshPermTtl()
    {
        $ttl = null;
        if (null === ($ttl = variable_get('redis_perm_ttl_' . $this->bin, null))) {
            if (null === ($ttl = variable_get('redis_perm_ttl', null))) {
                $ttl = self::LIFETIME_PERM_DEFAULT;
            }
        }
        if ($ttl === (int)$ttl) {
            $this->permTtl = $ttl;
        } else {
            if ($iv = DateInterval::createFromDateString($ttl)) {
                // http://stackoverflow.com/questions/14277611/convert-dateinterval-object-to-seconds-in-php
                $this->permTtl = ($iv->y * 31536000 + $iv->m * 2592000 + $iv->d * 86400 + $iv->h * 3600 + $iv->i * 60 + $iv->s);
            } else {
                // Sorry but we have to log this somehow.
                trigger_error(sprintf("Parsed TTL '%s' has an invalid value: switching to default", $ttl));
                $this->permTtl = self::LIFETIME_PERM_DEFAULT;
            }
        }
    }

    /**
     * Find from Drupal variables the maximum cache lifetime.
     */
    public function refreshMaxTtl()
    {
        // And now cache lifetime. Be aware we exclude negative values
        // considering those are Drupal misconfiguration.
        $maxTtl = variable_get('cache_lifetime', 0);
        if (0 < $maxTtl) {
            if ($maxTtl < $this->permTtl) {
                $this->maxTtl = $maxTtl;
            } else {
                $this->maxTtl = $this->permTtl;
            }
        } else if ($this->permTtl) {
            $this->maxTtl = $this->permTtl;
        }
    }

    /**
     * Set last flush time
     *
     * @param string $permanent
     * @param string $volatile
     */
    public function setLastFlushTime($permanent = false, $volatile = false)
    {
        // Here we need to fetch absolute values from backend, to avoid
        // concurrency problems and ensure data validity.
        list($flushPerm, $flushVolatile) = $this->backend->getLastFlushTime();

        $checksum = $this->getValidChecksum(
            max(array(
                $flushPerm,
                $flushVolatile,
                $permanent,
                time(),
            ))
        );

        if ($permanent) {
            $this->backend->setLastFlushTimeFor($checksum, false);
            $this->backend->setLastFlushTimeFor($checksum, true);
            $this->flushCache = array($checksum, $checksum);
        } else if ($volatile) {
            $this->backend->setLastFlushTimeFor($checksum, true);
            $this->flushCache = array($flushPerm, $checksum);
        }
    }

    /**
     * Get latest flush time
     *
     * @return string[]
     *   First value is the latest flush time for permanent entries checksum,
     *   second value is the latest flush time for volatile entries checksum.
     */
    public function getLastFlushTime()
    {
        if (!$this->flushCache) {
            $this->flushCache = $this->backend->getLastFlushTime();
        }

         // At the very first hit, we might not have the timestamps set, thus
         // we need to create them to avoid our entry being considered as
         // invalid
        if (!$this->flushCache[0]) {
            $this->setLastFlushTime(true, true);
        } else if (!$this->flushCache[1]) {
            $this->setLastFlushTime(false, true);
        }

        return $this->flushCache;
    }

    /**
     * Create cache entry
     *
     * @param string $cid
     * @param mixed $data
     *
     * @return array
     */
    protected function createEntryHash($cid, $data, $expire = CACHE_PERMANENT)
    {
        list($flushPerm, $flushVolatile) = $this->getLastFlushTime();

        if (CACHE_TEMPORARY === $expire) {
            $validityThreshold = max(array($flushVolatile, $flushPerm));
        } else {
            $validityThreshold = $flushPerm;
        }

        $time = $this->getValidChecksum($validityThreshold);

        $hash = array(
            'cid'     => $cid,
            'created' => $time,
            'expire'  => $expire,
        );

        // Let Redis handle the data types itself.
        if (!is_string($data)) {
            $hash['data'] = serialize($data);
            $hash['serialized'] = 1;
        } else {
            $hash['data'] = $data;
            $hash['serialized'] = 0;
        }

        return $hash;
    }

    /**
     * Expand cache entry from fetched data
     *
     * @param array $values
     *   Raw values fetched from Redis server data
     *
     * @return array
     *   Or FALSE if entry is invalid
     */
    protected function expandEntry(array $values, $flushPerm, $flushVolatile)
    {
        // Check for entry being valid.
        if (empty($values['cid'])) {
            return;
        }

        // This ensures backward compatibility with older version of
        // this module's data still stored in Redis.
        if (isset($values['expire'])) {
            $expire = (int)$values['expire'];
            // Ensure the entry is valid and have not expired.
            if ($expire !== CACHE_PERMANENT && $expire !== CACHE_TEMPORARY && $expire <= time()) {
                return false;
            }
        }

        // Ensure the entry does not predate the last flush time.
        if ($this->allowTemporaryFlush && !empty($values['volatile'])) {
            $validityThreshold = max(array($flushPerm, $flushVolatile));
        } else {
            $validityThreshold = $flushPerm;
        }

        if ($values['created'] <= $validityThreshold) {
            return false;
        }

        $entry = (object)$values;

        // Reduce the checksum to the real timestamp part
        $entry->created = (int)$entry->created;

        if ($entry->serialized) {
            $entry->data = unserialize($entry->data);
        }

        return $entry;
    }

    /**
     * {@inheritdoc}
     */
    public function get($cid)
    {
        $values = $this->backend->get($cid);

        if (empty($values)) {
            return false;
        }

        list($flushPerm, $flushVolatile) = $this->getLastFlushTime();

        $entry = $this->expandEntry($values, $flushPerm, $flushVolatile);

        if (!$entry) { // This entry exists but is invalid.
            $this->backend->delete($cid);
            return false;
        }

        return $entry;
    }

    /**
     * {@inheritdoc}
     */
    public function getMultiple(&$cids)
    {
        $ret    = array();
        $delete = array();

        if (!$this->allowPipeline) {
            $entries = array();
            foreach ($cids as $cid) {
                if ($entry = $this->backend->get($cid)) {
                    $entries[$cid] = $entry;
                }
            }
        } else {
            $entries = $this->backend->getMultiple($cids);
        }

        list($flushPerm, $flushVolatile) = $this->getLastFlushTime();

        foreach ($cids as $key => $cid) {
            if (!empty($entries[$cid])) {
                $entry = $this->expandEntry($entries[$cid], $flushPerm, $flushVolatile);
            } else {
                $entry = null;
            }
            if (empty($entry)) {
                $delete[] = $cid;
            } else {
                $ret[$cid] = $entry;
                unset($cids[$key]);
            }
        }

        if (!empty($delete)) {
            if ($this->allowPipeline) {
                foreach ($delete as $id) {
                    $this->backend->delete($id);
                }
            } else {
                $this->backend->deleteMultiple($delete);
            }
        }

        return $ret;
    }

    /**
     * {@inheritdoc}
     */
    public function set($cid, $data, $expire = CACHE_PERMANENT)
    {
        $hash   = $this->createEntryHash($cid, $data, $expire);
        $maxTtl = $this->getMaxTtl();
        $permTtl = $this->getPermTtl();

        switch ($expire) {

            case CACHE_PERMANENT:
                $this->backend->set($cid, $hash, $permTtl, false);
                break;

            case CACHE_TEMPORARY:
                $this->backend->set($cid, $hash, $maxTtl, true);
                break;

            default:
                $ttl = $expire - time();
                // Ensure $expire consistency
                if ($ttl <= 0) {
                    // Entry has already expired, but we may have a stalled
                    // older cache entry remaining there, ensure it wont
                    // happen by doing a preventive delete
                    $this->backend->delete($cid);
                } else {
                    if ($maxTtl && $maxTtl < $ttl) {
                        $ttl = $maxTtl;
                    }
                    $this->backend->set($cid, $hash, $ttl, false);
                }
                break;
        }
    }

    /**
     * {@inheritdoc}
     */
    public function clear($cid = null, $wildcard = false)
    {
        if (null === $cid && !$wildcard) {
            // Drupal asked for volatile entries flush, this will happen
            // during cron run, mostly
            $this->setLastFlushTime(false, true);

            if (!$this->isSharded && $this->allowTemporaryFlush) {
                $this->backend->flushVolatile();
            }
        } else if ($wildcard) {
            if (empty($cid)) {
                // This seems to be an error, just do nothing.
                return;
            }

            if ('*' === $cid) {
                // Use max() to ensure we invalidate both correctly
                $this->setLastFlushTime(true);

                if (!$this->isSharded) {
                      $this->backend->flush();
                }
            } else {
                if (!$this->isSharded) {
                    $this->backend->deleteByPrefix($cid);
                } else {
                    // @todo This needs a map algorithm the same way memcache
                    // module implemented it for invalidity by prefixes. This
                    // is a very stupid fallback
                    $this->setLastFlushTime(true);
                }
            }
        } else if (is_array($cid)) {
            $this->backend->deleteMultiple($cid);
        } else {
            $this->backend->delete($cid);
        }
    }

    public function isEmpty()
    {
       return false;
    }

    /**
     * From the given timestamp build an incremental safe time-based identifier.
     *
     * Due to potential accidental cache wipes, when a server goes down in the
     * cluster or when a server triggers its LRU algorithm wipe-out, keys that
     * matches flush or tags checksum might be dropped.
     *
     * Per default, each new inserted tag will trigger a checksum computation to
     * be stored in the Redis server as a timestamp. In order to ensure a checksum
     * validity a simple comparison between the tag checksum and the cache entry
     * checksum will tell us if the entry pre-dates the current checksum or not,
     * thus telling us its state. The main problem we experience is that Redis
     * is being so fast it is able to create and drop entries at same second,
     * sometime even the same micro second. The only safe way to avoid conflicts
     * is to checksum using an arbitrary computed number (a sequence).
     *
     * Drupal core does exactly this thus tags checksums are additions of each tag
     * individual checksum; each tag checksum is a independent arbitrary serial
     * that gets incremented starting with 0 (no invalidation done yet) to n (n
     * invalidations) which grows over time. This way the checksum computation
     * always rises and we have a sensible default that works in all cases.
     *
     * This model works as long as you can ensure consistency for the serial
     * storage over time. Nevertheless, as explained upper, in our case this
     * serial might be dropped at some point for various valid technical reasons:
     * if we start over to 0, we may accidentally compute a checksum which already
     * existed in the past and make invalid entries turn back to valid again.
     *
     * In order to prevent this behavior, using a timestamp as part of the serial
     * ensures that we won't experience this problem in a time range wider than a
     * single second, which is safe enough for us. But using timestamp creates a
     * new problem: Redis is so fast that we can set or delete hundreds of entries
     * easily during the same second: an entry created then invalidated the same
     * second will create false positives (entry is being considered as valid) -
     * note that depending on the check algorithm, false negative may also happen
     * the same way. Therefore we need to have an abitrary serial value to be
     * incremented in order to enforce our checks to be more strict.
     *
     * The solution to both the first (the need for a time based checksum in case
     * of checksum data being dropped) and the second (the need to have an
     * arbitrary predictible serial value to avoid false positives or negatives)
     * we are combining the two: every checksum will be built this way:
     *
     *   UNIXTIMESTAMP.SERIAL
     *
     * For example:
     *
     *   1429789217.017
     *
     * will reprensent the 17th invalidation of the 1429789217 exact second which
     * happened while writing this documentation. The next tag being invalidated
     * the same second will then have this checksum:
     *
     *   1429789217.018
     *
     * And so on...
     *
     * In order to make it consitent with PHP string and float comparison we need
     * to set fixed precision over the decimal, and store as a string to avoid
     * possible float precision problems when comparing.
     *
     * This algorithm is not fully failsafe, but allows us to proceed to 1000
     * operations on the same checksum during the same second, which is a
     * sufficiently great value to reduce the conflict probability to almost
     * zero for most uses cases.
     *
     * @param int|string $timestamp
     *   "TIMESTAMP[.INCREMENT]" string
     *
     * @return string
     *   The next "TIMESTAMP.INCREMENT" string.
     */
    public function getNextIncrement($timestamp = null)
    {
        if (!$timestamp) {
            return time() . '.000';
        }

        if (false !== ($pos = strpos($timestamp, '.'))) {
            $inc = substr($timestamp, $pos + 1, 3);

            return ((int)$timestamp) . '.' . str_pad($inc + 1, 3, '0', STR_PAD_LEFT);
        }

        return $timestamp . '.000';
    }

    /**
     * Get valid checksum
     *
     * @param int|string $previous
     *   "TIMESTAMP[.INCREMENT]" string
     *
     * @return string
     *   The next "TIMESTAMP.INCREMENT" string.
     *
     * @see Redis_Cache::getNextIncrement()
     */
    public function getValidChecksum($previous = null)
    {
        if (time() === (int)$previous) {
            return $this->getNextIncrement($previous);
        } else {
            return $this->getNextIncrement();
        }
    }
}
