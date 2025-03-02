#!/bin/sh

# This file shows how you can use for loops in differnt ways

echo "Loop 1: "
for (( i=5; i < 10; i++ )); do
    echo $i
done

echo "\nLoop2: "
for i in $(seq 100 -10 0); do
    echo $i
done

echo "\nLoop3: "
for i in "amazon" "mac OS" "Linux"; do
    echo $i
done