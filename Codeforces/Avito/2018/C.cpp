#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
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
  int n,m,k;
  sc(n);sc(m);sc(k);
  ll **dp = new ll*[n+1];
  for(int i=0;i<=n;i++) dp[i] = new ll[k+1];
  for(int i=0;i<=k;i++) dp[0][i] = 0;
  for(int i=0;i<=n;i++) dp[i][0] = m;
  dp[0][0] =  0;

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=k;j++)
    {
      dp[i][j] = dp[i-1][j];
      dp[i][j]%=MOD;
      dp[i][j] += (dp[i-1][j-1]*(m-1))%MOD;
      dp[i][j]%=MOD;
    }
  }
  cout<<dp[n][k]<<endl;
  // for(int i=0;i<=n;i++) {for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  return 0;
}

