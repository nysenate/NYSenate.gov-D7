
Slick Carousel
================================================================================

Slick is a powerful and performant slideshow/carousel solution leveraging Ken
Wheeler's Slick carousel.
See http://kenwheeler.github.io/slick

Powerful: Slick is one of the sliders [1], as of 9/15, the only one [2], which
supports nested sliders and a mix of lazy-loaded image/video/audio with
image-to-iframe or multimedia lightbox switchers.
See below for the supported media.

Performant: Slick is stored as plain HTML the first time it is requested, and
then reused on subsequent requests. Carousels with cacheability and lazyload
are lighter and faster than those without.

Slick has gazillion options, please start with the very basic working samples
from slick_example [3] only if trouble to build slicks. Be sure to read
its README.txt. Spending 5 minutes or so will save you hours in building more
complex slideshows.

[1] https://groups.drupal.org/node/20384
[2] https://www.drupal.org/node/418616
[3] http://dgo.to/slick_extras

FEATURES
--------------------------------------------------------------------------------
o Fully responsive. Scales with its container.
o Uses CSS3 when available. Fully functional when not.
o Swipe enabled. Or disabled, if you prefer.
o Desktop mouse dragging.
o Fully accessible with arrow key navigation.
o Built-in lazyLoad, and multiple breakpoint options.
o Random, autoplay, pagers, arrows, dots/text/tabs/thumbnail pagers etc...
o Supports pure text, responsive image, iframe, video, and audio carousels with
  aspect ratio. No extra jQuery plugin FitVids is required. Just CSS.
o Exportable via CTools.
o Works with Views, core and contrib fields: Image, Media or Field collection,
  or none of them.
o Optional and modular skins, e.g.: Carousel, Classic, Fullscreen, Fullwidth,
  Split, Grid or a multi row carousel.
o Various slide layouts are built with pure CSS goodness.
o Nested sliders/overlays, or multiple slicks within a single Slick via Field
  collection, or Views.
o Some useful hooks and drupal_alters for advanced works.
o Modular integration with various contribs to build carousels with multimedia
  lightboxes or inline multimedia.
o Media switcher: Image linked to content, Image to iframe, Image to colorbox,
  Image to photobox.
o Cacheability + lazyload = light + fast.



VERSIONS
--------------------------------------------------------------------------------
7.x-2.x supports exportable optionsets via CTools.
Be sure to run update, when upgrading from 7.x-1.x to 7.x-2.x.

7.x-2.1+ supports Slick 1.6 above.
7.x-2.0- supports Slick 1.5.9 below.
Slick 2.x is just out 9/21/15, and hasn't been officially supported now, 9/27.


INSTALLATION
--------------------------------------------------------------------------------
Install the module as usual, more info can be found on:
http://drupal.org/documentation/install/modules-themes/modules-7

The Slick module has several sub-modules:
- slick_ui, included, to manage optionsets, can be uninstalled at production.

- slick_fields, included, supports Image, Media, and Field collection fields.

- slick_views, to get more complex slides.
  http://dgo.to/slick_views

- slick_devel, if you want to help testing and developing the Slick.
- slick_example, to get up and running quickly.
  Both are included in slick_extras post beta1 (2015-5-31):
  http://dgo.to/slick_extras


REQUIREMENTS
--------------------------------------------------------------------------------
- Slick library:
  o Download Slick archive >= 1.5 from https://github.com/kenwheeler/slick/
  o Extract it as is, rename "slick-master" to "slick", so the assets are at:

    sites/../libraries/slick/slick/slick.css
    sites/../libraries/slick/slick/slick-theme.css (optional if a skin chosen)
    sites/../libraries/slick/slick/slick.min.js

- CTools, for exportable optionsets -- only the main "Chaos tools" is needed.
  If Panels or Views is installed, CTools is already enabled.

- libraries (>=2.x)

- jquery_update with jQuery > 1.7, perhaps 1.8 if trouble with the latest Slick.

- Download jqeasing from https://github.com/gdsmith/jquery.easing, so available
  at:
  sites/../libraries/easing/jquery.easing.min.js
  This is CSS easing fallback for non-supporting browsers.



OPTIONAL INTEGRATION
--------------------------------------------------------------------------------
Slick supports enhancements and more complex layouts.

