#!/bin/sh

# This program shows how you can use different enviormental variables

echo "Home Directory \n $HOME"
echo "Current Directory \n $PWD"
echo "Name of Program: \n $0"
echo "Number of Arguments: \n $#"
echo "2nd argument: \n $1"
echo "All arguments: \n $*"
echo "All Arguments: \n $@"
echo "Status: \n $?"
echo "Script Id: \n $$"