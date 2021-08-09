# Drupal 8 Cache Backport (D8Cache)

This guide contains information on the user-configurable parts of D8Cache.
Fully utilizing D8Cache may require some site customization. For clarity,
developer-centric documentation has been split out to `README.developer.md`.

Introduction - How does tag based caching work?
-----------------------------------------------

With Cache Tags it is possible to tag pages or other cache entries like 'blocks'
by using so-called cache tag strings. (e.g. `node:1`).

Then when the `node:1` object is updated the tag is invalidated.

The D8Cache module already supports cache tags for entities, menus, blocks and
search out of the box.

Getting started
---------------

To get started you download the module and enable it.

Then you need to configure settings.php:

```
$conf['cache_backends'][] = 'sites/all/modules/d8cache/d8cache-ac.cache.inc';
$conf['cache_class_cache_views_data'] = 'D8CacheAttachmentsCollector';
$conf['cache_class_cache_block'] = 'D8CacheAttachmentsCollector';
$conf['cache_class_cache_page'] = 'D8Cache';
```

In this example both `cache_views_data` and `cache_block` are taken over by a
`D8CacheAttachmentsCollector` class, which will ensure that render array
`#attached` properties are tracked properly when performing render caching.

Performance and Reliability notes
---------------------------------

- Possible deadlock when saving content

