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

ll rec(vector<vector<vector<ll> > > &dp, int A, int B, int C, bool frac)
{

  if(A+B == 1 && !frac) return dp[A][B][frac] = 1;
  if(A == 0 && B == 0 && frac) return dp[A][B][frac] = 1;
  if(A == 0 && B == 0 && !frac) return dp[A][B][frac] = 0;
  if(dp[A][B][frac] != -1) return dp[A][B][frac];
  ll cnt = 0;
  if(frac)
  {
    if(A >= C) 
    {
      cnt += rec(dp, A-C+1, B, C, frac);
      cnt %= MOD;
    } 
    if(B >= C)
    {
      cnt += rec(dp, A, B-C+1, C, frac);
      cnt %= MOD;
    }
    int leftA = min(A, C-1);
    int rightB = min(B, C-1);
    int numB = C-leftA-1;
    for(int i=leftA;i>=0;i--)
    {
      if(numB > rightB) break;
      cnt += rec(dp, A-i, B-numB, C, frac);
      cnt %= MOD;
      numB++;
    }
  }
  else
  {
    if(A >= C) 
    {
      cnt += rec(dp, A-C+1, B, C, frac);
      cnt %= MOD;
    } 
    if(B >= C)
    {
      cnt += rec(dp, A, B-C+1, C, frac);
      cnt %= MOD;
    }
    int leftA = min(A, C-1);
    int rightB = min(B, C-1);
    int numB = C-leftA;
    for(int i=leftA;i>=0;i--)
    {
      if(numB > rightB) break;
      cnt += rec(dp, A-i, B-numB, C, true);
      cnt %= MOD;
      numB++;
    }
  }
  // t(A, B, frac,cnt);
  dp[A][B][frac] = cnt;
  // t(A, B, frac, dp[A][B][frac]);
  return cnt;
}

ll solve(int A, int B,int C)
{
  vector<vector<vector<ll> > > dp(A+1, vector<vector<ll> > (B+1, vector<ll>(2,-1)));
  
  ll ans =  rec(dp, A, B, C,false);
  for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) t(i,j,dp[i][j]);
  return ans;
}

int main()
{
  __;
  int A,B,C;
  cin >> A >> B >> C;
  cout << solve(A,B,C) << endl;
  return 0;
}
