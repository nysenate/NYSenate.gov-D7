module.exports = function(grunt) {
  "use strict";

  var theme_name = 'nysenate';

  var global_vars = {
    theme_name: theme_name,
    theme_css: 'css',
    theme_scss: 'scss'
  }

  grunt.initConfig({
    global_vars: global_vars,
    pkg: grunt.file.readJSON('package.json'),

    sass: {
      dist: {
        options: {
          outputStyle: 'expanded',
          includePaths: ['<%= global_vars.theme_scss %>', require('node-bourbon').includePaths]
        },
        files: {
          '<%= global_vars.theme_css %>/nysenate_p.css': '<%= global_vars.theme_scss %>/nysenate.scss',
          '<%= global_vars.theme_css %>/vendors.css': '<%= global_vars.theme_scss %>/vendors.scss'
        }
      }
    },

    combine_mq: {
      default_options: {
        expanded: true,
        src: '<%= global_vars.theme_css %>/nysenate_p.css',
        dest: '<%= global_vars.theme_css %>/nysenate.css'
      }
    },
    
    bless: {
      css: {
        options: {
          compress: false
        },
        files: {
          'css/nysenate_ie8.css': 'css/nysenate_p.css',
          'css/nysenate_ie9.css': 'css/nysenate.css'
        }
      }
    },

    stripmq: {
      // viewport options
      options: {
        width: 1050,
        type: 'screen'
      },
      all: {
        files: {
          'css/nysenate_ie8.css': ['css/nysenate_ie8.css'],
          'css/nysenate_ie8-blessed1.css': ['css/nysenate_ie8-blessed1.css'],
          //'css/nysenate_ie8-blessed2.css': ['css/nysenate_ie8-blessed2.css'],
        }
      }
    },

    copy: {
      dist: {
        files: [
          {expand:true, cwd: 'bower_components/foundation/js', src: ['foundation/*.js'], dest: 'js/', filter: 'isFile'},
          {expand:true, cwd: 'bower_components/foundation/', src: ['foundation.min.js'], dest: 'js/', filter: 'isFile'},
          {expand:true, cwd: 'bower_components/foundation/js/vendor', src: ['fastclick.js'], dest: 'js/vendor', filter: 'isFile'},
          {expand:true, cwd: 'bower_components/foundation/js/vendor', src: ['jquery.cookie.js'], dest: 'js/vendor', filter: 'isFile'},
          {expand:true, cwd: 'bower_components/foundation/js/vendor', src: ['modernizr.js'], dest: 'js/vendor', filter: 'isFile'},
          {expand:true, cwd: 'bower_components/foundation/scss/foundation/components', src: '**/*.scss', dest: 'scss/vendor/foundation/components', filter: 'isFile'},
          {expand:true, cwd: 'bower_components/foundation/scss/foundation', src: '_functions.scss', dest: 'scss/vendor/foundation', filter: 'isFile'},
        ]
      }
    },

    watch: {
      grunt: { files: ['Gruntfile.js'] },

      sass: {
        files: '<%= global_vars.theme_scss %>/**/*.scss',
        tasks: ['sass', 'combine_mq', 'bless', 'stripmq' ],
        options: {
          livereload: true
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-combine-mq');
  grunt.loadNpmTasks('grunt-bless');
  grunt.loadNpmTasks('grunt-stripmq');

  grunt.registerTask('build', ['sass', 'copy']);
  grunt.registerTask('default', ['build', 'watch']);
  grunt.registerTask('rebuild', ['sass', 'combine_mq', 'bless', 'stripmq']);
}
