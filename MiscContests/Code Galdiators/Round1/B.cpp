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

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<int> > dp(n,vector<int> (2)),par(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>v[i];

    dp[0][1] = v[0];
    dp[0][0] = 0;
    par[0][0] = par[0][1] = -1;

    for(int i=1;i<n;i++)
    {
      dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
      dp[i][1] = dp[i-1][0] + v[i];
      par[i][1] = 0;
      if(dp[i-1][1]>dp[i-1][0]) par[i][0] = 1;
      else par[i][0] = 0;
    }

    // pair<int,int> p = par[n-1];
    vector<int> w;
    // if(dp[n-1][1]>dp[n-1][0]) w.pu(v[n-1]);

    int j = n-1,p;
    if(dp[n-1][1]>dp[n-1][0]) p = 1;
    else p = 0;

    while(j>=0)
    {
      if(p)
      {
        w.pu(v[j]);
      }
      p = par[j][p];
      j--;
    }

    for(int i=0;i<w.size();i++) cout<<w[i];
    cout<<endl;
    // cout<<max(dp[n-1][1],dp[n-1][0])<<endl;
  } 
  return 0;
}

