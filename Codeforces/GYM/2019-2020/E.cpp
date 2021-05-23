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

const int N = 2e5+10;
vector<vector<int> > adj(N);
vector<int> par(N);
vector<int> depth(N);

void dfs(int u,int dest,int p = -1)
{
  par[u] = p;
  if(u == dest) return;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      dfs(v,dest,u);
    }
  }
}

void dfs2(int u = 0,int p = -1)
{
  if(p != -1) depth[u] = depth[p]+1;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      dfs2(v,u);
    }
  }
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;


  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }
  
  vector<int> v(k);
  for(int i=0;i<k;i++) cin >> v[i];
  for(int i=0;i<k;i++) v[i]--;

  if(k == 1) {cout << "YES" << endl;cout << 1 << endl; return 0;}

  dfs(v[0],v[1]);

  int dest = v[1];
  vector<int> path;
  while(dest != v[0])
  {
    path.pu(dest);
    dest = par[dest];
  }
  path.pu(dest);
  // t(path);
  if(path.size()%2 == 0) cout << "NO" << endl;
  else
  {
    dfs2(path[path.size()/2]);
    int temp = depth[v[0]];
    bool flag = true;
    for(auto it : v)
    {
      if(depth[it] != temp) flag = false;
    }

    if(flag) 
    {
      cout << "YES" << endl;
      cout << path[path.size()/2]+1 << endl;
    }
    else cout << "NO" << endl;

  }
  return 0;
}

/*
6 3
1 2
2 3
3 4
4 5
4 6
1 5 6

9 4
1 2
2 3
3 4
4 5
3 6
3 8
6 7
8 9
1 5 7 8


*/