- Colorbox, to have grids/slides that open up image/video/audio in overlay.
- Photobox, idem ditto.
- Picture, to get truly responsive image.
- Media, including media_youtube, media_vimeo, and media_soundcloud, to have
  fairly variant slides: image, video, audio, or a mix of em.
- Field Collection, to add Overlay image/audio/video over the main image stage,
  with additional basic Scald integration for the image/video/audio overlay.
- Color field module within Field Collection to colorize the slide individually.
- Mousewheel, download from https://github.com/brandonaaron/jquery-mousewheel,
  so it is available at:
  sites/.../libraries/mousewheel/jquery.mousewheel.min.js


RECOMMENDED MODULES
--------------------------------------------------------------------------------
- Block reference to have more complex slide content for Fullscreen/width skins.
- Field formatter settings, to modify field formatter settings and summaries.


OPTIONSETS
--------------------------------------------------------------------------------
To create your optionsets, go to:

  admin/config/media/slick

Be sure to enable Slick UI sub-module first, otherwise regular "Access denied".
These will be available at field formatter "Manage display", and Views UI.


VIEWS AND FIELDS
--------------------------------------------------------------------------------
Slick works with Views and as field display formatters.
Slick Views is available as a style plugin included at slick_views.module.
Slick fields is available as a display formatter included at slick_fields.module
which supports core and contrib fields: Image, Media, Field collection.


PROGRAMATICALLY
--------------------------------------------------------------------------------
See slick_fields.module for advanced sample, or slick.api.php for a simple one.


NESTED SLICKS
--------------------------------------------------------------------------------
Nested slick is a parent Slick containing slides which contain individual child
slick per slide. The child slicks are basically regular slide overlays like
a single video over the large background image, only with nested slicks it can
be many videos displayed as a slideshow as well.
Use Field collection, or Views to build one.
Supported multi-value fields for nested slicks: Image, Media, Atom reference.


SKINS
--------------------------------------------------------------------------------
The main purpose of skins are to demonstrate that often some CSS lines are
enough to build fairly variant layouts. No JS needed. Unless, of course, for
more sophisticated slider like spiral 3D carousel which is beyond what CSS can
do. But more often CSS will do.

Skins allow swappable layouts like next/prev links, split image or caption, etc.
with just CSS. Be sure to enable slick_fields.module and provide a dedicated
slide layout per field to get more control over caption placements. However a
combination of skins and options may lead to unpredictable layouts, get
yourself dirty.

Optional skins:
--------------
- None
  It is all about DIY.
  Doesn't load any extra CSS other than the basic styles required by slick.
  Skins defined by sub-modules fallback to those defined at the optionset.
  Be sure to empty the Optionset skin to disable the skin at all.
  If you are using individual slide layout, do the layouts yourself.

- 3d back
  Adds 3d view with focal point at back, works best with 3 slidesToShow,
  centerMode, and caption below the slide.

- Classic
  Adds dark background color over white caption, only good for slider (single
  slide visible), not carousel (multiple slides visible), where small captions
  are placed over images, and animated based on their placement.

- Full screen
  Works best with 1 slidesToShow. Use z-index layering > 8 to position elements
  over the slides, and place it at large regions. Currently only works with
  Slick fields, use Views to make it a block. Use block_reference inside FC to
  have more complex contents inside individual slide, and assign it to Slide
  caption fields.

- Full width
  Adds additional wrapper to wrap overlay audio/video and captions properly.
  This is designated for large slider in the header or spanning width to window
  edges at least 1170px width for large monitor. To have a custom full width
  skin, simply prefix your skin with "full", e.g.: fullstage, fullwindow, etc.

- Boxed
  Added a 0 60px margin to slick-list container and hide neighboring slides.
  An alternative to centerPadding which still reveals neighboring slides.

- Split
  Caption and image/media are split half, and placed side by side. This requires
  any layout containing "split", otherwise useless.

- Box carousel
  Added box-shadow to the carousel slides, multiple visible slides. Use
  slidesToShow option > 2.

- Boxed split
  Caption and image/media are split half, and have edge margin 0 60px.

