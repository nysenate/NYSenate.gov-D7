CONTENTS OF THIS FILE
--------------------

* Introduction
* Requirements
* Installation
* Configuration
* Maintainers


INTRODUCTION
------------

The Semantic Views allows users to alter the default HTML output by the Views module without overriding template files.

* For a full description of the module visit https://www.drupal.org/node/2354711

* To submit bug reports and feature suggestions, or to track changes visit https://www.drupal.org/project/issues/semanticviews


REQUIREMENTS
------------

This module requires the following module:

* Views - https://www.drupal.org/project/views


INSTALLATION
------------

* Install the Semantic Views module as you would normally install a contributed Drupal module. Visit https://www.drupal.org/docs/7/extending-drupal-7/installing-contributed-modules-find-import-enable-configure-drupal-7 for further information.


CONFIGURATION
--------------

1. Navigate to Administration > Modules and enable Semantic Views, Views, and the Views UI modules.
2. Navigate to Administration > Structure > Views and next to the view to edit, select the "Edit" function.
3. In the "Format" fieldset, select the link next to "Format:" (by default it is set to Unformatted list). Select "Semantic Views" and Apply the changes.
4. Select the "Settings" link to view the available options.
5. The "Grouping Title" fieldset allows users to change Elements and Class Attributions when using groups. The view will insert the Grouping's Title Field.
6. The "List" fieldset provides choices for List types and Class attributions. Note: if the output is a HTML list, the row element should also be set to "li".
7. The "Row" fieldset provides choices for the row's Elements and Class attributions. The rows can also be defined by "First/Last every nth" and by "Striping class attributes".
8. Save any changes.

When properly configured, the Semantic Views style plugin can effectively replace Views' own unformatted, HTML List and Grid styles. The row style plugin can let help leverage your theme's other CSS styles more easily.


MAINTAINERS
-----------

* Scyther - https://www.drupal.org/u/scyther
