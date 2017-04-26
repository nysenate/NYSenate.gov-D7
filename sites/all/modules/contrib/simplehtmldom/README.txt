                                         simplehtmldom API
==========================================================================================================

OVERVIEW
----------------------

The module is a bridge between PHP Simple HTML DOM Parser (simplehtmldom) library and Drupal.
The library provides powerful API for HTML parsing. Moreover, it works fine with broken markup.
After installing this module you will be able to use PHP Simple HTML DOM Parser functions right in your code.
See more details about library usage here http://simplehtmldom.sourceforge.net/


DEPENDENCIES
----------------------

The module requires PHP Simple HTML DOM Parser library (see INSTALLATION section).
Tested with PHP Simple HTML DOM Parser 1.5.

The module is compatible with Libraries API module, however, it doesn't require it.


INSTALLATION
----------------------

Please copy the latest version of PHP Simple HTML DOM Parser library from http://sourceforge.net/projects/simplehtmldom/
to you libraries folder, for example sites/all/libraries/simplehtmldom/simple_html_dom.php
Then install the module as usual.


UPGRADE FROM 7.x-1.x
----------------------

Replace old simplehtmldom module folder with new one.
Make sure you don't have PHP Simple HTML DOM Parser (simplehtmldom) library inside the module folder.
Install PHP Simple HTML DOM Parser library manually (see INSTALLATION section).
