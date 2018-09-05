#!/bin/sh

ARCHIT=`uname`

pushd $HOME/Dropbox/Programming/Euler/Code/CPP >& /dev/null

if [ $ARCHIT = 'Darwin' ]
then
  export DYLD_LIBRARY_PATH=`pwd`/lib/Release:$DYLD_LIBRARY_PATH
else
  export LD_LIBRARY_PATH=`pwd`/lib/Release:$LD_LIBRARY_PATH
fi

popd >& /dev/null

unset ARCHIT
