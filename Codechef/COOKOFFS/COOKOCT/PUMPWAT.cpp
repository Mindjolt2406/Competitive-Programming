#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

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
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    int *m1 = new int[n];
    int *m2 = new int[n];
    nextsmallest(l,m1,n);
    reverse(l,l+n);
    nextsmallest(l,m2,n);
    reverse(l,l+n);
    reverse(m2,m2+n);
    for(int i=0;i<n;i++) if(m2[i]!=-1) m2[i] = n-1-m2[i];
    for(int i=0;i<n;i++) cout<<m1[i]<<" ";cout<<endl;
    for(int i=0;i<n;i++) cout<<m2[i]<<" ";cout<<endl;
  }
  return 0;
}

