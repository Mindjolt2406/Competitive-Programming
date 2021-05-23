/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
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

const int N = 1e5+10;

ll power(ll x, ll y, ll p)
{
        ll res = 1;      // Initialize result
        x = x % p;  // Update x if it is more than or
        while (y > 0)
        {
                        if (y & 1)
                                        res = (res*x) % p;
                        y = y>>1; // y = y/2
                        x = (x*x) % p;
        }
        return res;
}

int main()
{
  __;
  int t;
  cin >> t;
  ll dp[N] = {0};
  dp[0] = 2;
  dp[1] = 2;
  dp[2] = 2;
  vector<int> v;
  int prod = 1,sum1 = 1;
  while(sum1 < 1e5)
  {
    v.pu(sum1);
    prod <<= 1;
    sum1 += prod;
  }

  for(int i=3;i<=N;i++)
  {
    for(int j=0;j<v.size();j++)
    {
      if(i-v[j]<0) break;
      // if(i==6) t(i,v[j],i-v[j]);
      // dp[i] += (dp[i-v[j]]*power(2,MOD-2,MOD))%MOD;
      dp[i] += dp[i-v[j]];
      dp[i] %= MOD;
    }
    // dp[i] *= 2;
    // dp[i] %= MOD;
  }

  while(t--)
  {
    int a;
    cin >> a;
    if(a==0) cout << 1 << endl;
    else cout << dp[a] << endl;
  }
  return 0;
}

