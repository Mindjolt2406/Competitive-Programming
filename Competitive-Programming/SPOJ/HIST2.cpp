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

int countbit(int n)
{
  int count= 0;
  while(n)
  {
    count+=(int)n&1;
    n<<=1;
  }
  return count;
}

int checkbit(int i,int j)
{
  cout<<"i: "<<i<<" j: "<<j<<" "<<(i&(1<<j)>>j) <<endl;
  return i&(1<<j)>>j;
}

int main()
{
  int n;
  sc(n);
  while(n)
  {
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    vector<int> dp;
    dp.assign((1<<n),0);
    dp[0] = 0;
    for(int i=0;i<(1<<n);i++)
    {
      // Count the number of bits, if needed.
      int x = countbit(i);
      int c = l[x];
      // Here it isn't, as only order matters
      for(int j=0;j<n;j++)
      {
        if(! checkbit(i,j)) // If the jth bit is not set
        {
          int sum1 = 0;
          // Check left
          if(j==0) sum1+=c;
          else if (checkbit(i,j-1))
          {
            int a = dp[i],b = dp[i&(~(1<<(j-1)))];
            cout<<"i: "<<i<<" dp[i]: "<<dp[i]<<" dp: "<<b<<endl;
            sum1+=abs(a-b);
          }
          // Check right
          if(j==n-1) sum1+=c;
          else if(checkbit(i,j+1))
          {
            int a = dp[i],b = dp[i&(~(1<<(j+1)))];
            cout<<"i: "<<i<<" dp[i]: "<<dp[i]<<" dp: "<<b<<endl;
            sum1+=abs(a-b);
          }
          dp[i|(1<<j)] = max(dp[i|(1<<j)],dp[i]+sum1);
        } 
      }
    }
    printf("%d\n",dp[(1<<n)-1] + 2*n);
    for(int i=0;i<(1<<n);i++) cout<<"i: "<<i<<" dp: "<<dp[i]<<endl;
    sc(n);

  }
  return 0;
}

/*
4 3 2 1

*/
