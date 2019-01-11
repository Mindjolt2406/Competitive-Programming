//INcomplete
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

ll max1 = -1;

ll max(ll x,ll y)
{
  return x > y ? x : y;
}

ll dfs(vector<pair<int,int> > *adj,int *visited,int *value,int u)
{
  if(visited[u]) return -1;
  visited[u] = 1;
  ll curr = value[u];
  max1 = max(max1,curr);
  ll max2 = -1;
  for(int i=0;i<adj[u].size();i++)
  {
    max2 = max(max2,dfs(adj,visited,value,adj[u][i].fi)-adj[u][i].se);
  }
  max1 = max(max1,max2);
  t(u,max1,max2);
  return max2;
}

int main()
{
  int n;
  sc(n);
  int value[n];
  vector<pair<int,int> > *adj = new vector<pair<int,int> > [n];
  for(int i=0;i<n;i++) sc(value[i]);
  for(int i=0;i<n-1;i++)
  {
    int a,b,c;
    sc(a);sc(b);sc(c);
    a--;b--;
    adj[a].pu(mp(b,c));
    adj[b].pu(mp(a,c));
  }
  int*visited = (int*)calloc(n,sizeof(int));
  dfs(adj,visited,value,0);
  cout<<max1<<endl;
  return 0;
}

