<?php

/**
 * Common implementation for Redis-based implementations
 */
abstract class Redis_Path_AbstractHashLookup extends Redis_AbstractBackend implements
    Redis_Path_HashLookupInterface
{
    /**
     * @todo document me
     *
     * @param string $key
     * @param string $hkey
     * @param string $hvalue
     */
    abstract protected function saveInHash($key, $hkey, $hvalue);

    /**
     * @todo document me
     *
     * @param string $key
     * @param string $hkey
     * @param string $hvalue
     */
    abstract protected function deleteInHash($key, $hkey, $hvalue);

    /**
     * @todo document me
     *
     * @param string $keyPrefix
     * @param string $hkey
     * @param string $language
     */
    abstract protected function lookupInHash($keyPrefix, $hkey, $language = null);

    /**
     * Normalize value to avoid duplicate or false negatives
     *
     * @param string $value
     *
     * @return string
     */
    private function normalize($value)
    {
        if (null !== $value) {
            return strtolower(trim($value));
        }
    }

    /**
     * {@inheritdoc}
     */
    public function saveAlias($source, $alias, $language = null)
    {
        $alias  = $this->normalize($alias);
        $source = $this->normalize($source);

        if (null === $language) {
            $language = LANGUAGE_NONE;
        }

        if (!empty($source)) {
            $this->saveInHash($this->getKey(array(self::KEY_ALIAS, $language)), $source, $alias);
        }
        if (!empty($alias)) {
            $this->saveInHash($this->getKey(array(self::KEY_SOURCE, $language)), $alias, $source);
        }
    }

    /**
     * {@inheritdoc}
     */
    public function deleteAlias($source, $alias, $language = null)
    {
        $alias  = $this->normalize($alias);
        $source = $this->normalize($source);

        if (null === $language) {
            $language = LANGUAGE_NONE;
        }

        $this->deleteInHash($this->getKey(array(self::KEY_ALIAS, $language)), $source, $alias);
        $this->deleteInHash($this->getKey(array(self::KEY_SOURCE, $language)), $alias, $source);
    }

    /**
     * {@inheritdoc}
     */
    public function lookupAlias($source, $language = null)
    {
        $source = $this->normalize($source);

        return $this->lookupInHash(self::KEY_ALIAS, $source, $language);
    }

    /**
     * {@inheritdoc}
     */
    public function lookupSource($alias, $language = null)
    {
        $alias = $this->normalize($alias);

        return $this->lookupInHash(self::KEY_SOURCE, $alias, $language);
    }
}
