#!/bin/sh

#A demonstration of an until loop

value=10
until [ $value -lt 1 ]; do
    echo $value
    value=$((value-1))
done