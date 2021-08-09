
/**
 *  @file
 *  Create the 'Livestream' tab for the WYSIWYG plugins.
 */

(function ($) {
  namespace('media.browser.plugin');

  Drupal.media.browser.plugin.livestream_library = function(mediaBrowser, options) {

    return {
      mediaFiles: [],
      init: function() {
        tabset = mediaBrowser.getTabset();
        tabset.tabs('add', '#livestream_library', 'Livestream');
        var that = this;
        mediaBrowser.listen('tabs.show', function (e, id) {
          if (id == 'livestream_library') {
            // This is kinda rough, I'm not sure who should delegate what here.
            mediaBrowser.getActivePanel().addClass('throbber');
            mediaBrowser.getActivePanel().html('');
            //mediaBrowser.getActivePanel().addClass('throbber');

            // Assumes we have to refresh everytime.
            // Remove any existing content
            mediaBrowser.getActivePanel().append('<ul></ul>');
            that.browser = $('ul', mediaBrowser.getActivePanel());
            that.browser.addClass('clearfix');
            that.getMedia();
          }
        });
      },

      getStreams: function () {
        return ['livestream://'];
      },

      getConditions: function () {
        return {};
        //return this.settings.conditions;
      },

      getMedia: function() {
        var that = this;
        var callback = mediaBrowser.getCallbackUrl('getMedia');
        var params = {
          conditions: JSON.stringify(this.getConditions()),
          streams: JSON.stringify(this.getStreams())
        };
        jQuery.get(
          callback,
          params,
          function(data, status) {
            that.mediaFiles = data.media;
            that.emptyMessage = data.empty;
            that.pager = data.pager;
            that.render();
          },
          'json'
        );
      },

      render: function() {
        var that = this;
        mediaBrowser.getActivePanel().removeClass('throbber');
        if (this.mediaFiles.length < 1) {
          jQuery('<div id="media-empty-message" class="media-empty-message"></div>').appendTo(this.browser)
            .html(this.emptyMessage);
          return;
        }

        for (var m in this.mediaFiles) {
          mediaFile = this.mediaFiles[m];

          var listItem = jQuery('<li></li>').appendTo(this.browser)
            .attr('id', 'media-file-' + mediaFile.fid)
            .addClass('media-file');

          var imgLink = jQuery('<a href="#"></a>').appendTo(listItem)
            .html(mediaFile.preview)
            .bind('click', mediaFile, function(e) {
              // Notify the main browser
              //this.selectedMedia = mediaFile;
              $('div.media-thumbnail img').removeClass('selected');
              $('div.media-thumbnail img', $(this)).addClass('selected');
              mediaBrowser.notify('mediaSelected', {mediaFiles: [e.data]});
              //that.settings.onSelect(mediaFile);
              return false;
            });
        }
        jQuery('<div id="media-pager" class="media-pager"></div>').appendTo(this.browser)
          .html(this.pager);
      }
  };
};

  Drupal.media.browser.register('livestream_library', Drupal.media.browser.plugin.livestream_library);
})(jQuery);
