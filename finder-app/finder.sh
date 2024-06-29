#!/bin/sh
if [ "$#" != "2" ]; then
   echo "Must pass in exactly 2 arguments for filesdir and searchstr"
   exit 1
fi

if [ ! -d "$1" ]; then
   echo "$1 is not a directory"
   exit 1
fi

X=$(find $1 -type f | wc -l)
Y=$(grep -rc $2 $1 | awk -F ":" '{ sum += $2 } END { print sum }')
echo "The number of files are $X and the number of matching lines are $Y"
