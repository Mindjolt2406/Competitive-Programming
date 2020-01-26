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

const int N = 100;
vector<int> adj[100] = {};
vector<vector<bool> > dp(N,vector<bool>(3));

bool dfs(int u = 0,int p = -1)
{
  int isLeaf = true;
  for(auto v : adj[u]) 
  {
    if(v-p) 
    {
      bool boo = dfs(v,u);
      if(!boo) return false;
      isLeaf = false;
    }
  }
  if(isLeaf) 
  {
    dp[u][2] = false;
    dp[u][0] = dp[u][1] = true;
    return true;
  }

  bool boo = true; // Can I colour the vertex u? 
  for(auto v : adj[u]) if(v-p) boo &= dp[v][0];

  if(boo) dp[u][1] = true;

  boo = true; // Can the vertex u be uncoloured and undominated? 
  for(auto v : adj[u]) if(v-p) boo &= dp[v][2];

  if(boo) dp[u][0] = true;

  boo = true; // Can the vertex u be uncoloured but dominated?
  // In this case only 1 child can dominate the vertex u
  // All the others have to be uncoloured and dominated
  int cnt = 0,total = 0;;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      if(dp[v][2]) cnt++;
      total++;
    }
  }

  if(cnt<total-1) dp[u][2] = false;
  else
  {
    for(auto v : adj[u])
    {
      int a = cnt;
      if(v-p)
      {
        if(dp[v][2]) a--; 
        if(a<total-1) continue;
        if(dp[v][1]) dp[u][2] = true;
      }
    }
  }

  // If I can't characterize the vertex u in any of these categories, then it mustn't be posibile to colour this grpha in the first place
  if((dp[u][0] | dp[u][1] | dp[u][2]) == false) return false;
  return true;
}

int main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  bool boo = dfs();
  if((dp[0][1] | dp[0][2]) == false) boo = false;

  if(boo) cout<<"True"<<endl;
  else cout<<"False"<<endl;

  return 0;
}

