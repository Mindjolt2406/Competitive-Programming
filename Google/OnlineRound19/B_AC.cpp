#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> A, int K) 
{
  // O(N) solution where N = A.size()
  // The elements are distinct. Hence the largest K-sized subarray starts from the largest element in A[0:N-K+1]
  // By having all the elements to be distinct, we can reduce our computation from O(N*K) -> O(N)
  // The reason this works is that if we compare the any two K-sized subarrays, we can check which is bigger by only looking at the first element. By taking the maximum from the subarray A[0:N-K+1] (N-K+1 is not included), we are actually comparing all the valid K-sized subarrays and taking the best one. 

  int cur_max = -1,max_index = -1;

  for(int i = 0; i < A.size() - K + 1;i++) 
  {
    if(A[i] > cur_max)
    {
      cur_max = A[i];
      max_index = i;
    }
  }

  vector<int> ans;
  for(int i = max_index;i < max_index+K;i++)
  {
    ans.push_back(A[i]);
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

string fromIntVector(vector<int> arr)
{
  string out = "";
  for (int i=0; i<arr.size(); i++) {
    out += to_string(arr[i]);
    if (i != arr.size() - 1) {
      out += ",";
    }
  }
  return out;
}

int main()
{
  // Read from stdin, solve the problem, write answer to stdout.
  string arrS;
  int K;
  cin >> arrS >> K;
  vector<int> N = toIntVector(arrS);
  cout << fromIntVector(solution(N, K));
}

/*
Array X is greater than array Y if the first non-matching element in both arrays has a greater value in X than in Y.

For example, for arrays X and Y such that:

X = [1, 2, 4, 3, 5]

Y = [1, 2, 3, 4, 5]

X is greater than Y because the first element that does not match is larger in X (i.e. for X[2] and Y[2], X[2] > Y[2]).

A contiguous subarray is defined by an interval of the indices. In other words, a contiguous subarray is a subarray which has consecutive indexes.

Write a function that, given a zero-indexed array A consisting of N integers and an integer K, returns the largest contiguous subarray of length K from all the contiguous subarrays of length K.

For example, given array A and K = 4 such that:

A = [1, 4, 3, 2, 5]

the function should return [4, 3, 2, 5], because there are two subarrays of size 4:

[1, 4, 3, 2]

[4, 3, 2, 5]

and the largest subarray is [4, 3, 2, 5].

Assume that:
1 ≤ K ≤ N ≤ 100;
1 ≤ A[J] ≤ 1000;

given an array A contains N distinct integers.

In your solution, focus on correctness. The performance of your solution will not be the primary focus of the assessment.

*/