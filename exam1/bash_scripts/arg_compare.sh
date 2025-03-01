#!/bin/sh


echo "You entered $#/2 Arguments"
echo "Your arguments ar $@"


a=$1
b=$2

if [ $a -eq $b ]; then
    echo "$a and b are equal"
elif [ $a -gt $b ]; then
    echo "$a is greater than $b"
else
    echo "$a is less than $b"
fi

echo "Status $?"