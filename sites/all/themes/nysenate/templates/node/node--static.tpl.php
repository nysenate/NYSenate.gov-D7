<?php

// TEMP
$theme_path = '/'.drupal_get_path('theme', variable_get('theme_default', NULL));

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
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['links']);
    hide($content['field_tags']);
  ?>

  <!-- WINNERS MODULE - subset of initiative -->
  <div class="c-block c-block--initiative c-block--initiative__has-img">

    <img src="<?php print $theme_path; ?>/images/winners-block-img.jpg" alt="" />

    <div class="c-initiative--content">
      <p class="c-initiative--descript">9TH SENATE DISTRICT earth day
  2014 poster contest winner</p>
      <h4 class="c-initiative--title">Kelly Ann Hammond</h4>
      <ul class="c-initiative--meta">
        <li>Grade 4</li>
        <li>Fulmar Road</li>
      </ul>
    </div>
    <a href="#" class="c-block--btn icon-before__awards med-bg">read more</a>
  </div>
  <!-- end : WINNERS MODULE -->

  <div class="c-block c-block--initiative">
    <div class="c-initiative--content">
      <h4 class="c-initiative--title">No Free College for Convicts</h4>
    </div>
    <a href="#" class="c-block--btn icon-before__petition med-bg">review the petition</a>
  </div>

  <!-- INITIATIVE BLOCK - TWO UP -->
  <div class="l-row c-block--initiative__half-wrap">

    <div class="c-block c-block--initiative c-block--initiative__half lgt-bg">
      <div class="c-initiative--content">
        <p class="c-initiative--descript">senator dean g. skelos'</p>
        <h4 class="c-initiative--title">2014 Constituent Questionaire</h4>
      </div>
      <a href="#" class="c-block--btn icon-before__questionaire med-bg">take the questionnaire with line break</a>
    </div>

    <div class="c-block c-block--initiative c-block--initiative__half lgt-bg">
      <div class="c-initiative--content">
        <h4 class="c-initiative--title">No Free College for Convicts</h4>
      </div>
      <a href="#" class="c-block--btn icon-before__petition med-bg">review the petition</a>
    </div>

  </div>
  <!-- end initiative block two up -->

  <div class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">

    <img src="<?php print $theme_path; ?>/images/initiative-block-img.jpg" alt="" />

    <div class="c-initiative--content">
      <div class="c-initiative--inner">
        <h4 class="c-initiative--title">Shed the Meds Program wirds ad wird haklsdhf bird</h4>
      </div>
    </div>
    <a href="#" class="c-block--btn icon-before__petition med-bg">review the petition</a>
  </div>


  <!-- TEMPORARY MODULE EXAMPLE - EVENT TODAY -->
  <div class="c-event-block c-event-block--today">
    <div class="c-event-time"><span>7:00</span> PM <span>&nbsp;-&nbsp; 10:00</span> PM</div>
    <h3 class="c-event-name">State Legistlators Team Up To Host Yoga In The Park</h3>
    <a href="#" class="c-event-location"><span class="icon-before__circle-pin"></span>Lorem Place</a>
    <div class="c-event-address">8851 Somewhere Rd<br/>Bronx, NY 10462</div>
    <a href="#" class="c-event-rsvp">r.s.v.p. to this event</a>
  </div>
  <!-- end Event Today -->

  <!-- TEMPORARY MODULE EXAMPLE - UPCOMING EVENTS -->
  <div class="c-upcoming-container">
    <div class="c-title">Upcoming Events
      <a href="/events" class="c-calendar icon-after__arrow">Go to Calendar</a>
    </div>
    <div class="c-event-block c-event-block--upcoming u-odd">
      <div class="c-event-date"><span>01</span> August</div>
      <h3 class="c-event-name">State Legistlators Team Up To Host Yoga In The Park</h3>
      <a href="" class="c-event-location"><span class="icon-before__circle-pin"></span>Lorem Place</a>
      <div class="c-event-address">8851 Somewhere Rd<br/>Bronx, NY 10462</div>
      <div class="c-event-time">7:00 PM - 10:00 PM</div>
    </div>
    <div class="c-event-block c-event-block--upcoming">
      <div class="c-event-date"><span>02</span> August</div>
      <h3 class="c-event-name">State Legistlators Team Up To Host Yoga In The Park</h3>
      <a href="" class="c-event-location"><span class="icon-before__circle-pin"></span>Lorem Place</a>
      <div class="c-event-address">8851 Somewhere Rd<br/>Bronx, NY 10462</div>
    </div>
    <div class="c-event-block c-event-block--upcoming u-odd">
      <div class="c-event-date"><span>03</span> August</div>
      <h3 class="c-event-name">State Legistlators Team Up To Host Yoga In The Park</h3>
      <a href="" class="c-event-location"><span class="icon-before__circle-pin"></span>Lorem Place</a>
      <div class="c-event-address">8851 Somewhere Rd<br/>Bronx, NY 10462</div>
    </div>
    <div class="c-event-block c-event-block--upcoming">
      <div class="c-event-date"><span>04</span> August</div>
      <h3 class="c-event-name">State Legistlators Team Up To Host Yoga In The Park</h3>
      <a href="" class="c-event-location"><span class="icon-before__circle-pin"></span>Lorem Place</a>
      <div class="c-event-address">8851 Somewhere Rd<br/>Bronx, NY 10462</div>
      <div class="c-event-time">7:00 PM - 10:00 PM</div>
    </div>
  </div>
  <!-- end Upcoming Events -->

  <!-- TEMPORARY MODULE EXAMPLE - FEATURED ISSUE -->
  <div class="c-event-cluster c-event-cluster-featured-issue">
    <div class="c-title"><h3>Featured Issue</h3>
      <a href="#">Nigerian Kidnapping</a>
    </div>
    <div class="l-left">
      <a href="#">
        <img class="c-event-image" src="http://placehold.it/440x230" alt="" />
        <div class="c-description">Senator Dean G. Skelos Supports the Petition To Bring Back Our Girls</div>
      </a>
    </div>
    <div class="l-right">
      <a class="c-link c-link-with-image">
        <img class="c-link-image" src="http://placehold.it/80x60"/>
        <h3 class="c-link-title">More then 60 Nigerian Girls and Women Escape</h3>
      </a>
      <a class="c-link">
        <h3>How to Bring Back the Nigerian Schoolgirls, Three Months On</h3>
      </a>
      <a class="c-link c-link-with-image">
        <img class="c-link-image" src="http://placehold.it/80x60"/>
        <h3 class="c-link-title">'Bring Back Our Girls, Now and Alive'</h3>
      </a>
      <a class="c-link">
        <h3>How to Bring Back the Nigerian Schoolgirls, Three Months On</h3>
      </a>
    </div>
  </div>
  <!-- end Featured Issue -->

  <!-- TEMPORARY MODULE EXAMPLE - FEATURED STORY / VIDEO -->
