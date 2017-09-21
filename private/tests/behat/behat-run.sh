#!/bin/bash
usage()
{
cat << EOF
Usage: behat-run.sh
Run from the private/tests/behat directory
Requirements: run composer install and npm install
EOF
}

PHANTOMJS=node_modules/phantomjs/bin/phantomjs
FOREVER=node_modules/forever/bin/forever

if [ ! -f ${PHAMTOMJS} ] || [ ! -f ${FOREVER} ]; then
  usage
  exit 1;
fi

if [ ! -z ${PHANTOMJS} ] && !(pgrep -f "${PHANTOMJS} --webdriver=8643" > /dev/null); then
  ${FOREVER} start ${PHANTOMJS} --webdriver=8643
fi

# Run behat.
if [ -f bin/behat ]; then
  bin/behat
else
  usage
  exit 1;
fi
