#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include<sstream>
#define INF 1e9

using namespace std;

int solution(vector<int> A)
{
  // Put your solution here
  const int N = 1e5;
  vector<vector<int> > dp(2,vector<int> (N));
  
  
  int i = 0;
  dp[0][A[0]] = 1; // Take the first element
  dp[0][0] = 1; // Take nothing
  i++;
  while(i<A.size())
  {
    for(int j=0;j<N;j++)
    {
      // Take A[i]
      if(j-A[i]>=0 && dp[0][j-A[i]]) dp[1][j] = 1; 
      else if(dp[0][j]) dp[1][j] = 1;
    }

    swap(dp[1],dp[0]);
    dp[1].clear();
    i++;
  }

  int sum1 = 0;
  for(int i=0;i<A.size();i++) sum1 += A[i];

  int min1 = INF;

  for(int i=0;i<N;i++)
  {
    if(dp[0][i])
    {
      min1 = min(min1,abs(i-(sum1-i)));
    }
  }


  return min1; 
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
  cout << solution(toIntVector(AS));
}