<!--   <div class="c-event-featured-story">
    <h3 class="c-title">Featured Story</h3>
    <div class="l-left">
      <img class="c-story-image" src="http://placehold.it/380x220" alt="" />
    </div>
    <div class="l-right">
      <p class="c-story-name">Senator Skelos at the Nassau's Boys & Girls Club 2014 Reception</p>
      <a href="#" class="c-story-link">BOYS & GIRLS CLUB</a>
    </div>
  </div> -->
  <!-- end Featured Story / Video -->

  <!-- TEMPORARY MODULE EXAMPLE - NEWS CLUSTER -->
  <div class="c-news-container">
    <div class="c-container-title"><h2>Newsroom</h2>
      <a href="#" class="c-newsroom icon-after__arrow">Go to Newsroom</a>
    </div>
    <div class="c-news-block c-news-block-press-relase u-odd">
      <h3 class="c-title">Press Release</h3>
      <div class="c-newsroom-name">Senator Skelos' Statement Regarding the Two Destructive Fires in Nassau</div>
      <a href="" class="c-newsroom-link">Firefighters</a>
    </div>
    <div class="c-news-block c-news-block-video">
      <h3 class="c-title">Video</h3>
      <img class="c-newsroom-image" src="http://placehold.it/360x200" alt="" />
      <p class="c-newsroom-name">Senate Republican Leader Dean G. Skelos Budget Statement</p>
      <a href="" class="c-newsroom-link">Bronx</a>
    </div>
    <div class="c-news-block c-news-block-press-relase-image u-odd">
      <h3 class="c-title">Press Release</h3>
      <img class="c-newsroom-image" src="http://placehold.it/360x200" alt="" />
      <p class="c-newsroom-name">Senator Skelos' Statement Regarding the Two Destructive Fires in Nassau</p>
      <a href="" class="c-newsroom-link">Firefighters</a>
    </div>
    <div class="c-news-block c-news-block-tweet">
      <div class="c-title"><h3>Tweet</h3>
        <a href="#" class="c-newsroom twitter_follow">Follow</a>
      </div>
      <div  class="l-twitter-container">
        <img src="http://placehold.it/60x60" alt="" />
        <div class="c-twitter_info">
          <h3>Senator Dean Skelos</h3>
          <a href="#" class="c-link">@SenatorSkelos</a>
        </div>
      </div>
      <p class="c-tweet">Celebrating Ghanaian Heritage Annual Durbar at Dewitt Clinton High School <a href="#">@GhanaianHeritage</a></p>
      <div class="c-timestamp">10:01 AM - 13 Aug 2014</div>
    </div>
  </div>
  <!-- end News Cluster -->

  <!-- TEMPORARY MODULE EXAMPLE - SENATOR LISTING -->
  <div class="c-senators-container">
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">Joseph P., Jr Addabbo</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">Phillip Boyle</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">David Carlucci</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">John DeFrancisco</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">Martin Malave Dilan</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">Ruth Hassell Thompson</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">Liz Krueger</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
    <div class="c-senator-block">
      <a href="#"><img src="http://placehold.it/160x160" alt=""/></a>
      <a href="#"><h3 class="c-name">Andrew J. Lanza</h3></a>
      <a href="#" class="c-district">15TH District</a>
    </div>
  </div>
  <!-- end Senator Listing -->

  <!-- TEMPORARY MODULE EXAMPLE - COMMITTEES LISTING -->
  <div class="c-committees-container">
    <h2 class="c-container-title">All Committees</h2>
    <h3 class="c-category-title">Standing Committees</h3>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Aging</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Housing, Construction and Community Development</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Alcoholism and Drug Abuse</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Infrastructure and Capital Investment</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Children and Families</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Health</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Alcoholism and Drug Abuse</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Higher Education</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Children and Families</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Housing, Construction and Community Development</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Finance</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Infrastructure and Capital Investment</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Higher Education</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Children and Families</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Health</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Alcoholism and Drug Abuse</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Housing, Construction and Community Development</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Children and Families</h4></a>
    <h3 class="c-category-title">Temporary Committees</h3>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Higher Education</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Housing, Construction and Community Development</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Infrastructure and Capital Investment</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Aging</h4></a>
    <h3 class="c-category-title">Conferences & Caucuses</h3>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Higher Education</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Housing, Construction and Community Development</h4></a>
    <a href="#" class="c-committee-link u-odd"><h4 class="c-committee-title">Infrastructure and Capital Investment</h4></a>
    <a href="#" class="c-committee-link"><h4 class="c-committee-title">Aging</h4></a>
  </div>
  <!-- end Committees Listing -->

  <!-- TEMPORARY MODULE EXAMPLE - HOW THE SENATE WORKS -->
  <!-- Assumed Static HTML -->
