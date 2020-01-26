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


int main()
{
  __;
  int n;
  cin>>n;
  vector<vector<int> > dp(n,vector<int> (3));
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  dp[0][0] = 1;

  if(v[0]==1 || v[0]==3) dp[0][1] = 0;
  else dp[0][1] = 1;

  if(v[0]==2 || v[0]==3) dp[0][2] = 0;
  else dp[0][2] = 1;

  for(int i=1;i<n;i++)
  {
    if(v[i]==0)
    {
      dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
      dp[i][1] = INF;
      dp[i][2] = INF;
    }

    else if(v[i]==1)
    {
      dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
      dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
      dp[i][2] = INF;
    }

    else if(v[i]==2)
    {
      dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
      dp[i][1] = INF;
      dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
    }

    else
    {
      dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
      dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
      dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
    }
  }

  cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<endl;
  return 0;
}

