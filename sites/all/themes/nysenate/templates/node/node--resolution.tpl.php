<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<?php

/**
 * @file
 * A basic template for bill entities
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The name of the bill
 * - $url: The standard URL for viewing a bill entity
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - bill-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

 $node_url = $GLOBALS['base_url'].'/'.drupal_get_path_alias('node/'.$node->nid, array('absolute' => TRUE));
 $ol_base_url = variable_get('openleg_base_url');
?>
<!-- RESOLUTION TEMPLATE -->
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="c-block c-detail--header c-detail--header__bill">
    <h2 class="nys-title"><?php echo $title; ?></h2>
    <div class="c-bill--flags">
      <?php if(isset($node->field_ol_last_status[LANGUAGE_NONE][0]['value']) && $node->field_ol_last_status[LANGUAGE_NONE][0]['value']) : ?>
        <span class="c-bill--flag"><?php echo $last_status; ?></span>
      <?php endif; ?>
      <?php if($node->field_ol_is_amended[LANGUAGE_NONE][0]['value'] === '1'): ?>
        <span class="c-bill--flag">amended</span>
      <?php endif; ?>
    </div>
  </div>

  <div class="c-detail--header-meta">
    <p class="c-detail--descript"><?php echo truncate_utf8($node->field_ol_name[LANGUAGE_NONE][0]['value'], 135, TRUE, TRUE, 132); ?></p>
    <div class="c-detail--related">
      <?php echo render($content['field_issues']); ?>
    </div>
    <a href="<?php print $ol_base_url; ?>/pdf/bills/<?php echo $node->field_ol_session[LANGUAGE_NONE][0]['value']; ?>/<?php echo $title; ?>" class="c-detail--download" target="_blank">download pdf</a>
  </div>

  <div class="c-detail--social">
    <h3 class="c-detail--subhead">share this resolution</h3>
    <ul>
      <li><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="c-detail--social-item facebook">facebook</a></li>
      <li><a target="_blank" href="https://twitter.com/home?status=<?php print $title; ?> Via: @nysenate: <?php print $node_url; ?>" class="c-detail--social-item twitter">twitter</a></li>
      <li><a href="mailto:?&subject=From NYSenate.gov: <?php print $title; ?>&body=Check out this resolution: <?php print $title; ?>: < <?php print $node_url; ?> >." class="c-detail--social-item email">email</a></li>
    </ul>
  </div>

  <div class="c-block">
    <?php if(isset($content['field_image_main']) && $content['field_image_main']) : ?>
      <div class="c-block c-block--img">
        <?php echo render($content['field_image_main']); ?>
      </div>
    <?php endif; ?>
  </div>

  <div class="c-block c-detail--sponsors">
    <?php print $sponsored_by; ?>
      <?php print $sponsor_block; ?>
      
  </div> <!-- .c-block -->

  <?php if(isset($content['field_featured_quote'][0]['#markup']) && isset($content['field_ol_sponsor']['#children'])):?>
    <div class="c-block c-sponsor-quote">
      <h3 class="c-sponsor-quote--title">sponsor's position</h3>
      <p class="c-sponsor-quote--text"><?php echo render($content['field_featured_quote']); ?></p>

      <div class="c-sponsor">
        <?php print $content['field_ol_sponsor']['#children']; ?>
      </div>
      <button class="js-quote-toggle c-block--btn c-block--btn-toggle">close</button>
      <div class="c-social">
        <ul class="c-social--list">
          <li><a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php echo $path;?>" class="icon-replace__facebook">facebook</a></li>
          <li><a target="_blank" href="http://twitter.com/share?url=<?php echo $path;?>" class="icon-replace__twitter">twitter</a></li>
        </ul>
      </div>
    </div><!-- sponsor quote -->
  <?php endif; ?>

  <!-- resolution details -->
  <?php if($node->field_ol_full_text[LANGUAGE_NONE][0]['value']) : ?>
  <div class="c-block c-detail--writeup-wrapper">
    <h3 class="c-detail--subhead">text</h3>
    <div class="c-detail--writeup">
      <h3 class=""><?php echo $title; ?></h3>
      <?php print nl2br($node->field_ol_full_text[LANGUAGE_NONE][0]['value']);?>
    </div>
  </div>
  <?php endif; ?>



  <?php if (!empty($node->field_ol_all_statuses[LANGUAGE_NONE][0]['value']) && !is_null(json_decode($node->field_ol_all_statuses[LANGUAGE_NONE][0]['value']))): ?>
  <div class="c-block c-detail--actions">
    <div class="c-detail--section-title">
      <h3 class="c-detail--subhead">actions</h3>
    </div>
    <?php
    $statuses = json_decode($node->field_ol_all_statuses[LANGUAGE_NONE][0]['value']);
    if (isset($statuses->items)) {
      $statuses = $statuses->items;

      // Handle legacy statuses.
      foreach ($statuses as $status) {
        if (isset($status->actionDate)) {
          $status->date = $status->actionDate;
        }

        if (isset($status->statusDesc)) {
          $status->text = $status->statusDesc;
        }
      }
    } else {
      // Handle legacy statuses.
      $statuses->date = $statuses->actionDate;
      $statuses->text = $statuses->statusDesc;

      $statuses = array($statuses);
    }
    ?>
    <ul class="c-action--items">
      <?php foreach ($statuses as $status): ?>
      <li>
        <span class="c-action--date"><?php if ($status->date) { echo date('d', strtotime($status->date)) . ' / ' . date('M', strtotime($status->date)) . ' / ' . date('Y', strtotime($status->date)); } ?></span>
        <ul>
          <li class="c-action--item"><?php if ($status->text) { echo $status->text; } ?></li>
        </ul>
      </li>
      <?php endforeach; ?>
    </ul>
  </div><!-- actions -->
  <?php endif; ?>

  <div class="c-block c-bill--details">
    <h3 class="c-detail--subhead c-detail--section-title">Resolution Details</h3>
      <dl>
      <?php $same_as = json_decode($node->field_ol_same_as[LANGUAGE_NONE][0]['value']); ?>
      <?php if($same_as):?>
        <dt>See Assembly Version of this Bill:</dt>
        <?php $first = TRUE;  foreach($same_as as $key => $item):?>
          <dd>
            <?php if($first) $first=FALSE; else print ",";?>
            <a href="/legislation/resolutions/<?php print $node->field_ol_session[LANGUAGE_NONE][0]['value'] . '/' . $same_as[$key]->printNo; ?>"><?php print $same_as[$key]->printNo; ?></a>
          </dd>
        <?php endforeach; ?>
      <?php endif;?>

      <?php if(!empty($amended_versions)):?>
      <dt>Versions:</dt>
        <?php print $amended_versions; ?>
      <?php endif; ?>

      <?php if(isset($node->field_ol_latest_status_committee[LANGUAGE_NONE][0]['value']) && $node->field_ol_latest_status_committee[LANGUAGE_NONE][0]['value']) : ?>
      <dt>Committee:</dt>
      <dd>
        <a href="#">
          <?php print $node->field_ol_latest_status_committee[LANGUAGE_NONE][0]['value']; ?>
        </a>
      </dd>
      <?php endif; ?>

      <?php if(isset($node->field_ol_law_section[LANGUAGE_NONE][0]['value']) && $node->field_ol_law_section[LANGUAGE_NONE][0]['value']): ?>
      <dt>Law Section:</dt>
      <dd><?php print $node->field_ol_law_section[LANGUAGE_NONE][0]['value'];?></dd>
      <?php endif; ?>

      <?php if(isset($node->field_ol_law_code[LANGUAGE_NONE][0]['value']) && $node->field_ol_law_code[LANGUAGE_NONE][0]['value']) : ?>
      <dt>Laws Affected:</dt>
      <?php print $node->field_ol_law_code[LANGUAGE_NONE][0]['value'];?></dd>
      <?php endif; ?>

    </dl>

  </div>

  <!-- Related Bills Content -->
  <?php
  $view = views_get_view('explore_issues_tabs');
  $view -> set_display('explore_issues_popular');
  $view -> set_items_per_page(6);
  $view -> pre_execute();
  $view -> execute();

  if($view->result != NULL) : ?>
  <div class="c-block c-container">
    <div class="c-container--header">
      <h2 class="c-container--title">Find and Follow Issues</h2>
      <a href="/explore-issues" class="c-container--link">Explore Issues</a>
    </div>
    <div class="c-block">
      <?php print $view->render(); ?>
    </div>
  </div>
  <?php endif; ?>

  <!-- Related Content -->
  <?php $disqus = render($content['disqus']);?>
  <?php if(!empty($disqus)): ?>
   <div class="c-block c-detail--summary">
    <h3 class="c-detail--subhead c-detail--section-title">Comments</h3>
    <p>Open Legislation comments facilitate discussion of New York State legislation. All comments are subject to moderation. Comments deemed off-topic, commercial, campaign-related, self-promotional; or that contain profanity or hate speech; or that link to sites outside of the nysenate.gov domain are not permitted, and will not be published. Comment moderation is generally performed Monday through Friday.</p>
    <p>By contributing or voting you agree to the Terms of Participation and verify you are over 13.</p>
    <p>&nbsp;</p>
    <?php echo $disqus; ?>
   </div>
  <?php endif; ?>
</div>
