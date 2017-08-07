<?php

/**
 * Bugfixes made over time test class.
 */
abstract class Redis_Tests_Path_PathUnitTestCase extends Redis_Tests_AbstractUnitTestCase
{
    /**
     * @var Cache bin identifier
     */
    static private $id = 1;

    /**
     * Get cache backend
     *
     * @return Redis_Path_HashLookupInterface
     */
    final protected function getBackend($name = null)
    {
        if (null === $name) {
            // This is needed to avoid conflict between tests, each test
            // seems to use the same Redis namespace and conflicts are
            // possible.
            $name = 'cache' . (self::$id++);
        }

        $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_PATH);
        $hashLookup = new $className(Redis_Client::getClient(), 'path', Redis_Client::getDefaultPrefix('path'));

        return $hashLookup;
    }

    /**
     * Tests basic functionnality
     */
    public function testPathLookup()
    {
        $backend = $this->getBackend();

        $source = $backend->lookupSource('node-1-fr', 'fr');
        $this->assertIdentical(null, $source);
        $alias = $backend->lookupAlias('node/1', 'fr');
        $this->assertIdentical(null, $source);

        $backend->saveAlias('node/1', 'node-1-fr', 'fr');
        $source = $backend->lookupSource('node-1-fr', 'fr');
        $source = $backend->lookupSource('node-1-fr', 'fr');
        $this->assertIdentical('node/1', $source);
        $alias = $backend->lookupAlias('node/1', 'fr');
        $this->assertIdentical('node-1-fr', $alias);

        // Delete and ensure it does not exist anymore.
        $backend->deleteAlias('node/1', 'node-1-fr', 'fr');
        $source = $backend->lookupSource('node-1-fr', 'fr');
        $this->assertIdentical(null, $source);
        $alias = $backend->lookupAlias('node/1', 'fr');
        $this->assertIdentical(null, $source);

        // Set more than one aliases and ensure order at loading.
        $backend->saveAlias('node/1', 'node-1-fr-1', 'fr');
        $backend->saveAlias('node/1', 'node-1-fr-2', 'fr');
        $backend->saveAlias('node/1', 'node-1-fr-3', 'fr');
        $alias = $backend->lookupAlias('node/1', 'fr');
        $this->assertIdentical('node-1-fr-3', $alias);

        // Add another alias to test the delete language feature.
        // Also add some other languages aliases.
        $backend->saveAlias('node/1', 'node-1');
        $backend->saveAlias('node/2', 'node-2-en', 'en');
        $backend->saveAlias('node/3', 'node-3-ca', 'ca');

        // Ok, delete fr and tests every other are still there.
        $backend->deleteLanguage('fr');
        $alias = $backend->lookupAlias('node/1');
        $this->assertIdentical('node-1', $alias);
        $alias = $backend->lookupAlias('node/2', 'en');
        $this->assertIdentical('node-2-en', $alias);
        $alias = $backend->lookupAlias('node/3', 'ca');
        $this->assertIdentical('node-3-ca', $alias);

        // Now create back a few entries in some langage and
        // ensure fallback to no language also works.
        $backend->saveAlias('node/4', 'node-4');
        $backend->saveAlias('node/4', 'node-4-es', 'es');
        $alias = $backend->lookupAlias('node/4');
        $this->assertIdentical('node-4', $alias);
        $alias = $backend->lookupAlias('node/4', 'es');
        $this->assertIdentical('node-4-es', $alias);
        $alias = $backend->lookupAlias('node/4', 'fr');
        $this->assertIdentical('node-4', $alias);
    }

    /**
     * Tests https://www.drupal.org/node/2728831
     */
    public function testSomeEdgeCaseFalseNegative()
    {
        $backend = $this->getBackend();

        $backend->deleteLanguage('fr');
        $backend->deleteLanguage('und');
        $backend->saveAlias('node/123', 'node-123');

        // Language lookup should return the language neutral value if no value
        $source = $backend->lookupSource('node-123', 'fr');
        $this->assertIdentical($source, 'node/123');
        $source = $backend->lookupAlias('node/123', 'fr');
        $this->assertIdentical($source, 'node-123');

        // Now, let's consider we have an item we don't know if it exists or
        // not, per definition we should not return a strict FALSE but a NULL
        // value instead to tell "we don't know anything about this". In a
        // very specific use-case, if the language neutral value is a strict
        // "not exists" value, it should still return NULL instead of FALSE
        // if another language was asked for.

        // Store "value null" for the language neutral entry
        $backend->saveAlias('node/456', Redis_Path_HashLookupInterface::VALUE_NULL);
        $source = $backend->lookupAlias('node/456');
        $this->assertIdentical(false, $source);

        $source = $backend->lookupAlias('node/456', 'fr');
        $this->assertIdentical(null, $source);
    }

    /**
     * Tests that lookup is case insensitive
     */
    public function testCaseInsensitivePathLookup()
    {
        $backend = $this->getBackend();

        $backend->saveAlias('node/1', 'Node-1-FR', 'fr');
        $source = $backend->lookupSource('NODE-1-fr', 'fr');
        $this->assertIdentical('node/1', $source);
        $source = $backend->lookupSource('node-1-FR', 'fr');
        $this->assertIdentical('node/1', $source);
        $alias = $backend->lookupAlias('node/1', 'fr');
        $this->assertIdentical('node-1-fr', strtolower($alias));

        // Delete and ensure it does not exist anymore.
        $backend->deleteAlias('node/1', 'node-1-FR', 'fr');
        $source = $backend->lookupSource('Node-1-FR', 'fr');
        $this->assertIdentical(null, $source);
        $alias = $backend->lookupAlias('node/1', 'fr');
        $this->assertIdentical(null, $source);
    }
}
