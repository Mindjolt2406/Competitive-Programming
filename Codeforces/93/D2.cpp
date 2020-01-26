/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  string s;
  cin>>s;
  int n = s.size();

  vector<int> p(n);
  p[0] = 0;
  for(int i=1;i<n;i++)
  {
    int a = p[i-1];
    while(a>0 && s[i]!=s[a])
    {
      a = p[a-1];
    }
    if(s[a]==s[i]) a++; //Increment
    p[i] = a;
  }

  if(p[n-1]==0) cout<<"Just a legend"<<endl;
  else
  {
    int boo = 0;
    for(int i=0;i<n-1;i++)
    {
      if(p[i]==p[n-1]) boo = 1;
    }

    if(boo) cout<<s.substr(0,p[n-1])<<endl;
    else
    {
      // t(p[p[n-1]-1]);
      if(p[p[n-1]-1]==0) cout<<"Just a legend"<<endl;
      else
      {
        cout<<s.substr(0,p[p[n-1]-1])<<endl;
      }
    }
  }
  return 0;
}

