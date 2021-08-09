CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Customization
 * Maintainers


INTRODUCTION
------------
The UUID Features Integration module provides a mechanism for exporting content
(nodes, taxonomy, fields) into a features module. What's that you say? You
thought features was only for configuration? This module is meant to be used in
the cases where certain pieces of content straddle the line between pure content
and configuration.
You've to configure the entity types / bundles to be exportable. Read the
documentation for further information.


 * For a full description of the module, visit the project page:
   https://www.drupal.org/project/uuid_features


 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/issues/uuid_features


REQUIREMENTS
------------
This module requires the following modules:
 * Features (https://drupal.org/project/features)
 * UUID (https://drupal.org/project/uuid)
 * #808690: Support for filefield (https://www.drupal.org/node/808690)
   for filefield integration


INSTALLATION
------------
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CUSTOMIZATION
-------------
* Customize the UUID Features Integration settings in Administration »
  Structure » Features » UUID export settings.


API
-------------
To alter query of features export options use hook_query_TAG_alter().

It allows to limit or filter export options using custom module to make
them more specific.

Tags available for use:
 * uuid_bean_features_export_options
 * uuid_book_features_export_options
 * uuid_commerce_product_features_export_options
 * uuid_current_search_configuration_features_export_options
 * uuid_field_collection_features_export_options
 * uuid_file_entity_features_export_options
 * uuid_fpp_features_export_options
 * uuid_node_features_export_options
 * uuid_nodequeue_item_features_export_options
 * uuid_panelizer_features_export_options
 * uuid_paragraphs_features_export_options
 * uuid_term_features_export_options
 * uuid_user_features_export_options


MAINTAINERS
-----------
Current maintainers:
 * Peter Philipp (das-peter) - https://www.drupal.org/u/das-peter
 * Brant Wynn (brantwynn) - https://www.drupal.org/u/brantwynn
 * Jeffrey C. - https://www.drupal.org/u/jeffrey-c.
 * Rob Loach (RobLoach) - https://www.drupal.org/u/robloach
 * Ezra Gildesgame (ezra-g) - https://www.drupal.org/u/ezra-g


This project has been sponsored by:
 * Treehouse Agency - https://www.phase2technology.com


