/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

const int N = 100100;
int p[N], sz[N];

void create(int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x,int y){
	x = find(x), y = find(y);
	if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

int dfs(vector<int>*adj, vector<int>&visited, int root,vector<int> &counter, vector<int>& boo)
{
  // t(root);
  if(visited[root]==1 && boo[root]==1) return -1;
  else if(visited[root]==1) return counter[root];
  visited[root] = 1;
  boo[root] = 1;
  int max1 = 0;
  for(int i=0;i<adj[root].size();i++) 
  {
    int a = dfs(adj,visited,adj[root][i], counter,boo);
    if(a==-1) return -1;
    // counter[root] += a;
    max1 = max(max1,a);
  }
  boo[root] = 0;
  counter[root] = max1+1; 
  return counter[root];
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<vector<int> > v(n,vector<int>(m));
  for(int i=0;i<n+m;i++) create(i);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      char c;
      cin>>c;
      if(c=='<') v[i][j] = 1;
      else if(c=='>') v[i][j] = 2;
      else {v[i][j] = 3; merge(i,n+j);}
    }
  }

  // set<int> s;
  // for(int i=0;i<n+m;i++) s.insert(find(i));
  // int n1 = s.size();
  vector<int> finder(n+m),parent(n+m,-1);
  for(int i=0;i<n+m;i++) finder[i] = find(i);

  vector<int>*adj = new vector<int>[n+m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j]==1) 
      {
        int a = finder[n+j], b = finder[i];
        adj[a].pu(b);
        parent[b] = a;
      }
      else if(v[i][j]==2)
      {
        int a = finder[i], b = finder[n+j];
        adj[a].pu(b);
        parent[b] = a;
      }
    }
  }


  int root = -1;
  for(int i=0;i<n+m;i++)
  {
    if(parent[finder[i]]==-1) root = finder[i];
  }

  vector<int> visited(n+m),counter(n+m),boo(n+m);

  int a = 0;
  for(int i=0;i<n+m;i++)
  {
    if(visited[finder[i]]==0) a = dfs(adj,visited,finder[i],counter,boo);
    if(a==-1) break;
  }
  // int a = dfs(adj,visited,root,counter,boo);
  if(a==-1) cout<<"No"<<endl;
  else
  {
    cout<<"Yes"<<endl;
    for(int i=0;i<n;i++) cout<<counter[finder[i]]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++) cout<<counter[finder[n+i]]<<" ";
    cout<<endl;
  }

  // for(int i=0;i<n+m;i++) cout<<counter[finder[i]]<<" ";cout<<endl;
  return 0;
}

