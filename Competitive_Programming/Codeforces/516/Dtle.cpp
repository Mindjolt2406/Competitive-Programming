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

vector<string> v;
map<int,int> col;
map<int,vector<pair<int,int> > > store;
map<pair<int,int> ,int> check;
map<int,pair<int,int> > value;
int*visited1 ;

void addEdge(set<int>*adj,int  u,int v)
{
  adj[u].insert(v);
  adj[v].insert(u);
}

void bfs(set<int> adj[],int n,int root)
{
  set<int> :: iterator it;
  queue<int> q;
  q.push(root);
  // int n = adj.size();
  visited1 = (int*)calloc(n,sizeof(int));
  while(!q.empty())
  {
    int u = q.front();
    // cout<<"here1"<<endl;
    q.pop();
    // cout<<"u: "<<u<<endl;
    // cout<<value[u].first<<" "<<value[u].second<<endl;
    visited1[u] = 1;
    int a = col[u];
    int boo = 0;
    for(it = adj[u].begin();it!=adj[u].end();it++)
    {
      // cout<<"*it: "<<*it<<endl;
      pair<int,int> p;
      p.first = value[u].first;
      p.second = value[u].second;
      if(visited1[*it]==0)
      {
        // cout<<"this: "<<*it<<endl;
        if(col[*it]<a && p.first>0) p.first--;
        else if(col[*it]>a && p.second>0) p.second--;
        else {boo = q.empty();continue;}
        // cout<<"*it2: "<<*it<<endl;
        value[*it] = p;
        q.push(*it);
        visited1[*it] = 1;
      }
      // cout<<*it<<endl;
    }
    // cout<<"boo: "<<boo<<endl;
    if(boo) break;
  }
}

int main()
{
  int n,m;
  sc(n);sc(m);
  int a,b;
  sc(a);sc(b);
  a--;b--;
  int x,y;
  sc(x);sc(y);
  set<int>* adj = new set<int>[n*m+1];
  for(int i=0;i<n;i++)
  {
    string s;
    scr(s);
    v.pu(s);
  }
  // cout<<"suze: "<<v.size()<<endl;
  int**visited = (int**)calloc(n,sizeof(int*));
  for(int i=0;i<n;i++) visited[i] = (int*)calloc(m,sizeof(int));
  int counter = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j]=='.' && !visited[i][j])
      {
        visited[i][j] = 1;
        int k = i;
        while(k<n && v[k][j]=='.')
        {
          visited[k][j] = 1;
          store[counter].pu(mp(k,j));
          check[mp(k,j)] = counter;
          // cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
          if(j<m-1 && visited[k][j+1] && v[k][j+1]=='.') if(adj[counter].find(check[mp(k,j+1)]) !=adj[counter].end())(addEdge(adj,counter,check[mp(k,j+1)]);
          if(j>0 && visited[k][j-1] && v[k][j-1]=='.') if(adj[counter].find(check[mp(k,j-1)]) !=adj[counter].end()) addEdge(adj,counter,check[mp(k,j-1)]);
          k++;
        }
        col[counter] = j; 
        counter++;
      } 
    }
  }
  map<int,vector<pair<int,int> > > :: iterator it1;
  // for(it1 = store.begin();it1!=store.end();it1++)
  // {
  //   cout<<it1->first<<": ";
  //   for(int i=0;i<it1->second.size();i++) cout<<"("<<(it1->second)[i].first<<" "<<(it1 ->second)[i].second<<") ";cout<<endl;
  // }
  set<int> :: iterator it;
  // for(int i=0;i<counter;i++) 
  // {
  //   cout<<i<<": ";
  //   for(it = adj[i].begin();it!=adj[i].end();it++) cout<<*it<<" ";cout<<endl;
  // }
  // for(int i=0;i<9;i++) cout<<col[i]<<" ";cout<<endl;
  int n1 = counter;
  value[check[mp(a,b)]] = mp(x,y);
  // cout<<check[mp(a,b)]<<endl;
  // cout<<value[5].first<<" "<<value[5].second<<endl;
  // cout<<"here1"<<endl;
  bfs(adj,n1,check[mp(a,b)]);
  // cout<<"here2"<<endl;
  int count = 0;
  // for(int i=0;i<n1;i++) 
  // {
  //   cout<<"i: "<<i<<endl;
  //   if(visited1[i]) count+=(int)store[i].size();
  //   // cout<<"i: "<<i<<endl;
  //   // if(!store[visited1[i]].empty() && store.find(visited1[i])!=store.end()) count+=store[visited1[i]].size();
  // }
  for(it1 = store.begin();it1!=store.end();it1++)
  {
    if(visited1[it1->first]) count+=it1->second.size();
  }
  cout<<count<<endl;
  return 0;
}