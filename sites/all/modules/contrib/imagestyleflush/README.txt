Image style flush
==================

This module will allow Drupal to flush all image styles at once or flush each image style individually right from administrative interface.

Features
--------

  - Flush all image styles
  - Flush each image style individually

This module was written by Stepan Kuzmin.

Dependencies
------------

The image (core) module.

Install
-------

1) Copy the imagestyleflush folder to the modules folder in your installation. Usually
   this is sites/all/modules.
   Or use the UI and install it via admin/modules/install.

2) In your Drupal site, enable the module under Administration -> Modules
   (/admin/modules).

Usage
-----

  You can flush image styles under Administration -> Configuration -> Media -> Image styles

Known problems
--------------

Private file image styles can't be flushed with this module.
