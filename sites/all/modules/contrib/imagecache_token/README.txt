ImageCache Token
----------------
Module provides additional tokens for image, file and media fields. For each
image style available additional token [node:field_image_field:style_name] will
be provided.


Installation
------------------------------------------------------------------------------
Copy module to sites/all/modules folder and activate ImageCache Token module in
admin panel.


Configuration
------------------------------------------------------------------------------
Because "file" and "media" file types may contain other types of files, not just
images, it is necessary to indicate which fields hold images. Field selection is
controlled via the settings page:

    admin/config/media/imagecache-token

All image fields are automatically supported.


Known problems
------------------------------------------------------------------------------
After creating new image style it might not appear immediately in available
tokens list. To resolve this try reseting the cache on the Performance page or
using Drush.

A known problem with the Token module can result in a timeout attempting to load
the token browser if there are a lot of entity types and/or fields on the site.
The problem is most notable when using the Entity Token module part of the
Entity API module, which is required when using the Commerce system. There is no
current fix for the problem, though there are some workarounds available:
* Even if the token browser is unresponsive, the tokens themselves will still
  work, so experiment with manually creating the tokens.
* Use the Token Tweaks module to limit how many levels of the token tree will
  be displayed:
  https://www.drupal.org/project/token_tweaks
* Collaborate on fixing the problem in the Token module:
  https://www.drupal.org/node/1334456


Credits / Contact
------------------------------------------------------------------------------
Currently maintained by Damien McKenna [1]. Originally written by Pavel A.
Karoukin [2] with contributions by Pascal Crott [3] and others in the community.


References
------------------------------------------------------------------------------
1: https://www.drupal.org/u/damienmckenna
2: https://www.drupal.org/u/pavel.karoukin
3: https://www.drupal.org/u/hydra
