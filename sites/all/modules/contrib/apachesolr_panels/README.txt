/* $Id: README.txt,v 1.1.2.2 2011/02/06 01:34:46 ximo Exp $ */

-- SUMMARY --

Create custom Apache Solr search pages with Panels. This module exposes the
search form, search results and information about the search as panes for use in
Panels, together with blocks from the Apache Solr module. This allows for more
flexible search pages and results.

For a full description of the module, visit the project page:
  http://drupal.org/project/apachesolr_panels

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/apachesolr_panels


-- REQUIREMENTS --

Apache Solr Search Integration
  http://drupal.org/project/apachesolr

CTools with Page Manager
  http://drupal.org/project/ctools

Panels 3.8 or higher
  http://drupal.org/project/panels


-- INSTALLATION --

* Install as usual, see this page for further information:
  http://drupal.org/getting-started/install-contrib/modules


-- USAGE --

For the advanced user:
1. Create a page using the Page manager with "!query" appended to its URL
2. Assign a String context to the "query" argument
3. Add Apache Solr Search panes to the Content of the page

You may use this exported search page to help you get started:
http://drupal.org/node/1052446

Here are more thorough step by step instructions:

1. Go to Site building › Pages › Add custom page

2. Give the page a URL ending in "!query" (e.g. "solr/!query")

3. Assign the "query" argument as a String, name it "Search query" and check the
   "Get all arguments after this one" checkbox

4. Complete the remaining steps to set up your page

5. Add search elements from the "Apache Solr Search" category of the
   "Add content" dialog (click the cogwheel of a region within the Content tab)

6. When adding "Apache Solr search results", set "Search query" as its context

7. Add any of the blocks provided by Apache Solr, such as "Current search",
   filters, sorts and "More like this" (all found under Miscellaneous)


Note: Don't use the default "search-apachesolr_search" page provided by Page
      manager. It will let you down.


-- CONTACT --

Current maintainers:
* Joakim Stai (ximo) - http://drupal.org/user/88701
* Adam Bramley (acbramley) - http://drupal.org/user/1036766

This project has been sponsored by:
* NodeOne
  The leading Drupal company in Sweden, NodeOne employs more than 40 drupalistas
  in Stockholm, Gothenburg and Copenhagen. Visit http://nodeone.se/in-english
  for more information.
