#!/bin/sh
CURDIR=$(pwd)
if [ -d "$CURDIR/install" ];then
   rm -rf $CURDIR/install -rf
   mkdir $CURDIR/install
else
   mkdir $CURDIR/install
fi

if [ -d "$CURDIR/usr" ];then
   rm -rf $CURDIR/usr -rf
   mkdir $CURDIR/usr
else
   mkdir $CURDIR/usr
fi


cd $CURDIR/install
cmake ../ -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_INSTALL_PREFIX=$CURDIR/usr -DCPU_ONLY:BOOL=ON
make -j8
#make install
