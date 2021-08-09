<?php //dpm($content); ?>

<div class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">

    <a href="<?php print '/' . drupal_get_path_alias(current_path()) . '/earthday' ?>"><?php print render($content['field_promo_image']); ?></a>

    <div class="c-initiative--content">
        <div class="c-initiative--inner">
            <h4 class="c-initiative--title"><?php print $content['title']['#value']; ?></h4>
        </div>
    </div>

    <a href="<?php print '/' . drupal_get_path_alias(current_path()) . '/earthday' ?>" class="c-block--btn icon-before__awards icon-before__read_more med-bg">
        View Submissions
    </a>
</div>