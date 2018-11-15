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

pair<int,int> add(pair<int,int>p1,pair<int,int> p2,int odd,int even)
{
  return mp(p1.first+p2.first-odd,p1.second+p2.second-even);
}

pair<int,int> dfs(vector<int>*adj,int*visited,int*store,int u,int parent,int odd,int even,int*l,int*m,vector<int>&v)
{
  visited[u] = 1;
  int level = store[u];
  if(level%2==1)
  {
    if(l[u]!=m[u] ^ odd%2==1) {odd++;v.pu(u);}
  }
  else 
  {
    if(l[u]!=m[u] ^ even%2==1) {even++;v.pu(u);}
  }
  pair<int,int> p = mp(odd,even);
  int a = p.first,b = p.second;
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]!=parent && !visited[adj[u][i]]) p = add(p,dfs(adj,visited,store,adj[u][i],u,a,b,l,m,v),a,b);
  }
  return p;
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
    adj[a].pu(b);
    adj[b].pu(a);
  }
  int l[n],m[n];
  for(int i=0;i<n;i++) sc(l[i]);
  for(int i=0;i<n;i++) sc(m[i]);
  int*visited = (int*)calloc(n,sizeof(int));
  int* store = (int*)calloc(n,sizeof(int));
  queue<int> q;
  int even = 0,odd= 0,level = 1;
  q.push(0);
  q.push(-1);
  visited[0] = 1;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u==-1 && !q.empty()) {level++;q.push(-1);continue;}
    else if(u==-1) break;
    visited[u] = 1;
    store[u] = level;
    for(int i=0;i<adj[u].size();i++)
    {
      if(!visited[adj[u][i]]) 
      {
        q.push(adj[u][i]);
        visited[adj[u][i]] = 1;
      }
    }
  }
  for(int i=0;i<n;i++) visited[i] = 0;
  vector<int> v;
  pair<int,int> p = dfs(adj,visited,store,0,-1,0,0,l,m,v);
  cout<<p.first+p.second<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]+1<<endl;
  return 0;
}

