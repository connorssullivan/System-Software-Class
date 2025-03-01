#!/bin/sh



sum=0

# Get the arguments and add the digits
for i in $(echo $1 | fold -w1) 
do
    sum=$((sum+i))
done
# Print the result
echo $sum