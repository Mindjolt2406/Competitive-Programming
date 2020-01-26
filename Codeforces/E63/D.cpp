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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll max3(ll x, ll y, ll z)
{
  return max(x,max(y,z));
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<ll> v(n);
  vector<vector<ll> > dp(n,vector<ll>(3));
  for(int i=0;i<n;i++) cin>>v[i];
  dp[0][0] = dp[0][1] = dp[0][2] = v[0];
  dp[0][2]*=m;
  // In all these cases, it is necessary to take i. Leave the previous elements if needed
  // dp[i][0] -> Unchanged so far, can be changed in the future if neessary
  // dp[i][1] -> Done changed, don't touch it now
  // dp[i][2] -> Change is happening right now
  for(int i=1;i<n;i++)
  {
    // Looks like the normal question's dp. It should resemble it
    dp[i][0] = max(dp[i-1][0]+v[i], v[i]); 
    // Change could've gotten over long ago(1st case), or it just got over(2nd case)
    dp[i][1] = max(dp[i-1][1] + v[i], dp[i-1][2] + v[i]); 
    // If we're changing, we're continuing the change, or we've started the change the other elements didn't want or we're just alone
    dp[i][2] = max3(dp[i-1][2]+v[i]*m, dp[i-1][0] + v[i]*m,v[i]*m); 
  }

  ll max1 = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<3;j++) max1 = max(max1,dp[i][j]);
  }

  cout<<max1<<endl;
  return 0;
}

