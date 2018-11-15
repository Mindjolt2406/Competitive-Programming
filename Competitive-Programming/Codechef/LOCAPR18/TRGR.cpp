#include<bits/stdc++.h>
using namespace std;

vector < pair<int,int> > *edge;
int* visited;

void addEdge(int u,int v,int key,vector <int>adj[])
{
  adj[u].pu(m(v,key));
  adj[v].pu(m(u,key));
}

void dfs(vector <int>adj[],int u,int* colour, int* number, )
{
  if(visited[u]!=0) return;
  cout<<u<<" ";
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    dfs(adj,adj[u][i]);
  }
}

int connected(vector <int> adj[], pair <int,int> p, colour, int* number, list<int> refer[],int components)
{
  int a = p.first, b = p.second;
  addEdge(adj,a,b);
  if(colour[a]!=colour[b])
  {
    // Colour all vertices whose size is smaller
    list <int> :: iterator it;
    int d = colour[a],e = colour[b];
    if(number[d]>number[e])
    {
      for(it = refer[e].begin();it!=refer[e].end();it++) colour[*it] = d;
      number[d]+=number[e];
      number[e] = 0;
      refer[d].splice(refer[d].end(),refer[e]);
    }
    else
    {
      for(it = refer[d].begin();it!=refer[d].end();it++) colour[*it] = e;
      number[e]+=number[d];
      number[d] = 0;
      refer[e].splice(refer[e].end(), refer[d]);
    }
    return components-1;
  }
  return components;
}

int main()
{
  edge = new
}
