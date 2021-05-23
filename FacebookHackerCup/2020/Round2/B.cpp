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
  int N;
  ld p;
  cin >> N >> p;

  vector<vector<ld> > dp(N+1,vector<ld>(N+1));

  dp[1][1] = 0;

  for(ld n=2;n<=N;n++)
  {
    for(int i=1;i<=n;i++)
    {
      dp[n][i] += (i-1)*(i-2)*(dp[n-1][i-1] + 1); 
      dp[n][i] += (n-i)*(n-i-1) * (dp[n-1][i] + 1);

      ld temp = 2 * (i-1) * (n-i); 
      dp[n][i] += temp * p * (dp[n-1][i-1] + 1);
      dp[n][i] += temp * (1-p) * (dp[n-1][i] + 1);

      dp[n][i] += 2 * (i-1) * p * (dp[n-1][i-1] + 1) ;
      dp[n][i] += 2 * (1-p) * (n-i) * (dp[n-1][i] + 1);
      dp[n][i] += 2 * (i-1) * (1-p);
      dp[n][i] += 2 * (n-i) * p;

      dp[n][i] /= n;
      dp[n][i] /= (n-1);
    }
  }

  for(int i=1;i<=N;i++) 
  {
    cout << dp[N][i] << endl;
    // ld sum1 = 0;
    // for(int j=i;j<=N;j++)
    // {
    //   sum1 += j*dp[j][i];
    // }
    // cout << sum1 << endl;
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  cout << fixed << setprecision(8);
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ":\n";
    solve();
  }
  return 0;
}
