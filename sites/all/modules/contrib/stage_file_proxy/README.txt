CONTENTS OF THIS FILE
---------------------

* Introduction
* Requirements
* Installation
* Configuration
* Maintainers


INTRODUCTION
------------

The Stage File Proxy module saves you time and disk space by sending requests to
your development environment's files directory to the production environment and
making a copy of the production file in your development site. It makes it
easier to manage local development environments. This module should not be
installed on a server that faces the internet.

 * For a full description of the module visit
   https://www.drupal.org/project/stage_file_proxy

 * To submit bug reports and feature suggestions, or to track changes visit
   https://www.drupal.org/project/issues/stage_file_proxy


REQUIREMENTS
------------

This module does not require any additional modules outside of Drupal core.


INSTALLATION
------------

 * Install the Stage File Proxy module as you would normally install a
   contributed Drupal module. Visit https://www.drupal.org/node/895232 for
   further information.


CONFIGURATION
-------------

Using Drush:
    1. Enable Stage File Proxy
       $ drush en --yes stage_file_proxy
       $ drush variable-set stage_file_proxy_origin "http://www.example.com"

As this module is only going to be needed on pre-production sites, it would be
better to configure this within your settings.php or settings.local.php file.
    1. File proxy to the live site:
       $conf['stage_file_proxy_origin'] = 'http://www.example.com';
    2. To link to the files, and not copy them:
       $conf['stage_file_proxy_hotlink'] = TRUE;
       If this variable is set to TRUE then Stage File Proxy will not transfer
       the remote file to the local machine. It will just serve a 301 (permanent
       URL redirection) and create a link to the original file on the remote
       server.
    3. To make image sizes the correct size:
       $conf['stage_file_proxy_use_imagecache_root'] = FALSE;
       By default, this variable is set to TRUE.
       When set to FALSE, the Stage File Proxy will look for /imagecache/ in the
       URL and request the original file. It will then send a header to the
       browser to allow transfer of the original image so that imagecache can
       resize the file locally.
       This process speeds up future imagecache requests for the same original
       file.
    4. To help with multisites where the files directory is not the same for
       each URL:
       $conf['stage_file_proxy_origin_dir'] = 'sites/default/files';
       If this is set then Stage File Proxy will use a different path for the
       remote files. This is useful for multisite installations where the sites
       directory contains different names for each URL. If the variable is not
       set, it defaults to the same path as the local site
       (sites/default/files).
    5. To include the username and password within the origin URL:
       $conf['stage_file_proxy_origin'] =
       'http://user:password@prelive.example.com';
       This should be done only if the origin site is not publicly accessible
       and protected with basic access authentication.


MAINTAINERS
-----------

 * Greg Knaddison (greggles) - https://www.drupal.org/u/greggles
 * Rob Wilmshurst (robwilmshurst) - https://www.drupal.org/u/robwilmshurst
 * netaustin - https://www.drupal.org/user/199298
 * Axel Rutz (axel.rutz) - https://www.drupal.org/u/axelrutz

The 7.x branch is actively maintained by greggles with support:

 * CARD.com - https://www.card.com
