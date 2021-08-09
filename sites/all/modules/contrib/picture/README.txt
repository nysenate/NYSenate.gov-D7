-- SUMMARY --

Picture element

Hide image
----------

If you use the '- empty image -' option, you have to add the following
to your theme css to completely hide the image, otherwise it will
still take some space.

img[width="1"][height="1"] {
  display: none;
}

Warning:
For now this CSS will not work until https://drupal.org/node/2280471
gets fixed. It is postponed until the upstream issues
https://github.com/ResponsiveImagesCG/picture-element/issues/50 and
https://github.com/ResponsiveImagesCG/picture-element/issues/85
are fixed. Meanwhile you can hide the image with css using breakpoints. See
https://drupal.org/node/2280471 for more info.
