
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


INTRODUCTION
------------

The Media: UStream 7.x-1.0 module intergrates with the Media module to offer an
easy way to add UStream live channels and recorded videos to your website. The videos /
channels will be added as a 'file entity', enabling a wide variety of
options for developers. Media: UStream offers a very user-friendly experience
for adding, managing, and maintaining a large database of UStream videos and
channels on their site.

The module is currently complete, though additional features such as a search function
for UStream videos are in experimental development.

What works:
- Adding recorded media and live channels from UStream to media 2.x
  (selector) enabled file fields.
- Thumbnails for both channels and recordings.
- Screencaptures only work for recordings.
- Editing media via the 'manage files' page.
- Setting the player color.
- Autoplay channels / recordings.


INSTALLATION
------------

Installation is like any other module, just place the files in the
sites/all/modules directory and enable the module on the modules page.


CONFIGURATION
-------------

- Add a new "file" type field to your content type or entity. Choose the widget
  type "Media file selector". You can also select an existing file field.

- While setting up the field (or after selecting "edit" on an existing field)
  enable these checkboxes:
    - Enabled browser plugins: "Web"
    - Allowed remote media types: "Video"
    - Allowed URI schemes: "ustream:// (UStream videos)"

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

- Paste either a channel/video URL, or a UStream embed code, into the
"URL or Embed code" field.

- Click Submit. Once the video has been loaded, you may choose to rename the
video from the title it has on the UStream site. Then click Save, and you're done.


URL FORMATS
-----------

Media: Ustream supports all URLs in the following formats:
http://www.ustream.tv/channelname       (live channels)
http://www.ustream.tv/channel/[name]    (live channels)
http://www.ustream.tv/recorded/[id]     (recorded videos)

This module also supports all embed codes created by the "<>" button in
the Share menu of videos and channels.

UStream has recently begun using URLs with the http://www.ustream.tv/[name] 
format, for which Media: UStream has only spotty support. UStream's API does
not support retrieval of user or channel information for every existing [name]
from these kinds of URLs, so Media: UStream has no recourse but to report an
error for some of these URLs. I you get such an error, please use an embed
code for the channel or video you're interested in.

KNOWN ISSUES
------------

- Coding style is ok, but the coding comments need work.
  MediaInternetUStreamHandler.inc & MediaUStreamStreamWrapper.inc
- Settings for Wysiwyg editor button are not configurable.
- Unable to upload video to UStream: True, see for more information:
  http://community.ustream.tv/ustream/topics/can_i_upload_and_record_to_ustream_without_broadcasting_live
  http://community.ustream.tv/ustream/topics/how_and_where_do_i_upload_video_to_my_ustream_basic_account
- If your site has the EPSACrop module installed, you may see an error message
  about "getimagesize()" after you Submit a URL/embed code. This message is
  benign, and can be safely ignored.


UPGRADE NOTES
-------------

We do not offer an upgrade path at this stage, but patches are always welcome.


BRAINSTORM
----------

- Add an option to be able to always render the channel logo.
- Cron function to update channel logos.
- Search Ustream > Search Media module is in development for this.
- Show live channels tab on the media browser popup.
- Login to UStream via your website and have the ability
  to add files from the UStream files you have access to.
- Keep on tracking the UStream developers for interesting developments.
- Create something like this for the 'media' module:
  http://drupalcode.org/project/media_gallery.git/blob/HEAD:/images/empty_gallery.png


FURTHER READING
---------------

- Media 2.x Overview, including file entities and view modes:
  http://drupal.stackexchange.com/questions/40229/how-to-set-media-styles-in-media-7-1-2-media-7-2-x/40685#40685
- Media 2.x Walkthrough: http://drupal.org/node/1699054
- A site with some useful information: http://drupalmedia.freeworldmedia.nl/book/howtos-guides
