#!/bin/sh
# $Id$

#------------------------------------------------
# The Geant4 Virtual Monte Carlo package
# Copyright (C) 2007, Ivana Hrivnacova
# All rights reserved.
#
# For the licensing terms see geant4_vmc/LICENSE.
# Contact: vmc@pcroot.cern.ch
#-------------------------------------------------

# Script to produce source and optionally binary distribution of geant4_vmc.
# Called by main Makefile.
#
# According to: 
# $ROOTSYS/build/unix/makedist.sh
# Author: Fons Rademakers, 29/2/2000
#
# Usage: makedist.sh [gcc_version] [lib]
#
# By I.Hrivnacova, 7/10/2002

CURDIR=`pwd`

# gmake is called from geant4_vmc/source
cd ../..

if [ "x$1" = "xlib" ]; then
   GCC_VERS=""
   MAKELIB="geant4_vmc/lib"
elif [ "x$2" = "xlib" ]; then
   GCC_VERS=$1
   MAKELIB="geant4_vmc/lib"
else
   GCC_VERS=$1
fi
VERSION=`cat geant4_vmc/config/version_number`
MACHINE=`root-config --arch`
if [ "x$MAKELIB" = "xgeant4_vmc/lib" ]; then
   if [ "x$GCC_VERS" = "x" ]; then  
      TYPE=$MACHINE.
   else
      TYPE=$MACHINE.$GCC_VERS.
   fi
else   
  TYPE=""
fi  
TARFILE=geant4_vmc.$VERSION.$TYPE"tar"

TAR=`which gtar`
dum=`echo $TAR | grep "no gtar"`
stat=$?
if [ "$TAR" = '' ] || [ $stat = 0 ]; then
   TAR="tar cvf"
   rm -f $TARFILE.gz
   EXCLUDE=
else 
   TAR=$TAR" zcvf"
   rm -f $TARFILE.gz
   TARFILE=$TARFILE".gz"
   EXCLUDE="--exclude CVS"
fi

$TAR $TARFILE $EXCLUDE geant4_vmc/README geant4_vmc/"history" geant4_vmc/config  \
   geant4_vmc/"source" geant4_vmc/examples $MAKELIB
cd $CURDIR

exit 0