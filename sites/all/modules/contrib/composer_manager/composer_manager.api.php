<?php

/**
 * @file
 * Hooks provided by the Composer Manager module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to alter the consolidated JSON array.
 *
 * @param array &$json
 *   The consolidated JSON compiled from each module's composer.json file.
 */
function hook_composer_json_alter(&$json) {
  $json['minimum-stability'] = 'dev';
}

/**
 * Allow modules to perform tasks after a composer install has been completed.
 */
function hook_composer_dependencies_install() {
  // Tasks that require a composer install to have been performed.
}

/**
 * @} End of "addtogroup hooks".
 */
