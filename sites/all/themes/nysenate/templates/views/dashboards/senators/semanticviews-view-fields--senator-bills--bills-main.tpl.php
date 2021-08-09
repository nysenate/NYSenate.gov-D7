<div class="c-block c-list-item c-legislation-block">
    <div class="c-bill-meta">
      <h3 class="c-bill-num"><?php echo $fields['field_bill_id']->content; ?></h3>
      <h4 class="c-bill-topic"><?php echo $fields['field_openleg_issues']->content;?></h4>
    </div>
    <div class="c-bill-body">
      <p class="c-bill-descript"><?php echo $fields['name']->content; ?></p>
      <div class="c-bill-path">
        <hr class="c-bill-path--line ">
        <ul>
      <?php 
        if(isset($fields['field_openleg_actions_status'])){
          for ($i = 1; $i <= $fields['field_openleg_actions_status']->content; $i++)
            echo "<li class='c-bill-path--step c-bill-path--step__passed'></li>";
          for ($i = $fields['field_openleg_actions_status']->content +1 ; $i <= 6; $i++)
            echo "<li class='c-bill-path--step'></li>";
        }
        else for ($i = 1; $i <= 6; $i++)
          echo "<li class='c-bill-path--step'></li>";
      ?>
        </ul>
      </div>

      <div class="c-bill-update">
        <p class="c-bill-update--date"><?php echo $fields['field_openleg_last_action_date']->content;?></p>
        <p class="c-bill-update--location"><?php if(isset($fields['field_openleg_current_committee'])) echo $fields['field_openleg_current_committee']->content; ?></p>
      </div>
    </div>
  </div>