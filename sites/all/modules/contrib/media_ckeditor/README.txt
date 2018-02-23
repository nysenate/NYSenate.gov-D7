CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Technical details

INTRODUCTION
------------

Current Maintainers:
 * Joseph Olstad <http://drupal.org/user/1321830>

Previous Maintainers:
 * Devin Carlson <http://drupal.org/user/290182>

Media CKEditor provides a bridge between Media and the stand-alone CKEditor
module, allowing files to be embedded within a textarea using the media browser.

REQUIREMENTS
------------

Media CKEditor has two dependencies.

Contributed modules
 * CKEditor - The latest development release.
 * Media - 7.x-2.x - The Media WYSIWYG submodule.

Additionally, the CKEditor library used by the CKEditor module must meet certain
criteria and two plugins must be available.

CKEditor Library
 * CKEditor - Version 4.3 or later.
   http://ckeditor.com/download

CKEditor Library Plugins
 * CKEditor Line Utilities plugin - Compatible with CKEditor.
   http://ckeditor.com/addon/lineutils
 * CKEditor Widget plugin - Compatible with the installed version of CKEditor.
   http://ckeditor.com/addon/widget

INSTALLATION
------------

***NEW***
  For a quicker and easier setup, follow this recipe
  https://www.drupal.org/node/2843391
  use this README.txt as additional troubleshooting
***end NEW***

* Install Media CKEditor via the standard Drupal installation process:
  'http://drupal.org/node/895232'.
* If you weren't previously using the CKEditor WYSIWYG client-side editor,
  download the CKEditor library (http://ckeditor.com/download) and extract it to
  'sites/all/libraries' or 'sites/sitename/libraries' as you require. The
  extracted folder must be named 'ckeditor'.
* Download the Line Utilities plugin (http://ckeditor.com/addon/lineutils),
  extract it and move it into the 'plugins' directory of the 'ckeditor' folder
  so that it is available at 'ckeditor/plugins/lineutils'.
* Download the Widget plugin (http://ckeditor.com/addon/widget), extract it and
  move it into the 'plugins' directory of the 'ckeditor' folder so that it is
  available at 'ckeditor/plugins/widget'.
* Enable the 'Convert Media tags to markup' filter for the desired text formats
  from the Text Formats configuration page: '/admin/config/content/formats'.
* Enable the 'Plugin for embedding files using Media CKEditor' Media CKEditor
  plugin for the desired text formats from the CKEditor configuration
  page: '/admin/config/content/ckeditor'.
* Disable CKEditor's Advanced Content Filter for each of the text formats.
