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

const int N = 4e5+10;
vector<int> adj[N] = {};
int vis[N] = {0};
int key = 1;

void dfs(int u,int p)
{
  vis[u] = key;
  for(auto v : adj[u]) if(v-p && !vis[v]) dfs(v,u);
}

int main()
{
  __;
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> v(n),ans(n);
  map<int,int> d;
  for(int i=0;i<n;i++) {cin>>v[i];d[v[i]] = i;}

  for(int i=0;i<n;i++)
  {
    int x = a-v[i], y = b-v[i], flag = 0;
    if(d.find(x)!=d.end() && d[x]!=d[v[i]]) 
    {
      adj[2*i].pu(2*d[x]);
      adj[2*d[x]+1].pu(2*i+1);
      flag++;
    }
    // else adj[2*i].pu(adj[2*i])

    if(d.find(y)!=d.end() && d[y]!=d[v[i]]) 
    {
      adj[2*i].pu(2*d[y]);
      adj[2*d[y]+1].pu(2*i+1);
      flag++;
    }
    // else ans[i] = 0;

    if(flag<2) {cout<<"NO"<<endl; return 0;}
  }

  for(int i=0;i<2*n;i++) 
  {
    cout<<i<<": ";
    for(auto v : adj[i]) cout<<v<<" "; cout<<endl;
  }

  for(int i=0;i<2*n;i++)
  {
    if(!vis[i] && adj[i].size()!=0) {dfs(i,-1);key++;}
  }

  for(int i=0;i<2*n;i++) cout<<vis[i]<<" "; cout<<endl;

  for(int i=0;i<2*n;i+=2)
  {
    if(vis[i]==vis[i+1]) {cout<<"NO"<<endl; return 0;}
  }

  cout<<"YES"<<endl;
  for(int i=0;i<2*n;i++) cout<<vis[i]<<" "; cout<<endl;
  for(int i=0;i<2*n;i+=2)
  {
    cout<<(vis[i]<vis[i+1])<< " ";
  }
  cout<<endl;
  return 0;
}

