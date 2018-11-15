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

int dfs(vector < int > *adj,int u,int visited[],int *key)
{
  if(visited[u]!=0) return INF;
  // cout<<u<<" ";
  vector<int> v;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    v.pu(dfs(adj,adj[u][i],visited,key));
  }
  if(v.size()==1 && v[0]==INF) 
  {
    // d[1]--;
    key[u] = 1;return 1;
  }
  else
  {
    sort(v.begin(),v.end());
    int count = 1;
    for(int i=0;i<v.size();i++)
    {
      if(v[i]==count) count++; 
      // while(d[count]==0) count++; 
    }
    // d[count]--;
    key[u] = count;
    return count;
  }
}

int main()
{
  cout<<"here"<<endl;
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n;
    sc(n);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    int*visited = (int*)calloc(n+1,sizeof(int));
    int*key = (int*)calloc(n+1,sizeof(int));
    vector<int>*adj = new vector<int>[n+1];
    cout<<"here"<<endl;
    // map<int,int> d;
    // for(int i=1;i<=n;i++) d[i] = n;
    for(int i=1;i<n;i++)
    {
      addEdge(adj,i+1,l[i]);
    }
    cout<<"here"<<endl;
    dfs(adj,1,visited,key);
    cout<<"jere"<<endl;
    ll sum1 = 0;
    for(int i=1;i<=n;i++) sum1+=key[i];
    // for(int i=1;i<=n;i++) cout<<key[i]<<" ";cout<<endl;
    printf("Case #%d: %lld\n",h,sum1);
  }
  return 0;
}
