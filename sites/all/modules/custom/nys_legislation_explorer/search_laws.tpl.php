<?php
/**
 * @file
 * Law search template for legislation search.
 *
 * @var array $search
 *   Array of $_GET search variables.
 */
?>
<?php if ($view == 'listing' || (isset($law_doc) && $law_doc->docType == 'CHAPTER')): ?>
  <hr/>
  <!-- Search panel -->
  <div class="c-law--search-container">
    <?php if (isset($law_doc)): ?>
      <p class="c-law--action-heading sm-heading">Search within <?php echo $law_doc->lawName ?></p>
    <?php else: ?>
      <p class="c-law--action-heading">Search</p>
    <?php endif; ?>
    <form id="law-search-form" action="">
      <div class="c-law-search-field">
        <input id="law-search" class="c-law-search-field-input" type="text" name="search_q" 
               data-law-id="<?php echo (isset($law_doc)) ? $law_doc->lawId : '' ?>"
               placeholder="Search by a term or phrase"/>
        <button class="c-site-search--btn c-law-search-field--icon-glass" id="edit-submit" name="op" 
                value="Search" type="submit">Search</button> 
      </div>
    </form>
  </div>
  <!-- Search results -->
  <img class="c-law--search-loader"
       src="<?php echo '/' . drupal_get_path('theme', 'nysenate') . '/images/ajax-loader.gif' ?>">
  <div id="law-global-search-results" class="c-law--search-results-container"></div>
<?php endif; ?>
<!-- Law listing view -->
<?php if ($view == 'listing'): ?>
  <!-- Law description block -->
  <p class="c-law-descript">
  </p>
  <!-- Law directory -->
  <div class="c-law--directory-container">
    <?php foreach ($law_listings as $type => &$laws): ?>
      <?php $law_type_str = ucwords(strtolower(str_replace("_", " ", $type))) ?>
      <h2 class="c-law--law-type">
        <a id="<?php echo $type?>" href="#<?php echo $type?>">
          <?php echo $law_type_str ?>
        </a>        
      </h2>
      <?php foreach ($laws as $k => &$v): ?>
        <a class="c-law-link" href="/legislation/laws/<?php echo $v->lawId ?>">
          <?php echo $v->name ?>
          <span>(<?php echo $v->lawId ?>)</span>  
        </a>
      <?php endforeach; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
<!-- Law Tree View -->
<?php if ($view == 'law-tree-view'): ?>
  <!-- Navigation breadcrumbs -->
  <nav class="breadcrumbs c-law-breadcrumbs">
    <a href="/legislation/laws/#<?php echo $law_info->lawType?>">
      <?php echo $law_info->lawType ?>
    </a>
    <?php if (isset($law_doc)): ?>
      <?php foreach ($law_doc->parents as $parent): ?>
        <a href="/legislation/laws/<?php echo "{$law_doc->lawId}/{$parent->locationId}" ?>/">
          <?php if ($parent->docType == 'CHAPTER'): ?>
            <?php echo $parent->lawName ?>
          <?php else: ?>
            <?php echo $parent->docType . ' ' . $parent->docLevelId ?>
          <?php endif; ?>
        </a>
      <?php endforeach; ?>
      <a class="c-law--inactive-breadcrumb">
        <?php if ($law_doc->docType == 'CHAPTER'): ?>
          <?php echo $law_doc->lawName ?>
        <?php else: ?>
          <?php echo $law_doc->docType . ' ' . $law_doc->docLevelId ?>
        <?php endif; ?>
      </a>
    <?php endif; ?>
  </nav>
  <div class="c-law-link-wrapper">
  <?php foreach ($law_tree->documents->documents->items as $k => &$v): ?>
    <div class="row c-law-link-container">
      <div class="columns medium-4">
        <h3 class="c-law-link-loc-id">
          <a href="/legislation/laws/<?php echo "{$v->lawId}/{$v->locationId}" ?>">
            <?php echo ucfirst(strtolower($v->docType)) . " " . $v->docLevelId ?>
          </a>
        </h3>
      </div>
      <div class="columns medium-8">
        <p class="c-law-link-title"><?php echo str_replace('\n', ' ', $v->title) ?></p>
        <p class="c-law-link-contained-sections">
          <?php echo (($v->docType != 'SECTION') ? "Sections (§{$v->fromSection} - §{$v->toSection})" : "") ?>
        </p>
      </div>
    </div>
  <?php endforeach; ?>
  </div>
  <?php if ($law_doc->docType == 'SECTION' || $law_tree->documents->documents->size == 0): ?>
    <div class="c-law-doc-text"><?php echo $law_doc->text ?></div>
  <?php endif; ?>
  <?php if ($law_doc->prevSibling || $law_doc->nextSibling): ?>
    <hr/>
    <div class="row c-law-sibling-links">
      <div class="medium-6 columns">
        <?php if ($law_doc->prevSibling): ?>
          <a class="icon-before__left" href="/legislation/laws/<?php echo "{$law_doc->lawId}/{$law_doc->prevSibling->locationId}" ?>/">
           <?php echo $law_doc->prevSibling->docType . ' ' . $law_doc->prevSibling->docLevelId . ' - ' . $law_doc->prevSibling->title ?>
          </a>
        <?php endif; ?>
      </div>
      <div class="medium-6 columns">
        <?php if ($law_doc->nextSibling): ?>
          <a class="right icon-after__right" href="/legislation/laws/<?php echo "{$law_doc->lawId}/{$law_doc->nextSibling->locationId}" ?>/">
           <?php echo $law_doc->nextSibling->docType . ' ' . $law_doc->nextSibling->docLevelId . ' - ' . $law_doc->nextSibling->title ?>
          </a>
        <?php endif; ?>
      </div>
    </div>
    <hr/>
  <?php endif; ?>
<?php endif; ?>
<br/>
<br/>
