/*
You are tasked to analyze trend lines and predict some important metrics for the company, and you realize that the first step is to master the science of finding line intersections.

Initially, you have the Cartesian plane without any lines. You are given  queries of three types:

   - add the line with equation .
   - remove the line with equation . It is guaranteed that the line exists.
  - Find the number of lines that intersect with the line  at a point with an integer -coordinate.
Complete the function dynamicLineIntersection which takes in an integer  denoting the number of queries and prints the answer of each  query in a single line. You will need to take the queries from the standard input.

Input Format

The first line contains one integer . The next  lines contain one of the following queries:




Constraints



,  and  are integers
Output Format

For each  query, print a single line containing a single integer denoting the answer to that query.

Sample Input 0

4
+ 1 0
+ 2 0
? 1
? 2
Sample Output 0

1
2

*/
#include<iostream>
#include<map>
#include<string>
#include<iterator>
using namespace std;

int main()
{
  int q;
  cin>>q;
  int count = 0;
  map <int,int> d;
  map <int,int> ::iterator it;
  for(int h=0;h<q;h++)
  {
    string s;
    cin>>s;
    if(s=="+")
    {
      int a,b;
      cin>>a>>b;
      if(a!=0) count++;
      else
      {
        if(d.find(b)!=d.end()) d[b]++;
        else d[b] = 1;
      }

    }
    else if(s=="-")
    {
      int a,b;
      cin>>a>>b;
      if(a!=0)count--;
      else
      {
        if(d.find(b)!=d.end())
        {
          d[b]--;
          if(d[b]==0) d.erase(d.find(b));
        }
      }
    }
    else
    {
      int a;
      cin>>a;
      int c = count;
      if(d.find(a)!=d.end())c+=d[a];
      cout<<c<<endl;
    }
  }
  return 0;
}
