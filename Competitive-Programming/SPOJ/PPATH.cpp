// Decent question, make a graph by taking all the primes and using brute force.
// Then do a BFS to find the shortest path as the edges are unweighted
// However, I mainly messed up in adding the counter to find the shortest path
// The 'NULLS' or in this case the -1, to diffrentiate between levels, should be added right after the -1
// has been crossed, not after the first node's children have been added
// I had to go to spoj's toolkit, and pick up a testcase to realize this mistake
// This is bad
// Debugging became too difficult as the data set was huge
// I should have isolated the bfs, and should've tried finding the shortest path on simple graphs
// My main mistakes till now are (which I can't see)
// 1. Not allocating memory properly(writing n instead of m) -> Causes spooky acion at a distance
// 2. Assuming some incorrect logical axioms
// 2 will be a really hard problem to overcome in the future

#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void sieve(int *l)
{
  for(int i=2;i<10000;i++)
  {
    if(l[i]==1) continue;
    else
    {
      for(int j=2*i;j<10000;j+=i) l[j] = 1;
    }
  }
}

int score(string a,string b)
{
  int count = 0;
  for(int i=0;i<4;i++) if(a[i]==b[i]) count++;
  return count;
}

void addEdge(vector<int> *adj, int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int bfs(vector<int> *adj,int*visited,int u,int v)
{
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  int count = 0,boo = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u==-1) {count++;boo = 0;}
    else if(u==v) {return count;}
    else
    {
      if(!boo) {q.push(-1);boo = 1;}
      for(int i=0;i<adj[u].size();i++)
      {
        if(!visited[adj[u][i]]) {q.push(adj[u][i]);visited[adj[u][i]] =1;}
      }
    }
  }
  return -1;
}

int main()
{
  int l[10000] = {0};
  l[0] = 1;l[1] = 1;l[2] = 0;l[3] = 0;
  sieve(l);
  vector<int> v;
  map <int,int> d;
  for(int i=0;i<10000;i++)
  {
    if(l[i]==0 && i/1000>=1) {v.pu(i);d[i] = v.size()-1;}
    else d[i] = -1;
  }
  int n = v.size();
  vector<int> *adj = new vector<int>[10000];
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      string a= to_string(v[i]);
      string b= to_string(v[j]);
      if(score(a,b)==3) addEdge(adj,i,j);
    }
  }
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int*visited = (int*)calloc(10000,sizeof(int));
    int a,b;
    cin>>a>>b;
    int c = 0;
    if(d[a]==-1 || d[b]==-1) c = -1;
    if(a!=b) c = bfs(adj,visited,d[a],d[b]);
    if(c==-1) cout<<"Impossible"<<endl;
    else cout<<c<<endl;
  }
  return 0;
}

/*
1 1009 9973

*/
