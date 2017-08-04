<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width. It is 5 rows high; the top
 * middle and bottom rows contain 1 column, while the second
 * and fourth rows contain 2 columns.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['above_left']: Content in the left column in row 2.
 *   - $content['above_right']: Content in the right column in row 2.
 *   - $content['middle']: Content in the middle row.
 *   - $content['below_left']: Content in the left column in row 4.
 *   - $content['below_right']: Content in the right column in row 4.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
  <?php if ($content['header']): ?>
    <header id="js-sticky" role="banner" class="l-header">
      <?php print $content['header']; ?>
    </header>
  <?php endif; ?>
  <?php if ($content['hero']): ?>
      <?php print $content['hero']; ?>
  <?php endif; ?>

  <?php if ($content['content']): ?>
    <main role="main" class="l-row l-row--main l-main">
      <a id="main-content"></a>
      <?php print $content['content']; ?>
    </main>
  <?php endif; ?>
  
  <!-- Standard Footer -->
  <?php if (!empty($content['footer_first']) || !empty($content['footer_middle']) || !empty($content['footer_last'])): ?>
    <!--.l-footer-->
    <footer class="l-footer" role="contentinfo">
      <?php if (!empty($content['footer_first'])): ?>
        <div id="footer-first">
          <?php print render($content['footer_first']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($content['footer_middle'])): ?>
        <div id="footer-middle">
          <?php print render($content['footer_middle']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($content['footer_last'])): ?>
        <div id="footer-last">
          <?php print render($content['footer_last']); ?>
        </div>
      <?php endif; ?>
    </footer>
    <!--/.footer-->
  <?php endif; ?>