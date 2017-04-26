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

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<div class="c-initiative--header">
		<h2 class="nys-article-title"><?php echo $title; ?></h2>
		<h4 class="c-initiative--subtitle">Initiative</h4>

		<?php if(isset($content['field_subheading'])): ?>
			<h3 class="c-initiative--section-title">
				<?php print render($content['field_subheading']); ?>
			</h3>
		<?php endif; ?>
	</div>

	<?php echo (isset($content['body'][0]['#markup'])) ? '<div class="body">'.$content['body'][0]['#markup'].'</div>' : ''; ?>

	<?php if(isset($content['field_image_main'][0]['#item']['uri'])): ?>
		<div class="c-initiative--featured-image">
			<img src="<?php print image_style_url('760x377', $content['field_image_main'][0]['#item']['uri']); ?>"/>
			<?php if(!empty($content['field_image_main'][0]['#item']['title'])): ?>
				<figcaption class="c-img--caption">garble! <?php echo $content['field_image_main'][0]['#item']['title']; ?></figcaption>
			<?php endif; ?>
		</div>
	<?php endif; ?>

	<?php if(isset($content['field_hide_webform']) && ($content['field_hide_webform']['#items'][0]['value'] != 1) && isset($content['field_webform'])): ?>
		<div class="c-block c-initiative--webform">
			<?php print render($content['field_webform']); ?>
		</div>
	<?php endif; ?>

	<?php if(isset($content['field_associated_senator'])): ?>

		<div class="c-block c-block--associated-senators">
			<div class="c-container--header__top-border">
				<h3 class="c-container--title">Senators Involved</h3>
			</div>
			
			<?php print render($content['field_associated_senator']); ?>
		</div>
	<?php endif; ?>

	<?php if(isset($content['field_honorees'])): ?>
		<div class="c-block c-block--initiative-honorees">
			<h3 class="c-initiative--section-title"><?php echo $content['field_honoree_section_title'][0]['#markup']; ?></h3>
			<?php print render($content['field_honorees']); ?>
		</div>
	<?php endif; ?>

	<?php if(isset($content['field_attachment'][0]['#markup'])): ?>
		<div class="c-block c-download-file">
			<h4 class="c-initiative--subtitle">To learn more about this initiative:</h4>
			<a href="<?php echo $content['field_attachment'][0]['#markup'];?>" class="c-download--link" target="_blank">Download PDF</a>
		</div>
	<?php endif; ?>

  <?php if(!empty($social_buttons)): ?>
    <?php print $social_buttons; ?>
  <?php endif; ?>
    
</section>
