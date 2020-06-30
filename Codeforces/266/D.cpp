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

const int N = 2010;
ll dp[N][N] = {0};

int main()
{
  __;
  int n,h;
  cin >> n >> h;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  if(h >= v[0]) 
  {
    if(h-v[0] == 1) 
    {
      dp[0][1] = 1;
      dp[0][0] = 1;
    }
    else if(h == v[0]) dp[0][0] = 1;
  }

  for(int i=1;i<n;i++)
  {
    if(h >= v[i])
    {
      int diff = h-v[i];
      // cases
      if(diff >=1) 
      {
        // Open a new interval and close it immediately
        dp[i][diff-1] += dp[i-1][diff-1];
        dp[i][diff-1]  %= MOD;

        // Close an existing interval
        dp[i][diff-1] += dp[i-1][diff]*diff;
        dp[i][diff-1] %= MOD;

        // Close an interval and open a interval
        if(diff > 1)
        {
          dp[i][diff-1] += dp[i-1][diff-1]*(diff-1);
          dp[i][diff-1] %= MOD;
        }
      }
      // Open and let it continue
      if(diff>=1) dp[i][diff] += dp[i-1][diff-1];
      dp[i][diff] %= MOD;
      
      // Don't do anything
      dp[i][diff] += dp[i-1][diff];
      dp[i][diff] %= MOD;
    }
  }

  cout << dp[n-1][0] << endl;

  // for(int i=0;i<=2;i++)
  // {
  //   for(int j=0;j<=1;j++) if(dp[i][j]) t(i,j,dp[i][j]);
  // }
  
  return 0;
}
