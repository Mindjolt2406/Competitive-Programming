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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

map<int,int> d;

void bfs(vector <int> adj[],int n,vector<int>&v,int start)
{
  queue<int> q;
  q.push(start);
  // cout<<"start: "<<start<<endl;
  d[start] = start-1;
  int count = 1;
  v.pu(-1);
  int* visited = (int*)calloc(n,sizeof(int));
  while(!q.empty())
  {
    int u = q.front();
    // cout<<"u: "<<u<<" d[u]: "<<d[u]<<endl;
    visited[u] = 1;
    // v.pu(d[u]);
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      if(visited[adj[u][i]]==0){q.push(adj[u][i]);visited[adj[u][i]] = 1;d[adj[u][i]] = u;v.pu(u);}
    }
    count++;
  }
}

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int main()
{
  int n;
  sc(n);
  vector<int>*adj = new vector<int>[n];
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    addEdge(adj,a,b);
  }
  int*visited = (int*)calloc(n,sizeof(int));
  vector<int> v;
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  // for(int i=0;i<n;i++) visited[l[i]-1] = 1;
  // int boo1 = 1;
  // for(int i=0;i<n;i++) if(visited[i]!=1) {boo1 = 0;break;}
  // if(!boo1) {cout<<"No"<<endl;return 0;}
  bfs(adj,n,v,l[0]-1);
  // cout<<"here"<<endl;
  // for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
  vector<int> v1;
  v1.pu(-1);
  for(int i=0;i<n;i++)
  {
    cout<<"i: "<<i<<" size: "<<adj[l[i]].size()<<endl;
    if(i==0) for(int j=0;j<adj[i].size();j++) v1.pu(d[l[i]]);
    else for(int j=0;j<adj[i].size()-1;j++) v1.pu(d[l[i]]);
  }
  for(int i=0;i<n;i++) l[i] = d[l[i]-1];
  // for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
  int boo = 1;
  for(int i=0;i<n;i++)
  {
    if(v[i]!=v1[i]) {boo = 0;break;}
  }
  for(int i=0;i<n;i++) cout<<v1[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++) cout<<v[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<d[v[i]]<<" ";cout<<endl;
  if(boo) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
