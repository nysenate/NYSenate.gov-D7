
(function ($) {

Drupal.behaviors.disqusCommentFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.comment-node-settings-form', context).drupalSetSummary(function (context) {
      var drupalCommentStatus = Drupal.checkPlain('Drupal Comments: ' + $('.form-item-comment input:checked', context).next('label').text());
      var disqusCommentStatus = $('.form-item-disqus-status input:checked', context).length > 0 ? '<br/> Disqus enabled' : '';
      return drupalCommentStatus + disqusCommentStatus;
    });
  }
};

})(jQuery);
