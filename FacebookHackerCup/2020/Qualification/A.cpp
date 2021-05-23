#include<bits/stdc++.h>
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

bool dfs(vector<vector<bool> > &adj,vector<bool> &vis,int u = 0,int target = 0)
{
  vis[u] = true;
  if(u == target) return true;
  bool flag = false;
  for(int v = 0;v<adj.size();v++)
  {
    if(adj[u][v] && !vis[v])
    {
      flag |= dfs(adj,vis,v,target);
    }
  }

  return flag;
} 

void solve()
{
  int n;
  cin >> n;
  string in,out;
  cin >> in >> out;
  vector<string> ans(n);
  vector<vector<bool> > adj(n,vector<bool>(n,false));
  for(int i=0;i<n;i++)
  {
    if(in[i] == 'Y')
    {
      if(i>0 && out[i-1] == 'Y') adj[i-1][i] = true;
      if(i+1 != n && out[i+1] == 'Y') adj[i+1][i] = true;
    }
    if(out[i] == 'Y')
    {
      if(i>0 && in[i-1] == 'Y') adj[i][i-1] = true;
      if(i+1 != n && in[i+1] == 'Y') adj[i][i+1] = true;
    }
  }

  // t(adj);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      vector<bool> vis(n);
      if(dfs(adj,vis,i,j)) ans[i] += 'Y';
      else ans[i] += 'N';
    }
  }

  for(auto it : ans) cout << it << endl;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": " << endl;
    solve();
  }
  return 0;
}
