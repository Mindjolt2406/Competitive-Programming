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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int dfs(vector<int>*adj,int*visited,vector<ll>&val,vector<ll>&ans,int u,int parent,ll sum)
{
  if(visited[u]) return 1;
  visited[u] = 1;
  // t(val[u],u,sum);
  int boo = 0;
  if(val[u]==-1) {val[u] = sum;boo = 1;}
  else if(val[u]<sum) {return 0;}


  if(boo)
  {
    // t(u,val[u]);
    ll min1 = INF;
    for(int i=0;i<adj[u].size();i++)
    {
      if(adj[u][i]!=parent) min1 = min(min1,val[adj[u][i]]);
    }
    
    if(min1!=INF)val[u]+=min1-sum;
    // t(u,val[u]);
  }

  ans[u] = val[u]-sum;
  if(ans[u]<0) return 0;
  // t(u,val[u],ans[u]);
  for(int i=0;i<adj[u].size();i++)
  {
    int a = dfs(adj,visited,val,ans,adj[u][i],u,val[u]);
    if(a==0) {return 0;}
  }
  return 1;
} 

int main()
{
  __;
  int n;
  cin>>n;
  vector<int>*adj = new vector<int>[n];
  for(int i=1;i<n;i++)
  {
    int a;
    cin>>a;
    a--;
    adj[i].pu(a);
    adj[a].pu(i);
  }
  vector<ll> val(n),ans(n);
  for(int i=0;i<n;i++) cin>>val[i];
  int*visited = (int*)calloc(n,sizeof(int));
  int a = dfs(adj,visited,val,ans,0,-1,0);
  if(a==0) cout<<-1<<endl;
  else
  {
    ll sum1 = 0;
    for(int i=0;i<n;i++) sum1+=ans[i];
    cout<<sum1<<endl;
  }
  return 0;
}
