alias f="g++ -std=c++14 $1.cpp"
alias .="./a.out"
if [ ! -e "$1.cpp" ]; then
  cp ~/Questions/template.cpp $1.cpp
  code $1.cpp
else 
  echo "File exists"
fi
