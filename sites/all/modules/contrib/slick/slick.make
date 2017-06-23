api = 2
core = 7.x

; @see https://github.com/drush-ops/drush

; Slick.
libraries[slick][download][type] = "file"
libraries[slick][download][url] = "https://github.com/kenwheeler/slick/archive/master.zip"
libraries[slick][directory_name] = "slick"
libraries[slick][destination] = "libraries"

; Easing, this should go to jqeasing.module...
; Make sure to remove version 1.3 from the lastest minified JS file name.
libraries[easing][download][type] = "file"
libraries[easing][download][url] = "https://github.com/gdsmith/jquery.easing/archive/master.zip"
libraries[easing][directory_name] = "easing"
libraries[easing][destination] = "libraries"

; Mousehwheel.
; @see https://github.com/kenwheeler/slick/issues/122
libraries[mousewheel][download][type] = "file"
libraries[mousewheel][download][url] = "https://github.com/brandonaaron/jquery-mousewheel/archive/master.zip"
libraries[mousewheel][directory_name] = "mousewheel"
libraries[mousewheel][destination] = "libraries"
