Slick Fields Module
================================================================================

Adds a field display formatter to allow you to display field content using
Slick carousel. The module doesn't require Field UI to be enabled by default
(so you can leave it off once everything is configured) but it is recommended
to use to setup your display settings.


SUPPORTED FIELDS:
--------------------------------------------------------------------------------
- Image
- Media
- Field collection

Additional supported fields:
- Scald for audio/video overlay, alternative to Media, within Field collection
- Color field module to colorize individual slide text within Field collection


USAGE:
--------------------------------------------------------------------------------

Manage the fields on any entity (e.g.: node of type Article):

"admin/structure/types/manage/article/display"

Select any field of type "Image", "Media file" or "Field collection" and set the
display options to "Slick carousel" under "Format".
Adjust formatter options accordingly, including your option set.

The more complex is your slide, the more options are available.

If using Media or Field collection, make sure to provide relevant View mode,
and the fields are made visible at their own Manage display page.


OPTIONSETS:
--------------------------------------------------------------------------------

To create your option sets, go to:

"admin/config/media/slick"


SLIDE LAYOUTS:
--------------------------------------------------------------------------------
Core image field supports several caption placements/ layout that affect the
entire slides.

If you have more complex need, use Media or Field collection.
You can place caption in several positions per individual slide as long as you
provide a dedicated List (text) with the following supported/pre-defined keys:
top, right, bottom, left, center, below, e.g:

Option #1
---------

bottom|Caption bottom
top|Caption top
right|Caption right
left|Caption left
center|Caption center
center-top|Caption center top
below|Caption below the slide


Option #2
---------

If you have complex slide layout via Media or Field collection with overlay
video or images within slide captions, also supported:

stage-right|Caption left, stage right
stage-left|Caption right, stage left


Option #3
---------

If you choose skin Split, additional layout options supported:

split-right|Caption left, stage right, split half
split-left|Caption right, stage left, split half


Split means image and caption are displayed side by side at a slight distance.

Specific to split layout, make sure to get consistent options (left and right)
per slide, and also choose optionset with skin Split to have a context per
slideshow. Otherwise layout per slideshow with reusable Media files will be
screwed up.

Except the "Caption below the slide" option, all is absolutely positioned aka
overlayed on top of the main slide image/ background.
Those layouts are ideally applied to large displays, not multiple small slides,
nor small carousels, except "Caption below the slide" which is reasonable with
small slides.


Option #4
---------

Merge all options as needed.


NOTES (deprecated):
--------------------------------------------------------------------------------
Current slick do not support variable height, so even short slides will have the
tallest heights, so use consistent relevant Slide layout options above, e.g.:
Mixing "Caption below the slide" with others will result inconsistent heights.

NOTES (updated):
--------------------------------------------------------------------------------
As of version 1.3.10 (or so ?), there is option adaptiveHeight that support
variable height.

More info relevant to each option is available at their form display by hovering
over them, and click a dark question mark.
