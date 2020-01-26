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

const int N = 5e5+10;
int sz[N] = {0}, ans[N] = {0};
bool big[N] = {0};
int counter[26] = {0};
int odd = 0;
vector<int> adj[N];
string s;

void add(int u,int p,int val)
{
  counter[s[u]-'a']+=val;
  int a = counter[s[u]-'a'];
  if(a%2==1) odd++;
  else odd--;
  for(auto v : adj[u])
  {
    if(!big[v] && p-v) add(v,u,val);
  }
}

int dfs1(int u,int p)
{
  int count = 1;
  for(auto v : adj[u]) 
  {
    if(p-v) count+=dfs1(v,u);
  }
  sz[u] = count;
  return count;
}

void dfs(int u,int p,bool keep)
{
  int mx = -1, bigChild = -1;
  for(auto v : adj[u])
  {
    if(sz[v]>mx) {mx = sz[v]; bigChild = v;}
  }

  for(auto v : adj[u])
  {
    if(!big[v] && p-v) dfs(v,u,0);
  }

  if(bigChild!=-1) {dfs(bigChild, u, 1);big[bigChild] = 1;}

  add(u,p,1);
  
  // Answer the queries
  if(odd<=1) ans[u] = 1;
  else ans[u] = 0;

  if(bigChild!=-1) big[bigChild] = 0;

  if(!keep) add(u,p,-1);
}

int main()
{
  __;
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n-1;i++)
  {
    int a;
    cin>>a;
    a--;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }

  cin>>s;
  
  return 0;
}

