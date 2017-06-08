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

// Set up reference variable indicating if this event spans multiple days.
$is_multiday = !(date('Ymd',$node->field_date[LANGUAGE_NONE][0]['value'])==date('Ymd',$node->field_date[LANGUAGE_NONE][0]['value2']));
?>
<article id="node-<?php print $node->nid; ?>" class="event_detail_page <?php print $classes; ?>"<?php print $attributes; ?>>

  <h1 class="nys-event-title"><?php print $title; ?></h1>
  <div class="c-event-block c-event-block--featured<?php if ($node->field_image_main) print "-image"; ?>">
    <?php if($node->field_image_main): ?>
    <div class="c-event-image"><?php print theme('image_style', array( 'path' =>  $field_image_main[0]['uri'], 'style_name' => '380x215')); ?></div>
    <?php endif; ?>
    <?php print theme('nysenate_event_date', array(
      'start_date' => $node->field_date[LANGUAGE_NONE][0]['value'],
      'end_date' => $node->field_date[LANGUAGE_NONE][0]['value2']
      )); ?>

    <?php if(!empty($node->field_location[LANGUAGE_NONE][0]['name'])): ?>
      <a href="http://maps.google.com/?q=<?php echo $node->field_location[LANGUAGE_NONE][0]['street'];?>+<?php echo $node->field_location[LANGUAGE_NONE][0]['city'];?>%2C+<?php echo $node->field_location[LANGUAGE_NONE][0]['province'];?>%2C+<?php echo $node->field_location[LANGUAGE_NONE][0]['postal_code'];?>" class="c-event-location" target="_blank"><span class="icon-before__circle-pin"></span><?php print $node->field_location[LANGUAGE_NONE][0]['name']; ?></a>
    <?php endif; ?>

    <?php if(!empty($node->field_location[LANGUAGE_NONE][0]['street'])): ?>
      <p class="c-event-address"><?php print $node->field_location[LANGUAGE_NONE][0]['street'] . '<br/>' . $node->field_location[LANGUAGE_NONE][0]['city'] . ', ' . $node->field_location[LANGUAGE_NONE][0]['province'] . ' ' . $node->field_location[LANGUAGE_NONE][0]['postal_code']; ?></p>
    <?php endif; ?>

    <div class="c-event-time"><?php print format_date($node->field_date[LANGUAGE_NONE][0]['value'], "custom", "g:i A"); ?> <?php if(isset($node->field_date[LANGUAGE_NONE][0]['value2']) && ($node->field_date[LANGUAGE_NONE][0]['value2'] != $node->field_date[LANGUAGE_NONE][0]['value'])) print '&nbsp-&nbsp' . format_date($node->field_date[LANGUAGE_NONE][0]['value2'], "custom", "g:i A");?></div>

    <div title="Add to Calendar" class="addthisevent">
      Add to Calendar
      <span class="start"><?php print format_date($node->field_date[LANGUAGE_NONE][0]['value'], "custom", "m/d/Y"); ?> <?php print format_date($node->field_date[LANGUAGE_NONE][0]['value'], "custom", "g:i A"); ?></span>
      <span class="end"><?php print format_date($node->field_date[LANGUAGE_NONE][0]['value2'], "custom", "m/d/Y"); ?> <?php print format_date($node->field_date[LANGUAGE_NONE][0]['value2'], "custom", "g:i A"); ?></span>
      <span class="timezone">America/New_York</span>
      <span class="title"><?php print $title; ?></span>
      <span class="location"><?php echo $node->field_location[LANGUAGE_NONE][0]['name'];?></span>
      <span class="date_format">MM/DD/YYYY</span>
      <span class="organizer">NY STATE SENATE</span>
      <span class="organizer_email">content@senate.state.ny.us</span>
    </div>

  </div>

  <?php if(isset($node->field_issues[LANGUAGE_NONE])): ?>
  <div class="nys-associated-topics">
    <div class="nys-associated-topics--label">related issues: </div>
    <ul>
    <?php
      foreach ($node->field_issues[LANGUAGE_NONE] as $value) : ?>
      <li>
        <?php echo l($value['taxonomy_term']->name,drupal_get_path_alias('taxonomy/term/'.$value['tid'])); ?>
      </li>
    <?php endforeach; ?>
    </ul>
  </div>
  <?php endif; ?>

  <?php if(isset($content['field_attachment'])): ?>
    <div class="c-news--download">
      <?php print render($content['field_attachment']); ?>
    </div>
  <?php endif; ?>

  <?php if(isset($content['field_yt'])): ?>
    <div class="c-block">
      <?php print drupal_render($content['field_yt']); ?>
    </div>
  <?php
    elseif (
      field_get_items('node', $node, 'field_video_status')[0]['value'] === "streaming_live_now"
      && isset($content['field_ustream_url'])
      ):
  ?>
    <div class="c-block">
      <?php print drupal_render($content['field_ustream_url']); ?>
    </div>
  <?php endif; ?>

  <div class="c-block">
      <?php print render($content['body']);?>
  </div>

  <?php if(!empty($social_buttons)): ?>
    <?php print $social_buttons; ?>
  <?php endif; ?>

</article>
