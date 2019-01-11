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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

// Started at 12:07

int dfs(vector<int>*adj,int *visited, int parent, int u, int key)
{
  if(visited[u]) return 0;
  visited[u] = key;
  int a = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]==parent) continue;
    a&=dfs(adj, visited, u,adj[u][i],key);
  }
  return a;
}

int main()
{
  int n,m;
  sc(n);sc(m);
  vector<int>*adj = new vector<int>[n];
  for(int i=0;i<m;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  int*visited = (int*)calloc(n,sizeof(int));
  int key = 1;
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      count+=dfs(adj,visited,-1,i,key);
      key++;
    }
  }
  cout<<count<<endl;
  return 0;
}

