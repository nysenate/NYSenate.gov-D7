<?php
/**
 * @file Template for Bill Detail Votes.
 *
 * @var string $title
 *   The block title.
 * @var array $content
 *   The block content.
 *   The vote block will have the following keys:
 *   - string aye_count
 *   - string nay_count
 *   - string absent_count
 *   - string excused_count
 *   - string abstained_count
 *   - string vote_type
 *   - string committee_type
 *   - array all_members
 *       An array of all Senate members tagged to the vote.
 *
 *   The following properties are included:
 *   - int #vote_instance
 *     The number vote for the page.
 *   - bool #member_content_flag
 *     If Senate members are tagged to the content.
 */
?>
<?php
// @todo Replace with a per-page accordion tracker.
// Currently accordion instances are hardcoded and there is already one by
// default on the Bill page.
$accordion = 'accordion-' . ($content['#vote_instance'] + 1);
$committee_name = !empty($content['committee_name']) ? ' ' . $content['committee_name'] : '';
$vote_type = !empty($content['vote_type']) ? $content['vote_type'] : '';
?>

<div class="c-bill--vote c-bill--vote_<?php print ($content['vote_type'] == 'floor' ? "1" : "2"); ?>">
  <h3 class="c-detail--subhead c-detail--section-title c-bill-detail--subhead">
    <?php echo "${content['vote_date']} - ${committee_name} ${vote_type} Vote" ?>
  </h3>
  <a href="/<?php print drupal_get_path_alias('node/' . $content['vote_bill_nid']); ?>">
    <span class="c-bill-action-version c-bill--flag c-bill-action--orig-bill">
     <?php echo $content['vote_print_number'] ?>
    </span>
  </a>
  <div class="pieContainer">
    <div class="aye"><?php print $content['aye_count']; ?></div>
    <div class="nay"><?php print $content['nay_count']; ?></div>
    <div class="vote_type"><?php print $content['vote_type']; ?></div>
    <div class="pieBackground"></div>
    <div id="pieSlice<?php print $content['#vote_instance']; ?>" class="hold">
      <div class="pie"></div>
    </div>
  </div>
  <div class="c-bill--vote-details">
    <div class="c-bill--vote-details-wrapper">
      <div class="vote-container">
        <div class="aye<?php if ($content['vote_type'] == 'committee'): print ' committee_vote'; endif; ?>">
          <div class="vote-count"><?php print $content['aye_count']; ?></div>
          <div class="vote-label">Aye</div>
        </div>
        <div class="nay<?php if ($content['vote_type'] == 'committee'): print ' committee_vote'; endif; ?>">
          <div class="vote-count"><?php print $content['nay_count']; ?></div>
          <div class="vote-label">Nay</div>
        </div>
      </div>
      <div class="vote-meta">
        <?php if ($content['vote_type'] == 'committee'): ?>
        <div class="meta-row">
          <div class="meta-count"><?php print $content['aye_wr_count']; ?></div>
          <div class="meta-label">Aye with Reservations</div>
        </div>
        <?php endif; ?>
        <div class="meta-row">
          <div class="meta-count"><?php print $content['absent_count']; ?></div>
          <div class="meta-label">Absent</div>
        </div>
        <div class="meta-row">
          <div class="meta-count"><?php print $content['excused_count']; ?></div>
          <div class="meta-label">Excused</div>
        </div>
        <div class="meta-row">
          <div class="meta-count"><?php print $content['abstained_count']; ?></div>
          <div class="meta-label">Abstained</div>
        </div>
      </div>
    </div>
  </div>

  <?php if ($content['#member_content_flag']): ?>
    <dl class="c-bill-vote--accordion accordion" data-accordion="">
      <dd class="accordion-navigation">
        <?php
        $committee_type = !empty($content['committee_type']) ? ' ' . $content['committee_type'] : '';
        $vote_type = !empty($content['vote_type']) ? ' ' . $content['vote_type'] : '';
        $accordion_show = "show$committee_type$vote_type vote details";
        $accordion_hide = "hide$committee_type$vote_type vote details";
        ?>
        <a href="#<?php print $accordion; ?>" class="accordion--btn nys-btn-more" data-open-text="<?php print $accordion_hide; ?>" data-closed-text="<?php print $accordion_show; ?>"><?php print $accordion_show; ?></a>
        <div id="<?php print $accordion; ?>" class="content">
          <?php if ($content['vote_date']): ?>
            <h3 class="c-vote-detail--date"><?php print ucfirst($content['committee_type']); ?> <?php print ucfirst($content['vote_type']); ?> Vote: <?php print $content['vote_date']; ?></h3>
          <?php endif; ?>
          <?php $count = 0; ?>
          <?php foreach ($content['all_members'] as $key => $members): ?>
            <div class="c-detail--vote-grp <?php print (++$count % 2 ? "odd" : "even"); ?>">
              <?php
                $title = explode('_members', $key);
                $title = str_replace("_", " ", $title[0]);
              ?>
              <div class="c-detail--section-title"><?php print $title . ' (' . count($members) . ')'; ?></div>
              <ul class="c-votes--items">
                <?php foreach ($members as $member): ?>
                  <li><?php print $member; ?></li>
                <?php endforeach; ?>
              </ul>
            </div>
          <?php endforeach; ?>
        </div>
      </dd>
    </dl>
  <?php endif; ?>
</div>

