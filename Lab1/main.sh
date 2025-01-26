#!/bin/bash

# Function to calculate the nth Fibonacci number
fibb() {
    local n=$1
    local a=0
    local b=1
    local c=1
    for ((i=0; i<n; i++)); do
        a=$b
        b=$c
        c=$((a + b))
    done
    # a is now nth Fibonacci number
    # echo $a
}

# Function to measure the time taken to run fibb 50 times
tim() {
    local start=$(date +%s%3N)
    for ((i=0; i<50; i++)); do
        fibb 100
    done
    local end=$(date +%s%3N)
    echo $((end - start))
}

# Main script
total_time=0
for ((i=0; i<200; i++)); do
    total_time=$((total_time + $(tim)))
done

total_time=$((total_time / 200))
echo $total_time