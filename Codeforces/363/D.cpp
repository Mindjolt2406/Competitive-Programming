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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 2e5+10;
vector<int> adj[N] = {};
vector<int> vis(N);
int key = 1;

void dfs(int u,int p = -1)
{
  // t(u,key);
  vis[u] = key;
  for(auto v : adj[u]) if(v-p && vis[v]==0) dfs(v,u);
}

int main()
{
  __;
  int n;
  cin>>n;
  vector<int> v(n);
  int cnt = 0, first = -1;
  vector<int> root;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    v[i]--;
    int a = v[i];
    adj[i].pu(a);
    adj[a].pu(i);
    if(v[i]==i) 
    {
      if(!(first+1)) first = i;
      root.pu(i);
    }
  }



  for(int i=0;i<n;i++)
  {
    if(vis[i]==0) {dfs(i);key++;}
  }

  vector<bool> colour(n+1,false);
  cnt = 0;

  if(first==-1) 
  {
    cnt++;
    first = 0;
    v[0] = vis[0];
  }
  colour[vis[first]] = true;

  for(int i=0;i<root.size();i++)
  {
    if(vis[root[i]] == vis[first]) continue;
    else 
    {
      cnt++;
      v[root[i]] = first;
      colour[vis[root[i]]] = true;
    }
  }

  for(int i=0;i<n;i++)
  {
    if(colour[vis[i]]==false) 
    {
      colour[vis[i]] = true;
      cnt++;
      v[i] = first;
    }
  }

  cout<<cnt<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]+1<<" "; cout<<endl;

  // for(int i=0;i<n;i++) cout<<vis[i]<<" ";cout<<endl;
  // t(first,vis[first]);
  return 0;
}

