/**
 * @file Plugin to support responsive images with the Picture module and
 * the CKEditor module.
 */
( function(){
  CKEDITOR.plugins.add('picture_ckeditor',
  {
      init : function(editor)
      {

        // Used later to ensure the required features have been enabled in the
        // Advanced Content Filter.
        features = {
          'imageSize': { 'requiredContent': 'img[data-picture-mapping]' },
          'imageAlign': { 'requiredContent': 'img[data-picture-align]' }
        };

        // If we have image2, enable the more advanced functionality
        if (CKEDITOR.config.plugins.indexOf('image2') != -1) {
          // CKEditor's normal alignment will be removed below, we need to
          // provide replacement classes based on Picture data
          CKEDITOR.addCss('img[data-picture-align="right"] { float: right; }');
          CKEDITOR.addCss('img[data-picture-align="left"] { float: left; }');
          CKEDITOR.addCss('img[data-picture-align="center"] { display: block; margin-left: auto; margin-right: auto; }');
          CKEDITOR.addCss('span[data-cke-display-name="image"] { display: block; }');
        }

        // Else, we need check if regular image is installed
        else if (CKEDITOR.config.plugins.indexOf('image') != -1) {
          CKEDITOR.config.disableObjectResizing = true;
        }

        // When opening a dialog, a 'definition' is created for it. For
        // each editor instance the 'dialogDefinition' event is then
        // fired. We can use this event to make customizations to the
        // definition of existing dialogs.
        CKEDITOR.on('dialogDefinition', function(event) {
          // Take the dialog name.
          if ((event.editor != editor)) return;
          var dialogName = event.data.name;
          // The definition holds the structured data that is used to eventually
          // build the dialog and we can use it to customize just about anything.
          // In Drupal terms, it's sort of like CKEditor's version of a Forms API and
          // what we're doing here is a bit like a hook_form_alter.
          var dialogDefinition = event.data.definition;


          if (dialogName == 'image2') {
            var infoTab = dialogDefinition.getContents('info');
            // UpdatePreview is copied from ckeditor image plugin.
            var updatePreview = function(dialog) {
              // Don't load before onShow.
              if (!dialog.originalElement || !dialog.preview) {
                return 1;
              }

              // Read attributes and update imagePreview.
              dialog.commitContent(PREVIEW, dialog.preview);
              return 0;
            };
            // Add the select list for choosing the image width.
            infoTab.add({
              type: 'select',
              id: 'imageSize',
              label: Drupal.settings.picture.label,
              items: Drupal.settings.picture.mappings,
              'default': 'not_set',
              requiredContent: features.imageSize.requiredContent,
              setup: function(widget) {
                mapping = widget.parts.image.getAttribute('data-picture-mapping');
                this.setValue(mapping ? mapping : 'not_set');
              },
              // Create a custom data-picture-mapping attribute.
              commit: function(widget) {
                widget.parts.image.setAttribute('data-picture-mapping', this.getValue());
              },
              validate: function() {
                if (this.getValue() == 'not_set') {
                  var message = 'Please make a selection from ' + Drupal.settings.picture.label;
                  alert(message);
                  return false;
                } else {
                  return true;
                }
              }
            }
            );

            // Alignment's inline styling should be deprecated in favor of
            // picture's data attributes
            infoTab.remove('alignment');

            // Picture breaks captions
            infoTab.remove('hasCaption');

            // Add a select widget to choose image alignment.
            infoTab.add({
              type: 'select',
              id: 'imageAlign',
              label: 'Image Alignment',
              items: [ [ 'Not Set', '' ], [ 'Left', 'left'],
                       [ 'Right', 'right' ], [ 'Center', 'center'] ],
              requiredContent: features.imageAlign.requiredContent,
              setup: function(widget) {
                alignment = widget.parts.image.getAttribute('data-picture-align');
                this.setValue(alignment ? alignment : '');
              },
              // Creates a custom data-picture-align attribute since working with classes
              // is more difficult. If we used classes, then we'd have to search for
              // exisiting alignment classes and remove them before adding a new one.
              // With the custom attribute we can always just overwrite it's value.
              commit: function(widget) {
                if (this.getValue() || this.isChanged()) {
                  widget.parts.image.setAttribute('data-picture-align', this.getValue());
                }
              }

            },
              // Position before imageSize.
              'imageSize'
            );
          }
          // Resources for the following:
          // Download: https://github.com/ckeditor/ckeditor-dev
          // See /plugins/image/dialogs/image.js
          // and refer to http://docs.ckeditor.com/#!/api/CKEDITOR.dialog.definition
          // Visit: file:///[path_to_ckeditor-dev]/plugins/devtools/samples/devtools.html
          // for an excellent way to find machine names for dialog elements.
          else if (dialogName == 'image') {
            dialogDefinition.removeContents('Link');
            var infoTab = dialogDefinition.getContents('info');
            var altText = infoTab.get('txtAlt');
            var IMAGE = 1,
                LINK = 2,
                PREVIEW = 4,
                CLEANUP = 8;
            // UpdatePreview is copied from ckeditor image plugin.
            var updatePreview = function(dialog) {
              // Don't load before onShow.
              if (!dialog.originalElement || !dialog.preview) {
                return 1;
              }

              // Read attributes and update imagePreview.
              dialog.commitContent(PREVIEW, dialog.preview);
              return 0;
            };
            // Add the select list for choosing the image width.
            infoTab.add({
              type: 'select',
              id: 'imageSize',
              label: Drupal.settings.picture.label,
              items: Drupal.settings.picture.mappings,
              'default': 'not_set',
              onChange: function() {
                var dialog = this.getDialog();
                var element = dialog.originalElement;
                element.setAttribute('data-picture-mapping', this.getValue());
                updatePreview(this.getDialog());
              },
              setup: function(type, element) {
                if (type == IMAGE) {
                  var value = element.getAttribute('data-picture-mapping');
                  this.setValue(value);
                }
              },
              // Create a custom data-picture-mapping attribute.
              commit: function(type, element) {
                if (type == IMAGE) {
                  if (this.getValue() || this.isChanged()) {
                    element.setAttribute('data-picture-mapping', this.getValue());
                  }
                } else if (type == PREVIEW) {
                  element.setAttribute('data-picture-mapping', this.getValue());
                } else if (type == CLEANUP) {
                  element.setAttribute('data-picture-mapping', '');
                }
              },
              validate: function() {
                if (this.getValue() == 'not_set') {
                  var message = 'Please make a selection from ' + Drupal.settings.picture.label;
                  alert(message);
                  return false;
                } else {
                  return true;
                }
              }
            },
              // Position before preview.
              'htmlPreview'
            );

            // Put a title attribute field on the main 'info' tab.
            infoTab.add( {
              type: 'text',
              id: 'txtTitle',
              label: 'The title attribute is used as a tooltip when the mouse hovers over the image.',
              onChange: function() {
                updatePreview(this.getDialog());
              },
              setup: function(type, element) {
                if (type == IMAGE)
                  this.setValue(element.getAttribute('title'));
              },
              commit: function(type, element) {
                if (type == IMAGE) {
                  if (this.getValue() || this.isChanged())
                    element.setAttribute('title', this.getValue());
                } else if (type == PREVIEW) {
                  element.setAttribute('title', this.getValue());
                } else if (type == CLEANUP) {
                  element.removeAttribute('title');
                }
              }
            },
              // Position before the imageSize select box.
              'htmlPreview'
            );

            // Add a select widget to choose image alignment.
            infoTab.add({
              type: 'select',
              id: 'imageAlign',
              label: 'Image Alignment',
              items: [ [ 'Not Set', '' ], [ 'Left', 'left'],
                       [ 'Right', 'right' ], [ 'Center', 'center'] ],
              'default': '',
              onChange: function() {
                updatePreview(this.getDialog());
              },
              setup: function(type, element) {
                if (type == IMAGE) {
                  var value = element.getAttribute('data-picture-align');
                  this.setValue(value);
                }
              },
              // Creates a custom data-picture-align attribute since working with classes
              // is more difficult. If we used classes, then we'd have to search for
              // exisiting alignment classes and remove them before adding a new one.
              // With the custom attribute we can always just overwrite it's value.
              commit: function(type, element) {
                if (type == IMAGE) {
                  if (this.getValue() || this.isChanged()) {
                    element.setAttribute('data-picture-align', this.getValue());
                  }
                } else if (type == PREVIEW) {
                  element.setAttribute('data-picture-align', this.getValue());
                } else if (type == CLEANUP) {
                  element.setAttribute('data-picture-align', '');
                }
              }

            },
              // Position before imageSize.
              'imageSize'
            );

            // Improve the alt field label. Copied from Drupal's image field.
            altText.label = 'The alt attribute may be used by search engines, and screen readers.';

            // Remove a bunch of extraneous fields. These properties will be set in
            // the theme or module CSS.
            infoTab.remove('basic');
          }
        });
      }
  });
})();
