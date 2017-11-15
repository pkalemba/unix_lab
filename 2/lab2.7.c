#!/bin/bash
file=$1
if test -b $1; then
  echo "file exists and is a block special file"
  fi
if test -c $1;then
  echo "file exists and is a character special file"
  fi
if test -d $1;then
  echo "file exists and is directory"
  fi
if test -f $1;then
  echo "file exists and is a regural file"
  fi
if test -g $1;then
  echo "file exists and its set group ID flag is set"
  fi
if test -h $1;then
  echo "file exists and is a symblolic link"
  fi
if test -p $1;then
  echo "file exists and is named pipe "
  fi
if test -s $1;then
  echo "file exists and has a size greater than zero"
  fi
if test -r $1;then
  echo "file exists and is readable"
  fi
if test -w $1;then
  echo "file exists and is writable"
fi
