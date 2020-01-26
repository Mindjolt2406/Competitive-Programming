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
#define vi vector<int>
#define vll vector<long long int>
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
using namespace std::chrono;

const int N = 10e6+5;
int dp[N] = {0};
// unordered_map<ll,ll> dp;

ll recur(ll a)
{
  // t(a);
  // if(dp.find(a)!=dp.end()) {return dp[a];}
  if(a<=1e6 && dp[a]!=0) return dp[a];
  int b = -1;
  if(a==1) b = 1;
  else if(a%2==1) b = 1+recur(3*a+1);
  else b = 1+recur(a/2);
  if(a<=1e6) dp[a] = b;
  return b;
}
int main()
{
  __;
  int max1 = -1,max2 = -1;
  auto start = high_resolution_clock::now();
  for(int i=1;i<=1e6;i++) if(dp[i]==0) {recur(i);}
  for(int i=1;i<=1e6;i++) 
  {
    if(max1<dp[i]) {max1 = dp[i]; max2 = i;}
  }
  auto stop = high_resolution_clock::now();
  auto dur = duration_cast<microseconds>(stop-start);
  t((ld)dur.count()/1e6);
  cout<<max2<<endl;
  return 0;
}

