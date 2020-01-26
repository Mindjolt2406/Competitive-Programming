#include <iostream>
#include <string>

using namespace std;

string solution(string T) {
  // Your solution goes here.

  // Minutes 
  if(T[4] == '?') T[4] = '9';
  if(T[3] == '?') T[3] = '5';

  // Hours
  if(T[0] == '?' && T[1] == '?')
  {
    T[0] = '2';
    T[1] = '3';
  }
  else if(T[0] == '?' || T[1] == '?')
  {
    if(T[0] == '?')
    {
      if(T[1] <= '3') // Then T[1] has a value
      {
        T[0] = '2';
      }
      else // T
      {
        T[0] = '1';
      }
    }
    else // T[1] = '?'
    {
      if(T[0] == '2')
      {
        T[1] = '3';
      }
      else // T[0] is either '0' or '1'
      {
        T[1] = '9';
      }
    }
  }

  return T;
}

int main() {
  // Read from stdin, solve the problem, write answer to stdout.
  string input;
  cin >> input;
  cout << solution(input);
}

/*
Given a time (in 24-hour format) with missing digits marked as '?', we want to replace all of the question marks by digits (0-9) in such a way as to obtain the latest possible time. The earliest possible time is 00:00 and the latest valid time is 23:59.

Write a function:

class Solution { public String solution(String T); }

that, given a string T, returns the latest valid time that can be obtained from T, as a string in the format "HH:MM", where HH denotes a two-digit value for hours and MM denotes a two-digit value for minutes.

Examples:

1. Given T = "2?:?8", the function should return "23:58".

2. Given T = "?8:4?", the function should return "18:49".

3. Given T = "??:??", the function should return "23:59".

4. Given T = "06:34", the function should return "06:34".

Assume that:

T consists of exactly five characters; the third one is ':'; the others are digits (0-9) or '?';
there always exists a valid time obtained by substituting '?' with digits.

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment
*/