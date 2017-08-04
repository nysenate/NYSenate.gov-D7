<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items.
 *   Use render($content) to print them all, or
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
 *   preprocess functions.
 *   The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser.
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


<?php /* ========================== TEASERS =========================================== */ ?>
<?php if ($teaser == TRUE || (arg(0) == 'search' && arg(1) == 'global')): ?>

  <?php if (nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws' && nys_statute_alias_arg(2) == 'all') { ?>
    <!-- ALL -->
    <a class="c-law-link" href="<?php echo NYS_STATUTE_IMPORT_BASE_PATH . $node->field_statuteid[LANGUAGE_NONE][0]['value']; ?>">
      <?php echo $node->title;?></a>

  <?php } elseif ((nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws') && nys_statute_alias_arg(2) == 'CONSOLIDATED' || nys_statute_alias_arg(2) == 'UNCONSOLIDATED' || nys_statute_alias_arg(2) == 'COURTACTS' || nys_statute_alias_arg(2) == 'RULES') { ?>
    <!-- LAWID -->
      <a class="c-law-link" href="<?php echo NYS_STATUTE_IMPORT_BASE_PATH . $node->field_statuteid[LANGUAGE_NONE][0]['value']; ?>">
        <?php echo $node->title . '  &nbsp;(' .  $node->field_lawid[LANGUAGE_NONE][0]['value'] . ')'; ?></a>

  <?php } else { ?>

    <div class="row c-law-link-container<?php
      $additional_class = '';
      if (arg(0) == 'search' && arg(1) == 'global') {
        $additional_class = ' search-results';
      }
      $additional_class = $additional_class . ' ' . strtolower($node->field_doctype[LANGUAGE_NONE][0]['value']);
      echo $additional_class;
      ?>">
      <div class="columns medium-4">
        <h3 class="c-law-link-loc-id">
          <a href="<?php echo NYS_STATUTE_IMPORT_BASE_PATH . $node->field_statuteid[LANGUAGE_NONE][0]['value']; ?>">
            <?php echo ucfirst(strtolower($node->field_doctype[LANGUAGE_NONE][0]['value'])) . " " . $node->field_doclevelid[LANGUAGE_NONE][0]['value'] ?>
          </a>
        </h3>
        <?php if (arg(0) == 'search' && arg(1) == 'global')  { ?>
 		  <div class="c-search-result--topic">
            <div class="statutes-link-wrapper field-label-hidden field-wrapper clearfix">
              <a href="/legislation/statutes">STATUTES</a>
            </div>
          </div>
        <?php } ?>
      </div>
      <div class="columns medium-8">
        <p class="c-law-link-title">
          <a href="<?php echo NYS_STATUTE_IMPORT_BASE_PATH . $node->field_statuteid[LANGUAGE_NONE][0]['value']; ?>">
            <?php echo $node->title; ?>
            <?php
              if($node->field_doctype['und'][0]['value'] == 'CHAPTER') {
                print '  &nbsp;(' .  $node->field_lawid[LANGUAGE_NONE][0]['value'] . ')';
              }
            ?>
          </a>
        </p>
        <p class="c-law-link-contained-sections">
          <?php
            if (arg(0) == 'search' && arg(1) == 'global')  {
                // Its a search result emit a breadcrumb.
                print nys_statute_get_breadcrumb_markup($node->field_parentstatuteid[LANGUAGE_NONE][0]['value'], $node->title, $node->field_lawid[LANGUAGE_NONE][0]['value']);
            }
            else {
              if (strpos($node->field_statuteid[LANGUAGE_NONE][0]['value'], '/') == 0) {
                if($node->field_doctype['und'][0]['value'] == 'CHAPTER') {
                  echo "Chapter " . nys_statute_get_law_chapter($node->field_statuteid[LANGUAGE_NONE][0]['value']);
                }
              }
              elseif ($node->field_fromsection[LANGUAGE_NONE][0]['value'] != $node->field_tosection[LANGUAGE_NONE][0]['value']) {
                echo "Sections (§{$node->field_fromsection[LANGUAGE_NONE][0]['value']} - §{$node->field_tosection[LANGUAGE_NONE][0]['value']})";
              }
            }
          ?>
        </p>
      </div>
    </div>

  <?php } ?>
<?php endif; ?>
<?php /* =========================== /TEASERS ====================================== */ ?>

<?php /* =========================== NODES ========================================= */ ?>
<?php if ($teaser == FALSE && arg(0) != 'search' && arg(1) != 'global'): ?>

	<?php /* --------------------------- PAGE TITLE -------------------------------- */ ?>
	<h2 class="nys-title">
	<?php
    if (nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws' && nys_statute_alias_arg(2) == 'all') {
      print t('Laws, Court Acts, and Legislative Chamber Rules');
    }
    elseif (nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws' && nys_statute_alias_arg(2) == 'CONSOLIDATED') {
      print t('Consolidated Laws');
    }
    elseif (nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws' && nys_statute_alias_arg(2) == 'UNCONSOLIDATED') {
      print t('Unconsolidated Laws');
    }
    elseif (nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws' && nys_statute_alias_arg(2) == 'COURTACTS') {
      print t('Court Acts');
    }
    elseif (nys_statute_alias_arg(0) == 'legislation' && nys_statute_alias_arg(1) == 'laws' && nys_statute_alias_arg(2) == 'RULES') {
      print t('Legislative Chamber Rules');
    }
    else {
      print nys_statute_get_law_name($node->field_lawid[LANGUAGE_NONE][0]['value']);
    }
    print '</h2>';
?>
	<?php /* --------------------------- BREAD CRUMBS ------------------------------ */ ?>

	<?php if (is_array($node->field_parentstatuteid) && count($node->field_parentstatuteid)) {
	        $parent_id = $node->field_parentstatuteid[LANGUAGE_NONE][0]['value'];
	      }
          else {
            $parent_id = '';
          }
	      print nys_statute_get_breadcrumb_markup($parent_id, $node->title, $node->field_lawid[LANGUAGE_NONE][0]['value'], $node->field_locationid[LANGUAGE_NONE][0]['value'], $node->field_doctype[LANGUAGE_NONE][0]['value'], $node->field_doclevelid[LANGUAGE_NONE][0]['value']);
	?>
  

	<?php /* ---------------------- GENERIC CHILD STATUTES VIEW -------------------- */ ?>
	<?php if(1): //if($node->field_doctype['und'][0]['value'] != 'SECTION'): ?>
		<?php

      $view = nys_statute_render_child_statutes($node);
      if (empty($view) == FALSE) {
        print $view;
      }
      elseif(empty($node->field_text[LANGUAGE_NONE][0]['value']) == FALSE) {
        print '<div class="c-law-doc-text">';
        echo nys_statute_html_format_raw_law_text($node->field_text[LANGUAGE_NONE][0]['value']);
        print '</div>';
      }

    ?>
	<?php endif; ?>
	<?php /* ---------------------- /GENERIC CHILD STATUTES VIEW ------------------- */ ?>

	<?php /* ---------------------- SPECIFIC NODE VIEWS ---------------------------- */ ?>

	<?php /* ----------------------------  CHAPTER   ------------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'CHAPTER'): ?>
	<!-- doctype CHAPTER -->

	<!-- /doctype CHAPTER -->
	<?php endif; ?>

	<?php /* ----------------------------  ARTICLE   ------------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'ARTICLE'): ?>
	<!-- doctype ARTICLE -->

	<!-- /doctype CHAPTER -->
	<?php endif; ?>

	<?php /* -----------------------------  SECTION  ------------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'SECTION' || $node->field_doctype['und'][0]['value'] == 'ARTICLE' || $node->field_doctype['und'][0]['value'] == 'CHAPTER'): ?>
	<!-- doctype SECTION -->

    <?php if(0): ?>
		    <div class="c-law-doc-text"><?php echo nys_statute_html_format_raw_law_text($node->field_text[LANGUAGE_NONE][0]['value']); ?></div>
    <?php endif; ?>

	<!-- /doctype SECTION -->	<?php endif; ?>

	<?php /* -------------------------------  TITLE  ------------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'TITLE'): ?>
	<!-- doctype SECTION -->

	<!-- /doctype SECTION -->
	<?php endif; ?>

	<?php /* -------------------------------  PART  -------------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'PART'): ?>
	<!-- doctype PART -->

	<!-- /doctype PART -->
	<?php endif; ?>

	<?php /* -----------------------------   SUB_PART   ---------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'SUB_PART'): ?>
	<!-- doctype SUB_PART -->

	<!-- /doctype SUB_PART -->
	<?php endif; ?>

	<?php /* -----------------------------  SUBARTICLE  ---------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'SUBARTICLE'): ?>
	<!-- doctype SUBARTICLE -->

	<!-- /doctype SUBARTICLE -->
	<?php endif; ?>

	<?php /* -----------------------------  SUBTITLE  ------------------------------ */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'SUBTITLE'): ?>

	<!-- doctype SUBTITLE -->

	<!-- /doctype SUBTITLE -->
	<?php endif; ?>

	<?php /* ------------------------------   MISC   ------------------------------- */ ?>
	<?php if($node->field_doctype['und'][0]['value'] == 'MISC'): ?>
	<!-- doctype MISC -->

	<!-- /doctype MISC -->
	<?php endif; ?>

	<?php /* ---------------------- /SPECIFIC NODE VIEWS --------------------------- */ ?>

	<?php /* ----------------------------  LOWER NAV  ------------------------------ */ ?>
	<?php if ((is_array($node->field_prevsibling) == TRUE && count($node->field_prevsibling) > 0) || (is_array($node->field_nextsibling) == TRUE && count($node->field_nextsibling) > 0)): ?>
		<hr/>
		<div class="row c-law-sibling-links">
      		<div class="medium-6 columns">
				<?php if (is_array($node->field_prevsibling) == TRUE && count($node->field_prevsibling) > 0): ?>
					<a class="icon-before__left" href="<?php echo "{$node->field_prevsibling[LANGUAGE_NONE][0]['url']}" ?>/">
           				<?php echo $node->field_prevsibling[LANGUAGE_NONE][0]['title']; ?>
          			</a>
				<?php endif; ?>
			</div>
			<div class="medium-6 columns">
				<?php if (is_array($node->field_nextsibling) == TRUE && count($node->field_nextsibling) > 0): ?>
					<a class="right icon-after__right" href="<?php echo "{$node->field_nextsibling[LANGUAGE_NONE][0]['url']}" ?>/">
           				<?php echo $node->field_nextsibling[LANGUAGE_NONE][0]['title']; ?>
          			</a>
				<?php endif; ?>
			</div>
		</div>
		<hr/>
	<?php endif; ?>
	<?php /* ----------------------------  /LOWER NAV  ----------------------------- */ ?>

<?php endif; ?>
<?php /* =========================== /NODES ======================================== */ ?>
