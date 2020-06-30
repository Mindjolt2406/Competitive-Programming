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

const int N = 1e6+5;
const int MAXLOG = 21;
int pow2[MAXLOG+3] = {0};
int pow3[MAXLOG+3] = {0};
// int pow3[MAXLOG] = {0};

int f(int n,int x, int y)
{
  // t(x,pow2[x],pow3[y]);
  return n/(pow2[x]*pow3[y]);
}

// vector<vector<vector<int> > > dp(N,vector<vector<int> > (25,vector<int>(2)));
int dp[N][24][2] = {0};

int main()
{
  __;

  for(int i=0;i<MAXLOG+3;i++) pow2[i] = pow(2,i);
  for(int i=0;i<MAXLOG+3;i++) pow3[i] = pow(3,i);

  int n;
  cin >> n;
  
  int x = 0;
  int k = n;
  while(k > 1)
  {
    x++;
    k >>= 1;
  }
  

  dp[0][x][0] = 1;
  if(pow(2,x-1)*3 <= n) dp[0][x-1][1] = 1;

  for(int i=1;i<n;i++)
  {
    for(int x=0;x<MAXLOG;x++)
    {
      // t(i,x);
      for(int y=0;y<2;y++)
      {
        dp[i][x][y] += (1LL*dp[i-1][x][y]*(f(n,x,y)-i)) % MOD;
        if(dp[i][x][y] >= MOD) dp[i][x][y] -= MOD;
        dp[i][x][y] += (1LL*dp[i-1][x+1][y]*(f(n,x,y) - f(n,x+1,y))) % MOD;
        if(dp[i][x][y] >= MOD) dp[i][x][y] -= MOD;
      }
      dp[i][x][0] += (1LL*dp[i-1][x][1]*(f(n,x,0) - f(n,x,1))) % MOD;
      if(dp[i][x][0] >= MOD) dp[i][x][0] -= MOD;
    }
  }

  cout << dp[n-1][0][0] << endl;

  // for(int i=0;i<n;i++) for(int j=0;j<3;j++) for(int k=0;k<2;k++) if(dp[i][j][k]) t(i,j,k,dp[i][j][k]);
  return 0;
}