<div class="c-senate-works-container">
    <div class="c-container-title"><h2>How the Senate Works</h2>
      <a href="#" class="c-senate-works icon-after__arrow">Learn More</a>
    </div>

    <ul class="mobile-carousel">
      <li class="c-senate-works-step l-first">
        <img class="c-senate-works-step-image" src="http://placehold.it/100x100" alt=""/>
        <p class="c-senate-works-step-description">Senator writes a bill</p>
      </li>
      <li class="c-senate-works-step">
        <img class="c-senate-works-step-image" src="http://placehold.it/100x100" alt=""/>
        <p class="c-senate-works-step-description">Senator proposes the bill</p>
      </li>
      <li class="c-senate-works-step">
        <img class="c-senate-works-step-image" src="http://placehold.it/100x100" alt=""/>
        <p class="c-senate-works-step-description">Committee votes<br/>on the bill</p>
      </li>
      <li class="c-senate-works-step">
        <img class="c-senate-works-step-image" src="http://placehold.it/100x100" alt=""/>
        <p class="c-senate-works-step-description">Floor votes<br/>on the bill</p>
      </li>
      <li class="c-senate-works-step l-last">
        <img class="c-senate-works-step-image" src="http://placehold.it/100x100" alt=""/>
        <p class="c-senate-works-step-description">Bill is passed</p>
      </li>
    </ul>
  </div>
  <!-- end How the Senate Works -->


  <h2 class="c-subpage-header--title">About <?php print $title; ?></h2>
  <p class="c-subpage-header--subtitle01"><?php print $node->field_current_duties[LANGUAGE_NONE][0]['value'];?></p>
  <p class="c-subpage-header--subtitle02 lgt-text">
    <span class="u-mobile-only">(R, C, IP)</span>
    <span class="u-tablet-plus">republican, conservative, independence</span>
  </p>
  <p class="c-subpage-header--subtitle03">9th senate district</p>


  <img class="senator-about--main-img" src="<?php print image_style_url('760x377', $node->field_image_main[LANGUAGE_NONE][0]['uri']); ?>" />

  <div class="l-row c-listing-block">
    <h3>Committees</h3>
    <ul>
      <li class="c-listing-block--item">
        <a class="lgt-text">Rules</a>
        <span>chair</span>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Veterans, Homeland Security & Military Affairs</a>
        <span>CO-CHAIR</span>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Commerce, Economic Development & Small Business</a>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Crime Victims, Crime & Correction</a>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Finance</a>
      </li>

      <li class="c-listing-block--item">
        <a class="lgt-text">Health</a>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Hudson Valley Delegation</a>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Judiciary</a>
      </li>
      <li class="c-listing-block--item">
        <a class="lgt-text">Social Services</a>
      </li>
    </ul>
  </div>

  <h4 class="c-blockquote"><?php print $node->field_pull_quote[LANGUAGE_NONE][0]['value']; ?></h4>

  <p>Senator Skelos, the highest-ranking Republican official in state government, has long been an outspoken advocate for reducing taxes, controlling government spending and helping the private sector create new jobs.  He was elected Majority Leader of the Senate by his colleagues on two occasions, in June 2008 and January 2011. Under Senator Skelos’ leadership, Republicans have reached across the aisle to work with Governor Cuomo to turn New York around.  During that time, the Legislature enacted a property tax cap, expanded the DNA databank, passed two early state budgets and ended Albany dysfunction. As the author of Megan’s Law, Senator Skelos created the New York State Sex Offender Registry and authored numerous measures strengthening this powerful statute, including the Workplace and Campus Registration acts.</p>

  <p class="c-pullquote icon-before__quotes">
    Efecrem diissa tea nontea nos mer usquis At parividem, quidet ventrum unt. Se, veritab eribus verendet visses eristab esseniquam ant.
    <span class="c-pullquote--citation icon-before__minus">senator dean g. skelos</span>
  </p>

  <p>This is a  lorem ipsum dolor text eatia sant aut  by Senator Skelos telling her thoughts & reasoning for this legislation. Sit velest aliquia dolupta tatio. Arum facia conet ut rae consed moluptae consed quisqui delitas estius sunt molorit aut quisqui odit reperferum ratum ipicto minvend itibus aniatur sum ali catecabo. Obis solupti asitisc imaxim re, sequid ut que nimus aut od quia doluptatur?  Giti ape suntias simagnim andelen isquam faccatibus elitat iniamusam quaspit, veria que pro eatia sant aut quatem sitis arum quibusda inctis sequam quisint pa provid moluptatis Agnatemquodit reptatio. Itatis dolupid magnisi tation re nihil inis eostore perferupta dolorendi diaturibus et, ommolum ipitisc iissimus, que conesto volorestis eossin nobit, ex eat.</p>

  <div class="c-embed-img">
    <img class="" src="/" />
    <span class="c-embed-caption">Senator Skelos speaks about the Boy & girls Club 2014 Reception donations</span>
  </div>

  <p>imus dem quisinu lloritionem ea aut vitam ne nossi demo doluptati acepro quas res modit qui derum alic torerum nisimus, sit aut vit quae. Ictur simpedipit exerumquat liquo testemp orrum, ut quat eaquis is et pla dolupta venimil landantin pore rerro dolor mo blab ilignatur aut volupturibus dolupti nvendentur atur.</p>

  <p>imus dem quisinu lloritionem ea aut vitam ne nossi demo doluptati acepro quas res modit qui derum alic torerum nisimus, sit aut vit quae. Ictur simpedipit exerumquat liquo testemp orrum, ut quat eaquis is et pla dolupta venimil landantin pore rerro dolor mo blab ilignatur aut volupturibus dolupti nvendentur atur.</p>

  <!-- video -->
  <div class="c-embed-vid">
    <img class="" src="/" />
    <span class="c-embed-caption">Senator Skelos speaks about the Boy & girls Club 2014 Reception donations</span>
  </div>

  <p>This is a  lorem ipsum dolor text eatia sant aut  by Senator Skelos telling her thoughts & reasoning for this legislation. Sit velest aliquia dolupta tatio. Arum facia conet ut rae consed moluptae consed quisqui delitas estius sunt molorit aut quisqui odit reperferum ratum ipicto minvend itibus aniatur sum ali catecabo. Obis solupti asitisc imaxim re, sequid ut que nimus aut od quia doluptatur?  Giti ape suntias simagnim andelen isquam faccatibus elitat iniamusam quaspit, veria que pro eatia sant aut quatem sitis arum quibusda inctis sequam quisint pa provid moluptatis Agnatemquodit reptatio.</p>

  <p>Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor. Curabitur blandit tempus porttitor. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>

  <p>Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean eu leo quam. Pellentesque ornare sem lacinia quam venenatis vestibulum. Nullam id dolor id nibh ultricies vehicula ut id elit.</p>


  <?php if (!empty($content['field_tags']) && !$is_front): ?>
    <?php //print render($content['field_tags']) ?>
  <?php endif; ?>

  <?php //print render($content['links']); ?>

</article>
