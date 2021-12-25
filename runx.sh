#!/bin/bash
# Script to compile and execute a c program in one step.

# Get file name without the .c extension
file_name="$(echo $1|sed 's/\(.*\)\.cpp/\1/')"

# Compile the program with -o option to specify the name of the binary
filename=$1
execname=$2
g++ -std=c++14 -o $2 $1
alias fx='g++ -std=c++14 -o ${execname} ${filename}'

# If there were no compilation errors, run the program
#if [[ $? -eq 0 ]]; then
#        ./$file_name
#fi
alias .="./$2"
