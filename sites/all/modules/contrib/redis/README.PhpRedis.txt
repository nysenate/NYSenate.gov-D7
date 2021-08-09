PhpRedis cache backend
======================

This client, for now, is only able to use the PhpRedis extension.

Get PhpRedis
------------

You can download this library at:

  https://github.com/phpredis/phpredis

Most common Linux distribution should now have packages for this PHP extension
however if that's not the case for the one you use, use the above link to find
the release source download links and follow the provided instructions in order
to compile it for your system.

Default behavior is to connect via tcp://localhost:6379 but you might want to
connect differently.

Connect via UNIX socket
-----------------------

Just add this line to your settings.php file:

  $conf['redis_cache_socket'] = '/tmp/redis.sock';

Don't forget to change the path depending on your operating system and Redis
server configuration.

Connect to a remote host and database
-------------------------------------

See README.txt file.

For this particular implementation, host settings are overridden by the
UNIX socket parameter.
