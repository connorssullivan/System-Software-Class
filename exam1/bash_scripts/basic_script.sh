#!/bin/sh


sorted_var=$(sort "notes.txt")

echo "$sorted_var" 

if [ -n basic_script.sh ]; then
    echo "basic_script.sh exists"
else 
    ehco "File soesnt exist"
fi
