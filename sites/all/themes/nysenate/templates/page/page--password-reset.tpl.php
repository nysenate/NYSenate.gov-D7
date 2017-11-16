<!--.page password-reset -->
<div role="document" class="page">
  <main role="main" class="l-row l-row--main l-main">
    <img src="<?php print $logo_path; ?>" style="width: 25%; margin: 0 auto;">
    <hr />
    <h1 class="nys-article-title" style="text-align: center;"><?php print $form_title; ?></h1>
    <div class="system-messages"><?php print $messages; ?></div>
    <div class="password-reset-greeting"><?php print $greeting; ?></div>
    <?php print $render_form; ?>
  </main>
</div>
