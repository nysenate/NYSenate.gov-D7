#!/usr/bin/env bash
# This rsyncs files directory by depth.
# FreeBSD or OS X Only, change from gfind to find for unix/linux.
# Add '-n' to rsync options for testing.
# Used for uploading a local backup.
export SITE=4c1822eb-3e98-45ae-bbfd-4ea751b4b5a9;
export ENV=dev;

cd sites/default/files
gfind . -type d -printf '%d\t%P\n' | sort -r -nk1 | cut -f2- | while read dir
do
  if [[ ! -z $dir ]]
    then dir=$dir/
  fi
  echo "rsync -rlvzP --ignore-existing --ipv4 -e 'ssh -p 2222' $dir. --exclude='*.css' --temp-dir='/srv/bindings/2203f5ee0e0f444fb8e307edcd53934a/tmp' $ENV.$SITE@appserver.$ENV.$SITE.drush.in:files/$dir"
  rsync -rlvzP --ignore-existing --ipv4 -e 'ssh -p 2222' $dir. --exclude="*.css" --temp-dir="/srv/bindings/2203f5ee0e0f444fb8e307edcd53934a/tmp" $ENV.$SITE@appserver.$ENV.$SITE.drush.in:files/$dir
done
