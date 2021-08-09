(function ($) {
  Drupal.behaviors.pictureLazyloadPictures = {
    attach: function (context, settings) {
      $(context).bind('cbox_load', function () {
        var href = $.colorbox.element()[0].hash;

        if (href.search('#picture-colorbox-') === 0) {
          href = '.' + href.substr(1, href.length) + ', #' + href.substr(1, href.length);
        }
        var $target = $(href);
        $('span[lazyload]', $target).replaceWith(function () {
          var picture = $('<div>').append($(this).clone()).html();

          picture = picture.replace(/<span/ig, '<picture');
          picture = picture.replace(/<\/span>/ig, '</picture>');
          picture = picture.replace(/ data-srcset="/ig, ' srcset="');
          $('img', picture).load(function() {
            // Ensure there's no max-width / max-height otherwise we won't get
            // the proper values. We could use naturalWeight / naturalHeight
            // but that's not supported by <IE9 and Opera.
            this.style.maxHeight = $(window).height() + 'px';
            this.style.maxWidth = $(window).width() + 'px';
            $.colorbox.resize({innerHeight: this.height, innerWidth: this.width});
            // Remove overwrite of this values again to ensure we respect the
            // stylesheet.
            this.style.maxHeight = null;
            this.style.maxWidth = null;

            $.colorbox.resize();
          });

          return $(picture).attr('lazyload', null);
        });
      }).bind('cbox_complete', function () {
        $.colorbox.resize();
      });
    }
  };
})(jQuery);
