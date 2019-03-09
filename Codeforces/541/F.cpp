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

const int N = 300100;
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

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

void dfs(vector<int>*adj,int u,vector<int>&visited)
{
  if(visited[u]) return;
  visited[u] = 1;
  cout<<u+1<<" ";
  for(int i=0;i<adj[u].size();i++) dfs(adj,adj[u][i],visited);
}

int main()
{
  __;
  int n;
  cin>>n;
  vector<pair<int,int> > v;
  for(int i=0;i<n-1;i++) 
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    v.pu(mp(a,b));
  }

  vector<int>*adj = new vector<int>[n];
  vector<int> first(n), second(n);

  for(int i=0;i<n;i++) {first[i] = i; second[i] = i;}

  for(int i=0;i<n;i++) create(i);

  for(int i=0;i<v.size();i++)
  {
    int x = find(v[i].fi), y = find(p[v[i].se]);
    int a = first[x], b = second[x], c = first[y], d = second[y];
    merge(x,y);
    int z = find(x);
    adj[a].push_back(c);
    adj[c].push_back(a);
    first[z] = b;
    second[z] = d;
  }

  int c = first[find(0)];
  vector<int> visited(n);
  dfs(adj,c,visited);
  cout<<endl;
  return 0;
}

