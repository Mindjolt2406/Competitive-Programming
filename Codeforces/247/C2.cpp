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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int n,k,d;
  sc(n);sc(k);sc(d);
  ll **dp = new ll *[n+1];
  for(int i=0;i<=n;i++) {dp[i] = new ll[2];dp[i][0] = 0;dp[i][1] = 0;}
  dp[0][0] = 1, dp[0][1] = 0;
  for(int i=1;i<=n;i++)
  {
    dp[i][1] = 0;
    // if(i>=d) dp[i][1] = dp[i-d][0];
    for(int j=d;j<=k;j++) if(i>=j) {dp[i][1]+=dp[i-j][0];dp[i][1]%=MOD;}
    for(int j=1;j<=k;j++) if(i>=j) {dp[i][1]+=dp[i-j][1];dp[i][1]%=MOD;}
    dp[i][0] = 0;
    for(int j=1;j<=k;j++) 
    {
      if((i>=d && j<d)|| (i<d && i>=j)) dp[i][0]+=dp[i-j][0];dp[i][0]%=MOD;
    }
  }
  cout<<dp[n][1]<<endl;
  for(int i=0;i<=n;i++) t(i,dp[i][0],dp[i][1]);
  return 0;
}

