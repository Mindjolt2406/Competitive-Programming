#include<bits/stdc++.h>
#define MAX  1000000001
using namespace std;

void nextsmallest(int l[],int m[],int n)
{
  map<int,int> d;
  for(int i=0;i<n;i++) d[l[i]] = i;
  stack<int> s;
  for(int i=0;i<n;i++)
  {
    if(!s.empty() && l[i]<s.top())
    {
      while(!s.empty() && l[i]<s.top())
      {
        m[d[s.top()]] = i;
        s.pop();
      }
      s.push(l[i]);
    }
    else s.push(l[i]);
  }
}

int main()
{
  int n; cin>>n; int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  int m[n];
  for(int i=0;i<n;i++) m[i] = MAX;
  nextsmallest(l,m,n); // in m
  return 0;
}
