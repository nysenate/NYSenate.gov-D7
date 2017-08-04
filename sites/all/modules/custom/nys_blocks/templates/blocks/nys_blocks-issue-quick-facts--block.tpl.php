<div class="c-block c-stats--container c-quick-facts--container">
  <h3 class="c-container--title"><?php echo $issue_name; ?> quick facts</h3>
  <span class="c-stats--highlight u-mobile-only"></span>

  <div class="c-carousel--nav u-mobile-only">
    <button class="c-carousel--btn prev hidden">prev</button>
    <button class="c-carousel--btn next">next</button>
  </div>

  <ul id="js-carousel-issue-stats" class="js-carousel c-carousel">
    <li class="c-carousel--item c-stats--item quickFactsLink pointer" data-panel="2" id="clickable2">
      <h4 class="c-stat"><?php echo $bills_facts_count; ?></a></h4>
      <p class="c-stat--descript">bills and<br/>resolutions</p>
    </li>
    <li class="c-carousel--item c-stats--item quickFactsLink pointer" data-panel="1" id="clickable1">
      <h4 class="c-stat"><?php echo $news_stories_facts_count; ?></a></h4>
      <p class="c-stat--descript">news stories</p>
    </li>
    <li class="c-carousel--item c-stats--item quickFactsLink pointer" data-panel="3" id="clickable3">
      <h4 class="c-stat pointer quickFactsLink"><?php echo $meetings_facts_count; ?></h4>
      <p class="c-stat--descript">meetings or<br/>public hearings</p>
    </li>
  </ul>
</div>


