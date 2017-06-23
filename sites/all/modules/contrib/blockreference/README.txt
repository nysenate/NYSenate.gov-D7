
Block reference README

CONTENTS OF THIS FILE
----------------------

  * Introduction
  * Installation
  * Usage
  * Theming
  * Notes


INTRODUCTION
------------
Defines a field type Block reference which creates a relationship to a block and
allows the block to be displayed as the content of the field.

Project page: http://drupal.org/project/blockreference.


INSTALLATION
------------
Install and enable the Block reference module.
For detailed instructions on installing contributed modules see:
http://drupal.org/documentation/install/modules-themes/modules-7


USAGE
-----
Block reference fields will now be available in the Field UI.
For detailed instructions on using the Field UI see:
http://drupal.org/documentation/modules/field-ui


THEMEING
--------
To assist in themeing blocks that are displayed using the block reference
module, the block reference element is available in the $variables array in
template_preprocess_block().

The element can be found at:

    $variables['elements']['#blockreference_element']

Note that the element will not be there for non-blockreference blocks so you
should first check the existence of the element before using its contents.


NOTES
-----
* Relationships are saved using the block's `bid`, not its delta +
  module.
* Block configuration visibility settings are respected since version
  7.x-1.14. If a referenced block does not appear when viewing the node,
  check the block's visibility settings on /admin/structure/block. Note
  that visibility settings are evaluated regardless of whether the
  block is assigned to a region.
