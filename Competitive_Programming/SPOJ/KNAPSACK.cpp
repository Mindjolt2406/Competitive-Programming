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

int dp[2001][2001] = {0};

int main()
{
  int max1 = 0;
  int n,k;
  sc(k);sc(n);
  pair<int,int> *l = new pair<int,int>[n];
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    l[i] = mp(a,b);
  }
  dp[0][l[0].first] = l[0].second;
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      // if(j+l[i+1].first<=k) dp[i+1][j+l[i+1].first] = max(dp[i][j]+l[i+1].second,dp[i][j+l[i+1].first]);
      if(j>=l[i].first)dp[i][j] = max(dp[i-1][j],dp[i-1][j-l[i].first]+l[i].second);
      else dp[i][j] = dp[i-1][j];
    }
  }
  for(int j=0;j<=k;j++) max1= max(max1,dp[n-1][j]);
  printf("%d\n",max1);
  // for(int i=0;i<n;i++) {for(int j=0;j<=k;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  return 0;
}
