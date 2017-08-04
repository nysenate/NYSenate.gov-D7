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


Gotchas
------------------------------------------------------------------------------
I've observed that after you create new image style it might not appear
immediately in available tokens list. If this is a case, you will need to reset
cache on the Performance page.


Credits / Contact
------------------------------------------------------------------------------
Currently maintained by Damien McKenna [1]. Originally written by Pavel A.
Karoukin [2] with contributions by Pascal Crott [3] and others in the community.


References
------------------------------------------------------------------------------
1: https://www.drupal.org/u/damienmckenna
2: https://www.drupal.org/u/pavel.karoukin
3: https://www.drupal.org/u/hydra
