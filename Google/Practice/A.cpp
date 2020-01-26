#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include<sstream>
#define INF 1e9

using namespace std;

int solution(vector<int> A)
{
  // Your solution goes here.
  int max1  = -INF;
  int ans = 0;
  for(int i=0;i<A.size();i++)
  {
    if(A[i] > max1)
    {
      max1 = A[i];
      ans++;
    }
  }
  return ans; 
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  vector<int> A = toIntVector(AS);
  cout << solution(A);
}