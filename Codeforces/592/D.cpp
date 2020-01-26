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

const int N = 1e5+100;
vector<int> adj[N] = {};
vector<vector<ll> > dp(N);

int main()
{
  __;
  int n;
  cin >> n;
  vector<ll> x(n),y(n),z(n);
  for(int i=0;i<n;i++) cin >> x[i];
  for(int i=0;i<n;i++) cin >> y[i];
  for(int i=0;i<n;i++) cin >> z[i];

  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;

    adj[a].pu(b);
    adj[b].pu(a);
  }

  int cnt1 = 0;
  for(int i=0;i<n;i++) 
  {
    // t(i,adj[i].size());
    if(adj[i].size()==1) cnt1++;
    if(adj[i].size()>2) {cout << -1 << endl; return 0;}
  }
  // t(cnt1);
  if(cnt1 != 2){cout << -1 << endl; return 0;}

  int left = -1;
  for(int i=0;i<n;i++) if(adj[i].size()==1) {left = i; break;}

  vector<int> vert;
  int parent = -1;
  for(int i=0;i<n;i++)
  {
    vert.pu(left);
    if(adj[left].size()==1) {parent = left;left = adj[left][0];}
    else 
    {
      parent = adj[left][0] + adj[left][1] - parent;
      swap(left,parent);
    }
  }

  // _;
  // t(vert);
  int first = vert[0];
  dp[first] = {y[first],z[first],x[first],z[first],x[first],y[first]};
  // back[ first].pu({-1,-1,-1,-1,-1,-1});
  vector<int> back = {4,2,5,0,3,1};

  for(int i=1;i<vert.size();i++)
  { 
    // t(i);
    vector<ll> temp(6);
    int idx = vert[i];
    int prev = vert[i-1];
    // t(idx,prev);
    temp[0] = dp[prev][4] + y[idx];
    temp[1] = dp[prev][2] + z[idx];
    temp[2] = dp[prev][5] + x[idx];
    temp[3] = dp[prev][0] + z[idx];
    temp[4] = dp[prev][3] + x[idx];
    temp[5] = dp[prev][1] + y[idx];
    dp[idx] = temp;
  }

  vector<int> ans(n);
  ll min1 = 1e18,min2 = 7;
  for(int i=0;i<6;i++) 
  {
    if(dp[vert[vert.size()-1]][i] < min1) 
    {
      min1 = dp[vert[vert.size()-1]][i];
      min2 = i;
    }
  }

  ll cost = min1;
  int back_idx = min2;
  for(int i=vert.size()-1;i>=0;i--)
  {
    int idx = vert[i];
    if(back_idx == 0 || back_idx == 5) ans[idx] = 1;
    if(back_idx == 1 || back_idx == 3) ans[idx] = 2;
    if(back_idx == 2 || back_idx == 4) ans[idx] = 0;
    back_idx = back[back_idx];
  }

  cout << cost << endl;
  for(int i=0;i<n;i++) cout << ans[i] + 1 << " ";
  cout << endl;

  return 0;
}

