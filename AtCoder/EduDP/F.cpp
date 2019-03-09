#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
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
  string s,t;
  cin>>s>>t;
  s = "$"+s;
  t = "$"+t;
  int n = s.size(),m = t.size();
  vector<vector<int> > dp(n,vector<int>(m));
  vector<vector<int> > keep(n,vector<int>(m));
  dp[0][0] = s[0]==t[0];
  if(dp[0][0]) keep[0][0] = 3;
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++)
    {
      // if(i==0 && j==0) continue;
      // else if(i==0)
      // {
      //   dp[i][j] = dp[i][j-1];
      //   keep[i][j] = 1;
      // }
      // else if(j==0)
      // {
      //   dp[i][j] = dp[i-1][j];
      //   keep[i][j] = 2;
      // }
      // else
      // {
        int a = s[i]==t[j];
        int max1 = -1;
        if(dp[i-1][j-1] + a >= dp[i-1][j]) {max1 = dp[i-1][j-1]+a; keep[i][j] = 3;}
        else {max1 = dp[i-1][j]; keep[i][j] = 2;}
        if(dp[i][j-1] > max1) {max1 = dp[i][j-1]; keep[i][j] = 1;}
        dp[i][j] = max1;
      // }
    }
  }

  int i = n-1, j = m-1;
  string k;
  while(i>=0 && j>=0)
  {
    if(i==0 && j==0) break;
    int a = keep[i][j];
    if(a==3)
    {
      // k+=s[i];
      if(s[i]==t[j]) k+=s[i];
      i = i-1;
      j = j-1;
    }
    else if(a==2)
    {
      i = i-1;
    }
    else
    {
      j = j-1;
    }
  } 
  // cout<<dp[n-1][m-1]<<endl;
  reverse(k.begin(),k.end());
  cout<<k<<endl;
  // for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<dp[i][j]<<" "; cout<<endl;}
  // for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<keep[i][j]<<" "; cout<<endl;}
  return 0;
}

