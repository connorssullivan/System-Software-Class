#!/bin/sh

# Shore demonstration to shor a break and ontinue statment

for (( i=0; i<10; i++ )); do
    if [ $i -eq 5 ]; then
        continue
    fi
    echo $i
done


for i in $(seq 1 2 10); do
    if [ $i -eq 5 ]; then
        break
    fi
    echo $i
done