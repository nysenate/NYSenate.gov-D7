
About
=====

Semantic Views allows you to alter the default HTML output by the Views module without overriding template files. This means, for example, you can change a field from being wrapped by a `<span>` tag to being wrapped in a `<h2>` tag.

The module provides a Views 2 style and row style plugin. These plugins ideally work together but can be used separately.

When properly configured, the Semantic Views style plugin can effectively replace Views' own unformatted, HTML List and Grid styles. The row style plugin can let help leverage your theme's other CSS styles more easily.

Install
=======

Unzip the file into your `sites/all/modules` folder. Visit `admin/modules` and locate the module under *Other*. Tick the box, and 'Save' changes at the bottom of the page to enable it.

For more help installing modules, see <http://drupal.org/node/70151>.

Terminology
===========

* *Output style* -- Views output styles are the wrapper around row output. Grouping, row striping, and enumeration are managed by the output style plugin.
* *Row style* -- Views row styles are the wrappers around individual field output. All of the fields for a result constitute a single row. Typically, this has been the most difficult output to theme.

Example
=======

Semantic Views does not relieve site builders of the burden of theming their views, but it does allow them to create a hierarchical cascade of tags and to select CSS styles that have not been tailored for Views field row style output.

A proper demonstration of the capabilities of this module is to compare the output of a single row in the original row style and the Semantic Views row style.

Original Views field row style output
-------------------------------------
    <div class="views-row views-row-1 views-row-odd views-row-first">
      <div class="views-field-title">
        <span class="field-content">
          <a href="/node/1" title="Augue Magna Cui Conventio Valetudo" alt="Augue Magna Cui Conventio Valetudo">
            Augue Magna Cui Conventio Valetudo</a>
        </span>
      </div>
      <div class="views-field-type">
        <span class="field-content">
          Story
        </span>
      </div>
      <div class="views-field-teaser">
        <div class="field-content">
          <p>
            node (story) - Abigo bene feugiat loquor neo lenis qui imputo. Suscipere molior obruo typicus jus euismod ille illum meus. Acsi populus pecus populus lobortis metuo voco. Aptent plaga incassum. Iriure cui cui commoveo eum hos dolor ex consectetuer. Typicus eros vulputate defui comis nobis humo. Ulciscor abigo occuro. Sagaciter tego dolore. Voco iusto jus. Abdo dolor verto gilvus mos iaceo vel loquor.
          </p>
        </div>
      </div>
      <div class="views-field-delete-node">
        <label class="views-label-delete-node">
          Delete link:
        </label>
        <span class="field-content">
          <a href="/node/1/delete&amp;destination=demo%2Fviews">
            delete</a>
        </span>
      </div>
      <div class="views-field-edit-node">
        <label class="views-label-edit-node">
          Edit link:
        </label>
        <span class="field-content">
          <a href="/node/1/edit&amp;destination=demo%2Fviews">
            edit</a>
        </span>
      </div>
    </div>

Semantic Views field row style output
-------------------------------------
    <div class="row row-0 first odd">
      <h2 class="title">
        <a href="/node/1" title="Augue Magna Cui Conventio Valetudo" alt="Augue Magna Cui Conventio Valetudo">
          Augue Magna Cui Conventio Valetudo
        </a>
      </h2>
      <div class="node-type">
        Story
      </div>
      <p>
        node (story) - Abigo bene feugiat loquor neo lenis qui imputo. Suscipere molior obruo typicus jus euismod ille illum meus. Acsi populus pecus populus lobortis metuo voco. Aptent plaga incassum. Iriure cui cui commoveo eum hos dolor ex consectetuer. Typicus eros vulputate defui comis nobis humo. Ulciscor abigo occuro. Sagaciter tego dolore. Voco iusto jus. Abdo dolor verto gilvus mos iaceo vel loquor.
      </p>
      <label>
        Delete link:
      </label>
      <a href="/node/1/delete&amp;destination=demo%2Fsemantic">
        delete
      </a>
      <label>
        Edit link:
      </label>
      <a href="/node/1/edit&amp;destination=demo%2Fsemantic">
        edit
      </a>
    </div>

