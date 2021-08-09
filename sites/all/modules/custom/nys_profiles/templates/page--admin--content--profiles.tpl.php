<?php
/**
 * @file
 * Manage Honoree Profiles template.
 */
?>





<div id="page">

    <div id="content" class="clearfix">
        <div class="element-invisible"><a id="main-content"></a></div>

        <div id="content-wrapper">

            <div id="main-content">

                <h2><strong>Manage Honoree Profiles Overview</strong></h2>
                <p>You can click on the tabs above to manage the honorees the for Veterans and Women of Distinction programs.</p>
                <p>From those pages you can:
                <ul>
                    <li>Search for honorees by name, senator, or year.</li>
                    <li>Edit honoree information for any senator.</li>
                    <li>Send custom emails to Senate office contacts individually or in bulk.</li>
                    <li>Manage all the details for the ceremony.</li>
                </ul>
                </p>

                <?php
                    $block = block_load('block',8);
                    $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                    $output = drupal_render($render_array);
                    print $output;
                ?>

            </div>


        </div>


    </div>

</div>
