#!/bin/sh
#Take the list of comand line arguments and compute the max number
max=$1

for i in $@; do
    if [ $i -gt $max ]; then
        max=$i
    fi
done

echo $max

