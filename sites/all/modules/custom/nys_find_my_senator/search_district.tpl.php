<?php

/**
 * @file
 * District search template for legislation search.
 */

// Add css for this template.
$options = array(
  'type' => 'file',
  'group' => CSS_THEME,
);
drupal_add_css(drupal_get_path('module', 'nys_find_my_senator') . '/css/find_my_senator.css', $options);
if (!isset($searched)) {
  $searched = '';
}
?>
<div class="c-find-my-senator">
  <h2 class="nys-title">Find My Senator</h2>
  <?php if ($searched): ?>
    <div class="c-find-my-senator--results">
      <?php if ($json_resp->acceptableMatch && $json_resp->senateAssigned): ?>
        <?php $senate_district = $json_resp->districts->senate; ?>
        <div class="row c-find-my-senator--row">
          <div class="columns medium-6 l-padded-column">
            <h2 class="c-container--title">Your Senator</h2>
            <hr class="c-find-my-senator--divider"/>
            <?php if (!empty($senator_info) && $senator_info != FALSE): ?>
              <img class="c-find-my-senator--senator-img"
                   src="<?php print $senator_info['image_path'] ?>"/>
            <?php endif; ?>
            <div class="c-find-my-senator--district-info">
              <p>
                <a class="c-find-my-senator--senator-link"
                   href="<?php print (!empty($senator_info) && $senator_info != FALSE) ? $senator_info['path_alias'] : '' ?>">
                  <?php print $senate_district->senator->name ?>
                </a>
              </p>
              <p><?php print $senate_district->name ?></p>
            </div>
                <div>
                    <p class="c-login-create">
                      <?php if ($user->uid === 0): ?>
                        <?php print l(t('Message Senator'), '/registration/nojs/form/start/message-senator', array(
                            'external' => TRUE,
                            'attributes' => array(
                              'class' => array(
                                'c-block--btn',
                                'c-btn--small',
                                'c-btn--find-senator',
                                'icon-before__contact',
                              ),
                            ),
                            'query' => array(
                              'senator' => $senator_info['nid'],
                            ),
                          )
                        ) ?>

                      <?php else: ?>
                          <a href="<?php print substr($senate_district->senator->url, 24) . "/message" ?>" class="c-block--btn c-btn--small c-btn--find-senator">Message Senator</a>
                      <?php endif; ?>
                    </p>


            </div>

          </div>
          <div class="columns medium-6 r-padded-column">
            <h2 class="c-container--title">Matched Address</h2>
            <hr class="c-find-my-senator--divider"/>
            <p class="c-find-my-senator--address-line">
              <?php print $json_resp->address->addr1 ?>
            </p>
            <p class="c-find-my-senator--address-line">
              <?php print $json_resp->address->city . ', ' . $json_resp->address->state . ' ' .
                $json_resp->address->zip5 . '-' . $json_resp->address->zip4 ?>
            </p>
          </div>
        </div>
        <div class="row c-find-my-senator--row">
          <div class="columns large-12">
            <h2 class="c-container--title">Senate District Map</h2>
            <hr class="c-find-my-senator--divider"/>
            <iframe class="c-find-my-senator--map-frame"
                    src="//pubgeo.nysenate.gov/map/senate/<?php print $senate_district->district ?>">
            </iframe>
          </div>
        </div>
        <div class="row">
          <div class="columns large-12">
            <h2 class="c-container--title">Connect</h2>
            <hr/>
            <p><a class="c-find-my-senator--senator-link" href="registration/nojs/form">
              Create an account</a> on nysenate.gov so you can share your thoughts and feedback with
              your senator.
            </p>
          </div>
        </div>
    </div>
  <?php else: ?>
    <div class="c-find-my-senator--results">
      <p>Sorry we couldn't find a matching senate district based on the address you provided. Please
        check the address and try again.
      </p>
    </div>
  <?php endif; ?>
</div>
  <?php endif; ?>
<p>Please enter your street address and zip code to find out who your Senator is.</p>
<hr/>
<div class="c-find-my-senator--form-container">
  <form method="get" action="">
    <input type="hidden" name="search" value="true"/>
    <div class="row">
      <div class="columns medium-6 l-padded-column">
        <label for="address-line-1">Address Line 1</label>
        <input id="address-line-1" type="text" name="addr1" value="<?php print ($searched) ? $addr1 : '' ?>"/>
      </div>
      <div class="columns medium-3 l-padded-column ">
        <label for="city">City</label>
        <input id="city" name="city" type="text" value="<?php print ($searched) ? $city : '' ?>"/>
      </div>
      <div class="columns medium-3">
        <label for="zip5">Zip 5</label>
        <input id="zip5" name="zip5" type="text" value="<?php print ($searched) ? $zip5 : '' ?>"/>
      </div>
    </div>
    <button id="district-search-btn" class="c-block--btn c-btn--small c-btn--find-senator">Find My Senator</button>
  </form>
</div>
