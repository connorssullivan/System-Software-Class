#!/bin/sh
# Write a shell command line to convert an input string to ALL CAPS

echo "Enter a string: "
read str
echo $str | tr '[:lower:]' '[:upper:]'