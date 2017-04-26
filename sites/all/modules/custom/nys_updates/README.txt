
-- SUMMARY --

This module can be used for configuration changes, such as 
enabling modules, disabling modules, using variable_set, or running sql queries.

As a team development process, we should run "drush updb -y" after pulling latest changes from git, this 
will run the latest update hook in this modules .install file.

Please do the following after pulling latest development environment:

  drush fra -y && drush updb -y && drush cc all

You can add the following to your bash profile and restart bash:

alias drushit='drush fra -y && drush updb -y && drush cc all'

Then you can revert features, run updates and clear cache with one command on the command line:

drushit

We should do this after pulling code.  Especially if we see changes to this module or 
to features modules.
