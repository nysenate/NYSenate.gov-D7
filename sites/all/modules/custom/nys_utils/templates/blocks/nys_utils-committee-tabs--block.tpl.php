<?php
$all_news = views_get_view('senator_news'); 
$all_news_output = $all_news->preview('committee_news');

$committee_news_tab = views_get_view('senator_news');
$committee_news_tab_output = $committee_news_tab->preview('committee_news_tab');

$committee_event_archive_tab = views_get_view('senator_news');
$committee_event_archive_tab_output = $committee_event_archive_tab->preview('committee_event_archive_tab');

?>
<dl class="tabs l-tab-bar" data-tab>
	<div class="c-tab--arrow u-mobile-only"></div>
	<?php if(!empty($all_news_output)): ?>
		<dd class="active c-tab"><a class="c-tab-link first" href="#panel1">All Updates</a></dd>
	<?php endif;?>
	<?php if(!empty($committee_news_tab_output)): ?>
		<dd class="c-tab"><a class="c-tab-link" href="#panel2">News</a></dd>
	<?php endif;?>
	<?php if(!empty($committee_event_archive_tab_output)): ?>
		<dd class="c-tab"><a class="c-tab-link" href="#panel3">Meeting Archive</a></dd>
	<?php endif;?>
</dl>

<div class="tabs-content">
	<div class="content active" id="panel1">
		<?php
	      if (!empty($all_news_output)) {
	        print $all_news_output;
	      }
	    ?>
	</div>
	<div class="content" id="panel2">
		<?php
	      if (!empty($committee_news_tab->result)) {
	        print $committee_news_tab_output;
	      }
	    ?>
	</div>
	<div class="content" id="panel3">
		<?php
	      if (!empty($committee_event_archive_tab->result)) {
	        print $committee_event_archive_tab_output;
	      }
	    ?>
	</div>
</div>