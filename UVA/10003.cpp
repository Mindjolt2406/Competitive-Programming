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

int recur(int**dp,int m,int*l,int*lookup)
{
  // if(dp[i][j]!= INF) return dp[i][j];
  // if(lookup[i]+1==lookup[j]) {dp[i][j]=0;return 0;}
  // // cout<<"i: "<<i<<" j: "<<j<<endl;
  // for(int k=lookup[i]+1;k<lookup[j];k++)
  // {
  //   dp[i][j] = min(dp[i][j],recur(dp,i,l[k],l,lookup)+recur(dp,l[k],j,l,lookup)+(j-i));
  // }
  // return dp[i][j];
  for(int i=1;i<=m+1;i++)
  {
    for(int j=0;j<=m+1-i;j++)
    {
      dp[l[j]][l[i+j]] = INF;
      if((l[j]==0 && j!=0)|| (l[i+j]==0)) continue;
      if(i==1) {dp[l[j]][l[i+j]] = 0;continue;}
      for(int k=j+1;k<i+j;k++)
      {
        // cout<<"j: "<<j<<" i+j: "<<i+j<<" l[k]: "<<l[k]<<endl;
        dp[l[j]][l[i+j]] = min(dp[l[j]][l[i+j]],dp[l[j]][l[k]]+dp[l[k]][l[i+j]] + l[i+j]-l[j]);
        // dp[j][i+j] = min(dp[j][i+j],dp[j][l[k]]+dp[l[k]][i+j] + i);
        // cout<<dp[l[j]][l[k]]<<" "<<dp[l[k]][l[i+j]]<<" "<<dp[l[j]][i+j]<<endl;
      }
    }
  }
  // for(int i=0;i<=n;i++)
  // {
  //   if(lookup[j]==0 && j!=0) continue;
  //   for(int j=0;j<=n;j++)
  //   {
  //     if(lookup[i]==0 && i!=0) continue;
  //     if(lookup[i]+1==lookup[j]) {dp[i][j] = 0;continue;}
  //     for(int k=lookup[i]+1;k<lookup[j];k++)
  //     {
  //       dp[i][j] = min(dp[i][j],dp[i][l[k]]+dp[l[k]][j] + j-i);
  //     }
  //   }
  // }
  return dp[0][l[m+1]];
}

int main()
{
  int n;
  sc(n);
  int**dp = new int*[1001];
  for(int i=0;i<1001;i++) dp[i] = new int[1001];
  for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) dp[i][j] = INF;
  while(n)
  {
    int m;
    sc(m);
    int*lookup = (int*)calloc(1001,sizeof(int));
    int*l = new int[m+2];
    l[0]=  0;l[m+1] = n;
    lookup[0] = 0;lookup[n] = m+1;
    for(int i=1;i<=m;i++){sc(l[i]);lookup[l[i]] = i;}
    int c = recur(dp,m,l,lookup);
    printf("The minimum cutting is %d.\n",c);
    // cout<<dp[0][25]<<" "<<dp[0][50]<<" "<<dp[0][75]<<" "<<dp[50][100]<<" "<<dp[0][100]<<endl;
    sc(n);
  }
  return 0;
}

/*
100
3
25 50 75
10
4
4 5 7 8
0

*/
