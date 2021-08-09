# Pantheon Advanced Page Cache

[![CircleCI](https://circleci.com/gh/pantheon-systems/pantheon_advanced_page_cache/tree/7.x-1.x.svg?style=svg)](https://circleci.com/gh/pantheon-systems/pantheon_advanced_page_cache/tree/7.x-1.x)

Pantheon Advanced Page Cache module is a bridge between [Drupal cache metadata via the Drupal 8 Cache Backport module](https://www.drupal.org/project/d8cache) and the [Pantheon Global CDN](https://pantheon.io/docs/global-cdn/).

Just by turning on this module your Drupal site will start emitting the HTTP headers necessary to make the Pantheon Global CDN aware of data underlying the response. Then, when the underlying data changes (nodes and taxonomy terms are updated, user permissions changed) this module will clear only the relevant pages from the edge cache.

This module has no configuration settings of its own, just enable it and it will start sending data. To control the data being sent, see [the Drupal 8 Cache Backport module](https://www.drupal.org/project/d8cache).

Also, be sure to follow the `settings.php` setup instructions for [Drupal 8 Cache Backport](http://cgit.drupalcode.org/d8cache/tree/README.txt).

## Debugging

By default, Pantheon's infrastructure strips out the `Surrogate-Key` response header before responses are served to clients. The contents of this header can be viewed as `Surrogate-Key-Raw` by adding on a debugging header to the request.

A direct way of inspecting headers is with `curl -I`. This command will make a request and show just the response headers. Adding `-H "Pantheon-Debug:1"` will result in `Surrogate-Key-Raw` being included in the response headers. The complete command looks like this:

 `curl -IH "Pantheon-Debug:1" https://dev-cache-tags-demo.pantheonsite.io/`

 Piping to `grep` will filter the output down to just the `Surrogate-Key-Raw` header:

`curl -IH "Pantheon-Debug:1" https://dev-cache-tags-demo.pantheonsite.io/ | grep -i Surrogate-Key-Raw`

## Limit on header size

Pantheon's nginx configuration limits total header size to 32k.
This module caps the `Surrogate-Key` at 25,000 bytes to minimize the chances that a very long `Surrogate-Key` header combines with other long headers to trigger a 502 error.
This limit can be reached if your site renders thousands of entities in a single response.
You will see warning messages in your log directing you to [the issue queue](https://www.drupal.org/project/pantheon_advanced_page_cache/issues/2973861) if this limit is reached.

## Changing Listing Tags

Prior to the 1.2 release, this module would change the cache tags used on default listings.
This changing of was done to make cache hits more likely but resulted in [confusing cache clearing behavior](https://www.drupal.org/project/pantheon_advanced_page_cache/issues/2944229).
Sites that installed this module prior to 1.1 should uninstall and reinstall or run this command to update their settings.

```
terminus drush [MACHINE-NAME-OF-SITE].[ENV-NAME] -- vset pantheon_advanced_page_cache_override_list_tags FALSE
```

## Feedback and collaboration

For real time discussion of the module find Pantheon developers in our [Power Users Slack channel](https://pantheon.io/docs/power-users/). Bug reports and feature requests should be posted in [the drupal.org issue queue.](https://www.drupal.org/project/issues/pantheon_advanced_page_cache?categories=All) For code changes, please submit pull requests against the [GitHub repository](https://github.com/pantheon-systems/pantheon_advanced_page_cache) rather than posting patches to drupal.org.
