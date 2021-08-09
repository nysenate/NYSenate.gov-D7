<article class="c-block c-block--initiative c-block--initiative__has-img lgt-bg">

  <div class="c-initiative--content">
    <div class="c-initiative--inner">
      <p><?php echo $fields['field_senator']->content;?></p>
      <h3 class="c-initiative--title"><?php echo $fields['title']->content;?></h3>
    </div>
  </div>
  <a href="<?php echo $fields['path']->content;?>" class="c-block--btn icon-before__questionaire med-bg">
      <?php echo ($fields['type']->content == 'petition') ? "Review the Petition" : "Take The Questionnaire";?>
  </a>
</article>