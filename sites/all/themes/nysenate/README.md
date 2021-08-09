---
THE NYSENATE THEME
------------------
---

This documentation is a set of instructions related to the NY Senate theme found within this
directory, which is based on Zurb Foundation.  For more information on Zurb Foundation,
please visit the Drupal community documentation located at http://drupal.org/node/1948260.


---
BUILDING THE CSS STYLESHEETS
------------------------
---
The NY Senate theme utilizes SCSS.  As such, any style changes that you plan to make
will have to be made within the SCSS structure, then compiled into normal CSS.

The theme's SCSS files are located in the `scss/` directory, just below the
directory in which this file is located.  The SCSS directory contains many
files, each compartmentalized to their specific area of the theme.  Node.js (
http://nodejs.org) and Grunt (http://gruntjs.com/) are used in place of a standard
Ruby/Compass setup for compiling the theme's SCSS.

It is imperative that this process be followed for compiling the theme's SCSS;
newer versions of Sass will **NOT** correctly compile the files.

**Installation**

- Install nvm
  - (Mac) https://github.com/creationix/nvm
  - (Windows) https://github.com/coreybutler/nvm-windows
- `$ nvm install v0.12.3`
- `$ cd nys_senate/sites/all/themes/nysenate`
- `$ npm install request@2.81`
- `$ npm install`

**NOTE:** On Windows, it may be helpful to run `npm install -g grunt-cli` to make grunt
available.  Alternatively, add the grunt-cli bin to the shell path. 

**Compiling The SCSS Sheets**
A Grunt task has been set up within the theme that will make processing your SCSS
very easy.  From the command line in the main NY Senate theme directory
([DOCROOT]/sites/all/themes/nysenate), type:

- `$ npm run grunt`

Grunt will then watch the SCSS directories for any file changes.  Upon a change,
the compile job will run, and rebuild the site's CSS.

*Note: Clearing the site's CSS/JavaScript cache is required to see your updated style
changes.  This can be done in one of two ways -- for those with Drush installed,
from a command line type:*

- `$ drush cc css-js`

*For those without Drush, navigate to any page within the site's admin, and use
the options for clearing the cache under the site admin's "Home" menu (a icon).*

---
EDITING THE STYLESHEETS
------------------------
---
**Naming Classes**

CSS classes within the NY Senate theme have been standardized for consistency
using the following naming conventions:

 - prefix-ComponentName
 - prefix-ComponentName__MODIFIERNAME
 - prefix-ComponentName--subObject
 - prefix-ComponentName--subObject__MODIFIERNAME

**Prefix Definitions**

Many CSS classes use terms/definitions that are specific to placement or
functionality within the theme:

 - ***nys-***: a global element. something that is used site wide.
 - ***c-***: For components (e.g.: c-Dropdown, c-Button…).
 - ***l-***: Layout, columning, wrappers and containers… (e.g.: l-Masthead, l-Footer)
 - ***u-***: Utility classes — will probably never change, should never be overridden anywhere else in our code (e.g.: u-textCenter, u-clearfix…).
 - ***js-***: Hooks for JavaScript: should never appear in the CSS itself.

**Examples**

 - ***nys-senator*** : a wrapper that contains senator thumbnail image and info about senator
 - ***nys-senator--thumb*** : the circular thumbnail of a senator

 - ***c-senator-about--hero***: A wrapper for the About the Senator section of a page
 - ***c-senator-about--hero__collapsed***: The same wrapper with a modifier applied

 - ***l-row***: A row controlling overall width

