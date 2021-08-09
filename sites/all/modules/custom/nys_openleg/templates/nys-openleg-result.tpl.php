<?php
/**
 * @file nys-openleg-result.tpl.php
 *
 * @var $title string|string[] Parameters for head_title theme
 * @var $list_items string The rendered list items
 * @var $breadcrumbs string Rendered breadcrumbs
 * @var $nav string Rendered navigational markers
 * @var $share_path string The URL to the statute being rendered
 * @var $entry_text string The body of the entry
 * @var $history array a Drupal Forms API array for milestone selection
 * @var $search string Rendered HTML for search form
 * @var $deprecation_warning boolean Indicates if an old URL was used
 * @var $debug mixed
 */

global $base_url;

// Trap for unpopulated titles
if (is_array($title)) {
  $mail_title = reset($title);
}
else {
  $mail_title = (string) $title;
}
$mail_title = $mail_title ?: "Laws of New York <!-- untitled -->";

// Generate the link for share by email
$mail_link = 'mailto:?subject=' . $mail_title .
  ' | NY State Senate&amp;body=Check out this law: ' . $share_path;

if ($deprecation_warning) {
  $url_args = array_slice(arg() ,2, 2);
  $deprecation_url = $base_url . '/' . NYS_OPENLEG_MENU_PATH . '/' . implode('/', $url_args);
}
?>
<div class="nys-openleg-statute-container">
  <?php
  if ($deprecation_warning) { ?>
    <div class="nys-openleg-deprecation-warning">This URL is deprecated and will be removed in the future. Please update your bookmarks to use <a href="<?php echo $deprecation_url; ?>"><?php echo $deprecation_url; ?></a>.</div>
  <?php }
  echo $search;
  echo $breadcrumbs;
  echo $nav;
  ?>
  <div class="nys-openleg-result-tools">
    <?php if ($history) { ?>
      <div class="nys-openleg-history-container">
        <?php echo $history; ?>
      </div>
    <?php } ?>
    <div class="c-detail--social nys-openleg-result-share">
      <h3 class="c-detail--subhead">Share</h3>
      <ul>
        <li>
          <a target="_blank"
             href="https://www.facebook.com/sharer/sharer.php?u=<?php echo $share_path; ?>"
             class="c-detail--social-item facebook">
            Facebook
          </a>
        </li>
        <li>
          <a target="_blank"
             href="https://twitter.com/intent/tweet?text=From @nysenate: <?php echo $share_path; ?>"
             class="c-detail--social-item twitter">
            Twitter
          </a>
        </li>
        <li>
          <a href="<?php echo $mail_link; ?>"
             class="c-detail--social-item email">
            Email
          </a>
        </li>
      </ul>
    </div>
  </div>
  <div class="nys-openleg-result-container">
    <div class="nys-openleg-head-container">
      <?php
      echo _nys_openleg_theme_wrapper('nys_openleg_result_head_title', ['title' => $title]);
      ?>
    </div>

    <div class="nys-openleg-content-container">
      <?php if ($list_items) { ?>
        <div class="nys-openleg-items-container"><?php echo $list_items; ?></div>
      <?php }
      if ($entry_text) { ?>
        <div class="nys-openleg-result-text"><?php echo $entry_text; ?></div>
      <?php } ?>
    </div>
    <?php if ($debug) { ?>
      <pre class="nys-openleg-debug-container">
      <?php echo htmlentities(var_export($debug, 1), ENT_QUOTES); ?>
    </pre>
    <?php } ?>
  </div>
</div>
