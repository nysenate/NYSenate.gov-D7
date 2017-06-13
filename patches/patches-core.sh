#!/usr/bin/env bash

# Patch Core.
# Pantheon Pressflow 7 for DROPs.
# https://github.com/pantheon-systems/drops-7.
# Run patches-core.sh from the webroot to process core patches.

# Originally patched to resolve Field Collection hook_update_N issues.
curl https://www.drupal.org/files/issues/drupal-missing_indexes_field_crud-2003746-2.patch | patch -p1

# The drupal_render() function could use a bit more protection d.o issue
# 2884171. Related to NYSENATE-540.
curl  https://www.drupal.org/files/issues/drupal_render_array_checks-2884171-2.patch | patch -p1

# Pantheon apachesolr patches
patch -p1 < patches/contrib/pantheon_apachesolr-handle_indexing_bills-123015.patch
patch -p1 < patches/contrib/pantheon_apachesolr-curl_timeouts-123015.patch
