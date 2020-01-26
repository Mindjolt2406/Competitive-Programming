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

const int N = 1e5+10;
vector<int> adj[N];
int visited[N] = {0};
int colour[N] = {0};
int key = 1;

void dfs(int u,int p = -1)
{
  visited[u] = key;
  for(auto v : adj[u])
  {
    if(v-p) dfs(v,u);
  }
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
  __;
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n-1;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    if(!c)
    {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      dfs(i);
      key++;
    }
  }

  for(int i=0;i<n;i++)
  {
    colour[visited[i]]++;
  }

  ll a = power(n,k,MOD);
  for(int i=1;i<=n;i++)
  {
    ll b = power(colour[i],k,MOD);
    // t(b);
    a-=b;
    a+=MOD;
    a%=MOD;
  }

  cout<<a<<endl;
  return 0;
}

