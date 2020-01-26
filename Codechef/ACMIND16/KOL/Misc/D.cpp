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

int log22(int x)
{
  int cnt = 0;
  while(x!=1)
  {
    cnt++;
    x >>= 1;
  }
  return cnt;
}

ll pow2(int k)
{
  ll prod = 1;
  while(k--)
  {
    prod <<= 1;
  }

  return prod;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    ll l,r;
    cin >> l >> r;

    ll dp[50] = {0};
    ll prod = 1;
    dp[1] = 1;
    for(int i=2;i<35;i++)
    {
      prod <<= 1;
      dp[i] = dp[i-1] + prod*i;
    }

    // for(int i=0;i<4;i++) t(i,dp[i]);
    ll ans_l = 0;
    l--;
    if(l!=0)
    {
      ll l2 = pow2(log22(l));
      ans_l = (l - l2 + 1)*(log22(l) + 1) + dp[(int)log22(l)];
    }

    ll r2 = pow2(log22(r));
    ll ans_r = (r - r2 + 1)*(log22(r) + 1) + dp[(int)log22(r)];

    cout << (ans_r - ans_l)%MOD << endl;
  }
  return 0;
}