Requirements
============

* Drupal 6
* Views 2

Suggestions
----------

* Advanced Help

Usage
=====

After enabling the module, create a new view or edit an existing one that outputs fields not nodes. This module works for any Views base table (e.g., nodes, users, terms) and any display plugin (e.g., page, block, attachment). Select "Semantic Views" for the style and "Semantic Views : Fields" for the row style.

It is possible to use the two plugins separately. The *row style* plugin lets you change the HTML markup that wraps around the field content. The *style* plugin lets you change the HTML markup that wraps around each row.

Output style options
--------------------
![Output style options form](<path:output-style-options.png>)

All of these options are **optional**. When an option allows a HTML element and a class attribute, omitting the HTML element will cause the class attribute to be ignored and that content will be output without any HTML wrapping it.

**Note** Always input HTML elements without the `<` and `>`. Your valid input will be inserted between the angle brackets in the template.

**Note** Any class attributes you input will be concatenated and rendered as the class attribute's value in the template. For example, your valid input `row node blog` as the class attribute for a `div` element will be rendered as `<div class="row node blog">`.

### Grouping title

For Views where the results are grouped, the HTML **element** and **class attribute** can be specified for the element that wraps the title.

### List

With this option, Semantic Views can behave like the Views 2 **HTML List** display plugin. HTML unordered, ordered and definition lists can be created in the by choosing a list type. It's important to remember that HTML lists have additional constraints on their child elements. `<ul>` and `<ol>` must have `<li>` children and `<dl>` must have `<dt>` and `<dd>` children.

### Row

Rows are the results of the executed view. The number of rows in a view display is determined by the pager (or if the number of results is less than the pager limit, the number of results).

#### HTML element

The HTML element for the row is usually `<div>`.

#### Class attribute

This is the basic class attribute for each row. If it includes a # the row number will be substituted. Multiple class attributes can be specified: `row` or `row row-#`.

#### First and last classes

By default, Views row style adds a `first` class attribute to the first result in the pager and a `last` class attribute to the last result in the pager.

##### First/Last every n<sup>th</sup>

When this is set to `0`, the *first* and *last* class attributes are added first and last results in the pager. If you specify a number greater than 1, *first* and *last* class attributes are added at that interval within the pager result set. This can be used to improve upon the **Grid** display plugin that comes with Views 2.

For example, if you have a grid layout with 5 column units with a gutter maintained by right margins on all units except the last one, setting this option to `5` will add a `last` class to every 5th result row (not to be confused with rows in your grid layout). `first` class attributes are added to the first result row in the pager and to each result that follows a `last` result.

If the following two options are left empty, the `first/last every nth` option has no effect.

##### FIRST class attribute

This is the actual class attribute that is inserted. It is optional and defaults to `first`.

##### LAST class attribute

This is the actual class attribute that is inserted. It is optional and defaults to `last`.

#### Striping class attributes

When this is set, every row will have *one* of the class attributes specified here. The default is `odd even` so that *n* row has a class attribute of `odd` and *n + 1* row has a class attribute of `even`. You are not limited to only two striping class attributes. It's perfectly valid to use `north south east west` to stripe your rows 4 different ways or to leave this option empty to disable striping.

Row style options
-----------------
![Row style options form](<path:row-style-options.png>)

For each field in your view, you can specify the HTML element and class attribute. These are both **optional**. Omitting the HTML element will cause the class attribute to be ignored and that content will be output without any HTML wrapping it. For example, you may want to omit the HTML element from the wrapper on a node teaser or user picture because these may already have adequate markup.

* HTML element
* Class attribute

**Important!** There is no good way for Semantic Views to provide a default value for these options when new fields are added to your view. If you do not update the options for the row style, your field output will have no HTML element around it. The `div` that appears when you view the settings form for the row style is only saved when you actually click the `Update` button on the settings form.

Author and credit
=================

Developer:
Benjamin Doherty "bangpound" <http://drupal.org/user/16496>

Documentation and Advanced Help:
Heather James "heather" <http://drupal.org/user/740>
