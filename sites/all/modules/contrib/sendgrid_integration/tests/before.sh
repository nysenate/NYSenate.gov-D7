#!/bin/bash

# Simple script to install drupal for travis-ci running.

set -e $DRUPAL_TI_DEBUG

# Ensure the right Drupal version is installed.
echo "Ensure the right Drupal Version."
drupal_ti_ensure_drupal

# Enable simpletest module.
cd "$DRUPAL_TI_DRUPAL_DIR"
echo "DRUPAL TI - Drush Enable Simpletest module"
drush --yes en simpletest
echo "DRUPAL TI - Download Composer module and enable"
drush dl composer-8.x-1.x
echo "DRUPAL TI - Clear Drush cache"
drush cc drush
drush cc all
echo "DRUPAL TI - Delete cache dir"
rm -f "$DRUPAL_TI_CACHE_DIR"/HOME/.drush/cache
drush dl maillog
drush en -y maillog


# Ensure the module is linked into the code base and enabled.
echo "DRUPAL TI - Ensure the module is linked into the code base and enabled"
drupal_ti_ensure_module

# Clear caches and run a web server.
echo "DRUPAL TI - Clear caches"
drupal_ti_clear_caches
echo "DRUPAL TI - Run a web server"
drupal_ti_run_server

