#!/bin/sh

#This program performs arthithmitic on 2 cli arguments

echo "You are now running $0"

echo "You need to give 2 args, and you gave ",$#

a=$1
b=$2

add=$(expr $a + $b)
echo "$1 + $2 = $add"

sub=$(expr $a - $b)
echo "$a - $b = $sub"