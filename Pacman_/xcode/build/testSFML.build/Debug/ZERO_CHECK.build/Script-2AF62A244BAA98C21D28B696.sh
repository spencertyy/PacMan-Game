#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode
  make -f /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode
  make -f /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode
  make -f /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode
  make -f /Users/yuyaotu/Desktop/myGithubRepo/FinalProject/xcode/CMakeScripts/ReRunCMake.make
fi

