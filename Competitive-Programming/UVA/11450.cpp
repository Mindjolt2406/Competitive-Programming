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
  int t;
  sc(t);
  while(t--)
  {
    int m,n;
    sc(m);sc(n);
    int**dp = new int*[21];
    for(int i=0;i<=21;i++) dp[i] = new int[201];
    for(int i=0;i<=21;i++) for(int j=0;j<201;j++) dp[i][j] = 0;
    int **l = new int*[20];
    for(int i=0;i<20;i++) l[i] = new int[20];
    for(int i=0;i<20;i++) for(int j=0;j<20;j++) l[i][j] = 0;
    int max1 = 0;
    for(int i=0;i<n;i++)
    {
      int n1;
      sc(n1);
      max1 = max(max1,n1);
      for(int j=0;j<n1;j++) sc(l[i][j]);
    }
    for(int j=0;j<max1;j++)
    {
      for(int i=1;i<=200;i++)
      {
        if(i>=l[n-1][j]) dp[n-1][i] = max(l[n-1][j],dp[n-1][i]);
      }
    }
    // for(int i=0;i<n;i++) {for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";cout<<endl;}
    for(int i=n-2;i>=0;i--)
    {
      for(int j=1;j<=m;j++)
      {
        for(int k=0;k<max1;k++)
        {
          if(!l[i][k]) continue;
          if(j>=l[i][k] && j>=l[i][k]+dp[i+1][j-l[i][k]] && dp[i+1][j-l[i][k]]) dp[i][j] = max(l[i][k]+dp[i+1][j-l[i][k]],dp[i][j]);
        }
      }
    }
    if(dp[0][m])printf("%d\n",dp[0][m]);
    else printf("no solution\n");
    // for(int i=0;i<n;i++) {for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  }
  return 0;
}

/*
3
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
20 3
3 4 6 8
2 5 10
4 1 3 5 5
5 3
3 6 4 8
2 10 6
4 7 3 1 7

*/
