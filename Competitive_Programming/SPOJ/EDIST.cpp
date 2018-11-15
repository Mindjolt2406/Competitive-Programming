// I didn't take care of the empty string case, so it gave WA before I looked at geeksforgeeeks
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
#define scr(s) {char temp[2001];scanf("%s",temp);s = temp;}

using namespace std;

int min1(int x,int y,int z)
{
  return min(min(x,y),z);
}

int recur(int**dp,string a,string b,int n, int m)
{

  // cout<<"i: "<<i<<" j: "<<j<<endl;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      if(i==0 && j==0) dp[i][j] = 0;
      else if(i==0) dp[i][j] = j;
      else if(j==0) dp[i][j] = i;
      else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = 1 + min1(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[n][m];
  // if(dp[i][j]!=INF) return dp[i][j];
  // int c =  INF;
  // if(i>0 && j>0 && a[i]==b[j])
  // {
  //   dp[i-1][j-1] = min(recur(dp,a,b,i-1,j-1),dp[i-1][j-1]);
  //   c = dp[i-1][j-1];
  // }
  // else if(a[i]==b[j]) return 0;
  // else
  // {
  //   if(j>0){dp[i][j-1] = recur(dp,a,b,i,j-1);c = dp[i][j-1];} // Insert
  //   else {dp[i][0] = i;c = i;}
  //   if(i>0) {dp[i-1][j] = recur(dp,a,b,i-1,j);c = min(dp[i-1][j],c);} // Delete
  //   else {dp[0][j] = j;c = min(j,c);}
  //   if(i>0 && j>0) {dp[i-1][j-1] = recur(dp,a,b,i-1,j-1);c = min(c,dp[i-1][j-1]);} // Replace
  //   else if(i==0 && j==0) {dp[0][0] = 0;c = 0;}
  //   c++;
  // }
  // return c;
}

int main()
{
  int t;
  sc(t);
  int** dp = new int*[2010];
  for(int i=0;i<2010;i++) dp[i] = new int[2010];
  while(t--)
  {
    string a,b;
    scr(a);scr(b);
    int n = a.size();
    int m = b.size();
    for(int i=0;i<n+1;i++) for(int j=0;j<m+1;j++) dp[i][j] = INF;
    printf("%d\n",recur(dp,a,b,n,m));
  }
  return 0;
}

/*
1
MNEXY
MONEY

*/
