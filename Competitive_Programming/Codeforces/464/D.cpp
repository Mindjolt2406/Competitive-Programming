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

void addEdge(vector<int>*adj,int u,int v,int*visited1)
{
  visited1[u] = 1;visited1[v] = 1;
  // cout<<"u: "<<u<<" v: "<<v<<endl;
  adj[u].pu(v);
  adj[v].pu(u);
}

void dfs(vector<int>*adj,int u,int*visited,int key)
{
  if(visited[u]) return;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++)
  {
    dfs(adj,adj[u][i],visited,key);
  }
}

int main()
{
  int n;
  sc(n);
  string s1,s2;
  scr(s1);scr(s2);
  set<pair<int,int> > s;
  set<pair<int,int> > :: iterator it;
  for(int i=0;i<n;i++)
  {
    int a = s1[i]-'a';
    int b = s2[i]-'a';
    pair<int,int> p = mp(min(a,b),max(a,b));
    s.insert(p);
  }
  vector<int>*adj = new vector<int>[26];
  int*visited1 = (int*)calloc(26,sizeof(int));
  for(it = s.begin();it!=s.end();it++)
  {
    addEdge(adj,(*it).first,(*it).second,visited1);
  }
  int*visited = (int*)calloc(26,sizeof(int));
  int key = 1;
  for(int i=0;i<26;i++)
  {
    if(visited[i]==0 && visited1[i])
    {
      dfs(adj,i,visited,key);
      key++;
    }
  }
  // for(int i=0;i<26;i++) cout<<visited[i]<<" ";cout<<endl;
  // map<int,int> d;
  map<int,vector<int> > d;
  map<int,vector<int> > :: iterator it1;
  for(int i=0;i<26;i++)
  {
    if(visited[i]) d[visited[i]].pu(i);
  }
  int count = 0;
  for(it1 = d.begin();it1!=d.end();it1++)
  {
    if(it1->first==0) continue;
    count+=(it1)->second.size()-1;
  }
  cout<<count<<endl;
  for(it1 = d.begin();it1!=d.end();it1++)
  {
    if(it1->first==0) continue;
    vector<int> v = it1->second;
    for(int i=1;i<v.size();i++)
    {
      cout<<(char)(v[i-1]+'a')<<" "<<(char)(v[i]+'a')<<endl;
    }
  }
  return 0;
}
