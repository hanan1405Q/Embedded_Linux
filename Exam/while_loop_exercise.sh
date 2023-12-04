#!/bin/bash

chmod +x "$0"

read -p "Enter Positive Number : " num

if [ $num -lt 0 ]; then
    echo "Not a valid input. Enter a positive number."
    exit 1
fi

counter=0

while [ $counter -le $num ]; do
    echo "The Square of $counter = $(($counter * $counter))"
    ((counter++))
done
