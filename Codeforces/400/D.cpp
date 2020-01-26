/*
Rathin Bhargava
IIIT Bangalore

*/
// Be careful of n's and m's in these 2-SAT problems
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

const int N = 5e5;
vector<int> adj[N] = {};
vector<int> vis(N);
int key = 1;

void dfs(int u,int p) // Giving each vertex the color of the component they belong to
{
  vis[u] = key;
  for(auto v : adj[u]) if(v-p && !vis[v]) dfs(v,u);
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<vector<int>  > w(n);
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a;
    for(int j=0;j<a;j++) 
    {
      int b;
      cin>>b;
      b--;
      w[b].pu(i);
    }

  }

  // Making the graph
  for(int i=0;i<n;i++)
  {
    int b = w[i][0], c = w[i][1];
    // t(b,c);
    if(v[i])
    {
      adj[2*b].pu(2*c);
      adj[2*c].pu(2*b);
      adj[2*c+1].pu(2*b+1);
      adj[2*b+1].pu(2*c+1);
    }
    else
    {
      adj[2*b].pu(2*c+1);
      adj[2*c].pu(2*b+1);
      adj[2*c+1].pu(2*b);
      adj[2*b+1].pu(2*c);
    }
  }

  // for(int i=0;i<2*m;i++) 
  // {
  //   cout<<i<<": ";
  //   for(auto v : adj[i]) cout<<v<<" "; cout<<endl;
  // }

  for(int i=0;i<2*m;i++)
  {
    if(!vis[i]) {dfs(i,-1); key++;}
  }

  // for(int i=0;i<2*m;i++) cout<<vis[i]<<" "; cout<<endl;

  for(int i=0;i<m;i++)
  {
    int a = i<<1, b = (i<<1) +1;
    if(vis[a]==vis[b]) {cout<<"NO"<<endl; return 0;}
  }

  cout<<"YES"<<endl;

  return 0;
}

