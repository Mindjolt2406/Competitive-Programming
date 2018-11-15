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

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

ll dfs(vector <int> *adj,int u,int *visited,int parent, int**dp,int k)
{
  // dp[i][j] =  number of vertices in the subtree rooted at i at a distance j from i
  if(visited[u]!=0) return 0;
  dp[u][0]++;
  visited[u] = 1;
  ll count = 0;
  for(int i=0;i<adj[u].size();i++)
  {
    if(visited[adj[u][i]]==0) 
    {
      count+= dfs(adj,adj[u][i],visited,u,dp,k);
      dp[u][1]++;
      for(int j=2;j<=k;j++)
      {
        dp[u][j]+= dp[adj[u][i]][j-1];
      }
    }
  }

  count+=dp[u][k];
  ll c = 0;
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]==parent) continue;
    for(int j=1;j<k;j++)
    {
      c+=(dp[adj[u][i]][k-j-1]*(dp[u][j]-dp[adj[u][i]][j-1]));
    }
  }
  c/=2;
  count+=c;
  return count;
  // ll count2 = 0,count1 = 0;
  // for(int i=0;i<adj[u].size();i++)
  // {
  //   if(adj[u][i]==parent) continue;
  //   for(int j=1;j<=k;j++)
  //   {
  //     dp[u][j] -= dp[adj[u][i]][j-1];
  //   }
  //   for(int j=1;j<=(k)/2;j++)
  //   {
  //     if(j==k/2 && k%2==0) count2 += dp[u][j]*dp[adj[u][i]][k-j-1];
  //     else count1+= dp[u][j]*dp[adj[u][i]][k-j-1];
  //   }
  //   for(int j=1;j<=k;j++)
  //   {
  //     dp[u][j] += dp[adj[u][i]][j-1];
  //   }
  // }
  // count2/=2;
  // count+=count2;
  // count1+=dp[u][k];
  // count+=count1;
}

int main()
{
  int n,k;
  sc(n);sc(k);
  vector<int>*adj = new vector<int>[n];
  int**dp = new int*[n];
  for(int i=0;i<n;i++) dp[i] = new int[k+1];
  for(int i=0;i<n;i++) for(int j=0;j<=k;j++) dp[i][j] = 0;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    addEdge(adj,a,b);
  }
  int* visited = (int*)calloc(n,sizeof(int));
  ll count = dfs(adj,0,visited,-1,dp,k);
  cout<<count<<endl;
  return 0;
}
