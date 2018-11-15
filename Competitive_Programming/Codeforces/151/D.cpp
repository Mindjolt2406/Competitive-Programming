#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int min1(int*colour,int n)
{
  int min2 = 10000000;
  for(int i=0;i<n;i++)min2 = min(min2,colour[i]);
  return min2;
}

// void dfs(vector<int>*adj,int*visited,int*colour,int*add,int u)
// {
//   if(visited[u]) return;
//   visited[u] = 1;
//   for(int i=0;i<adj[u].size();i++)
//   {
//     if(colour[adj[u][i]]!=colour[u]) {add[colour[u]]++;add[colour[adj[u][i]]]++;}
//     dfs(adj,visited,colour,add,adj[u][i]);
//   }
// }

int main()
{
  int n,q;
  cin>>n>>q;
  int colour[n];
  set<int> *add = new set<int>[100001];
  for(int i=0;i<n;i++) cin>>colour[i];
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    // addEdge(adj,a,b);
    if(colour[a]!=colour[b])add[colour[a]].insert(colour[b]);
    if(colour[a]!=colour[b])add[colour[b]].insert(colour[a]);
  }
  int max1 = 0;
  for(int i=0;i<100001;i++) max1 = max(max1,(int)add[i].size());
  if(max1==0) cout<<min1(colour,n)<<endl;
  else for(int i=0;i<100001;i++) if(max1==add[i].size()){cout<<i<<endl;break;}
  return 0;
}
