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
#define scr(s) {char temp[1002];scanf("%s",temp);s = temp;}

using namespace std;

vector<pair<int,int> > adj[1000100];
int visited[1000100],store[1000100];

void bfs()
{
  deque<pair<int,int> > q;
  q.push_front(mp(0,0));
  store[0] = 0;
  while(!q.empty())
  {
    pair<int,int> p = q.front();
    q.pop_front();
    int u = p.first, b = p.second;
    // store[u] = b;
    visited[u] = 1;
    // cout<<u<<" "<<store[u]<<endl;
    for(int i=0;i<adj[u].size();i++)
    {
      if(store[adj[u][i].first] > store[u] + adj[u][i].second) 
      {
        store[adj[u][i].first] = min(store[adj[u][i].first],store[u] + adj[u][i].second);
        if(adj[u][i].second) q.push_back(mp(adj[u][i].first, adj[u][i].second+store[u]));
        else q.push_front(mp(adj[u][i].first, adj[u][i].second+store[u]));
      } 
    }
  }
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,m;
    sc(n);sc(m);
    vector<string> v;
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      v.pu(s);
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        int c = m*i+j;
        if(i>0 && v[i][j]!=v[i-1][j]) adj[c].pu(mp(c-m,1));
        else if(i>0) adj[c].pu(mp(c-m,0)); 
        if(j>0 && v[i][j]!=v[i][j-1]) adj[c].pu(mp(c-1,1));
        else if(j>0) adj[c].pu(mp(c-1,0));
        if(i<n-1 && v[i][j]!=v[i+1][j]) adj[c].pu(mp(c+m,1));
        else if(i<n-1) adj[c].pu(mp(c+m,0));
        if(j<m-1 && v[i][j]!=v[i][j+1]) adj[c].pu(mp(c+1,1));
        else if(j<m-1) adj[c].pu(mp(c+1,0)); 
      }
    }
    // for(int i=0;i<n*m;i++) 
    // {
    //   cout<<i<<": ";
    //   for(int j=0;j<adj[i].size();j++) cout<<adj[i][j].first<<" ";cout<<endl;
    // }
    for(int i=0;i<n*m;i++) store[i] = INF;
    bfs();
    // for(int i=0;i<n*m;i++) cout<<"i: "<<i<<" store: "<<store[i]<<endl;
    cout<<store[n*m-1]<<endl;
    for(int i=0;i<n*m;i++) {adj[i].clear();store[i] = 0;visited[i] = 0;}
  }
  return 0;
}

/*
1
3 6
spiltc
opoyir
nyblcq

*/