<?php

/**
 * @file
 * Template for displaying single location.
 */
?>
<div class="location vcard" itemscope itemtype="http://schema.org/PostalAddress">
  <div class="adr">
    <?php if (!empty($name)): ?>
      <span class="fn" itemprop="name"><?php print $name; ?></span>
    <?php endif; ?>

    <?php if (!empty($street) || !empty($additional)): ?>
      <div class="street-address">
        <span itemprop="streetAddress"><?php print $street; ?></span>
        <?php if (!empty($additional)): ?>
          <span class="additional" itemprop="streetAddress">
            <?php print ' ' . $additional; ?>
          </span>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($city)): ?>
      <span class="locality" itemprop="addressLocality">
      <?php print $city . ', '; ?>
      </span>

    <?php endif; ?>
    <?php if (!empty($province)): ?>
      <span class="region" itemprop="addressRegion"><?php print $province_print; ?></span>
    <?php endif; ?>
    <?php if (!empty($postal_code)): ?>
      <span class="postal-code" itemprop="postalCode"><?php print $postal_code; ?></span>
    <?php endif; ?>

    <?php if (!empty($email)): ?>
      <div class="email">
        <abbr class="type" title="email"><?php print t("Email address"); ?>:</abbr>
        <span><a href="mailto:<?php print $email; ?>" itemprop="email"><?php print $email; ?></a></span>
      </div>
    <?php endif; ?>
    <?php if (!empty($phone)): ?>
        <div class="tel value" itemprop="telephone"><span>Phone: </span><?php print $phone; ?></div>

    <?php endif; ?>
    <?php if (!empty($fax)): ?>
        <div class="tel" itemprop="faxNumber"><span>Fax: </span><?php print $fax; ?></div>
    <?php endif; ?>
      <?php if (!empty($contact_name)): ?>
          <div class="tel fn" itemprop="openingHours"><span>Office Hours: </span><?php print $contact_name; ?></div>
      <?php endif; ?>
    <?php
    // "Geo" microformat, see http://microformats.org/wiki/geo.
    ?>
    <?php if(!empty($street) && !empty($city) && !empty($province_print) && !empty($postal_code)): ?>
      <?php $loc = str_replace(' ', '+', ($street.'+'.$city.', '.$province_print.'+'.$postal_code));?>
      <a class="c-office-location-link" href="https://www.google.com/maps/place/<?php echo $loc;?>" target="_blank">map</a>
    <?php endif; ?>
  </div>
</div>
