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
#define INF 1e18
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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  __;
  int n;
  cin >> n;
  ll a,b;
  cin >> a >> b;

  vector<int> v(n+1);
  map<int,int> d;
  vector<vector<ll> > dp(n+2,vector<ll>(n+2));
  vector<int> left(n+1),right(n+1);

  for(int i=1;i<=n;i++) 
  {
    cin >> v[i];
    d[v[i]] = i;
  }

  set<int> s; // Upper bound gives you the minimum of all the elements greater than this
  set<int,greater<int> > t; // Upper bound gives you the maximum of all elements smaller than this

  s.insert(+1e9);
  t.insert(-1e9);

  for(int i=1;i<=n;i++)
  {
    left[i] = *s.upper_bound(v[i]);
    s.insert(v[i]);
  }

  for(int i=n;i>0;i--)
  {
    right[i] = *t.upper_bound(v[i]);
    t.insert(v[i]);
  }

  t(left,right);
  dp[0][n+1] = 0;
  for(int sz=n+1;sz>=2;sz--)
  {
    for(int i=0;i<=n+2-sz;i++)
    {
      int j = sz+i-1;
      dp[i][j] = INF;
      if(i>0) 
      {
        // Right rotate to sort the ith guy and send him to the left
        // Right rotation is not necessary when
        int idx = d[i];
        if(left[idx]>=j)
        {
          dp[i][j] = min(dp[i][j],dp[i-1][j]);
        }
        else
        {
          dp[i][j] = min(dp[i][j],dp[i-1][j]+b);
        }
      }
      // t(i,j,dp[i][j]);
      if(j<=n) 
      {
        // Left rotate to sort the ith guy and send him to the right
        int idx = d[j];
        if(right[idx]<=i)
        {
          dp[i][j] = min(dp[i][j],dp[i][j+1]);
        }
        else dp[i][j] = min(dp[i][j],dp[i][j+1]+a);
      }
      // t(i,j,dp[i][j]);
    }
  }

  ll ans = INF;
  for(int i=0;i<=n;i++) ans = min(ans,dp[i][i+1]);

  cout << ans << endl;

  for(int i=0;i<=n+1;i++)
  {
    for(int j=i;j<=n+1;j++)
    {
      t(i,j,dp[i][j]);
    }
  }
  // t(dp.size());
  return 0; 
}

