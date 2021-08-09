# Drupal 8 Cache Backport (D8Cache)

This guide contains information on the API and developer interfaces of D8Cache.
For information on configuring D8Cache, see `README.md`.

Drupal 8 API comparison
-----------------------
While D8Cache is similar to the Drupal 8 Cache API, there are some
differences due to fundamental changes in the way Drupal 8 and Drupal 7 handle
page generation.

| Drupal 8 API                                         | Drupal 7 D8Cache API
| ---------------------------------------------------- | --------------------
| Cache::invalidateTags($tags)                         | drupal_invalidate_cache_tags($tags)
| onResponseListener() / $response->getCacheTags()     | drupal_get_cache_tags()
| onResponseListener() / $response->getCacheMaxAge()   | drupal_get_cache_max_age()
| onResponseListener() / $response->getCacheContexts() | [TBD]
| onResponseListener() / $response->addCacheTags()     | drupal_pre_emit_cache_tags_alter()
| onResponseListener() / $response->mergeCacheMaxAge() | drupal_pre_emit_cache_max_age_alter()
| onResponseListener() / $response->addCacheContexts() | [TBD]
| CacheableMetadata::fromRenderArray($build)           | drupal_get_cacheable_metadata_from_render_array($build)
| $build['#cache']['tags'][] = 'node'                  | $build['#attached']['drupal_add_cache_tags'][] = array($tags);
| $build['#cache']['max-age'] = 900                    | $build['#attached']['drupal_set_cache_max_age'][] = array(900);
| $build['#cache']['contexts'] = 'user'                | $build['#attached']['drupal_add_cache_contexts'][] = array(array('user'));
| $cache->set($cid, $data, $expire, $tags)             | _cache_get_object($bin)->set($cid, $data, $expire, $tags)
| $cache->get($cid, $allow_invalid == TRUE)            | _cache_get_object($bin)->get($cid, TRUE)
| $cache->getMultiple($cid, $allow_invalid == TRUE)    | _cache_get_object($bin)->getMultiple($cids, TRUE)

Note: Cache contexts have not been implemented yet in D8Cache.

Note: Calling code should check that the returned object from
`_cache_get_object($bin)` implements the `DrupalTaggableCacheInterface` before
calling `DrupalTaggableCacheInterface` methods. This is the case for all objects
handled by the `D8Cache` and `D8CacheAttachmentsCollector` cache backends.

Note: Drupal 8 uses `max-age` values much more consistently than Drupal 7.
Drupal 7 uses hardcoded expiration timestamps extensively, so conversion must be
done back and forth.
Be careful when working with `$max_age` and `$expire`, as they are fundamentally
different!

Which cache tags are invalidated by default?
--------------------------------------------

While in Drupal 8 even a configuration change does invalidate certain cache
tags, that does make less sense in Drupal 7.

Code that is deployed should clear e.g. the 'rendered' cache tag
via:

```
  drupal_invalidate_cache_tags(array('rendered'));
```

manually to refresh the cache. Alternatively a drush cc all will also continue
to be effective.

The cache tags in Drupal 7 deal only with 'content' not with configuration. And
users and menus are considered content here, too.

The line is drawn where things are edited live by content editors (not admins)
vs. things that should be deployed via features / in code.

D8CacheAttachmentsCollector
---------------------------

The `D8CacheAttachmentsCollector` ensures that no procedural calls to
`drupal_add_cache_tags()` or `drupal_set_cache_max_age()` get lost.

In the future (once core support for it is included) this will also
automatically collect attachments from `drupal_add_*()` functions, which
will automatically collect assets like 'js', 'css' or 'library'.

This will make render caching in Drupal 7 easier than ever before.

The `D8CacheAttachmentsCollector` also has special code for the block
module to ensure its `cache_get_multiple()` support does not break the
asset collection.

The hope is that eventually large parts of D8Cache will become part of Drupal 7
core itself.

Once block cache and render cache in core are fixed, then the
`D8CacheAttachmentsCollector` will mostly be useful for views and panels to give
them the ability to collect assets as well.

Note: As the page cache is served before all modules are loaded, you must
not use `D8CacheAttachmentsCollector` for the 'cache_page' bin!

Frequently asked questions - Developers
---------------------------------------
For configuration-related questions, see the corresponding FAQ in `README.md`.

### Every content change expires all pages. How can I avoid that?

