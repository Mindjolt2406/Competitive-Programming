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
  vector<int> p(n); // the pi array (dp array)
  // t(s,m);
  for(int i=1;i<n;i++)
  {
    int c = p[i-1];
    while(c>0 && s[c]!=s[i]) c = p[c-1];
    if(s[c]==s[i]) c++;
    p[i] = c;
  }

  vector<int> ans(n+1);
  for(int i=0;i<n;i++) ans[p[i]]++;
  for(int i=n;i>0;i--) ans[p[i-1]]+=ans[i];
  for(int i=0;i<n;i++) ans[i]++;

  int a = p[n-1];
  vector<int> v;
  if(a==0) {cout<<"Just a legend"<<endl; return 0;}
  while(a>0) 
  {
    v.pu(a);
    a = p[a-1];
  }

  for(int i=0;i<v.size();i++) if(ans[v[i]]>=3) {cout<<s.substr(0,v[i])<<endl; return 0;}
  
  cout<<"Just a legend"<<endl;
  
  return 0;
}

