#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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

void solve()
{
  int n,m,k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  vector<vector<int > > w(n);
  for(int i=0;i<n;i++)
  {
    char prev = 'A';
    int cnt = 0;
    for(auto c : v[i])
    {
      if(c == prev) cnt++;
      else 
      {
        prev = (prev == 'A') ? 'B' : 'A';
        w[i].pu(cnt);
        cnt = 0;
      }
    }
    if(cnt) w[i].pu(cnt);
  }

  vector<vector<vector<vector<int> > > > dp(n,vector<vector<vector<int> > > (m,vector<vector<int> > (n*m,vector<int>(2))));

  for(int i=0;i<n;i++) 
  {
    for(int j=0;j<w[i].size();j++)
    {
      if(j%2 == 0)  // A
      {
        for(int k=0;k<n*m;k++)
        {
          dp[i][j][k][0] = min(dp[i][j][k][0],dp[i][j-1][k][1]+1);
          dp[i][j][k][1] = min(dp[i][j][k-w[i][j]][1],dp[i][j-1][k][0]+1);
        }
      }
      else
      {
        for(int k=0;k<n*m;k++)
        {
          dp[i][j][k][0] = min(dp[i][j][k-w[i][j]][0],dp[i][j-1][k][1]+1);
          dp[i][j][k][1] = min(dp[i][j][k-w[i][j]][1],dp[i][j-1][k][0]+1);
        }
      }
    }
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}
