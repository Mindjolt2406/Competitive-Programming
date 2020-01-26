#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long INF=4557430888798830399;
int n,A,B;
int a[5001];
long long dp[5001][5001];
long long ans=INF;
int main()
{
    memset(dp,63,sizeof(dp));
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
        	if(a[i]>j) dp[i][j]=min(dp[i][j],dp[i-1][j]+A),dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]);
			else dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
	for(int i=0;i<=n;i++)
		ans=min(ans,dp[n][i]);
    printf("%lld",ans);
    return 0;
}
