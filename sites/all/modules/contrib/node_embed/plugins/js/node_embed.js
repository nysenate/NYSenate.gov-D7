(function ($) {

/**
 * Wysiwyg plugin button implementation for NodeEmbed plugin.
 */
Drupal.wysiwyg.plugins.node_embed = {
  /**
   * Return whether the passed node belongs to this plugin.
   *
   * @param node
   *   The currently focused DOM element in the editor content.
   */
  isNode: function(node) {
    return ($(node).is('img.wysiwyg-node_embed'));
  },

  /**
   * Execute the button.
   *
   * @param data
   *   An object containing data about the current selection:
   *   - format: 'html' when the passed data is HTML content, 'text' when the
   *     passed data is plain-text content.
   *   - node: When 'format' is 'html', the focused DOM element in the editor.
   *   - content: The textual representation of the focused/selected editor
   *     content.
   * @param settings
   *   The plugin settings, as provided in the plugin's PHP include file.
   * @param instanceId
   *   The ID of the current editor instance.
   */
  invoke: function(data, settings, instanceId) {

    // Show the node selection Dialog.
    var iframeSrc = Drupal.settings.basePath + 'ckeditor-node-embed';
    var dialogMarkup = '<div id="nodeEmbedDialog" title="Embed a Node" style="width:100%; height:100%">' +
      '<iframe frameborder="no" style="width:600px; height:350px; border:0" src="'+iframeSrc+'"></iframe>' +
      '<div class="nodeEmbedButtons"><button id="buttonEmbedFromDialog">Embed</button><button id="buttonCancelDialog">Cancel</button></div>' +
      '</div>';

    var dialog = $(dialogMarkup).dialog({
      autoOpen: false,
      height: 470,
      width: 650,
      modal: true,
      dialogClass: 'node_embed_dialog'
    });

    $(dialog).bind('dialogclose', function(event, ui) {
      $(this).remove();
    });

    $('#buttonEmbedFromDialog').click(function(e) {

      // Set or updated whenever a node is selected.
      var node_id = window.currentActiveNid;
      if (node_id != null && node_id != "" ) {
        dialog.editor_content = '[[nid:' + node_id + ']]';
      }

      if (window.currentActiveNid && window.currentActiveNid != "") {
        var edit_content = "[[nid:" + window.currentActiveNid + "]]";
        if (data.format == 'html') {
          var content = '<div class="embed">' + edit_content + '</div>';
        }
        else {
          var content = edit_content;
        }

        // Write the content to the editor.
        if (typeof content != 'undefined') {
          Drupal.wysiwyg.instances[instanceId].insert(content);
        }
      }

      $(dialog).dialog('close');
    });

    $('#buttonCancelDialog').click(function(e) {
      $(dialog).dialog('close');
    });

    $(dialog).dialog('open');
  }
};

})(jQuery);
