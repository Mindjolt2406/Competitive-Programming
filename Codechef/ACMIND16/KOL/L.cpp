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
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

int recur(int i,int j, vector<vector<int> > &dp, vector<vector<int> > &keep)
{
  if(i==j) return keep[i][j];
  if(dp[i][j]+1) return dp[i][j];

  for(int k = i;k+1<=j;k++)
  {
    dp[i][j] = min(dp[i][j],dp[i][k] + keep[i][k] + dp[k+1][j] + keep[k+1][j]);
  }
  return dp[i][j];
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<int> edge(m);
  for(int i=0;i<m;i++) 
  {
    cin >> edge[i];
    edge[i]--;
  }

  vector<vector<int> > adj(n);

  int prev = edge[0];

  adj[edge[0]].pu(-1);

  for(int i=1;i<m;i++)
  { 
    adj[edge[i]].pu(edge[i-1]);
    adj[edge[i-1]].pu(edge[i]);
  } 

  for(int i=0;i<n;i++) sort(adj[i].begin(),adj[i].end());

  vector<vector<int> > dp(n,vector<int>(n,-1));
  vector<vector<int> > keep(n,vector<int>(n));

  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      int cnt = 0;
      for(int k=i;k<=j;k++)
      {
        cnt += (adj[k]).upper_bound(i) - adj[k].begin();
        cnt += adj[k].end() - adj[k].lower_bound(j);
      }
      keep[i][j] = cnt;
    }
  }
  
  return 0;
}

