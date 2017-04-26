<div class="c-block c-block--social">
  <div class="c-container--header__top-border">
    <h3 class="c-container--title"><?php print $social_share_title; ?></h3>
  </div>
  <a target="_blank" href="https://www.facebook.com/sharer/sharer.php?u=<?php print $node_url; ?>" class="c-block--btn c-btn--small c-btn--facebook">facebook</a>
  <a target="_blank" href="https://twitter.com/home?status=<?php print $title; ?> Via: @nysenate: <?php print $node_url; ?>" class="c-block--btn c-btn--small c-btn--twitter">twitter</a>
  <a href="mailto:?&subject=From NYSenate.gov: <?php print $title; ?>&body=<?php print $CTA; ?>: <?php print $title; ?>: < <?php print $node_url; ?> >." class="c-block--btn c-btn--small c-btn--email">email</a>
</div>