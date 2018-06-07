#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

vector < pair<int,int> > *adj;
vector < pair<int,int> > *tree;
int* size;
int* colour;
int* visited;
int n;

void printsize()
{
  for(int i=0;i<n;i++) cout<<size[i]<<" ";
  cout<<endl;
}

void addEdge(int u,int v, int key)
{
  adj[u].pu(m(v,key));
  adj[v].pu(m(u,key));
  // cout<<adj[u].back().first<<" "<<adj[u].back().second<<endl;
}

int dfs(int u)
{
  if(visited[u]!=0) return 0;
  cout<<u<<" ";
  visited[u] = 1;
  int count = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    count+=dfs(adj[u][i].first);
  }
  size[u] = count;
  return count;
}

int main()
{
  cin>>n;
  adj = new vector < pair <int,int> >[n];
  for(int i=0;i<n-1;i++)
  {
    int a,b,key;
    cin>>a>>b>>key;
    a--;b--;
    addEdge(a,b,key);
  }
  size = new int[n];
  colour = new int[n];
  for(int i=0;i<n;i++) colour[i] = i; //Initializing the colour array
  visited = (int*)calloc(n,sizeof(int));
  dfs(0);
  cout<<endl;
  return 0;
}

/*
12
2 1 98
3 2 53
2 4 80
2 5 61
1 6 87
2 7 44
4 8 90
3 9 64
4 10 98
2 11 84
2 12 69

*/
