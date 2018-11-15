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
  // cout<<"u: "<<u<<" v: "<<v<<endl;
  adj[u].pu(v);
}

int dfs(vector<int>*adj,int*visited,int*sum,int*ans,int u)
{
  // cout<<"u: "<<u<<endl; 
  if(visited[u]==1) return ans[u];
  visited[u] = 1;
  if(adj[u].size()==0) {ans[u] = 1;return 1;}
  int count = 1,sum1 = 1;ds
  for(int i=0;i<adj[u].size();i++)
  {
    count+=dfs(adj,visited,ans,adj[u][i]);
    sum1+=ans[adj[u][i]];
    count%=MOD;
    sum1%=MOD;
  }
  ans[u] = count; 
  // sum[u] = sum1;
  return count;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    bitset<1000000> bs;
    bs.reset();
    vector<int>*adj = new vector<int>[750001];
    for(int i=0;i<n;i++) {sc(l[i]);bs[l[i]] = true;}
    for(int i=0;i<n;i++)
    {
      int j = 2*l[i];
      while(j<=750000)
      {
        if(bs[j]) {addEdge(adj,l[i],j); break;}
        j+=l[i];
      }
    }
    int*visited = (int*)calloc(750001,sizeof(int));
    int*sum = (int*)calloc(750001,sizeof(int));
    int*ans = (int*)calloc(750001,sizeof(int));
    sort(l,l+n);
    for(int i=0;i<n;i++)
    {
      if(visited[l[i]]==0)
      {
        dfs(adj,visited,sum,ans,l[i]);
      }
    }
    // for(int i=0;i<n;i++) cout<<ans[l[i]]<<" ";cout<<endl;
    int sum1 = 0;
    for(int i=0;i<n;i++)
    {
      sum1+=ans[l[i]];
      sum1%=MOD;
    }
    cout<<sum1<<endl;
    
  }
  return 0;
}

