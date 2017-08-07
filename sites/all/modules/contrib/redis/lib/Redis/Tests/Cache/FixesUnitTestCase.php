<?php

if (!class_exists('Redis_Tests_AbstractUnitTestCase')) {
  require_once(__DIR__ . '/../AbstractUnitTestCase.php');
}

/**
 * Bugfixes made over time test class.
 */
abstract class Redis_Tests_Cache_FixesUnitTestCase extends Redis_Tests_AbstractUnitTestCase
{
    /**
     * @var Cache bin identifier
     */
    static private $id = 1;

    protected function createCacheInstance($name = null)
    {
        return new Redis_Cache($name);
    }

    /**
     * Get cache backend
     *
     * @return Redis_Cache
     */
    final protected function getBackend($name = null)
    {
        if (null === $name) {
            // This is needed to avoid conflict between tests, each test
            // seems to use the same Redis namespace and conflicts are
            // possible.
            $name = 'cache' . (self::$id++);
        }

        $backend = $this->createCacheInstance($name);

        $this->assert(true, "Redis client is " . ($backend->isSharded() ? '' : "NOT ") . " sharded");
        $this->assert(true, "Redis client is " . ($backend->allowTemporaryFlush() ? '' : "NOT ") . " allowed to flush temporary entries");
        $this->assert(true, "Redis client is " . ($backend->allowPipeline() ? '' : "NOT ") . " allowed to use pipeline");

        return $backend;
    }

    public function testTemporaryCacheExpire()
    {
        global $conf; // We are in unit tests so variable table does not exist.

        $backend = $this->getBackend();

        // Permanent entry.
        $backend->set('test1', 'foo', CACHE_PERMANENT);
        $data = $backend->get('test1');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foo', $data->data);

        // Permanent entries should not be dropped on clear() call.
        $backend->clear();
        $data = $backend->get('test1');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foo', $data->data);

        // Expiring entry with permanent default lifetime.
        $conf['cache_lifetime'] = 0;
        $backend->set('test2', 'bar', CACHE_TEMPORARY);
        sleep(2);
        $data = $backend->get('test2');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('bar', $data->data);
        sleep(2);
        $data = $backend->get('test2');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('bar', $data->data);

        // Expiring entry with negative lifetime.
        $backend->set('test3', 'baz', time() - 100);
        $data = $backend->get('test3');
        $this->assertEqual(false, $data);

        // Expiring entry with short lifetime.
        $backend->set('test4', 'foobar', time() + 2);
        $data = $backend->get('test4');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foobar', $data->data);
        sleep(4);
        $data = $backend->get('test4');
        $this->assertEqual(false, $data);

        // Expiring entry with short default lifetime.
        $conf['cache_lifetime'] = 1;
        $backend->refreshMaxTtl();
        $backend->set('test5', 'foobaz', CACHE_TEMPORARY);
        $data = $backend->get('test5');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foobaz', $data->data);
        sleep(3);
        $data = $backend->get('test5');
        $this->assertEqual(false, $data);
    }

    public function testDefaultPermTtl()
    {
        global $conf;
        unset($conf['redis_perm_ttl']);
        $backend = $this->getBackend();
        $this->assertIdentical(Redis_Cache::LIFETIME_PERM_DEFAULT, $backend->getPermTtl());
    }

    public function testUserSetDefaultPermTtl()
    {
        global $conf;
        // This also testes string parsing. Not fully, but at least one case.
        $conf['redis_perm_ttl'] = "3 months";
        $backend = $this->getBackend();
        $this->assertIdentical(7776000, $backend->getPermTtl());
    }

    public function testUserSetPermTtl()
    {
        global $conf;
        // This also testes string parsing. Not fully, but at least one case.
        $conf['redis_perm_ttl'] = "1 months";
        $backend = $this->getBackend();
        $this->assertIdentical(2592000, $backend->getPermTtl());
    }

    public function testGetMultiple()
    {
        $backend = $this->getBackend();

        $backend->set('multiple1', 1);
        $backend->set('multiple2', 2);
        $backend->set('multiple3', 3);
        $backend->set('multiple4', 4);

        $cidList = array('multiple1', 'multiple2', 'multiple3', 'multiple4', 'multiple5');
        $ret = $backend->getMultiple($cidList);

        $this->assertEqual(1, count($cidList));
        $this->assertFalse(isset($cidList[0]));
        $this->assertFalse(isset($cidList[1]));
        $this->assertFalse(isset($cidList[2]));
        $this->assertFalse(isset($cidList[3]));
        $this->assertTrue(isset($cidList[4]));

        $this->assertEqual(4, count($ret));
        $this->assertTrue(isset($ret['multiple1']));
        $this->assertTrue(isset($ret['multiple2']));
        $this->assertTrue(isset($ret['multiple3']));
        $this->assertTrue(isset($ret['multiple4']));
        $this->assertFalse(isset($ret['multiple5']));
    }

    public function testPermTtl()
    {
        global $conf;
        // This also testes string parsing. Not fully, but at least one case.
        $conf['redis_perm_ttl'] = "2 seconds";
        $backend = $this->getBackend();
        $this->assertIdentical(2, $backend->getPermTtl());

        $backend->set('test6', 'cats are mean');
        $this->assertIdentical('cats are mean', $backend->get('test6')->data);

        sleep(3);
        $item = $backend->get('test6');
        $this->assertTrue(empty($item));
    }

    public function testClearAsArray()
    {
        $backend = $this->getBackend();

        $backend->set('test7', 1);
        $backend->set('test8', 2);
        $backend->set('test9', 3);

        $backend->clear(array('test7', 'test9'));

        $item = $backend->get('test7');
        $this->assertTrue(empty($item));
        $item = $backend->get('test8');
        $this->assertEqual(2, $item->data);
        $item = $backend->get('test9');
        $this->assertTrue(empty($item));
    }

    public function testGetMultipleAlterCidsWhenCacheHitsOnly()
    {
        $backend = $this->getBackend();
        $backend->clear('*', true); // It seems that there are leftovers.

        $backend->set('mtest1', 'pouf');

        $cids_partial_hit = array('foo' => 'mtest1', 'bar' => 'mtest2');
        $entries = $backend->getMultiple($cids_partial_hit);
        $this->assertIdentical(1, count($entries));
        // Note that the key is important because the method should
        // keep the keys synchronized.
        $this->assertEqual(array('bar' => 'mtest2'), $cids_partial_hit);

        $backend->clear('mtest1');

        $cids_no_hit = array('cat' => 'mtest1', 'dog' => 'mtest2');
        $entries = $backend->getMultiple($cids_no_hit);
        $this->assertIdentical(0, count($entries));
        $this->assertEqual(array('cat' => 'mtest1', 'dog' => 'mtest2'), $cids_no_hit);
    }
}
