#!/bin/sh

# Take the input and see if its yes of no

flag="false"

while [ "$flag" != "true" ]; do
    echo  "Are you Eligible?"
    read anser

    case $anser in
        y* | Y*)
            echo "You are Eligible"
            flag="true";;
        n* | N*)
            echo "You are not Eligible"
            flag="true";;
        *) 
            echo "Invalid Input";;
    esac
done