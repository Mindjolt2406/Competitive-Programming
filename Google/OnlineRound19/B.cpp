#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool compare(vector<int> &A, vector<int> &B)
{
  // Returns true if A > B

  for(int i=0;i<A.size();i++)
  {
    if(A[i] > B[i]) 
    {
      return true;
    }
    else if (A[i] < B[i])
    {
      return false;
    }
    // Otherwise continue
  }

  // If the function reaches here, both the arrays are equal. However, since the elements are distinct, this will not happen
  return false;
}

vector<int> solution(vector<int> A, int K) 
{
  // O(N*K) solution where N = A.size()

  // Current maximum initialised to the first K element of array A
  vector<int> cur_max;

  for(int i=0;i<K;i++) 
  {
    cur_max.push_back(A[i]);
  }

  // left and right stand for the first and last elements of the K-sized subarray
  for(int left = 1;left < A.size()-K+1;left++) 
  {
    int right = left + K - 1;

    vector<int> temp;
    for(int j = left; j <= right; j++)
    { 
      temp.push_back(A[j]);
    }

    if(compare(temp,cur_max)) 
    {
      // Update cur_max as temp > cur_max
      cur_max = temp;
    }
  }

  return cur_max;
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