<?php if (!empty($related_issues)): ?>
<div class="view view-issues-listings view-id-issues_listings view-display-id-news_issues_listing view-dom-id-1bdc388c62c9901ac7c127036e5adc41 jquery-once-2-processed">
  <div class="view-header">
    <div class="large-12 columns">
      <h3 class="nys-title">Related Issues</h3>
    </div>
  </div>
  <div class="view-content">
    <?php
    $first    = ' first';
    $even_odd = ' odd';
    foreach ($related_issues as $index => $issue): ?>
   
    <div class="c-block--issue lgt-bg<?php echo $first.$even_odd; ?>">
      <h4 class="c-issue-block--title"><a href="/<?php echo $issue->path; ?>"><?php echo $issue->name; ?></a></h4>
      <div class="c-block--btn">
        <span class="flag-wrapper flag-follow-issue">
          <?php echo flag_create_link('follow_issue', $issue->tid); ?>
        </span>
      </div>
    </div>
      <?php
      $first = '';
      $even_odd = $index % 2 == 0 ? ' even' : ' odd';
    endforeach; ?>
  </div>
  <div class="view-footer">
    <div class="c-block--explore-issues">
      <a href="/explore-issues" class="icon-after__arrow">Explore All Issues</a>
    </div>
  </div>
</div>
<?php endif; ?>