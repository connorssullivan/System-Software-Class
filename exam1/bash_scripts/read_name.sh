#!/bin/sh

# Simply Read a name, check if the name is not null and write it to a file if the file doesnt

echo "Please Enter your name"

read my_name
filename="my_name.txt"

if [ -n "$my_name" ]; then
    if [ ! -e $filename ]; then
        touch $filename
        echo "My name is $my_name" >$filename
    else
        echo "File $filename already exists"
    fi
else
    echo "Please enter a name"
fi
