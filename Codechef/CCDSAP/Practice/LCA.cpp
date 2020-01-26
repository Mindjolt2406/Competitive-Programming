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
#define ll long long int
#define ld long double
#define fi first
#define se second
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

const int N = 2e5+10;
const int LOG = 32;
int parent[N][LOG] = {0}; // Initialise this to -1 in main
int height[N] = {0};
vector<int> adj[N] = {};

void dfs(int u,int p = -1)
{
  if(p+1) height[u] = height[p]+1;
  parent[u][0] = p;

  // Make the array for u
  for(int i=1;i<LOG;i++)
  {
    if(parent[u][i]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }

  for(auto v : adj[u]) if(p-v) dfs(v,u);
}

int LCA(int u,int v)
{
  if(height[u]>height[v]) swap(u,v);

  // Make the heights of u and v equal
  int i=LOG;
  for(int i=LOG-1;i>=0;i--)
  {
    while(parent[v][i]+1 && height[parent[v][i]]>=height[u]) v = parent[v][i];
  }

  if(u==v) return u;
  for(int i=LOG-1;i>=0;i--)
  {
    while(parent[u][i]!=parent[v][i])
    {
      v = parent[v][i];
      u = parent[u][i];
    }
  }

  return parent[u][0];
}

int main()
{
  __;
  for(int i=0;i<N;i++) for(int j=0;j<LOG;j++) parent[i][j] = -1;
  return 0;
}

