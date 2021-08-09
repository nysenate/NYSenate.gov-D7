<?php //if(isset($senator_full_name) && isset($senator_headshot)):?>
<div class="l-header-region l-row l-row--hero c-senator-hero">
  <div class="c-senator-hero--img">
    <a href="#" alt="<?php print $senator_full_name; ?>">
      <img src="http://placekitten.com/g/75/75" />
    </a>
  </div>
  <div class="c-senator-hero--info">
    <div>
      <h2 class="c-senator-hero--title">new york state senator</h2>
      <h3 class="c-senator-hero--name"><a href="/<?php echo $senator_url; ?>" alt="<?php print $senator_full_name; ?>">Fake Madeupman</a></h3>
    </div>
  </div>
  <a class="c-block--btn c-senator-hero--contact-btn icon-before__contact med-bg" href="/contact/">contact senator</a>
</div>
<?php //endif; ?>