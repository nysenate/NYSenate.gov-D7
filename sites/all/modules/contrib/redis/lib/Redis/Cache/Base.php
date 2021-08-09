<?php

/**
 * @todo
 *   - Improve lua scripts by using SCAN family commands
 *   - Deambiguate why we need the namespace only for flush*() operations
 *   - Implement the isEmpty() method by using SCAN or KEYS
 */
abstract class Redis_Cache_Base extends Redis_AbstractBackend
{
    /**
     * Lastest cache flush KEY name
     */
    const LAST_FLUSH_KEY = '_last_flush';

    /**
     * Delete by prefix lua script
     */
    const EVAL_DELETE_PREFIX = <<<EOT
local keys = redis.call("KEYS", ARGV[1])
for i, k in ipairs(keys) do
    redis.call("DEL", k)
end
return 1
EOT;

    /**
     * Delete volatile by prefix lua script
     */
    const EVAL_DELETE_VOLATILE = <<<EOT
local keys = redis.call('KEYS', ARGV[1])
for i, k in ipairs(keys) do
    if "1" == redis.call("HGET", k, "volatile") then
        redis.call("DEL", k)
    end
end
return 1
EOT;
}
