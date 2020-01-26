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

const int N = 1e5;
vector<int> adj[N] = {};
vector<int> vis(N);
vector<int> val(N);
int key = 1;

void dfs(int u,int p=-1)
{
  vis[u] = key;
  for(auto v : adj[u]) if(v-p && vis[v]!=key) dfs(v,u);
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  while(m--)  
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;

    if(c==0)
    {
      adj[2*a].pu(2*b+1);
      adj[2*b+1].pu(2*a);
      adj[2*a+1].pu(2*b);
      adj[2*b].pu(2*a+1);
    }
    else
    {
      adj[2*a].pu(2*b);
      adj[2*b].pu(2*a);
      adj[2*a+1].pu(2*b+1);
      adj[2*b+1].pu(2*a+1);
    }
  }

  for(int i=0;i<2*n;i++)
  {
    if(!vis[i]) 
    {
      dfs(i);
      key++;
    }
  }

  int boo = 0;
  for(int i=0;i<2*n;i+=2)
  {
    if(vis[i]==vis[i+1]) {boo = 1; break;}
    else
    {
      if(vis[i]<vis[i+1]) val[i/2] = 1;
      else val[i/2] = 0;
    }
  }

  // for(int i=0;i<2*n;i++) cout<<vis[i]<<" "; cout<<endl;
  // for(int i=0;i<n;i++) cout<<val[i]<<" "; cout<<endl;
  if(boo) cout<<"Impossible"<<endl;
  else
  {
    vector<int> ans;
    for(int i=0;i<n;i++) if(val[i]) ans.pu(i+1);
    cout<<ans.size()<<endl;
    pr(ans);
  }

  // for(int i=0;i<2*n;i++) cout<<vis[i]<<" "; cout<<endl;
  return 0;
}

