README for Disqus for Drupal 7

Disqus 7.x-1.x
=================================

Disqus Official PHP API Support
=================================

INSTALL
=============
You will need to install the Libraries API module (7.x-2.x branch).

https://drupal.org/project/libraries

The Disqus Official PHP API can be downloaded at:

https://github.com/disqus/disqus-php

Copy the contents of the disqusapi folder to sites/all/libraries/disqusapi.
You will need to obtain your user access key from the application specific
page found here:

http://disqus.com/api/applications/

BUILT-IN FEATURES
=============
This module can automatically update and/or delete your Disqus threads when you
delete/update your nodes. 

Visit Disqus configuration page after you installed Disqus API to configure it's
behaviour. 

EXAMPLES
=============
You can find the API reference here:

http://disqus.com/api/docs/

Any of these methods can be called by creating an instance of the Disqus API
through disqus_api(). You must use try/catch to avoid php throwing a general
exception and stopping script execution.

For a full explanation of the official API you can view the readme located here:

https://github.com/disqus/disqus-php/blob/master/README.rst

Example: Calling threads/details and threads/update

  $disqus = disqus_api();
  if ($disqus) {
    try {
      // Load the thread data from disqus. Passing thread is required to allow the thread:ident call to work correctly. There is a pull request to fix this issue.
      $thread = $disqus->threads->details(array('forum' => $node->disqus['domain'], 'thread:ident' => $node->disqus['identifier'], 'thread' => '1', 'version' => '3.0'));
    }
    catch (Exception $exception) {
      drupal_set_message(t('There was an error loading the thread details from Disqus.'), 'error');
      watchdog('disqus', 'Error loading thread details for node @nid. Check your API keys.', array('@nid' => $node->nid), WATCHDOG_ERROR, 'admin/config/services/disqus');
    }
    if (isset($thread->id)) {
      try {
        $disqus->threads->update(array('access_token' => variable_get('disqus_useraccesstoken', ''), 'thread' => $thread->id, 'forum' => $node->disqus['domain'], 'title' => $node->disqus['title'], 'url' => $node->disqus['url'], 'version' => '3.0'));
      }
      catch (Exception $exception) {
        drupal_set_message(t('There was an error updating the thread details on Disqus.'), 'error');
        watchdog('disqus', 'Error updating thread details for node @nid. Check your user access token.', array('@nid' => $node->nid), WATCHDOG_ERROR, 'admin/config/services/disqus');
      }
    }
  }

