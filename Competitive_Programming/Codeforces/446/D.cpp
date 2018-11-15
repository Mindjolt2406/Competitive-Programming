// Won't work, figure out why
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

int countsum(ll *l, int x,int n)
{
  ll sum1 = 0;
  cout<<"x: "<<x;
  for(int i=0;i<n;i++)
  {
    if((x&(1<<i))>>i) sum1+=l[i];
  }
  cout<<" sum1: "<<sum1<<endl;
  return sum1;
}

int main()
{
  int n;
  sc(n);
  ll*l = new ll[n];
  ll*pref  =(ll*)calloc(n,sizeof(ll));
  for(int i=0;i<n;i++) {scll(l[i]);}
  // pref[0] = l[0];
  // for(int i=1;i<n;i++) pref[i] = pref[i-1]+l[i];
  ll*dp = (ll*)calloc(1<<n,sizeof(ll));
  ll*dp2 = (ll*)calloc(1<<n,sizeof(ll));
  for(int i=0;i<1<<n;i++) dp[i] = -1;
  dp[0] = 0;
  for(int i=0;i<1<<n;i++)
  {
    //Count the number of bits in i
    // int x = countsum(l,i,n);
    // dp2[i] = x;
    if(dp[i]==-1) continue;
    for(int j=0;j<n;j++)
    {
      // If the jth bit is not set
      if((i&(1<<j))>>j==0)
      {
        // pref[x] and l[j]+dp[i];
        cout<<"i: "<<i<<" dp[i]: "<<dp[i]<<endl;
        if(countsum(l,(i|1<<j),n) !=l[j]+dp[i] && dp[i|1<<j]==-1) 
        {
          dp[i|1<<j] = l[j]+dp[i];
          cout<<"index: "<<(i|1<<j)<<" dp: "<<dp[i|1<<j]<<endl;
          // if(dp[i]==-1) dp[i] = 0;
        }
      } 
    }
  }
  // for(int i=0;i<1<<n;i++) cout<<dp[i]<<" ";cout<<endl;
  // cout<<"jere"<<endl;
  if(dp[(1<<n)-1]==-1) cout<<-1<<endl;
  else
  {
    int sum1 = dp[(1<<n)-1];
    int k = (1<<n)-1;
    vector<ll> v;
    while(k)
    {
      for(int i=0;i<n;i++)
      {
        // If the ith bit is set, subtract l[i] from sum1, and make k go to k&(~(1<<i))
        if((k&(1<<i))>>i)
        {
          int c = k&(~(1<<i));
          if(dp[c]==-1) continue;
          else 
          {
            // cout<<"i: "<<i<<endl;
            sum1-=l[i];
            v.pu(l[i]);
            k = k&(~(1<<i));
            break;
          }
        }
      }
    }
    for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";cout<<endl;
  }
  return 0;
}

