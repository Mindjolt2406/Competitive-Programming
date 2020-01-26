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

const int N = 1e5;
vector<int> adj[N] = {};
vector<int> vis(N);

bool check(int i,int j, int n,int m)
{
  if(i<0 || j<0 || i>=n || j>=m) return false;
  return true;
}

bool dfs(int u = 0,int p = -1)
{
  t(u,vis[u]);
  if(vis[u] == 1) return true;
  else if(vis[u]) return false;

  vis[u] = 1;

  bool is_cycle = false;
  for(auto v : adj[u])
  {
    if(v-p) is_cycle |= dfs(v,u);
    // is_cycle |= dfs(v,u);
  }

  vis[u] = 2;

  return is_cycle;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;

  int dx[8] = {0,0,1,1,1,-1,-1,-1};
  int dy[8] = {1,-1,1,0,-1,1,0,-1};

  vector<string> v(n);
  for(int i=0;i<n;i++)
  {
    cin >> v[i];
    for(int j=0;j<m;j++)
    { 
      if(v[i][j] != '#') continue;

      for(int k=0;k<8;k++)
      {
        int x = i + dx[k];
        int y = j + dy[k];
        if(check(x,y,n,m) && v[x][y] == '#')
        {
          // The other way round will be done automatically
          adj[i*n+j].pu(x*n+y);
          adj[x*n+y].pu(i*n+j);
          // t(i*n+j,x*n+y);
        }
      }
    }
  }

  int cnt = 0;
  for(int i=0;i<n*m;i++)
  {
    if(!vis[i]) 
    {
      cnt += dfs(i);
      // t(i,cnt);
    }
  }

  cout << cnt << endl;
  return 0;
}

