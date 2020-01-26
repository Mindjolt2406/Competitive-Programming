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
#define vi vector<int>
#define vll vector<long long int>
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

const int N = 3e5+10;
int sz[N] = {0};
int col[N] = {0};
int dp[N] = {0};
vector<int> adj[N] = {};

int dfs1(int u = 0,int p = -1)
{
 
  int boo = 1, count = 0;
  for(auto v : adj[u])
  {
    if(v-p) {boo = 0; count+=dfs1(v,u);}
  }
  count+=boo;
  sz[u] = count;
  return count;
}

void dfs2(int u,int p)
{
  vector<int> w;
  for(auto v : adj[u])
  {
    if(v-p) {dfs2(v,u); w.pu(dp[v]);}
  }

  if(col[u]==0)
  {
    sort(w.begin(),w.end());
    
  }
  else
  {
    int max1 = -1, max2 = -1;
    for(auto v : adj[u])
    {
      max1 = max(max1,dp[v]);
      if(max1==dp[v]) max2 = v;
    }
    dp[u] = max1+sz[u]-sz[max2];
  }
}

int main()
{
  __;
  
  return 0;
}

