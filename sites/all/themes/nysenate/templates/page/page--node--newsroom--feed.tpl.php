<?php
/**
 * @file
 * Newsroom Feed page template.
 *
 * This file prints just the markup array to avoid
 * cluttering the RSS XML from a feed block.
 */

if (!empty($page['content']['system_main']['main']['#markup'])):
  print trim($page['content']['system_main']['main']['#markup']);
elseif (!empty($page['content']['system_main']['content']['#markup'])):
  print trim($page['content']['system_main']['content']['#markup']);
else:
  print render($page['content']);
endif;
