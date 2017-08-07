<div class="c-block c-list-item c-legislation-block">
    <div class="c-bill-meta">
      <h3 class="c-bill-num"><?php echo $fields['field_bill_id']->content; ?></h3>
      <h4 class="c-bill-topic"><?php echo $fields['field_openleg_issues']->content;?></h4>
    </div>
    <div class="c-bill-body">
      <p class="c-bill-descript"><?php echo $fields['name']->content; ?></p>
    </div>
    <div class="c-bill-body">
      <div id="all_votes">
        <?php
        //To display "20 ayes" like text you just reuse these variables...
        $aye = isset($fields['view_1']->content)?$fields['view_1']->content:0;
        $nay = isset($fields['view']->content)?$fields['view']->content:0;
        $aye_constituent = isset($fields['view_2']->content)?$fields['view_2']->content:0;
        $nay_constituent = isset($fields['view_3']->content)?$fields['view_3']->content:0;
        $total_votes = $aye + $nay;
        $total_constituent_votes = $aye_constituent + $nay_constituent;


        $settings = array();
          $settings['chart']['chartOne'] = array(  
              'header' => array('Aye', 'Nay'),
              'rows' => array(array($aye, $nay)),
              'columns' => array('Votes'),
              'chartType' => 'PieChart',
              'containerId' =>  'all_votes',
              'options' => array( 
                'forceIFrame' => FALSE, 
                'title' => '',
                'width' => 500,
                'height' => 250,
                'pieHole'=> 0.6,
                'pieSliceText'=> 'none',
                'colors'=> array('#1f798f', '#04a9c5'),
              'legend'=> array(
                  'position'=>'none'
                ),
              )
            );
          //Draw it.
          draw_chart($settings); 
        ?>
      </div>
      <div id="constituent_votes">
        <?php
        $settings2 = array();
          $settings2['chart']['chartTwo'] = array(  
              'header' => array('Aye', 'Nay'),
              'rows' => array(array($aye_constituent, $nay_constituent)),
              'columns' => array('Votes'),
              'chartType' => 'PieChart',
              'containerId' =>  'constituent_votes',
              'options' => array( 
                'forceIFrame' => FALSE, 
                'title' => '',
                'width' => 500,
                'height' => 250,
                'pieHole'=> 0.6,
                'pieSliceText'=> 'none',
                'colors'=> array('#1f798f', '#04a9c5'),
              'legend'=> array(
                  'position'=>'none'
                ),
              )   
            );
          //Draw it.
          $ret2 = draw_chart($settings2); 
        ?>
      </div>
    </div>
  </div>

  