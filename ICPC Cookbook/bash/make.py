#!/bin/bash

alias f="g++ -std=c++14 $1.cpp"
if [ ! -e "$1.cpp" ]; then
  cp ~/IIITB/Questions/template.cpp .
  mv template.cpp $1.cpp
else 
  echo "File exists"
fi
