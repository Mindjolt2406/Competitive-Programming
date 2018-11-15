// This problem was pretty good
// Initially, I thought that it was just a variation of the coin change problem eith permutations instead of combinations
// However, becau
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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int recur(int i, int k, int d, int**dp,int boo)
{
  if(dp[i][boo]!=-1) return dp[i][boo];
  int sum1 = 0,boo2 = 0;
  for(int j=1;j<=k;j++)
  {
    if(j>=d)boo2 = 1;
    if(i>=j)
    {
      sum1+=recur(i-j,k,d,dp,boo2|boo);
      sum1%=MOD;
    }
  }
  dp[i][boo] = max(sum1,dp[i][boo]);
  return dp[i][boo];
}

int main()
{
  int n,k,d;
  sc(n);sc(k);sc(d);
  int**dp = new int*[n+1];
  for(int i=0;i<=n;i++) dp[i] = new int[2];
  for(int i=0;i<=n;i++) {dp[i][0] = -1;dp[i][1] = -1;}
  dp[0][0] = 0;dp[0][1] = 1;
  recur(n,k,d,dp,0);
  cout<<dp[n][0]<<endl;
  ll sum1 = 0;
  return 0;
}