If you are storing cache tags in the database, be aware there is a
[D8 core issue](https://www.drupal.org/project/drupal/issues/2966607)
(#2966607) open regarding a possible deadlock between content saving and tag
invalidation. If you are encountering deadlocks when saving content, you may
want to try using the Drupal 7 backport of this patch from
[here](https://www.drupal.org/project/drupal/issues/3004437) -- it adds the
ability for modules to run code after a database transaction has been committed.

A future Drupal 7 release will include this functionality, once the Drupal 8
version has been finalized.

D8Cache will automatically detect when this support is available, and if so,
will defer tag invalidation until after the current transaction has completed.

- Drupal core patch may be needed for accurate render caching

If you are having trouble with missing javascript / CSS when doing render
caching, try running this the core patch from
[here](https://www.drupal.org/project/drupal/issues/2820757) (#2820757.)

See that issue for specifics on when this may be necessary.

Frequently asked questions - Users
----------------------------------
For answers to more code-related questions, please see the corresponding FAQ in `README.developer.md`.

### How can I specify a class to use as backend for D8Cache if my bin uses a different backend from the default?

Before:

```
$conf['cache_default_class'] = 'Redis_Cache';
$conf['cache_class_cache_page'] = 'DrupalDatabaseCache';
```

After:

```
$conf['cache_default_class'] = 'Redis_Cache';
$conf['cache_class_cache_page'] = 'D8Cache';
$conf['d8cache_cache_class_cache_page'] = 'DrupalDatabaseCache';
```

So the only thing needed is to prefix the usual 'cache_class_*' variable with
'd8cache_'.

It is also possible to specify another default backend for D8Cache with
'd8cache_cache_default_class', which can be useful to add another decorator just
to the cache bins using the D8Cache backends.

Note that D8Cache is generally only useful for cache bins that store rendered
content. While it can be used on other cache bins with no issues, it is
slightly more efficient to use a regular cache backend class for most bins.

### How I store cache tags in a different backend than the database?

Add this to your settings.php:
```
$conf['d8cache_use_cache_tags_cache'] = TRUE;
```

This will make D8Cache look in the 'cache_d8cache_cache_tags' bin for the cache
tags, and only check the database for any tags that it could not find in this
secondary cache.

Note for developers:
Alternatively, you can extend the `D8Cache` and `D8CacheAttachmentsCollector`
classes and use a trait to override the `checksumValid()` and `getCurrentChecksum()`
functions. Your module should also implement `hook_cache_tags_invalidate()`.

### How do I serve the page cache without boostrapping the database?

Add to settings.php:
```
$conf['d8cache_use_cache_tags_cache'] = TRUE;
// D8Cache will automatically bootstrap the database if needed.
$conf['page_cache_without_database'] = TRUE;
// Unless your boot modules were specifically designed to work without the
// database, you must disable page cache hooks. (hook_boot/hook_exit)
$conf['page_cache_invoke_hooks'] = FALSE;
// Use D8Cache for cache_page to handle tag invalidation properly.
$conf['cache_class_cache_page'] = 'D8Cache';
// cache_bootstrap is needed during Drupal startup, and must use a cache
// backend directly.
$conf['cache_class_cache_bootstrap'] = 'MemCacheDrupal';
// cache_d8cache_cache_tags must also use a cache backend directly.
$conf['cache_class_cache_d8cache_cache_tags'] = 'MemCacheDrupal';
// This is the backing store for cache_page. Invalidation will be handled
// by D8Cache as configured above.
$conf['d8cache_cache_class_cache_page'] = 'MemCacheDrupal';
```
The database will still be bootstrapped if any of the cache tags are missing
from `cache_d8cache_cache_tags`. This is necessary to ensure that invalidations
will be honored properly even when some of the cache tags have been expired from
the cache tags cache.

### I am using an external caching system / proxy / CDN with key-based invalidation. How should I configure D8Cache for this configuration?

- Ensure your cache invalidation API is set up. Refer to your provider's
documentation for this.
- Ensure there is a module implementing `hook_emit_cache_tags()` and
`hook_invalidate_cache_tags()` to ensure tags are being exposed to the external
system, and are being remotely invalidated correctly.
  - On Pantheon, the [pantheon_advanced_page_cache](https://www.drupal.org/project/pantheon_advanced_page_cache) module will do this for you.
  - Other service providers may have an integration available. Check with your
  provider.
  - See `README.developer.md` for more information.
  - Ensure the performance settings at `?q=admin/config/development/performance`
   are set as appropriate for your provider. Example settings:
     - Cache pages for anonymous users: yes
     - Cache blocks: yes
     - Expiration of cached pages: `15 min` (or personal preference)

### I am using an external caching system / proxy / CDN with key-based invalidation and I would like to disable the page cache entirely. How do I do this with D8Cache?

This method should only be used if you know the access and retention
patterns of the CDN and have determined you can force your CDN to ignore
the `Cache-Control: max-age` header when determining its own cache storage
duration. Otherwise, disabling the page cache may impact performance negatively.

This method works best when you have a busy site using a relatively constant
configuration such as a single varnish cluster with dedicated cache storage
space that has been sized appropriately to store the entire cache, or a two-tier
system where frontend servers are contacting a primary cache server instead of
the backend server.

This method tends to *not* work as well when used with a "Global CDN" that has
many different frontend servers requesting pages from your backend, especially
if they aggressively decay content, unless it is set up in a two-tier manner as
described in the previous paragraph, or have some other way of sharing
the cache data. The more distinct frontend servers are directly contacting the
backend, the more you would get a benefit from leaving the page cache on.

- First of all, if you are using a provider as opposed to an in-house setup,
check your provider's documentation *first*. They may have an easier to follow
guide that is optimized for their platform. The generic guide presented here
assumes a lot of knowledge about how the HTTP protocol and HTTP reverse proxying
work.
- See answer to previous question for configuring invalidation. This is crucial
for this mode, as content will no longer be expiring naturally. The
performance setting 'Expiration of cached pages' will define what the *browser*
sees, not the CDN caching policy.
- Add to `settings.php`:
  ```
  if (!class_exists('DrupalFakeCache')) {
  // Load DrupalFakeCache to allow enabling caching but not storing locally.
  $conf['cache_backends'][] = 'includes/cache-install.inc';
  }
  // Disable the cache_page backing store by using the fake cache backend.
  // Actual invalidation with the external cache is handled through API calls.
  $conf['cache_class_cache_page'] = 'DrupalFakeCache';

  // Collect attachments for blocks and views data.
  $conf['cache_class_cache_block'] = 'D8CacheAttachmentsCollector';
  $conf['cache_class_cache_views_data'] = 'D8CacheAttachmentsCollector';
  ```
- Configure your service provider to enforce a large minimum TTL on cache
objects.
- Verify that the `Cache-Control: max-age` and/or `Expires` header(s) delivered
reflect the 'Expiration of cached pages' setting, and are *not* being set to a
large value by the CDN. Failure to check this can lead to outdated content being
cached for a long time in users' browsers. This is difficult to clean up after.
  - `curl` or a browser's "developer console" are both useful for doing this check.
- Verify that editing content will force the CDN to refresh.
- You will probably want to implement `hook_pre_invalidate_cache_tags_alter()`
in a custom module and prune tags such as `*_list` tags that are expiring
content too aggressively. The decision of what to do here depends on how your
site is constructed. Be careful, it's easy to accidentally neglect to invalidate
something and cause stale content to show up on pages.
- Review your performance metrics afterwards, to ensure that disabling the page
cache has not caused performance regressions.

### Every content change expires all pages. How can I avoid that?
### How can I emit a custom header with cache tags for my special Varnish configuration?
### How can I add a custom cache tag?
### How can I avoid the block and page cache being invalidated when content changes?
### When does max-age "bubble up" to containing cache items and when does it not?

See the corresponding question in README.developer.md.

### Is there more material to learn about cache tags and cache max-age?

The official documentation for Drupal 8 is the best resource right now:

* https://www.drupal.org/docs/8/api/cache-api/cache-tags
* https://www.drupal.org/docs/8/api/cache-api/cache-max-age

The backported API for Drupal 7 should be as similar as possible. See also
the section "Drupal 8 API comparison" in `README.developer.md`.

### My question is not answered here, what should I do?

Please open an issue here:

  https://www.drupal.org/project/issues/d8cache
