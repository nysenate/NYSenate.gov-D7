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
 
if (isset($node->field_image_main[LANGUAGE_NONE][0]['uri'])) {
  $field_image_main_uri = $node->field_image_main[LANGUAGE_NONE][0]['uri'];
}
else {
  $field_image_main_uri = '';
}
 
if (isset($field_link_type[0]['value'])) {
  $link_type_value = $field_link_type[0]['value'];
}
else {
  $link_type_value = '';
}

if (isset($field_external_web_page[0]['safe_value'])) {
  $external_web_page_safe_value = $field_external_web_page[0]['safe_value'];
}
else {
  $external_web_page_safe_value = '';
}

if (isset($node->field_call_to_action[LANGUAGE_NONE][0]['value'])) {
  $call_to_action_value = $node->field_call_to_action[LANGUAGE_NONE][0]['value'];
}
else {
  $call_to_action_value = '';
}

if (isset($node->field_promotional_content[LANGUAGE_NONE][0]['target_id'])) {
  $promotional_content_target_id = $node->field_promotional_content[LANGUAGE_NONE][0]['target_id'];
}
else {
  $promotional_content_target_id = FALSE;
}


?>
<?php if($teaser): ?>

    <!-- INITIATIVE BLOCK - TWO UP -->
  <div class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">

    <img src="<?php print $theme_path; ?>/images/initiative-block-img.jpg" alt="" />

    <div class="c-initiative--content">
      <div class="c-initiative--inner">
	       <?php if( $call_to_action_value == "petition") {; ?>
	       	<?php if(!empty($node->field_senator[LANGUAGE_NONE][0]['entity'])): ?>
	       		<h4 class="senator-name"><?php echo $node->field_senator[LANGUAGE_NONE][0]['entity']->title; ?>'s petition</h4>
	       	<?php endif; ?>
	       <?php } ?>
        <h4 class="c-initiative--title"><?php print $title; ?></h4>
      </div>
    </div>
    <a href="<?php $link_type_value == 'external' ? print $external_web_page_safe_value : print url('node/' . $promotional_content_target_id); ?>" class="c-block--btn icon-before__<?php echo $call_to_action_value; ?> med-bg">
	    <?php if( $call_to_action_value == "petition") {; ?>
	    	review the petition
	    <?php  } else if ($call_to_action_value == "questionaire") {; ?>
		    take the questionnaire
	    <?php } else {; ?>
	    	View the report
	    <?php } ?>
	    </a>
  </div>
  <!-- end initiative block two up -->

<?php elseif($view_mode == 'full'): ?>

  <?php if (!$field_image_main_uri): ?>

    <div class="c-initiative-block lgt-bg">
      <h4 class="c-initiative-block--title">No Free College for Convicts</h4>
      <a href="#" class="c-block--btn icon-before__petition med-bg">
        <span>review the petition</span>
      </a>
    </div>

  <?php else: ?>

        <!-- INITIATIVE BLOCK - TWO UP -->
  <div class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">

    <a href="<?php $link_type_value == 'external' ? print $external_web_page_safe_value : print url('node/' . $promotional_content_target_id); ?>"><?php print theme('image_style', array( 'path' =>  $field_image_main_uri, 'style_name' => '280x280')); ?></a>

    <div class="c-initiative--content">
      <div class="c-initiative--inner">
        <h4 class="c-initiative--title"><?php print $title; ?></h4>
      </div>
    </div>
    <?php $allowed_values = array(
        'petition' => 'Review the Petition',
        'questionaire' => 'Take the Questionaire',
        'senator_leadership' => 'Senator Leadership List',
        'view_report' => 'View the Report',
        'view_honorees' => 'View All Honorees',
        'read_more' => 'Read More'
      );

    ?>
    <a href="<?php $link_type_value == 'external' ? print $external_web_page_safe_value : print url('node/' . $promotional_content_target_id); ?>" class="c-block--btn icon-before__awards icon-before__<?php echo $call_to_action_value; ?> med-bg">
	    <?php print $allowed_values[$call_to_action_value]; ?>
    </a>
  </div>
  <!-- end initiative block two up -->

  <?php endif;?>

<?php endif; ?>