- Grid
  Only reasonable if you have considerable amount of slides.
  Uses the Foundation 5.5 block-grid, and disabled if you choose your own skin
  not named Grid. Otherwise overrides skin Grid accordingly.

  Requires:
  "Visible slides", Skin "Grid" for starter, A reasonable amount of slides,
  Optionset with "Rows" and "slidesPerRow = 1".
  Avoid "variableWidth" and "adaptiveHeight". Use consistent dimensions.
  This is module feature, older than core Rows, and offers more flexibility.
  Available at slick_views, and configurable via Views UI.

- Rounded, should be named circle
  This will circle the main image display, reasonable for small carousels, maybe
  with a small caption below to make it nice. Use "slidesToShow" option > 2.
  Expecting square images.

If you want to attach extra 3rd libraries, e.g.: image reflection, image zoomer,
more advanced 3d carousels, etc, simply put them into js array of the target
skin. Be sure to add proper weight, if you are acting on existing slick events,
normally < 0 (slick.load.min.js) is the one.

Use hook_slick_skins_info() to register ones.
See slick.slick.inc, or slick.api.php for more info on skins.


GRID
--------------------------------------------------------------------------------
To create Slick grid or multiple rows carousel, there are 3 options:

1. One row grid managed by library:
   Visit "admin/config/media/slick",
   Edit current optionset, and set
   slidesToShow > 1, and Rows and slidesperRow = 1

2. Multiple rows grid managed by library:
   Visit "admin/config/media/slick",
   Edit current optionset, and set
   slidesToShow = 1, Rows > 1 and slidesPerRow > 1

3. Multiple rows grid managed by Module:
   Visit "admin/structure/views/view/slick_x/edit/block_grid" at slick_example,
   Be sure to install the Slick example sub-module first.
   Requires skin "Grid", and set
   slidesToShow, Rows and slidesPerRow = 1.

The first 2 are supported by core library using pure JS approach.
The last is the Module feature using pure CSS Foundation block-grid. The key is:
the total amount of Views results must be bigger than Visible slides, otherwise
broken Grid, see skin Grid above for more details.


HTML STRUCTURE
--------------------------------------------------------------------------------
Note, non-BEM classes are added by JS.
<div class="slick slick-processed">
  <div class="slick__slider slick-initialized slick-slider">
    <div class="slick__slide"></div>
  </div>
  <nav class="slick__arrow"></nav>
</div>

asNavFor should target slick-initialized class/ID attributes.


BUG REPORTS OR SUPPORT REQUESTS
--------------------------------------------------------------------------------
A basic knowledge of Drupal site building is required. If you get stuck:

  o consult the provided READMEs,
  o descriptions on each form item,
  o the relevant guidelines from the supported modules,
  o consider the project issue queues, your problem may be already addressed,
  o install slick_example.

If you do have bug reports, we love bugs, please:
  o provide steps to reproduce it,
  o provide detailed info, a screenshot of the output and Slick form, or words
    to identify it any better,
  o make sure that the bug is caused by the module.

For the Slick library bug, please report it to the actual library:
  https://github.com/kenwheeler/slick

You can create a fiddle to isolate the bug if reproduceable outside the module:
  http://jsfiddle.net/

For the support requests, a screenshot of the output and Slick form is helpful.
Shortly, you should kindly help the maintainers with detailed info to help you.
Thanks.


TROUBLESHOOTING
--------------------------------------------------------------------------------
- When upgrading from Slick v1.3.6 to later version, try to resave options at:
  o admin/config/media/slick
  o admin/structure/types/manage/CONTENT_TYPE/display
  o admin/structure/views/view/VIEW
  only if trouble to see the new options, or when options don't apply properly.
  Most likely true when the library adds/changes options, or the module
  does something new.

- Always clear the cache, and re-generate JS (if aggregation is on) when
  updating the module to ensure things are picked up:
  o admin/config/development/performance

- If switching from beta1 to the latest via Drush fails, try the good old UI.
  Be sure to clear cache first, then run /update.php, if broken slick.

- If you are customizing template files, or theme functions, be sure to re-check
  against the latest.

- A Slick instance may be cached by its ID. Having two different slicks with the
  same ID will cause the first one cached override the second.
  IDs are guaranteed unique if using sub-modules. However if you do custom works,
  or input one at Slick Views UI, be sure to have unique IDs as they should be.
  Be sure no useless/ sensitive data such as "Edit link" as they may be rendered
  as is regardless permissions.

