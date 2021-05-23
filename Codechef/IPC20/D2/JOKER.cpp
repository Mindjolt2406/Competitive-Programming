#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 1e5+10;
vector<int> adj[N];
vector<int> w(N);
vector<int> maxVal(N,-INF);
vector<int> ans(N);

void dfs(int u = 0, int p = -1)
{
  for(auto v : adj[u])
  {
    if(v-p)
    {
      dfs(v,u);
      maxVal[u] = max(maxVal[u],maxVal[v]);
    }
  }

  ans[u] = w[u] - maxVal[u];
  maxVal[u] = max(w[u],maxVal[u]);
  return;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> par(n);
  int root = -1;

  for(int i=0;i<n;i++) cin >> w[i];
  for(int i=0;i<n;i++) cin >> par[i];

  int rootNum = 0;
  for(int i=0;i<n;i++)
  {
    if(par[i] == -1) 
    {
      rootNum++;
      root = i;
    }
    else
    {
      adj[i].pu(par[i]-1);
      // adj[par[i]-1].pu(i);
    }
  }

  // if(rootNum > 1) while(true) {}
  // dfs(root);

  // int minAns = INF;
  // for(int i=0;i<n;i++) minAns = min(minAns,ans[i]);

  // cout << minAns << endl;

  // for(int i=0;i<n;i++) w[i] = maxVal[i] = ans[i] = 0;
  // for(int i=0;i<n;i++) adj[i].clear();
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }  
  return 0;
}
