#!/bin/sh

# A Program that uses basic Functions

studentId() {
    local studentId
    echo "What is your Student ID: "
    read studentId
    echo "Your student id is $studentId"
}

addArgs() {
    local sum=0
    for arg in "$@"; do
        sum=$(expr $sum + $arg)
    done

    return $sum
    exit 0
}

add() {
    local a=$1
    local b=$2
    local sum=$(expr $a + $b)
    return $sum
}

sub() {
    local a=$1
    local b=$2
    local sum=$(expr $a - $b)
    return $sum
}


# Comment out
#studentId

#addArgs 1 2 3 4 5
#sum=$?
#echo "The sum is $sum"

add 1 2
sum=$?
echo "The sum is $sum"

sub 3 2
sum=$?
echo "The sum is $sum"

exit 0