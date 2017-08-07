<?php

/**
 * PhpRedis implementation.
 *
 * @todo
 *   Set high expire value to the hash for rotation when memory is empty
 *   React upon cache clear all and rebuild path list?
 */
class Redis_Path_Predis extends Redis_Path_AbstractHashLookup
{
    protected function saveInHash($key, $hkey, $hvalue)
    {
        $client = $this->getClient();

        $value = $client->hget($key, $hkey);

        if ($value === self::VALUE_NULL) { // Remove any null values
            $value = null;
        }
        if ($value) {
            $existing = explode(self::VALUE_SEPARATOR, $value);
            if (!in_array($hvalue, $existing)) {
                // Prepend the most recent path to ensure it always be
                // first fetched one
                // @todo Ensure in case of update that its position does
                // not changes (pid ordering in Drupal core)
                $value = $hvalue . self::VALUE_SEPARATOR . $value;
            } else { // Do nothing on empty value
              $value = null;
            }
        } else if (empty($hvalue)) {
            $value = self::VALUE_NULL;
        } else {
            $value = $hvalue;
        }

        if (!empty($value)) {
            $client->hset($key, $hkey, $value);
        }
        // Empty value here means that we already got it
    }

    protected function deleteInHash($key, $hkey, $hvalue)
    {
        $client = $this->getClient();

        $value = $client->hget($key, $hkey);

        if ($value) {
            $existing = explode(self::VALUE_SEPARATOR, $value);
            if (false !== ($index = array_search($hvalue, $existing))) {
                if (1 === count($existing)) {
                    $client->hdel($key, $hkey);
                } else {
                    unset($existing[$index]);
                    $client->hset($key, $hkey, implode(self::VALUE_SEPARATOR, $existing));
                }
            }
        }
    }

    protected function lookupInHash($keyPrefix, $hkey, $language = null)
    {
        $client = $this->getClient();

        if (null === $language) {
            $language = LANGUAGE_NONE;
            $doNoneLookup = false;
        } else if (LANGUAGE_NONE === $language) {
            $doNoneLookup = false;
        } else {
            $doNoneLookup = true;
        }

        $ret = $client->hget($this->getKey(array($keyPrefix, $language)), $hkey);
        if ($doNoneLookup && (!$ret || self::VALUE_NULL === $ret)) {
            $previous = $ret;
            $ret = $client->hget($this->getKey(array($keyPrefix, LANGUAGE_NONE)), $hkey);
            if (!$ret || self::VALUE_NULL === $ret) {
                // Restore null placeholder else we loose conversion to false
                // and drupal_lookup_path() would attempt saving it once again
                $ret = $previous;
            }
        }

        if (self::VALUE_NULL === $ret) {
            return false; // Needs conversion
        }
        if (empty($ret)) {
            return null; // Value not found
        }

        $existing = explode(self::VALUE_SEPARATOR, $ret);

        return reset($existing);
    }

    /**
     * {@inheritdoc}
     */
    public function deleteLanguage($language)
    {
        $client = $this->getClient();
        $client->del($this->getKey(array(self::KEY_ALIAS, $language)));
        $client->del($this->getKey(array(self::KEY_SOURCE, $language)));
    }
}
