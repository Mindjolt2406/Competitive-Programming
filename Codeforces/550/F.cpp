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

const int N = 2e5+10;
vector<int> adj[N];
int vis[N] = {0};
bool flag = false;

void dfs(int u = 0)
{
  for(auto v : adj[u])
  {
    if(vis[v]==-1) 
    {
      vis[v] = vis[u]^1;
      dfs(v);
    }
    else if(vis[v]!=vis[u]) continue;
    else flag = true;
  }
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  string s;
  vector<pair<int,int> > v;
  for(int i=0;i<n;i++) vis[i] = -1;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    v.pu(mp(a,b));
    adj[a].pu(b);
    adj[b].pu(a);
  }
  vis[0] = 0;
  dfs();
  if(flag) cout<<"NO"<<endl;
  else 
  {
    cout<<"YES"<<endl;
    for(int i=0;i<v.size();i++)
    {
      int a = v[i].fi, b = v[i].se;
      if(vis[a]==0) s+="0";
      else s+="1";
    }
    cout<<s<<endl;
  }
  return 0;
}

