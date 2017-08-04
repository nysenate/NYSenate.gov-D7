CKEDITOR.plugins.add('NodeEmbed', {
  requires: ['iframedialog'],

  // Initialize the plugin.
  init: function(editor) {

    // Add the popup for the plugin.
    CKEDITOR.dialog.add('nodeembed', function() {
      return {
        title: 'Node Embed',
        minWidth: 700,
        minHeight: 400,
        // The contents of the dialog.
        contents: [{
          id: 'iframe',
          label: 'Embed a Node: ',
          expand: true,
          elements: [{
            type: 'iframe',
            src: Drupal.settings.basePath + 'ckeditor-node-embed',
            width: '100%',
            height: '100%',
            onContentLoad: function() {}
          }]
        }],

        // Set or updated whenever a node is selected and insert the tag into the editor.
        onOk: function() {
          var node_id = window.currentActiveNid;
          if (node_id != null && node_id != "") {
            this._.editor.insertHtml('<div class="embed">[[nid:' + node_id + ']]</div>');
          }
        }
      };
    });

    // Add the button to the menu.
    editor.ui.addButton('NodeEmbed', {
      label: 'Node Embed',
      icon: this.path + 'images/icon.gif',
      command: 'NodeEmbed'
    });

    // Add the command to open the window.
    editor.addCommand('NodeEmbed', {
      exec: function(e) {
        e.openDialog('nodeembed');
      }
    });

    // If the "menu" plugin is loaded, register the menu items.
    if (editor.addMenuItems) {
      editor.addMenuItems({
        nodemenu: {
          label: 'Node Embed',
          command: 'NodeEmbed',
          group: 'NodeEmbed',
          order: 1
        }
      });
    }
  }
});
