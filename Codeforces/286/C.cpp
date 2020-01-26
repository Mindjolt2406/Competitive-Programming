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

const int N = 3e4+20;

int dp[N][500] = {0};
bool is[N][500] = {0};
int d[N] = {0};
int max1 = -1;

int recur(int cur, int prev,int k)
{
  if(abs(k-prev)>246) return -1;
  if(prev <= 0) return -1;
  
  int j = prev-k+250;

  if(cur == 3e4) 
  {
    return d[(int)3e4];
  }
  else if(cur > 3e4) return 0;

  if(is[cur][j]) return dp[cur][j];
  else 
  {
    dp[cur][j] = 0;
    is[cur][j] = 1;
    dp[cur][j]+=d[cur];
  }

  // t(cur,prev);

  int ans = dp[cur][j];

  ans = max(ans,recur(cur+prev-1,prev-1,k)+d[cur]);
  ans = max(ans,recur(cur+prev,prev,k)+d[cur]);
  ans = max(ans,recur(cur+prev+1,prev+1,k)+d[cur]);

  dp[cur][j] = ans;
  // t(ans,cur,prev,dp[cur][j]);
  return dp[cur][j];
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<=N;i++) d[i] = 0;
  for(int i=0;i<n;i++) 
  {
    int a;
    cin >> a;
    d[a]++;
  }
  cout << recur(k,k,k) << endl;
  return 0;
}

