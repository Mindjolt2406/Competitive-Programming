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


void dfs(int u,vector<vector<int> > &adj,vector<int> &vis,int key)
{
  vis[u] = key;
  for(auto v : adj[u]) if(!vis[v]) dfs(v,adj,vis,key);
}

pair<int,int>  dfs2(int u,vector<vector<int> > &adj2,vector<int> &vis2,vector<int> &counter,int col = 0)
{
  vis2[u] = col;
  pair<int,int> p = mp(0,0);
  if(col) p.se+= counter[u];
  else p.fi+=counter[u];
  for(auto v : adj2[u])
  {
    if(vis2[v]==-1) 
    {
      pair<int,int> q = dfs2(v,adj2,vis2,counter,col^1);
      p.fi += q.fi;
      p.se += q.se;
    }
  }
  return p;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    vector<vector<int> > adj(N), adj2(N);
    int key = 1;
    vector<int> vis(N),vis2(N,-1);
    vector<int> counter;
    int n;
    cin >> n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      for(int j=0;j<n;j++)
      {
        int x = i-j+n-1, y = i+j+2*n-1;
        if(s[j] == '.') 
        {
          adj[2*x+1].pu(2*y);
          adj[2*y].pu(2*x+1);
          adj[2*y+1].pu(2*x);
          adj[2*x].pu(2*y+1);
        }
        else 
        {
          adj[2*y+1].pu(2*x+1);
          adj[2*x+1].pu(2*y+1);
          adj[2*x].pu(2*y);
          adj[2*y].pu(2*x);
        }
      }
    }

    for(int i=0;i<8*n-4;i++)
    {
      if(!vis[i]) 
      {
        dfs(i,adj,vis,key);
        key++;
      }
      // t(i,vis[i]);
    }

    counter.resize(8*n);
    for(int i=0;i<8*n-4;i++) 
    {
      if(i&1) counter[vis[i]]++;
    }
    
    // for(int i=0;i<5;i++) t(i,counter[i]);
    for(int i=0;i<4*n-2;i++)
    {
      adj2[vis[2*i]].pu(vis[2*i+1]);
      adj2[vis[2*i+1]].pu(vis[2*i]); 
      // t(vis[2*i],vis[2*i+1]);
    }

    int cnt1 = 0, cnt2 = 0;
    int ans = 0;
    for(int i=0;i<8*n-4;i++)
    {
      if(vis2[vis[i]] == -1) 
      {
        pair<int,int> p = dfs2(vis[i],adj2,vis2,counter,0);
        ans += min(p.fi,p.se);
      }
      else continue;
    }

    cout << "Case #"<< h << ": " << ans << endl;

    // for(int i=0;i<N;i++)
    // {
    //   adj[i].clear();
    //   adj2[i].clear();
    // }

    // key = 1;

    // counter.clear();
    // vis.resize(N,0);
    // vis2.resize(N,-1);
  }
  return 0;
}

/*
1
5
.####
#.###
##.##
###.#
#####

*/