- Current slide previously has a workaround class "slide--current". Core added
  "slick-current" later (a year or so) at v1.5.6. Now (8/25/15) "slide--current"
  is dropped for "slick-current", but the workaround is still kept due to core
  known issue with asNavFor and nested slicks not having proper "slick-current".
  If you use "slide--current" before, be sure to update it to "slick-current".


KNOWN ISSUES
--------------------------------------------------------------------------------
- Slick admin CSS may not be compatible with your private or contrib admin
  themes. Only if trouble with admin display, please disable it at:
  admin/config/media/slick/ui

- The Slick lazyLoad is not supported with picture-enabled images. Slick only
  facilitates Picture to get in. The image formatting is taken over by Picture.
  Some other options such as Media switchers are currently not supported either.

- Photobox is best for:
  - infinite true + slidesToShow 1
  - infinite false + slidesToShow N
  If "infinite true + slidesToShow > 1" is a must, but you don't want dup
  thumbnails, simply override the JS to disable 'thumbs' option.

- The following is not module related, but worth a note:
  o lazyLoad ondemand has issue with dummy image excessive height.
    Added fixes to suppress it via "Aspect ratio" option.
  o If the total < slidesToShow, Slick behaves. Previously added a workaround to
    fix this, but later dropped and handed over to the core instead.
  o Fade option with slideToShow > 1 will screw up.
  o variableWidth ignores slidesToShow.
  o Too much centerPadding at small device affects slidesToShow.
  o Infinite option will create duplicates or clone slides which look more
    obvious if slidesToShow > 1. Simply disable it if not desired.
  o As of v1.6.0, the parent of nested slicks is not lazyloading ondemand
    correctly, settings it to progressive will do till the fix is there.
  o If thumbnail display is Infinite, the main one must be infinite too, else
    incorrect syncing.


PERFORMANCE
--------------------------------------------------------------------------------
Any module, even the most innocent one, that provides settings in the UI needs
to store them in a table. The good thing is we can store them in codes.

With Bulk exporter, or Features, optionsets may be stored in codes. Be sure to
revert to Default via UI to avoid database lookup.
It is analog to Drupal 8 CMI, so it is the decent choice today.

See slick_example for the stored-in-code samples.

Store large array of skins at my_module.slick.inc to get advantage of Drupal
autoloading while short ones should be left in the main module file so that
they are always available.

Most heavy logic were already moved to backend, however slick can be optimized
more by configuring the "Cache" value per slick instance.

Note: Slick is already faster, lighter and less memory than similar[1]
solutions[2] for anonymous users with just Drupal cache. The builtin Slick Cache
option is more useful for authenticated traffic, best with Authcache.
Leave empty to disable caching, or if traffics are mostly anonymous.

[1] https://www.drupal.org/node/2313461#comment-10817842
[2] https://www.drupal.org/node/2463305#comment-10850288


QUICK PERFORMANCE TIPS
--------------------------------------------------------------------------------
- Use lazyLoad "ondemand" / "anticipated" for tons of images, not "progressive".
  Unless within an ajaxified lightbox.
- Tick "Optimized" option on the top right of Slick optionset edit page.
- Use image style with regular sizes containing effect "crop" in the name. This
  way all images will inherit dimensions calculated once.
- Disable core library "slick-theme.css" as it contains font "slick" which
  may not be in use when using own icon font at:
  /admin/config/media/slick/ui
- Use Blazy multi-serving images, Responsive image, or Picture, accordingly.
- Uninstall Slick UI at production.
- Enable Drupal cache, and CSS/ JS assets aggregation.


HOW CAN YOU HELP?
--------------------------------------------------------------------------------
Please consider helping in the issue queue, provide improvement, or helping with
documentation.

If you find this module helpful, please help back spread the love. Thanks.


AUTHOR/MAINTAINER/CREDITS
--------------------------------------------------------------------------------
Slick 7.x-2.x by gausarts, inspired by Flexslider with CTools integration.
Slick 7.x-1.x by arshadcn, the original author.

- https://www.drupal.org/node/2232779/committers
- CHANGELOG.txt for helpful souls with their patches, suggestions and reports.


READ MORE
--------------------------------------------------------------------------------
See the project page on drupal.org: http://drupal.org/project/slick.

More info relevant to each option is available at their form display by hovering
over them, and click a dark question mark.

See the Slick docs at:
- http://kenwheeler.github.io/slick/
- https://github.com/kenwheeler/slick/
