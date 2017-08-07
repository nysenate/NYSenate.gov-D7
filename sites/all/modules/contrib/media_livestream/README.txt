
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Configuration
 * Usage
 * Known issues
 * Upgrade notes
 * Further reading
 * Notes
 * Api docs


INTRODUCTION
------------

The Media: Livestream 7.x-1.0 module intergrates with the Media module to offer an
easy way to add Livestream live channels and recorded videos to your website.
The videos / channels will be added as a 'file entity', enabling a wide variety of
options for developers. Media: Livestream offers a very user-friendly experience
for adding, managing, and maintaining a large database of Livestream videos and
channels on their site.

The module is currently complete, though additional features such as a search function
for Livestream videos / channels are in experimental development.

What works:
- Adding recorded media and live channels from Livestream to media 1.x and 2.x
  (selector) enabled file fields.
- Thumbnails.
- Editing media via the 'manage files' page.
- All player settings and layouts.

What does not:
- new.livestream.com - If you are on the new platform, this module can not
  work for you at this stage, see 'Known issues' below for an explanation.


INSTALLATION
------------

Installation is like any other module, just place the files in the
sites/all/modules directory and enable the module on the modules page.

This module is able to use the transliteration module to transliterate image
file names to a correct format before saving them to the disk. If the
transliteration module is not installed, the video id is used as a file name.
See the transliteration project page for more information:
http://drupal.org/project/transliteration


CONFIGURATION
-------------

- Add a new "file" type field to your content type or entity. Choose the widget
  type "Media file selector". You can also select an existing file field.

- While setting up the field (or after selecting "edit" on an existing field)
  enable these checkboxes:
    - Enabled browser plugins: "Web"
    - Allowed remote media types: "Video"
    - Allowed URI schemes: "livestream:// (Livestream videos)"

- You also need to add 'Livestream' to the 'Allowed streams'
  section on the file entity 'video' configuration page. See:

  admin/structure/file-types/manage/video/edit

- Configure (autoplay) options:

  The easiest way to use (for example) the 'autoplay' options is to install
  the entity_view_mode module and create a new view mode for the 'file' entity.
  Then visit the file entity video configuration page at:

  admin/structure/file-types/manage/video/file-display

  Click on your new mode and enable 'autoplay'. Now you can use this new mode
  in views and on the node display configuration pages to render your
  autoplay-video / channel.

  This works identical for all other options.


USAGE
-----

- Add a new node of the content type set up in the Configuration section above.

- Click on the 'Select media' button to add a file, and select the Web
tab in the Media dialog.

- Paste either a channel/video URL, or a Livestream embed code, into the
"URL or Embed code" field.

- Click Submit. Once the video has been loaded, you may choose to
rename the video from the title it has on the Livestream site.

Then click Save, and you're done.


KNOWN ISSUES
------------

- Coding style is ok, but the coding comments need work.
  MediaInternetLivestreamHandler.inc & MediaLivestreamStreamWrapper.inc

- Settings for Wysiwyg editor button are not configurable.

- If your site has the EPSACrop module installed, you may see an error message
  about "getimagesize()" after you Submit a URL/embed code. This message is
  benign, and can be safely ignored.

- I'm on the 'new' Livestream, but i can not add videos via this module!?
  As per: http://www.livestream.com/forum/showthread.php?t=9261 we do not
  know if and when Livestream will open up the api. Go ask them, not us.
  404 not found on the roadmap: http://new.livestream.com/pages/about/roadmap


UPGRADE NOTES
-------------

We do not offer an upgrade path at this stage, but patches are always welcome,
but we do not expect an upgrade path will be supported any time soon.


BRAINSTORM
----------

- Add an option to be able to always render the channel logo, or the banner.
- Cron function to update channel details/logos, latest videos stream.
- Search Livestream > Search Media module is in development for this.
- Show live channels tab on the media browser popup.
- Login to Livestream via your website and have the ability
  to add files from the Livestream files you have access to.
- Keep on tracking the Livestream developers for interesting developments.
- Do player colors still work? If so: implement them (maybe with a nice colorpicker).


FURTHER READING
---------------

- Media 2.x Overview, including file entities and view modes:
  http://drupal.stackexchange.com/questions/40229/how-to-set-media-styles-in-media-7-1-2-media-7-2-x/40685#40685
- Media 2.x Walkthrough: http://drupal.org/node/1699054
- A site with some useful information: http://drupalmedia.freeworldmedia.nl/book/howtos-guides


API DOCS
--------

http://www.livestream.com/userguide/index.php?title=Account_API
http://www.livestream.com/userguide/index.php?title=Channel_API
http://www.livestream.com/userguide/index.php?title=Guide_API
http://www.livestream.com/userguide/index.php?title=Live_Thumbnail_API
