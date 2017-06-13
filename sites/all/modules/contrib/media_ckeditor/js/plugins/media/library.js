
/**
 *  @file
 *  Attach Media ckeditor behaviors.
 */

(function ($) {
  Drupal.media = Drupal.media || {};

  /**
   * Attaches 'insert' button to media widget.
   */
  Drupal.behaviors.mediaWidgetInsert = {
    attach: function (context, settings) {
      if (Drupal.ckeditorInstance && Drupal.settings.media_ckeditor && Drupal.settings.media_ckeditor.wysiwyg_insert) {
        // Only add buttons on fields that have been configured so, by
        // consulting the Drupal.settings.media_ckeditor.wysiwyg_insert var.
        for (var fieldName in Drupal.settings.media_ckeditor.wysiwyg_insert) {
          var fieldId = '#edit-' + fieldName.replace(/_/g, '-');
          // Within the field markup, look for the table of files.
          $(fieldId, context).find('.media-widget').once('mediaInsertButton', function() {
            // For each file, check to see if there is a file ID.
            if ($(this).find('input.fid').val() != 0) {
              // Now we add the button next to "Remove".
              var insertButton = $('<a class="media-insert button">' + Drupal.t('Insert') + '</a>')
                .click(function(e) {
                  e.preventDefault();
                  var fid = $(this).parent().parent().find('.fid').val();
                  var mediaFile = {fid: fid}
                  Drupal.ckeditorInstance.mediaInsert = {mediaFiles: [mediaFile]};
                  Drupal.ckeditorInstance.execCommand('media');
                });
              // Insert the button, differently for single vs. multi value.
              var multiValue = $(fieldId + ' table', context).length;
              if (multiValue) {
                insertButton.insertBefore($(this).parent().parent().find('input.remove'));
              }
              else {
                insertButton.insertBefore($(this).find('input.remove'));
              }
            }
          });
        }
      }
    }
  };

  Drupal.settings.ckeditor.plugins['media'] = {
    /**
     * Execute the button.
     */
    invoke: function (data, settings, instanceId) {
      if (data.format == 'html') {
        // CKEDITOR module support doesn't set this setting
        if (typeof settings['global'] === 'undefined') {
          settings['global'] = {id: 'media_wysiwyg'};
        }
        // If the selection is (or contains) an element with the attribute of
        // "data-media-element", assume the user wants to edit that thing.
        var $alreadyInsertedMedia;
        if (jQuery(data.node).is('[data-media-element]')) {
          $alreadyInsertedMedia = jQuery(data.node);
        }
        else {
          $alreadyInsertedMedia = jQuery(data.node).find('[data-media-element]');
        }
        // First check to see if we are using an Insert button.
        if (typeof Drupal.ckeditorInstance.mediaInsert !== 'undefined') {
          var mediaFile = Drupal.ckeditorInstance.mediaInsert.mediaFiles[0];
          delete Drupal.ckeditorInstance.mediaInsert;
          Drupal.media.popups.mediaStyleSelector(mediaFile, function (mediaFiles) {
            Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, mediaFiles, CKEDITOR.instances[instanceId]);
          }, settings['global']);
        }
        // Next check to see if we are editing already-inserted media.
        else if ($alreadyInsertedMedia.length) {
          var mediaFile = Drupal.media.filter.extract_file_info($alreadyInsertedMedia);
          Drupal.media.popups.mediaStyleSelector(mediaFile, function (mediaFiles) {
            Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, mediaFiles, CKEDITOR.instances[instanceId]);
          }, settings['global']);
        }
        // Otherwise we are embedding new media.
        else {
          Drupal.media.popups.mediaBrowser(function (mediaFiles) {
            Drupal.settings.ckeditor.plugins['media'].mediaBrowserOnSelect(mediaFiles, instanceId);
          }, settings['global']);
        }
      }
    },

    /**
     * Respond to the mediaBrowser's onSelect event.
     */
    mediaBrowserOnSelect: function (mediaFiles, instanceId) {
      var mediaFile = mediaFiles[0];
      var options = {};
      Drupal.media.popups.mediaStyleSelector(mediaFile, function (formattedMedia) {
        Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, formattedMedia, CKEDITOR.instances[instanceId]);
      }, options);

      return;
    },

    insertMediaFile: function (mediaFile, formattedMedia, ckeditorInstance, fullyRenderedFile) {

      // See if we should use ajax to get the fully rendered file.
      if (typeof fullyRenderedFile === 'undefined' &&
          Drupal.settings.media_ckeditor.fully_rendered_files) {

        $.ajax({
          url: Drupal.settings.basePath + 'media/rendered-in-wysiwyg',
          type: 'GET',
          data: {
            fid: mediaFile.fid,
            view_mode: formattedMedia.type,
            fields: formattedMedia.options
          },
          success: function(html) {
            // To work around an IE issue, preload any image. The issue is
            // that IE requests the image 2 times, and one request gets a 503,
            // causing a broken image icon in the WYSIWYG instead of the actual
            // image.
            var $images = $(html).find('img');
            if (!$images.length || $(html).find('picture').length) {
              // If there are no images, just insert the html immediately, by
              // re-calling this function with the ajax-retrieved HTML.
              Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, formattedMedia, ckeditorInstance, html);
            }
            else {
              // Otherwise do the same, but only after the first image preloads.
              // Possible future improvement might be to handle multiple images
              // instead of just the first, but even better would be to remove
              // this workaround entirely, when/if IE's behavior changes.
              var image = new Image();
              image.onload = function() {
                Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, formattedMedia, ckeditorInstance, html);
              }
              image.src = $images.first().attr('src');
            }
          },
          error: function(data) {
            // Fallback to whatever the HTML was already going to be.
            Drupal.settings.ckeditor.plugins['media'].insertMediaFile(mediaFile, formattedMedia, ckeditorInstance, formattedMedia.html);
          }
        });

        // Stop for now, because the callback above re-calls this same function.
        return;
      }

      // See if we already used ajax to get the fully rendered file.
      if (typeof fullyRenderedFile !== 'undefined') {
        formattedMedia.html = fullyRenderedFile;
      }

      // Customization of Drupal.media.filter.registerNewElement().
      var element = Drupal.media.filter.create_element(formattedMedia.html, {
        fid: mediaFile.fid,
        view_mode: formattedMedia.type,
        attributes: mediaFile.attributes,
        fields: formattedMedia.options
      });

      var hasWidgetSupport = typeof(CKEDITOR.plugins.registered.widget) != 'undefined';

      // Use own wrapper element to be able to properly deal with selections.
      // Check prepareDataForWysiwygMode() in plugin.js for details.
      var wysiwygHTML = Drupal.media.filter.getWysiwygHTML(element);

      if (wysiwygHTML.indexOf("<!--MEDIA-WRAPPER-START-") !== -1) {
        ckeditorInstance.plugins.media.mediaLegacyWrappers = true;
        wysiwygHTML = wysiwygHTML.replace(/<!--MEDIA-WRAPPER-START-(\d+)-->(.*?)<!--MEDIA-WRAPPER-END-\d+-->/gi, '');
      }

      // Insert element. Use CKEDITOR.dom.element.createFromHtml to ensure our
      // custom wrapper element is preserved.
      var editorElement = CKEDITOR.dom.element.createFromHtml(wysiwygHTML);
      ckeditorInstance.insertElement(editorElement);

      // Initialize widget on our html if possible.
      if (parseFloat(CKEDITOR.version) >= 4.3 && hasWidgetSupport) {
        ckeditorInstance.widgets.initOn( editorElement, 'mediabox' );

        // Also support the image2 plugin.
        ckeditorInstance.widgets.initOn( editorElement, 'image' );
      }
    },

    /**
     * Forces custom attributes into the class field of the specified image.
     *
     * Due to a bug in some versions of Firefox
     * (http://forums.mozillazine.org/viewtopic.php?f=9&t=1991855), the
     * custom attributes used to share information about the image are
     * being stripped as the image markup is set into the rich text
     * editor.  Here we encode these attributes into the class field so
     * the data survives.
     *
     * @param imgElement
     *   The image
     * @fid
     *   The file id.
     * @param view_mode
     *   The view mode.
     * @param additional
     *   Additional attributes to add to the image.
     */
    forceAttributesIntoClass: function (imgElement, fid, view_mode, additional) {
      var wysiwyg = imgElement.attr('wysiwyg');
      if (wysiwyg) {
        imgElement.addClass('attr__wysiwyg__' + wysiwyg);
      }
      var format = imgElement.attr('format');
      if (format) {
        imgElement.addClass('attr__format__' + format);
      }
      var typeOf = imgElement.attr('typeof');
      if (typeOf) {
        imgElement.addClass('attr__typeof__' + typeOf);
      }
      if (fid) {
        imgElement.addClass('img__fid__' + fid);
      }
      if (view_mode) {
        imgElement.addClass('img__view_mode__' + view_mode);
      }
      if (additional) {
        for (var name in additional) {
          if (additional.hasOwnProperty(name)) {
            switch (name) {
              case 'field_file_image_alt_text[und][0][value]':
                imgElement.attr('alt', additional[name]);
                break;
              case 'field_file_image_title_text[und][0][value]':
                imgElement.attr('title', additional[name]);
                break;
              default:
                imgElement.addClass('attr__' + name + '__' + additional[name]);
                break;
            }
          }
        }
      }
    },

    /**
     * Retrieves encoded attributes from the specified class string.
     *
     * @param classString
     *   A string containing the value of the class attribute.
     * @return
     *   An array containing the attribute names as keys, and an object
     *   with the name, value, and attribute type (either 'attr' or
     *   'img', depending on whether it is an image attribute or should
     *   be it the attributes section)
     */
    getAttributesFromClass: function (classString) {
      var actualClasses = [];
      var otherAttributes = [];
      var classes = classString.split(' ');
      var regexp = new RegExp('^(attr|img)__([^\S]*)__([^\S]*)$');
      for (var index = 0; index < classes.length; index++) {
        var matches = classes[index].match(regexp);
        if (matches && matches.length === 4) {
          otherAttributes[matches[2]] = {
            name: matches[2],
            value: matches[3],
            type: matches[1]
          };
        }
        else {
          actualClasses.push(classes[index]);
        }
      }
      if (actualClasses.length > 0) {
        otherAttributes['class'] = {
          name: 'class',
          value: actualClasses.join(' '),
          type: 'attr'
        };
      }
      return otherAttributes;
    },

    sortAttributes: function (a, b) {
      var nameA = a.name.toLowerCase();
      var nameB = b.name.toLowerCase();
      if (nameA < nameB) {
        return -1;
      }
      if (nameA > nameB) {
        return 1;
      }
      return 0;
    }
  };

  // If media_ckeditor is configured to render items in the wysiwyg as full
  // rendered file entities, we need to completely hijack a function from
  // media_wysiwyg.filter.js.
  if (Drupal.settings.media_ckeditor.fully_rendered_files) {

    // Replaces function of the same name, from media_wysiwyg.filter.js.
    Drupal.media.filter.replacePlaceholderWithToken = function(content) {

      var $placeholder = $(content);
      if ($placeholder.hasClass('media-element')) {
        var macro = Drupal.media.filter.create_macro($placeholder);
        Drupal.media.filter.ensure_tagmap();
        Drupal.settings.tagmap[macro] = content;
        return macro;
      }
      return content;
    }
  }
})(jQuery);
