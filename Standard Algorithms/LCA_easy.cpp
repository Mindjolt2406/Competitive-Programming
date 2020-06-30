const int N = 2e5+1;
vector<int> adj[N] = {};
int MAXLOG = 25;
vector<vector<int> >  parent(N,vector<int>(MAXLOG,-1));
int height[N] = {0};


void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  if(p+1) height[u] = height[p]+1;
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(p-v) dfsLCA(v,u);
}

int LCA(int u,int v)
{
  // height means depth here
  if(height[v]>height[u]) swap(u,v);

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) u = parent[u][i];
  }

  // height[u]==height[v]
  if(u==v) return u;
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i]) 
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[v][0];
}

int main()
{
  // __;
  int n;
  cin>>n;
  for(int i=0;i<n;i++) for(int j=0;j<25;j++) parent[i][j] = -1;
  for(int i=0;i<n;i++) 
  {
    int m;
    cin>>m;
    for(int j=0;j<m;j++)
    {
      int a;
      cin>>a;
      adj[i].pu(a);
      adj[a].pu(i);
    }
  }
  dfs(0);
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int a,b;
    cin>>a>>b;
    printf("%d\n",LCA(a,b));
  }
  return 0;
}