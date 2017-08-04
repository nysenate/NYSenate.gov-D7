Redis module testing
====================

Unit tests won't cover the cache backend until the 8.x series.

This won't be fixed, by design. Drupal 8.x now ships a complete cache backend
unit tests suite which will be used when this module will be upgraded.

7.x testing
===========

7.x testing will keep it to the bare minimum and will test some minor bugs such
as admin UI or autoloading related bugs.

Cleanup environment
===================

php -f scripts/run-tests.sh -- --clean

Run common tests
================


php -f scripts/run-tests.sh -- --verbose --color \
    --url "http://yoursite" \
    --class "Redis_Tests_Client_UnitTestCase"

Run all PhpRedis tests
======================

php -f scripts/run-tests.sh -- --verbose --color \
    --url "http://laborange.net" \
    --class "Redis_Tests_Cache_PhpRedisFixesUnitTestCase,Redis_Tests_Cache_PhpRedisFlushUnitTestCase,Redis_Tests_Cache_PhpRedisShardedFixesUnitTestCase,Redis_Tests_Cache_PhpRedisShardedFlushUnitTestCase,Redis_Tests_Cache_PhpRedisShardedWithPipelineFixesUnitTestCase,Redis_Tests_Lock_PhpRedisLockingUnitTestCase,Redis_Tests_Path_PhpRedisPathUnitTestCase,Redis_Tests_Queue_PhpRedisQueueUnitTestCase"

Run all Predis tests
======================

php -f scripts/run-tests.sh -- --verbose --color \
    --url "http://yoursite" \
    --class "Redis_Tests_Cache_PredisFixesUnitTestCase,Redis_Tests_Cache_PredisFlushUnitTestCase,Redis_Tests_Cache_PredisShardedFixesUnitTestCase,Redis_Tests_Cache_PredisShardedFlushUnitTestCase,Redis_Tests_Cache_PredisShardedWithPipelineFixesUnitTestCase,Redis_Tests_Lock_PredisLockingUnitTestCase,Redis_Tests_Path_PredisPathUnitTestCase"
