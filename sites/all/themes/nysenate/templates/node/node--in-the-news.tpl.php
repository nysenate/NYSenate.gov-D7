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

  $author = (isset($content['field_article_author'][0]['#markup'])) ? $content['field_article_author'][0]['#markup'] : ( isset($content['field_senator'][0]['#markup']) ? $content['field_senator'][0]['#markup'] : FALSE);
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($page): ?>
    <header class="c-news--head">
      <h1 class="nys-article-title"><?php print $title; ?></h1>
      <div class="c-news--head-meta">
        <?php if(isset($content['field_article_author'])): ?>
            <p class="c-news--author"><?php print render($content['field_article_author'][0]['#markup']); ?></p>
        <?php endif; ?>
        <?php if (!empty($field_date)): ?>
          <p class="c-news--pub-date">
            <?php print render($content['field_date'][0]['#markup']); ?>
          </p>
        <?php endif; ?>

        <?php if(isset($content['field_issues'])): ?>
        <ul class="nys-associated-topics">
          ISSUE:
          <?php for($i = 0; $i < count($content['field_issues']['#items']); $i++) : ?>
            <li><?php print render($content['field_issues'][$i]); ?></li>
          <?php endfor; ?>
        </ul>
        <?php endif; ?>

        <?php if (isset($content['field_committee'])): ?>
          <ul class="nys-associated-topics">
            COMMITTEE:
            <?php for ($i = 0; $i < count($content['field_committee']['#items']); $i++): ?>
              <li><?php print render($content['field_committee'][$i]); ?></li>
            <?php endfor; ?>
          </ul>
        <?php endif; ?>

      </div>
    </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <div class="c-news--body c-in-the-news--body">
    <?php if (!empty($field_publication_source_link) && !empty($field_publication_title)): ?>
    <div class="c-news--body-title">Originally published in
      <a href="<?php print $field_publication_source_link[0]['safe_value']; ?>" title="<?php print $field_publication_title[0]['safe_value']; ?>" target="_blank">
        <?php print $field_publication_title[0]['safe_value']; ?>
      </a>
      <?php if (!empty($field_itn_publication_date)): ?>
      on
      <?php print render($content['field_itn_publication_date'][0]['#markup']); endif; ?>
    </div>
    <?php endif; ?>

    <?php if($node->field_image_main): ?>
    <div class="c-block c-block--img">
      <?php print theme('image_style', array('path' => $field_image_main[0]['uri'], 'style_name' => '760x377')); ?>
        <?php if(!empty($node->field_image_main[LANGUAGE_NONE][0]['title'])): ?>
          <p class="c-img--caption"><?php print $node->field_image_main[LANGUAGE_NONE][0]['title']; ?></p>
        <?php endif; ?>
    </div>
    <?php endif; ?>

    <div class="c-block c-block-quoted-body">
      <?php if(isset($content['field_subheading'])): ?>
        <p class="c-news--subtitle">
          <?php print $content['field_subheading'][0]['#markup']; ?>
        </p>
      <?php endif; ?>

      <?php print render($content['body']);?>
    </div>

    <?php if(isset($content['field_chapters'])): ?>
      <section class="c-block">
        <?php print render($content['field_chapters']); ?>
      </section>
    <?php endif; ?>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_tags']);
    ?>

    <?php if(isset($content['field_attachment'])): ?>
      <div class="c-block c-news--download">
        <h2 class="c-initiative--subtitle">More Information:</h2>
        <?php print render($content['field_attachment']); ?>
      </div>

    <?php endif; ?>

  <?php if(!empty($social_buttons)): ?>
    <?php print $social_buttons; ?>
  <?php endif; ?>


  </div>
</article>
