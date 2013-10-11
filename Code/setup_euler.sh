#!/bin/sh

ARCHIT=`uname`

if [ $ARCHIT = 'Darwin' ]
then
  export DYLD_LIBRARY_PATH=`pwd`/CPP/lib:$DYLD_LIBRARY_PATH
else
  export LD_LIBRARY_PATH=`pwd`/CPP/lib:$LD_LIBRARY_PATH
fi

unset ARCHIT


