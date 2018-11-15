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

int main()
{
  int **dp = new int*[101];
  for(int i=0;i<101;i++) dp[i] =new int[101];
  for(int i=0;i<101;i++) for(int j=0;j<101;j++) dp[i][j] = 0;
  for(int i=0;i<15;i++)
  {
    for(int j=0;j<=i;j++) sc(dp[i][j]);
  }

  for(int i=14;i>=0;i--)
  {
    for(int j=0;j<=i;j++)
    {
      dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + dp[i][j];
    }
  }
  cout<<dp[0][0]<<endl;
  return 0;
}
