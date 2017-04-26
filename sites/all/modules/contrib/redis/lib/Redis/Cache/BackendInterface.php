<?php

/**
 * Real cache backend primitives. This functions will be used by the
 * Redis_Cache wrapper class that implements the high-level logic that
 * allows us to be Drupal compatible.
 */
interface Redis_Cache_BackendInterface extends Redis_BackendInterface
{
    /**
     * Defaut constructor
     *
     * @param string $namespace
     */
    public function __construct($client, $namespace);

    /**
     * Get namespace
     *
     * @return string
     */
    public function getNamespace();

    /**
     * Set last flush time
     *
     * @param int $time
     * @param boolean $volatile
     */
    public function setLastFlushTimeFor($time, $volatile = false);

    /**
     * Get last flush time
     *
     * @return int[]
     *   First value is for non-volatile items, second value is for volatile items.
     */
    public function getLastFlushTime();

    /**
     * Get a single entry
     *
     * @param string $id
     *
     * @return stdClass
     *   Cache entry or false if the entry does not exists.
     */
    public function get($id);

    /**
     * Get multiple entries
     *
     * @param string[] $idList
     *
     * @return stdClass[]
     *   Existing cache entries keyed by id,
     */
    public function getMultiple(array $idList);

    /**
     * Set a single entry
     *
     * @param string $id
     * @param mixed $data
     * @param int $ttl
     * @param boolean $volatile
     */
    public function set($id, $data, $ttl = null, $volatile = false);

    /**
     * Delete a single entry
     *
     * @param string $cid
     */
    public function delete($id);

    /**
     * Delete multiple entries
     *
     * This method should not use a single DEL command but use a pipeline instead
     *
     * @param array $idList
     */
    public function deleteMultiple(array $idList);

    /**
     * Delete entries by prefix
     *
     * @param string $prefix
     */
    public function deleteByPrefix($prefix);

    /**
     * Flush all entries
     */
    public function flush();

    /**
     * Flush all entries marked as temporary
     */
    public function flushVolatile();
}
