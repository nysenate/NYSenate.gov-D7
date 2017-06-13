/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/**
 * @file Plugin for inserting images from Drupal media module
 *
 * @TODO Remove all the legecy media wrapper once it's sure nobody uses that
 * anymore.
 */
( function() {
  var mediaPluginDefinition = {
    icons: 'media',
    requires: ['button'],
    // All the default distributions of the editor have the widget plugin
    // disabled by default.
    hasWidgetSupport: false,
    mediaLegacyWrappers: false,
    hidpi: true,
    onLoad: function() {
      // Check if this instance has widget support.
      mediaPluginDefinition.hasWidgetSupport = typeof(CKEDITOR.plugins.registered.widget) != 'undefined';
      // Add dependency to widget plugin if possible.
      if (parseFloat(CKEDITOR.version) >= 4.3 && mediaPluginDefinition.hasWidgetSupport) {
        mediaPluginDefinition.requires.push('widget');
      }
    },

    // Wrap Drupal plugin in a proxy plugin.
    init: function(editor){
      editor.addCommand( 'media',
      {
        exec: function (editor) {
          var data = {
            format: 'html',
            node: null,
            content: ''
          };
          var selection = editor.getSelection();
          if (selection) {
            data.node = selection.getSelectedElement();

            if (data.node) {
              data.node = data.node.$;
            }
            if (selection.getType() == CKEDITOR.SELECTION_TEXT) {
              if (CKEDITOR.env.ie && CKEDITOR.env.version < 10) {
                data.content = selection.getNative().createRange().text;
              }
              else {
                data.content = selection.getNative().toString();
              }
            }
            else if (data.node) {
              // content is supposed to contain the "outerHTML".
              data.content = data.node.parentNode.innerHTML;
            }
          }

          // If we are inside another media element, we need to move the cursor to the end of the element
          var selected_element = selection.getStartElement();
          var parent = selected_element.getParent();
          //if we are inside "a" tag and inside "span" (with class media-element)
          if (selected_element.is('a') && parent.is('span') && parent.hasClass('media-element')) {
            selection.selectElement(parent);
            selected_ranges = selection.getRanges();
            selected_ranges[0].collapse(false);
            selection.selectRanges(selected_ranges);
          }
          //if we are outside "a" tag but inside "span" (with class media-element)
          else if (selected_element.is('span') && selected_element.hasClass('media-element')) {
              selection.selectElement(selected_element);
              selected_ranges = selection.getRanges();
              selected_ranges[0].collapse(false);
              selection.selectRanges(selected_ranges);
          }
          Drupal.settings.ckeditor.plugins['media'].invoke(data, Drupal.settings.ckeditor.plugins['media'], editor.name);
        }
      });

      // Add a Ckeditor context menu item for editing already-inserted media.
      if (editor.contextMenu) {
        editor.addCommand('mediaConfigure', {
          exec: function (editor) {
            editor.execCommand('media');
          },
        });

        editor.addMenuGroup('mediaGroup');
        editor.addMenuItem('mediaConfigureItem', {
          label: Drupal.t('Media settings'),
          icon: this.path + 'images/icon.gif',
          command: 'mediaConfigure',
          group: 'mediaGroup'
        });

        editor.contextMenu.addListener(function(element) {
          if (element.getAttribute('data-media-element') ||
              element.find('[data-media-element]').count()) {
            return { mediaConfigureItem: CKEDITOR.TRISTATE_OFF };
          };
        });
      }

      // Add the toolbar button.
      editor.ui.addButton( 'Media',
      {
        label: 'Add media',
        command: 'media'
      });

      var ckeditorversion = parseFloat(CKEDITOR.version);

      // Because the media comment wrapper don't work well for CKEditor we
      // replace them by using a custom mediawrapper element.
      // Instead having
      // <!--MEDIA-WRAPPER-START-1--><img /><!--MEDIA-WRAPPER-END-1-->
      // We wrap the placeholder with
      // <mediawrapper data="1"><img /></mediawrapper>
      // That way we can deal better with selections - see selectionChange.
      CKEDITOR.dtd['mediawrapper'] = CKEDITOR.dtd;
      CKEDITOR.dtd.$blockLimit['mediawrapper'] = 1;
      CKEDITOR.dtd.$inline['mediawrapper'] = 1;
      CKEDITOR.dtd.$nonEditable['mediawrapper'] = 1;
      if (ckeditorversion >= 4.1) {
        // Register allowed tag for advanced filtering.
        editor.filter.allow( 'mediawrapper[!data]', 'mediawrapper', true);
        // Don't remove the data-file_info attribute added by media!
        editor.filter.allow( '*[!data-file_info]', 'mediawrapper', true);
        // Ensure image tags accept all kinds of attributes.
        editor.filter.allow( 'img[*]{*}(*)', 'mediawrapper', true);
        // Objects should be selected as a whole in the editor.
        CKEDITOR.dtd.$object['mediawrapper'] = 1;
      }
      function prepareDataForWysiwygMode(data) {
        if (typeof Drupal.media !== 'undefined') {
          data = Drupal.media.filter.replaceTokenWithPlaceholder(data);
        }
        // Legacy media wrapper.
        mediaPluginDefinition.mediaLegacyWrappers = (data.indexOf("<!--MEDIA-WRAPPER-START-") !== -1);
        if (mediaPluginDefinition.mediaLegacyWrappers) {
          data = data.replace(/<!--MEDIA-WRAPPER-START-(\d+)-->(.*?)<!--MEDIA-WRAPPER-END-\d+-->/gi, '<mediawrapper data="$1">$2</mediawrapper>');
        }
        return data;
      }
      function prepareDataForSourceMode(data) {
        var replacement = '$2';
        // Legacy wrapper
        if (mediaPluginDefinition.mediaLegacyWrappers) {
          replacement = '<!--MEDIA-WRAPPER-START-$1-->$2<!--MEDIA-WRAPPER-END-$1-->';
        }
        data = data.replace(/<mediawrapper data="(.*?)">(.*?)<\/mediawrapper>/gi, replacement);
        if (typeof Drupal.media !== 'undefined') {
          data = Drupal.media.filter.replacePlaceholderWithToken(data);
        }
        return data;
      }

      // Ensure the tokens are replaced by placeholders while editing.
      // Check for widget support.
      if (mediaPluginDefinition.hasWidgetSupport) {
        editor.widgets.add( 'mediabox',
        {
          button: 'Create a mediabox',
          editables: {},
          allowedContent: '*',
          upcast: function( element ) {
            // Ensure media tokens are converted to media placeholders.
            html = Drupal.media.filter.replaceTokenWithPlaceholder(element.getHtml());
            // Only replace html if it's different
            if (html != element.getHtml()) {
              element.setHtml(html);
              // CKEditor's setHtml() method automatically fixes the HTML that
              // it receives, which means that if it gets an <li> without a
              // <ul> or <ol> parent, it adds a <ul>. These extra <ul> tags just
              // keep piling up every time this function runs. So check here to
              // see if we may need to fix this.
              if (element.children && element.children[0]) {
                // We identify this by looking for a <ul> inside a <ul> or <ol>.
                if (('ul' === element.name && 'ul' === element.children[0].name) ||
                    ('ol' === element.name && 'ul' === element.children[0].name)) {
                  // If this did happen, fix it by promoting the grandchildren
                  // (ie, actual list items) to children.
                  element.children = element.children[0].children;
                }
              }
            }
            return element.name == 'mediawrapper' || 'data-media-element' in element.attributes;
          },

          downcast: function( widgetElement ) {
            var token = Drupal.media.filter.replacePlaceholderWithToken(widgetElement.getOuterHtml());
            if (token) {
              return new CKEDITOR.htmlParser.text(token);
            }
            return false;
          },

          init: function() {
            // Add double-click functionality to the widget.
            this.on('doubleclick', function(evt) {
              editor.execCommand('media');
            }, null, null, 5 );
          }
        });
      }
      else if (ckeditorversion >= 4) {
        // CKEditor >=4.0
        editor.on('setData', function( event ) {
          event.data.dataValue = prepareDataForWysiwygMode(event.data.dataValue);
        });
      }
      else {
        // CKEditor >=3.6 behaviour.
        editor.on( 'beforeSetMode', function( event, data ) {
          event.removeListener();
          var wysiwyg = editor._.modes[ 'wysiwyg' ];
          var source = editor._.modes[ 'source' ];
          wysiwyg.loadData = CKEDITOR.tools.override( wysiwyg.loadData, function( org )
          {
            return function( data ) {
              return ( org.call( this, prepareDataForWysiwygMode(data)) );
            };
          } );
          source.loadData = CKEDITOR.tools.override( source.loadData, function( org )
          {
            return function( data ) {
              return ( org.call( this, prepareDataForSourceMode(data) ) );
            };
          } );
        });
      }

      // Provide alternative to the widget functionality introduced in 4.3.
      if (!mediaPluginDefinition.hasWidgetSupport) {
        // Ensure tokens instead the html element is saved.
        editor.on('getData', function( event ) {
          event.data.dataValue = prepareDataForSourceMode(event.data.dataValue);
        });

        // Ensure our enclosing wrappers are always included in the selection.
        editor.on('selectionChange', function( event ) {
          var ranges = editor.getSelection().getRanges().createIterator();
          var newRanges = [];
          var currRange;
          while(currRange = ranges.getNextRange()) {
            var commonAncestor = currRange.getCommonAncestor(false);
            if (commonAncestor && typeof(commonAncestor.getName) != 'undefined' && commonAncestor.getName() == 'mediawrapper') {
              var range = new CKEDITOR.dom.range( editor.document );
              if (currRange.collapsed === true) {
                // Don't allow selection within the wrapper element.
                if (currRange.startOffset == 0) {
                  // While v3 plays nice with setting start and end to avoid
                  // editing within the media wrapper element, v4 ignores that.
                  // Thus we try to move the cursor further away.
                  if (parseInt(CKEDITOR.version) > 3) {
                    range.setStart(commonAncestor.getPrevious());
                    range.setEnd(commonAncestor.getPrevious());
                  }
                  else {
                    range.setStartBefore(commonAncestor);
                  }
                }
                else {
                  // While v3 plays nice with setting start and end to avoid
                  // editing within the media wrapper element, v4 ignores that.
                  // Thus we try to move the cursor further away.
                  if (parseInt(CKEDITOR.version) > 3) {
                    range.setStart(commonAncestor.getNext(), 1);
                    range.setEnd(commonAncestor.getNext(), 1);
                  }
                  else {
                    range.setStartAfter(commonAncestor);
                  }
                }
              }
              else {
                // Always select the whole wrapper element.
                range.setStartBefore(commonAncestor);
                range.setEndAfter(commonAncestor);
              }
              newRanges.push(range);
            }
          }
          if (newRanges.length) {
            editor.getSelection().selectRanges(newRanges);
          }
        });
      }
    }
  };

  CKEDITOR.plugins.add( 'media', mediaPluginDefinition);
} )();
