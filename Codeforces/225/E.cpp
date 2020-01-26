/*
Rathin Bhargava
IIIT Bangalore

*/

// Needed a little help to realise it could be done with a bit. I only figured it out when I saw that it was being done
// with 2 bits
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

const int N = 2e5+10;
vector<int> adj[N];
int start[N] = {0}, finish[N] = {0},vert[2*N] = {0};
bool level[N] = {0};
int t = 1;

void dfs(int u,int p = -1, bool lvl = 0)
{
  start[u] = t;
  vert[t] = u;
  t++;
  level[u]= lvl;
  for(auto v : adj[u]) if(v-p) dfs(v,u,lvl^1);
  finish[u] = t;
  vert[t] = u;
  t++;
} 

typedef struct BIT //int
{
  vector<int> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  int sum(int i)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, int delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  int getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> &v)
  {
    init(2*v.size()+10);
    int n = 2*v.size();
    for(int i=1;i<=n;i++) inc(i,0);
  }
} BIT;

int main()
{
  __;
  int n,q;
  cin>>n>>q;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  for(int i=1;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs(0);
  BIT bit1,bit2;
  bit1.init(v);
  bit2.init(v);
  // for(int i=1;i<=2*n;i++) cout<<bit1.sum(i)<<" ";
  // cout<<endl;
  // for(int i=1;i<=2*n;i++) cout<<bit2.sum(i)<<" ";
  // cout<<endl;
  while(q--)
  {

    int a;
    cin>>a;
    if(a==1)
    {
      int x,val;
      cin>>x>>val;
      x--;
      if(level[x])
      {
        bit2.inc(start[x],val);
        bit2.inc(finish[x]+1,-1*val);
        bit1.inc(start[x],-1*val);
        bit1.inc(finish[x]+1,val);
      }
      else
      {
        bit1.inc(start[x],val);
        bit1.inc(finish[x]+1,-1*val);
        bit2.inc(start[x],-1*val);
        bit2.inc(finish[x]+1,val);
      }
    }
    else
    {
      int x;
      cin>>x;
      x--;
      if(level[x]) cout<<bit2.sum(start[x])+v[x]<<endl;
      else cout<<bit1.sum(start[x])+v[x]<<endl;
    }

    // for(int i=0;i<n;i++) cout<<start[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++) cout<<finish[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=2*n;i++) cout<<bit1.sum(i)<<" ";
    // cout<<endl;
    // for(int i=1;i<=2*n;i++) cout<<bit2.sum(i)<<" ";
    // cout<<endl;
  }
  return 0;
}

