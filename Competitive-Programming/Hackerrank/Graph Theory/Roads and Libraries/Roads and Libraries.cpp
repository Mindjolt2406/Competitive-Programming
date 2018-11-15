#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<long long int>*adj,long long int u,long long int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

long long int dfs(vector<long long int>*adj,long long int* visited,long long int u,long long int key)
{
  if(visited[u]) return 0;
  visited[u] = key;
  long long int count = 1;
  for(long long int i=0;i<adj[u].size();i++)
  {
    count+=dfs(adj,visited,adj[u][i],key);
  }
  return count;
}

int main()
{
  long long int t;
  cin>>t;
  while(t--)
  {
    long long int n,q,cl,cr;
    cin>>n>>q>>cl>>cr;
    vector<long long int>*adj = new vector<long long int>[n];
    for(long long int h=0;h<q;h++)
    {
      long long int a,b;
      cin>>a>>b;
      a--;b--;
      addEdge(adj,a,b);
    }
    if(cl<=cr) cout<<cl*n<<endl;
    else
    {
      long long int* visited = (long long int*)calloc(n,sizeof(long long int));
      long long int key = 1,count = 0;
      for(long long int i=0;i<n;i++)
      {
        if(visited[i]==0) {count+=dfs(adj,visited,i,key);key++;}
      }
      // cout<<"count: "<<count-key+1<<" key: "<<key-1<<endl;
      cout<<((count-key+1)*cr + (key-1)*cl)<<endl;
    }
  }
}
