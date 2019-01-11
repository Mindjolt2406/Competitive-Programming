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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

ll dp[1100][10];

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    ll sum1 = 0;
    for(int i=0;i<pow(2,n);i++) for(int j=0;j<n;j++) dp[i][j] = 0;
    for(int i=0;i<n;i++) dp[(int) pow(2,i)][i] = 1;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        for(int mask = 0;mask<pow(2,n);mask++)
        {
          if(dp[mask][j]!=0) continue;
          int a = __builtin_popcount(mask);
          if(a>i+1) continue;
          if(mask & (1<<j))
          {
            // t(mask,(mask & ~(1<<j)));
            // cout<<mask & ~(1<<j)<<endl;
            if(j>0)
            {
              dp[mask][j]+=dp[mask][j-1] + dp[mask & ~(1<<j)][j-1];
              dp[mask][j]%=MOD;
            }

            if(j+1<n)
            {
              dp[mask][j]+=dp[mask][j+1] + dp[mask & ~(1<<j)][j+1];
              dp[mask][j]%=MOD;
            }
            t(mask,i,j,dp[mask][j]);
          }
        }
      }
      if(i>=n) for(int j=0;j<n;j++) sum1+=dp[(int) pow(2,n)-1][j];
      t(i);
      for(int i=0;i<pow(2,n);i++) {for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";cout<<endl;}
    }

    // for(int i=0;i<pow(2,n);i++) {for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";cout<<endl;}
    cout<<sum1<<endl;
  }
  return 0;
}

