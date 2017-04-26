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

*Requirements:*
 - Node.js v0.12.3

**NOTE:** THIS VERSION IS SPECIFICALLY REQUIRED -- OTHER VERSIONS OF Node.js
WILL NOT HANDLE DEPENDENCIES CORRECTLY

 - Mac Universal Installer: https://nodejs.org/dist/v0.12.3/node-v0.12.3.pkg
 - Windows (x86) Installer: https://nodejs.org/dist/v0.12.3/node-v0.12.3-x86.msi
 - Windows (x64) Installer: https://nodejs.org/dist/v0.12.3/x64/node-v0.12.3-x64.msi

If you already have a different version of Node.js installed, you will need to use the Node
Version Manager (nvm) on Mac (https://github.com/creationix/nvm/blob/master/README.markdown)
or nvm-windows on Windows (https://github.com/coreybutler/nvm-windows) to download,
install, and use the proper version.  See the documentation of the respective packages
for details.

Once you have set up your environment for Node.js, navigate to the theme directory
(the same location as this file) and type:

    npm install

A `packages.json` file is included in the theme's root directory, which will
define the dependencies required for Node.js.  This command will install the required
dependencies to compile the SCSS into a subdirectory called `node_modules`,
which by default, has already been added to the `.gitignore` file.  The dependencies
are NOT included with the theme code, and must be installed by the end-developer.

**NOTE:** On Windows, it may be helpful to run `npm install -g grunt-cli` to make grunt
available.  Alternatively, add the grunt-cli bin to the shell path. 

**Compiling The SCSS Sheets**
A Grunt task has been set up within the theme that will make processing your SCSS
very easy.  From the command line in the main NY Senate theme directory
([DOCROOT]/sites/all/themes/nysenate), type:

	grunt

Grunt will then watch the SCSS directories for any file changes.  Upon a change,
the compile job will run, and rebuild the site's CSS.

*Note: Clearing the site's CSS/JavaScript cache is required to see your updated style
changes.  This can be done in one of two ways -- for those with Drush installed,
from a command line type:*

	drush cc css-js

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

