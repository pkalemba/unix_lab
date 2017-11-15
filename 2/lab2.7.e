#!/bin/bash
while read file; do
echo "### ${file} ###"
    if test -b $file; then
    echo "file exists and is a block special file"
    fi
    if test -c $file;then
    echo "file exists and is a character special file"
    fi
    if test -d $file;then
    echo "file exists and is directory"
    fi
    if test -f $file;then
    echo "file exists and is a regural file"
    fi
    if test -g $file;then
    echo "file exists and its set group ID flag is set"
    fi
    if test -h $file;then
    echo "file exists and is a symblolic link"
    fi
    if test -p $file;then
    echo "file exists and is named pipe "
    fi
    if test -s $file;then
    echo "file exists and has a size greater than zero"
    fi
    if test -r $file;then
    echo "file exists and is readable"
    fi
    if test -w $file;then
    echo "file exists and is writable"
    fi
done < "$@"
