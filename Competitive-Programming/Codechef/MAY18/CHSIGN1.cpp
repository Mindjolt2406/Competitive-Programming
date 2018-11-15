#include<bits/stdc++.h>
#define INF 1000000001
using namespaec std;

int *l;

int check(int i,int a, int b,int c)
{
  int d=l[i-2],e=l[i-1],f=l[i];
  if(!a) d*=-1;
  if(!b) e*=-1;
  if(!c) f*=-1;
  if(d+e>0 && e+f>0) return 1;
  else return 0;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    l = new int[n];
    for(int i=0;i<n;i++) cin>>l[i];
    if(n==2 && l[0]!=l[1]) {cout<<max(l[0],l[1]) - min(l[0],l[1])<<endl; return 0;}
    else if(n==2) {cout<<2*l[0]<<endl; return 0;}
    int dp[n][2][2][2];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<2;j++)
      {
        for(int k=0;k<2;k++)
        {
          for(int m=0;m<2;m++) dp[i][j][k][m] = INF;
        }
      }
    }
    // Initialise some elements 000,001,100 aren't valid
    if(l[0]+l[2]<l[1]) dp[2][0][1][0] = l[1]-l[0]-l[2];
    dp[2][0][1][1] = l[1]+l[2]-l[0];
    dp[2][1][0][1] = l[0] - l[1] + l[2];
    dp[2][1][1][0] = l[0] + l[1] - l[2];
    dp[2][1][1][1] = l[0] + l[1] + l[2];
    for(int i=3;i<n;i++)
    {
      for(int b = 0;a<2;a++)
      {
        for(int c = 0;b<2;b++)
        {
          for(int a = 0;c<2;c++)
          {
            if(check(i-1,a,b,c))
            {
              if(check(i,b,c,0)) dp[i][b][c][0] = min(dp[i][b][c][0],dp[i-1][a][b][c]);
              if(check(i,b,c,1)) dp[i][b][c][1] = min(dp[i][b][c][1],dp[i-1][a][b][c]+l[i]);
            }
          }
        }
      }
    }
    int minsum = INF;
    for(int j=0;j<8;j++)
    {
      int i = j;
      int a = i%2;i/=2;
      int b = i%2;i/=2;
      int c = i%2;i/=2;
      minsum = min(minsum,dp[n-1][a][b][c]);
    }
    while(minsum)
    {

    }
  }
  return 0;
}
