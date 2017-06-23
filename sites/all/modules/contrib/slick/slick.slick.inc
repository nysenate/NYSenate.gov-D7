<?php
/**
 * @file
 * Default skins for the Slick carousel.
 */

/**
 * Implements hook_slick_skins_info().
 *
 * This file is loaded automatically when needed.
 *
 * All the skins are very basic, to perform possible variants. It doesn't care
 * about looking great, and other element stylings, but basic one and layouts.
 * Detailed styling is all yours to match your actual design.
 * It should be used in relation to individual slide layout to get the most out
 * of it, see README.txt on slick_fields.module for possible Slide layouts using
 * a field with Field collection.
 *
 * Each skin supports 5 keys:
 * - name: The human readable name of the skin.
 * - description: The description about the skin, for help and manage pages.
 * - css: An array of CSS files to attach.
 * - js: An array of JS files to attach, e.g.: image zoomer, reflection, etc.
 * - inline css: An optional flag to determine whether the image is turned into
 *   CSS background rather than image with SRC, see fullscreen skin.
 *
 * @see hook_hook_info()
 * @see https://drupal.org/node/1887922
 */
function slick_slick_skins_info() {
  $path = drupal_get_path('module', 'slick');

  $skins = array(
    'default' => array(
      'name' => t('Default'),
      'css' => array(
        $path . '/css/theme/slick.theme--default.css' => array('weight' => -20),
      ),
    ),
    '3d-back' => array(
      'name' => t('3d back'),
      'css' => array(
        $path . '/css/theme/slick.theme--3d-back.css' => array('weight' => 1),
      ),
      'description' => t('Adds 3d view with focal point at back, works best with 3 slidesToShow, centerMode, and caption below the slide.'),
    ),
    'asnavfor' => array(
      'name' => t('Thumbnail: asNavFor'),
      'css' => array(
        $path . '/css/theme/slick.theme--asnavfor.css' => array('weight' => 2),
      ),
      'description' => t('Affected thumbnail navigation only.'),
      'group' => 'thumbnail',
    ),
    'classic' => array(
      'name' => t('Classic'),
      'description' => t('Adds dark background color over white caption, only good for slider (single slide visible), not carousel (multiple slides visible), where small captions are placed over images, and animated based on their placement.'),
      'css' => array(
        $path . '/css/theme/slick.theme--classic.css' => array('weight' => 2),
      ),
    ),
    'fullscreen' => array(
      'name' => t('Full screen'),
      'description' => t('Adds full screen display, works best with 1 slidesToShow.'),
      'css' => array(
        $path . '/css/theme/slick.theme--fullscreen.css' => array('weight' => 4),
        $path . '/css/theme/slick.theme--full.css' => array('weight' => 5),
      ),
      'inline css' => TRUE,
      'group' => 'full',
    ),
    'fullwidth' => array(
      'name' => t('Full width'),
      'description' => t('Adds .slide__constrained wrapper to hold caption overlay within the max-container (1170px for large monitor).'),
      'css' => array(
        $path . '/css/theme/slick.theme--fullwidth.css' => array('weight' => 5),
        $path . '/css/theme/slick.theme--full.css' => array('weight' => 5),
      ),
      'group' => 'full',
    ),
    'boxed' => array(
      'name' => t('Boxed'),
      'description' => t('Adds margins to the sides of slick-list revealing arrows.'),
      'css' => array(
        $path . '/css/theme/slick.theme--boxed.css' => array('weight' => 6),
      ),
    ),
    'grid' => array(
      'name' => t('Grid'),
      'description' => t('The last grid carousel. Use slidesToShow > 1 to have more grid combination, only if you have considerable amount of grids, otherwise 1.'),
      'css' => array(
        $path . '/css/theme/slick.theme--grid.css' => array('weight' => 7),
      ),
      'group' => 'grid',
    ),
    'split' => array(
      'name' => t('Split'),
      'description' => t('Puts image and caption side by side, related to slide layout options.'),
      'css' => array(
        $path . '/css/theme/slick.theme--split.css' => array('weight' => 8),
      ),
    ),
    'boxed-carousel' => array(
      'name' => t('Box carousel'),
      'description' => t('Carousel that has margins, alternative to centerMode.'),
      'css' => array(
        $path . '/css/theme/slick.theme--boxed.css' => array('weight' => 9),
        $path . '/css/theme/slick.theme--boxed--carousel.css' => array('weight' => 10),
      ),
    ),
    'boxed-split' => array(
      'name' => t('Box split'),
      'description' => t('Adds margins and split caption and image.'),
      'css' => array(
        $path . '/css/theme/slick.theme--boxed.css' => array('weight' => 11),
        $path . '/css/theme/slick.theme--split.css' => array('weight' => 12),
      ),
    ),
    'rounded' => array(
      'name' => t('Rounded'),
      'description' => t('Rounds the .slide__media, great for 3-5 visible-slides carousel.'),
      'css' => array(
        $path . '/css/theme/slick.theme--rounded.css' => array('weight' => 13),
      ),
    ),
  );

  return $skins;
}
