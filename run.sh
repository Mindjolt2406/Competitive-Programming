#!/bin/bash
#shopt -s expand_aliases
# Script to compile and execute a c program in one step.

# Get file name without the .cpp extension
file_name="$(echo $1|sed 's/\(.*\)\.cpp/\1/')"

# Compile the program with -o option to specify the name of the binary
g++ -std=c++14  "$1"
alias f="g++ -std=c++14 $1 "
alias .="./a.out"
# If there were no compilation errors, run the program
#if [[ $? -eq 0 ]]; then
#        ./$file_name.out
#fi
