<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user module
 *     is responsible for handling the default user navigation block. In that case
 *     the class would be "block-user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>

<!-- TEMPORARY MODULE EXAMPLE - HOW THE SENATE WORKS -->
<!-- Assumed Static HTML -->

<button class="js-mobile-nav--btn c-block--btn c-nav--toggle u-mobile-only icon-replace"></button>

<div class="c-nav--wrap c-senator-nav--wrap">
  <div class="c-nav c-senator-nav l-row l-row--nav">
    
    <nav role="navigation">
      <?php
        $main_menu = module_invoke('menu', 'block_view', 'menu-senator-s-microsite-menu'); 
        print render($main_menu['content']);    
      ?>

      <div class="u-mobile-only">
      <?php
        $search_box = module_invoke('apachesolr_search_blocks', 'block_view', 'core_search'); 
        print render($search_box['content']);    
      ?>
      </div>

      <button class="js-search--toggle u-tablet-plus c-site-search--btn icon-replace__search">search</button>

      <div class="c-mobile-login--list u-mobile-only">
        <?php if ($user->uid == '0'): ?>
          <span class="c-header--btn c-header--btn-login">
          <?php echo ctools_modal_text_button(t('login'), 'registration/nojs/login', t('login'), 'ctools-modal-login-modal');?>
          </span>
        <?php else: ?>
          <a href="<?php print $dashboard_link . '/issues'; ?>" class="c-header--btn c-header--btn-login <?php if($user_avatar){ echo 'has-avatar'; } ?>">
              <?php if($user_avatar): ?>
                <?php echo $user_avatar; ?>
                <span>My Dashboard</span>
              <?php else: ?>
                My Dashboard
              <?php endif; ?>
          </a>
          <?php if($senator_nid): ?>
            <a class="c-header--btn c-header--btn-senator" href="<?php print $senator_microsite_link; ?>">
              <div class="nys-senator">
                <div class="nys-senator--thumb">
                  <?php echo $senator_image; ?>
                </div>
                <div class="nys-senator--info">
                  <h3 class="nys-senator--title">Your Senator</h3>
                  <h2 class="nys-senator--name"><?php echo $senator_name; ?></h2>
                </div>
              </div>
            </a>
          <?php endif; ?>
          <a class="c-header--btn c-header--btn-edit" href="/user/<?php echo $user->uid; ?>/edit">Edit Account</a>
          <a href="/user/logout" class="c-header--btn c-header--btn-logout">logout</a>
        <?php endif; ?>
      </div> 
    </nav>
  </div>

  <div class="u-tablet-plus">
    <?php
      // Load the Apache Solr Search include file that contains the page_load function.
      module_load_include('inc', 'apachesolr_search', 'apachesolr_search.pages');

      // Load the custom search page.
      $search_page = apachesolr_search_page_load('core_search');

      if (!empty($search_page)):

        $form = drupal_get_form('apachesolr_search_blocks_' . $search_page['page_id']);

        // Setup the right form action: dont rely on standard REQUEST_URI.
        $form['#action'] = url($search_page['search_path']);

        // Replace the usual Search placeholder with a more specific one.
        $search_placeholder = 'Search Sen. ' . $senator_name;
        $form['basic']['keys']['#attributes']['placeholder'] = t($search_placeholder);

        // Set up the lucene filter to pass through to the URL by json_encoding it.
        $form['basic']['get']['#value'] = drupal_json_encode(array(
          'fq[]' => 'sm_field_senator:node:' . $microsite_senator_nid,
          )
        );

        print drupal_render($form);

      endif;
    ?>
  </div>
</div>
