<?php

/**
 * @file
 * Default theme implementation to display a teaser display for Advanced Poll.
 */
?>
<aside class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <div class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">
      <?php print render($content['field_image_main']); ?>
    <div class="c-initiative--content">
      <div class="c-initiative--inner">
        <h3 class="c-initiative--title"><?php print $title; ?></h3>
        <div>
          <?php print render($content['advpoll_choice']); ?>
        </div>
      </div>
    </div>
</aside>
