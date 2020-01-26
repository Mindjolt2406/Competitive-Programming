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

const int N = 1e6+10;
vector<int> adj[N] = {};
vector<vector<int> > dp(N,vector<int> (2));


void dfs(int u = 0,int p = -1)
{
  // t(u);
  bool isLeaf = true;
  
  int max1 = -1,max2 = -1;
  int sum1 = 0;

  for(auto v : adj[u])
  {
    if(v-p)
    {
      isLeaf = false;
      dfs(v,u);
      
      sum1 += max(dp[v][0],dp[v][1]);

      if(dp[v][1] > max1)
      {
        max1 = dp[v][1];
        max2 = v;
      }
    }
  }

  if(isLeaf) 
  {
    dp[u][0] = 1;
    dp[u][1] = 0;
    return;
  }

  dp[u][0] = 1;
  // t(u,sum1,max1,max2,dp[max2][1]);
  dp[u][1] = sum1 - max(dp[max2][0],dp[max2][1]) + dp[max2][1];
}

int main()
{
  __;
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs();

  cout << max(dp[0][0],dp[0][1]) << endl;

  // for(int i=0;i<9;i++) t(i,dp[i]);


  return 0;
}

/*
9
1 2
1 3
2 8
2 4
2 5
5 6
5 7
2 9

*/
