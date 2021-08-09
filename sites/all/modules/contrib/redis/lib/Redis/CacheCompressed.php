<?php

/**
 * This typically brings 80..85% compression in ~20ms/mb write, 5ms/mb read.
 */
class Redis_CacheCompressed extends Redis_Cache implements DrupalCacheInterface
{
    private $compressionSizeThreshold = 100;
    private $compressionRatio = 1;

    /**
     * {@inheritdoc}
     */
    public function __construct($bin)
    {
        parent::__construct($bin);

        $this->compressionSizeThreshold = (int)variable_get('cache_compression_size_threshold', 100);
        if ($this->compressionSizeThreshold < 0) {
            trigger_error('cache_compression_size_threshold must be 0 or a positive integer, negative value found, switching back to default 100', E_USER_WARNING);
            $this->compressionSizeThreshold = 100;
        }

        // Minimum compression level (1) has good ratio in low time.
        $this->compressionRatio = (int)variable_get('cache_compression_ratio', 1);
        if ($this->compressionRatio < 1 || 9 < $this->compressionRatio) {
            trigger_error('cache_compression_ratio must be between 1 and 9, out of bounds value found, switching back to default 1', E_USER_WARNING);
            $this->compressionRatio = 1;
        }
    }

    /**
     * {@inheritdoc}
     */
    protected function createEntryHash($cid, $data, $expire = CACHE_PERMANENT)
    {
        $hash = parent::createEntryHash($cid, $data, $expire);

        // Empiric level when compression makes sense.
        if (!$this->compressionSizeThreshold || strlen($hash['data']) > $this->compressionSizeThreshold) {

            $hash['data'] = gzcompress($hash['data'], $this->compressionRatio);
            $hash['compressed'] = true;
        }

        return $hash;
    }

    /**
     * {@inheritdoc}
     */
    protected function expandEntry(array $values, $flushPerm, $flushVolatile)
    {
        if (!empty($values['data']) && !empty($values['compressed'])) {
            // Uncompress, suppress warnings e.g. for broken CRC32.
            $values['data'] = @gzuncompress($values['data']);

            // In such cases, void the cache entry.
            if ($values['data'] === false) {
                return false;
            }
        }

        return parent::expandEntry($values, $flushPerm, $flushVolatile);
    }
}
