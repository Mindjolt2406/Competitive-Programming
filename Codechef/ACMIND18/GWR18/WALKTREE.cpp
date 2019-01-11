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
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6, t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll period[1000000];
ll ans[1000000];
// ll ans[1000000] = {0};

void dfs(vector<int>*adj, int u,int parent,int count,int index)
{
  if(parent!=-1) {period[u] = period[parent]*count; period[u]%=MOD;}
  else period[u] = 1;
  if(index!=0) ans[u] = (period[parent] + ans[adj[parent][index-1]])%MOD;
  else ans[u] = ans[parent];
  // t(u,index,parent,ans[u],period[u],count);
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]==parent) continue;
    dfs(adj,adj[u][i],u,adj[u].size(),i);
  }
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    vector<int>*adj = new vector<int>[n];
    // adj[0].pu(-1);
    for(int i=0;i<n;i++)
    {
      int a;
      sc(a);
      for(int j=0;j<a;j++)
      {
        int b;
        sc(b);
        b--;
        adj[i].pu(b);
      }
    }
    dfs(adj,0,-1,1,0);
    for(int i=0;i<n;i++) printf("%lld ",ans[i]+1);
    printf("\n");
  }
  return 0;
}

