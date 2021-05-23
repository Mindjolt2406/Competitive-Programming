#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000000
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

int n = 1;

int dfs(int u,int val,vector<int> &ans,vector<int> &par)
{
  // t(u,n,edge.size(),val);
  bool rootSum = false;
  if(val&1) 
  {
    rootSum = true;
    val--;
  }

  if(val == 0) {ans[u] = 1;return ans[u];}

  int cnt0 = 0;
  while((val&1) == 0) {cnt0++; val >>= 1;}

  par[n] = u;
  n++;
  int getSum = dfs(n-1,val,ans,par);
  // t(u,getSum);
  int orig_cnt0 = cnt0;
  while(cnt0--)
  {
    par[n] = u;
    // edge.pu(mp(u,n));
    ans[n] = getSum;
    par[n+1] = n;
    // edge.pu(mp(n,n+1));
    ans[n+1] = getSum;
    n+=2;
  }

  if(rootSum) ans[u] = (orig_cnt0+1)*getSum;
  else ans[u] = INF; // Should only happen for root

  return (orig_cnt0+1)*getSum;
}

int main()
{
  __;
  int k;
  cin >> k;
  vector<int> ans(1e5+10);
  vector<int> par(1e5+10);
  if(k == 1)
  {
    cout << 2 << endl;
    cout << 1 << endl;
    cout << INF << " " << 1 << endl;
    return 0;
  }
  dfs(0,k,ans,par);

  cout << n << endl;
  for(int i=1;i<n;i++) cout << par[i]+1 << " "; cout << endl;

  for(int i=0;i<n;i++) cout << ans[i] << " "; cout << endl;
  return 0;
}
