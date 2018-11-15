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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int n,k;
  sc(n);sc(k);
  ll dp[n][k+1][2][2];
  for(int i=0;i<n;i++)
  {
    dp[i][1][0][0] = 1;
    dp[i][1][0][1] = 0;
    dp[i][1][1][0] = 0;
    dp[i][1][1][1] = 1; 
  }
  if(k>1)
  {
    dp[0][2][0][1] = 1;
    dp[0][2][1][0] = 1;
    dp[0][2][0][0] = 0;
    dp[0][2][1][1] = 0;
  }

  // dp[i][j] is the number of ways to form j components till the ith index. The extra 2 dimensions represent the color it ends with
  for(int i=0;i<n;i++)
  {
    for(int j=2;j<=k;j++)
    {
      if(i==0 && j==2) continue;
      // if(j==1) continue;
      else if(i==0 && j>2)
      {
        dp[0][j][0][0] = 0;
        dp[0][j][0][1] = 0;
        dp[0][j][1][0] = 0;
        dp[0][j][1][1] = 0; 
      }
      else
      {
        // Initialising it to 0 first
        dp[i][j][0][0] = 0;dp[i][j][1][1] = 0;
        dp[i][j][0][1] = 0;dp[i][j][1][0] = 0;
        // 0 0
        dp[i][j][0][0]+=dp[i-1][j][0][0];
        dp[i][j][0][0]+=dp[i-1][j][0][1]+dp[i-1][j][1][0];
        dp[i][j][0][0]+=dp[i-1][j-1][1][1];
        // 0 1
        dp[i][j][0][1]+=dp[i-1][j][0][1];
        dp[i][j][0][1]+=dp[i-1][j-1][0][0]+dp[i-1][j-1][1][1];
        if(j>2) dp[i][j][0][1] += dp[i-1][j-2][1][0];
        // 1 0
        dp[i][j][1][0]+=dp[i-1][j][1][0];
        dp[i][j][1][0]+=dp[i-1][j-1][0][0]+dp[i-1][j-1][1][1];
        if(j>2) dp[i][j][1][0]+=dp[i-1][j-2][1][0];
        // 1 1
        dp[i][j][1][1]+=dp[i-1][j][1][1];
        dp[i][j][1][1]+=dp[i-1][j][1][0]+dp[i-1][j][0][1];
        dp[i][j][1][1]+=dp[i-1][j-1][0][0];

        dp[i][j][0][0]%=MOD;dp[i][j][0][1]%=MOD;dp[i][j][1][0]%=MOD;dp[i][j][1][1]%=MOD;
      }
    }
  }
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=1;j<=k;j++)
  //   {
  //     cout<<"i: "<<i<<" j: "<<j<<" - ";
  //     cout<<dp[i][j][0][0]<<" "<<dp[i][j][0][1]<<" "<<dp[i][j][1][0]<<" "<<dp[i][j][1][1]<<endl;
  //   }
  // }
  ll sum1 = 0;
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      sum1+=dp[n-1][k][i][j];
      sum1%=MOD;
    }
  }

  cout<<sum1<<endl;
  return 0;
}

