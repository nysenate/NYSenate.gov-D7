<?php

/**
 * Predis cache backend.
 */
class Redis_Cache_Predis extends Redis_Cache_Base
{
    public function setLastFlushTimeFor($time, $volatile = false)
    {
        $client = $this->getClient();
        $key    = $this->getKey(self::LAST_FLUSH_KEY);

        if ($volatile) {
            $client->hset($key, 'volatile', $time);
        } else {
            $client->hmset($key, array(
                'permanent' => $time,
                'volatile' => $time,
            ));
        }
    }

    public function getLastFlushTime()
    {
        $client = $this->getClient();
        $key    = $this->getKey(self::LAST_FLUSH_KEY);
        $values = $client->hmget($key, array("permanent", "volatile"));

        if (empty($values) || !is_array($values)) {
            $values = array(0, 0);
        } else {
            if (empty($values[0])) {
                $values[0] = 0;
            }
            if (empty($values[1])) {
                $values[1] = 0;
            }
        }

        return $values;
    }

    public function get($id)
    {
        $client = $this->getClient();
        $key    = $this->getKey($id);
        $values = $client->hgetall($key);

        // Recent versions of PhpRedis will return the Redis instance
        // instead of an empty array when the HGETALL target key does
        // not exists. I see what you did there.
        if (empty($values) || !is_array($values)) {
            return false;
        }

        return $values;
    }

    public function getMultiple(array $idList)
    {
        $ret = array();

        $pipe = $this->getClient()->pipeline();
        foreach ($idList as $id) {
            $pipe->hgetall($this->getKey($id));
        }
        $replies = $pipe->execute();

        foreach (array_values($idList) as $line => $id) {
            // HGETALL signature seems to differ depending on Predis versions.
            // This was found just after Predis update. Even though I'm not sure
            // this comes from Predis or just because we're misusing it.
            if (!empty($replies[$line]) && is_array($replies[$line])) {
                $ret[$id] = $replies[$line];
            }
        }

        return $ret;
    }

    public function set($id, $data, $ttl = null, $volatile = false)
    {
        // Ensure TTL consistency: if the caller gives us an expiry timestamp
        // in the past the key will expire now and will never be read.
        // Behavior between Predis and PhpRedis seems to change here: when
        // setting a negative expire time, PhpRedis seems to ignore the
        // command and leave the key permanent.
        if (null !== $ttl && $ttl <= 0) {
            return;
        }

        $key = $this->getKey($id);

        $data['volatile'] = (int)$volatile;

        $pipe = $this->getClient()->pipeline();
        $pipe->hmset($key, $data);
        if (null !== $ttl) {
            $pipe->expire($key, $ttl);
        }
        $pipe->execute();
    }

    public function delete($id)
    {
        $client = $this->getClient();
        $client->del($this->getKey($id));
    }

    public function deleteMultiple(array $idList)
    {
        $pipe = $this->getClient()->pipeline();
        foreach ($idList as $id) {
            $pipe->del($this->getKey($id));
        }
        $pipe->execute();
    }

    public function deleteByPrefix($prefix)
    {
        $client = $this->getClient();
        $ret = $client->eval(self::EVAL_DELETE_PREFIX, 0, $this->getKey($prefix . '*'));
        if (1 != $ret) {
            trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
        }
    }

    public function flush()
    {
        $client = $this->getClient();
        $ret = $client->eval(self::EVAL_DELETE_PREFIX, 0, $this->getKey('*'));
        if (1 != $ret) {
            trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
        }
    }

    public function flushVolatile()
    {
        $client = $this->getClient();
        $ret = $client->eval(self::EVAL_DELETE_VOLATILE, 0, $this->getKey('*'));
        if (1 != $ret) {
            trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
        }
    }
}
