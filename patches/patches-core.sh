#!/usr/bin/env bash

# Patch Core.
# Pantheon Pressflow 7 for DROPs.
# https://github.com/pantheon-systems/drops-7.
# Run patches-core.sh from the webroot to process core patches.

# Originally patched to resolve Field Collection hook_update_N issues.
# See https://www.drupal.org/project/drupal/issues/2003746
curl https://www.drupal.org/files/issues/drupal-missing_indexes_field_crud-2003746-2.patch | patch -p1

# The drupal_render() function could use a bit more protection.
# See https://www.drupal.org/project/drupal/issues/2884171
# Related to NYSENATE-540.
curl  https://www.drupal.org/files/issues/drupal_render_array_checks-2884171-2.patch | patch -p1

# Pantheon apachesolr patches
# See NYSENATE-208.
patch -p1 < patches/core/pantheon_apachesolr-handle_indexing_bills-123015.patch
patch -p1 < patches/core/pantheon_apachesolr-curl_timeouts-123015.patch

# Make tabledrag more performant.
# See https://www.drupal.org/project/drupal/issues/2888143
curl https://www.drupal.org/files/issues/tabledrag_performance_improvement-2888143-1-d7.patch | patch -p1
