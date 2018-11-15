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
  // cout<<"here"<<endl;
}


int main()
{
  int n,q;
  sc(n);sc(q);
  vector<int>*adj = new vector<int>[n];
  for(int h=0;h<q;h++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    addEdge(adj,a,b);
  }
  int*visited=  (int*)calloc(n,sizeof(int));
  // vector<int>     v;
  // dfs(adj,visited,0,-1,v);
  set<int> s,s1;
  s1.clear();
  // cout<<s1.size()<<endl;
  set<int> :: iterator it;
  // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++)
  {
    int boo = 1;
    int u = i;
    // cout<<"u: "<<u<<" s1.size(): "<<s1.size()<<endl;
    // cout<<"u: "<<u<<" adj[u].size(): "<<adj[u].size()<<endl;
    if(s1.find(u)!=s1.end()) {continue;}
    // cout<<"here"<<endl;
    for(int j=0;j<adj[u].size();j++)
    {
      // cout<<"u: "<<u<<" adj[u][j]: "<<adj[u][j]<<endl;
      if(s.find(adj[u][j])!=s.end()) {boo = 0;break;}
    }
    if(boo)
    {
      // cout<<"here"<<endl;
      for(int j=0;j<adj[u].size();j++) s1.insert(adj[u][j]);
      s.insert(u);
    }
  }
  cout<<s.size()<<endl;
  for(it = s.begin();it!=s.end();it++) cout<<*it+1<<" ";cout<<endl;
  return 0;
}
