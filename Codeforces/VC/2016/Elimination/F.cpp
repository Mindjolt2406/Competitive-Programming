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

int dp[210][210][1101] = {0};

int main()
{
  __;
  // dp[i][j][k] = processing the ith guy, having j open sets and exactly k total imbalance

  // // We need j open sets
  //   // These sets already exist
  //     // Leave them all open
  //     dp[i][j][k] += dp[i-1][j][k-inc]*j;
  //     // Close one of them
  //     dp[i][j][k] += dp[i-1][j+1][k-inc]*(j+1);
    
  //   // Create a new one 
  //     // Close it immediately
  //     dp[i][j][k] += dp[i-1][j-1][k];

  //     // Leave it open for others to join
  //     dp[i][j][k] += dp[i-1][j-1][k];
      


  int n,total;
  cin >> n >> total;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  sort(v.begin(),v.end());

  dp[0][0][0] = 1;
  dp[0][1][0] = 1;

  for(int i=1;i<n;i++)
  {
    for(ll j=0;j<=i+1;j++)
    {
      ll inc;
      for(int k=0;k<=total;k++)
      {
        // t(i,j,k);
        // Add to an existing set

        // Leave the sets open
        inc = (v[i]-v[i-1])*j;
        if(k-inc>=0) dp[i][j][k] += (dp[i-1][j][k-inc]*j)%MOD;
        dp[i][j][k] %= MOD;

        // Close one set 
        // If we want, we can say go only if j<i
        inc = (v[i]-v[i-1])*(j+1);
        if(k-inc>=0) dp[i][j][k] += (dp[i-1][j+1][k-inc]*(j+1))%MOD;
        dp[i][j][k] %= MOD;

        // Create a new set

        // Close the new set immediately
        inc = (v[i]-v[i-1])*j;
        if(k-inc>=0) dp[i][j][k] += (dp[i-1][j][k-inc])%MOD;
        dp[i][j][k] %= MOD;

        // Leave the set open for others to join
        inc = (v[i]-v[i-1])*(j-1);
        if(j>0 && k-inc>=0) dp[i][j][k] += (dp[i-1][j-1][k-inc])%MOD;
        dp[i][j][k] %= MOD;
      }
    }
  }

  int sum1 = 0;
  for(int i=0;i<=total;i++) 
  {
    sum1 += dp[n-1][0][i];
    sum1 %= MOD;
  }

  cout << sum1 << endl;

  // for(int i=0;i<n ;i++) for(int j=0;j<n;j++) for(int k=0;k<=total;k++) t(i,j,k,dp[i][j][k]);
  return 0;
}

