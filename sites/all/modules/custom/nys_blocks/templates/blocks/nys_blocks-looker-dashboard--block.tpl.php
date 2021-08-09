<?php $ent_type = entity_type_load('looker_plans');
$bundles = Bundle::loadByEntityType($ent_type); ?>

<h2 class="c-container--title">Constituent Analytics in your Email</h2>
<p class="c-block--p-small">Manage office recipients for daily and weekly constituent analytics reporting:</p>

<?php foreach ($bundles as $val) {
$label = l($val->label, url(nys_looker_integration_manage_path() . "/{$val->name}", ['absolute' => TRUE])); ?>

    <?php echo $label . "<br>";
} ?>
