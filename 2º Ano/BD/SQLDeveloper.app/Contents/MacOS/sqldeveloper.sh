#!/bin/bash 
TMP_PATH=`/usr/libexec/java_home -F -v 1.8`
if [ -z "$TMP_PATH" ] ; then
  TMP_PATH=`/usr/libexec/java_home -F -v 11`
  if [ -z "$TMP_PATH" ] ; then
    TMP_PATH=`/usr/libexec/java_home -F -v 12`
    if [ -z "$TMP_PATH" ] ; then
      osascript -e 'tell app "System Events" to display dialog "SQL Developer requires a minimum of Java 8. \nJava 8 can be downloaded from:\n http://www.oracle.com/technetwork/java/javase/downloads/"'
      exit 1
    fi
  fi
fi

export JAVA_HOME=$TMP_PATH

if [[ -f $HOME/.sqldeveloper/19.2.1/env.sh ]]; 
then
  	source "$HOME/.sqldeveloper/19.2.1/env.sh" >> /dev/null
elif [[ -f $HOME/.sqldeveloper/env.sh ]]; 
then
	source "$HOME/.sqldeveloper/env.sh"  >> /dev/null
fi

here="${0%/*}"
cd "${here}"
cd ../Resources/sqldeveloper/sqldeveloper/bin
bash ./sqldeveloper >>/dev/null
