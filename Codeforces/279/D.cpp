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
#define all(v) v.begin(),v.end()
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  ll a,b,c,d;
  cin>>a>>b>>c>>d;

  ll e = a*b;
  ll f = c*d;

  int cnt3e = 0, cnt2e = 0, cnt3f = 0, cnt2f = 0;
  while(e%3==0) {e/=3;e*=2; cnt3e++;}
  while(e%2==0) {e/=2;cnt2e++;}

  while(f%3==0) {f/=3;f*=2; cnt3f++;}
  while(f%2==0) {f/=2;cnt2f++;}

  if(e!=f) {cout<<-1<<endl; return 0;}
  
  ll temp3 = abs(cnt3e - cnt3f), temp2 = abs(cnt2e - cnt2f);

  ll ans = temp3+temp2;

  if(cnt3e > cnt3f)
  {
    while(temp3--)
    {
      if(a%3==0) {a/=3;a*=2;}
      else {b/=3;b*=2;}
    }
  }
  else
  {
    while(temp3--)
    {
      if(c%3==0) {c/=3;c*=2;}
      else {d/=3;d*=2;}
    }
  }

  if(cnt2e > cnt2f)
  {
    while(temp2--)
    {
      if(a%2==0) a/=2;
      else b/=2;
    }
  }
  else
  {
    while(temp2--)
    {
      if(c%2==0) c/=2;
      else d/=2;
    }
  }

  cout<<ans<<endl;
  cout<<a<<" "<<b<<endl;
  cout<<c<<" "<<d<<endl;
  return 0;
}

