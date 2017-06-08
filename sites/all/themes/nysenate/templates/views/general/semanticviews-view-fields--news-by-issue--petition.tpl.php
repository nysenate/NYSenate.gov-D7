<article class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">

  <img src="http://nysenate.dev/sites/default/files/styles/280x280/public/IMG_0039.JPG?itok=ceJ-p_nX" width="280" height="280" alt="">
  <div class="c-initiative--content">
    <div class="c-initiative--inner">
      <p><?php echo $fields['field_senator']->content;?></p>
      <h3 class="c-initiative--title"><?php echo $fields['title']->content;?></h4>
    </div>
  </div>
  <a href="<?php echo $fields['path']->content;?>" class="c-block--btn icon-before__questionaire med-bg">
      <?php echo ($fields['type']->content == 'petition') ? "Review the Petition" : "Take The Questionnaire";?>
  </a>
</article>