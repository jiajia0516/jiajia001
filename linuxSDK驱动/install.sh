#!/bin/bash

CURDIR=`pwd`
echo "Your current directory is $CURDIR. This is where the MVSDK software will be installed..."
A=`whoami`
B=`getconf LONG_BIT`

if [ $A != 'root' ]; then
   echo "You have to be root to run this script"
   echo "Fail !!!"
   exit 1;
fi


cp 88-mvusb.rules /etc/udev/rules.d/

cp include/* /usr/include/
echo "Copy header files"

if [ $B == '64' ]; then
	cp lib/x64/libMVSDK.so  /lib
	echo "Copy libMVSDK.so to /lib"
else
	cp lib/x86/libMVSDK.so  /lib
	echo "Copy libMVSDK.so to /lib"
fi

echo "Successful"
echo "Please  restart system  now!!!"
