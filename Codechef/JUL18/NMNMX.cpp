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

// map <pair<int,int>,ll> dp;
ll dp[5002][5002];

// int C(int n,int k)
// {
//   // cout<<"n: "<<n<<" k: "<<k<<endl;
//   ll p = dp[n][k];
//   ll p1 = dp[n][n-k];
//   // pair<int,int> p = mp(n,k);
//   // pair<int,int> p1 = mp(n,n-k);
//   if(n==0) return 0;
//   else if(k==0 || n==k) return 1;
//   else if(k==1 || n-k==1) return n;
//   if(dp[n][k]>=0) return p;
//   else if(dp[n][n-k]>=0) return p1;
//   dp[n][k] =  (C(n-1,min(k-1,n-k)) + C(n-1,min(k,n-k-1)))%MOD;
//   dp[n][n-k] = dp[n][k];
//   // cout<<p.first<<" "<<p.second<<" "<<dp[p]<<endl;
//   return dp[n][k];
// }

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll divide(ll a,ll b, ll p)
{
  return (a*power(b,p-2,p))%p;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    ll* l = new ll[n];
    for(int i=0;i<n;i++) scll(l[i]);
    sort(l,l+n);
    ll* m = new ll[n];
    m[0] = l[0];
    for(int i=1;i<n;i++) m[i] = (m[i-1]*l[i])%MOD;
    int left = 0,right = k-1;
    ll prod = 1;
    for(;left<n-k+1;left++)
    {
      for(right = left+k-1;right<n;right++)
      {
        if(left!=right+1)prod*= divide(m[right-1],m[left],MOD);
        prod%=MOD;
      }
    }
    printf("%lld\n",prod);
  }
  return 0;
}
