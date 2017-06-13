INTRODUCTION
------------
A Feeds + Feeds Tamper plugin that resolves strings pulled in from feeds importers
and maps them to Drupal entity IDs, so they can be used as entity references.

Adds support for freeform Entityreference linking when using Feeds.

 * For a full description of the module, visit the project page:
   https://www.drupal.org/project/feeds_tamper_string2id

 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/issues/feeds_tamper_string2id


REQUIREMENTS
------------
This module requires the following modules:
 * Feeds (https://drupal.org/project/feeds)
 * Chaos tools (https://drupal.org/project/ctools)
 * Job scheduler (https://www.drupal.org/project/job_scheduler)


RECOMMENDED MODULES
-------------------
 * Feeds tamper (https://www.drupal.org/project/feeds_tamper):
   Use the Feeds tamper module to get even greater control of your feed import.


INSTALLATION
------------
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CONFIGURATION
-------------
The module has no menu or modifiable settings. There is no configuration page. When
enabled, the module will add additional options to a Feed's node processor mapping
targets and Feed tamper plugin.

Easy example: consume an rss feed and link to a local authors bio page.
 1. Set up a content type where the feeds imports will land (eg Article)
 2. Set up another content type that the first will reference (eg Person)
 3. Add an entityreference field from Article->Person (eg "Attributed Author").
    Configure it to use 'autocomplete' as a data widget.
 4. Create some content of type 'Person' with titles exactly matching the names of
    the 'author' field that will be imported.
 5. Set up the feeds importer using most default settings and mappings for RSS.
 6. Add a mapping from the "Source:Author name" to "Target:Attributed author: Entity
    ID"
 7. Use feeds_tamper to add a "Transform: Convert string into entity ID" action to
    that mapping rule.
 8. Choose the simple "Entityreference autocomplete" method of string resolution.

 * For more information, visit the project page:
   https://www.drupal.org/project/feeds_tamper_string2id


MAINTAINERS
-----------
Current maintainers:
 * Dan Morrison (dman) - https://www.drupal.org/u/dman