Unfortunately once you add e.g. a recent_content block to the sidebar, d8cache
will add a node_list cache tag, which is cleared whenever an entity of that type
is created, updated or deleted.

To avoid this problem you can implement hook_pre_invalidate_cache_tags_alter()
to remove the node_list cache tag:

```
  /**
   * Implements hook_pre_invalidate_cache_tags_alter().
   */
  function mymodule_pre_invalidate_cache_tags_alter(&$tags) {
    $index_tags = array_flip($tags);

    if (isset($index_tags['node_list'])) {
      unset($tags[$index_tags['node_list']]);
    }
  }
```

The best way to expire your pages for node listings is to manually clear your cache tags.

### How can I emit a custom header with cache tags for my special Varnish configuration?

You can implement `hook_emit_cache_tags()` and use `drupal_add_http_header()`, e.g.:

```
  /**
   * Implements hook_emit_cache_tags().
   */
  function mymodule_emit_cache_tags($tags) {
    drupal_add_http_header('Surrogate-Key', implode(' ', $tags));
  }
```

### How can I react to cache tag invalidations?

You can implement `hook_invalidate_cache_tags()` like this:

```
  /**
   * Implements hook_invalidate_cache_tags().
   */
  function mymodule_invalidate_cache_tags($tags) {
    mycustom_varnish_clear_cache_tags($tags);
  }
```

### How can I add a custom cache tag?

In the code that needs a custom cache tag use:

```
  drupal_add_cache_tags(array('mymodule:custom-tag'));
```

In case that you need to put it into a render array use:

```
$build['#attached']['drupal_add_cache_tags'][] = array(
  array('mymodule:custom-tag'),
);
```

### How can I avoid the block and page cache being invalidated when content changes?

Unfortunately core's internal block and page caches are invalidated when content
changes automatically. The reason is that those cache bins use `CACHE_TEMPORARY`,
which is cleared during cron runs.

The d8cache module has a built-in configuration option to avoid this and make
cache items PERMANENT instead. In your settings.php use:

```
  $conf['d8cache_cache_options']['cache_block']['ttl'] = CACHE_PERMANENT;
  $conf['d8cache_cache_options']['cache_page']['ttl'] = CACHE_PERMANENT;
```

to make all block and page caches permanent. To set them to 1 hour instead, use:

```
  $conf['d8cache_cache_options']['cache_block']['ttl'] = 3600;
```

Alternatively you can also use `CACHE_PERMANENT` (maximum) and then in your code
use:

```
  drupal_set_cache_max_age(3600);
```

to restrict the max-age further down on a per block basis.

Note that this max-age is bubbled up to cache_page, but not for external
proxies like Varnish.

To emit a specific `Cache-Control` header based on the max-age set by the page, use:

```
  /**
   * Implements hook_emit_cache_max_age().
   */
  function mymodule_emit_cache_max_age($max_age) {
    $page_cache_maximum_age = variable_get('page_cache_maximum_age', 0);
    if ($max_age == CACHE_MAX_AGE_PERMANENT || $max_age > $page_cache_maximum_age);
      $max_age = $page_cache_maximum_age;
    }
    if (!isset($_COOKIE[session_name()])) {
      header('Cache-Control', 'public, max-age=' . $max_age);
    }
  }
```

### When does max-age "bubble up" to containing cache items and when does it not?

Due to legacy reasons neither a 'ttl' set via $conf in settings.php nor a time
set via 'expire' (e.g. via a time based views cache plugin) is taken as a
cache max-age value in the sense that it affects the whole page.

If you need this add:

```
  drupal_set_cache_max_age(3600);
```

in your code somewhere and every upper cache layer will be affected (except for
Varnish as stated already above).


### I want to use d8cache in my contrib module to expire my cache using tags -- how can I do that?

First of all you need to depend on 'd8cache' and then you should use:

```
  $cache = d8cache_cache_get_object('cache_mymodule');
  $cache->set($cid, $data, $expire, $tags);
```

While there is no function to set tags, using the cache object directly in this
way is the best way to achieve that.

### Is there more material to learn about cache tags and cache max-age?

The official documentation for Drupal 8 is the best resource right now:

* https://www.drupal.org/docs/8/api/cache-api/cache-tags
* https://www.drupal.org/docs/8/api/cache-api/cache-max-age

The backported API for Drupal 7 should be as similar as possible. See also
the section "Drupal 8 API comparison" above.

### My question is not answered here, what should I do?

Please open an issue here:

  https://www.drupal.org/project/issues/d8cache

