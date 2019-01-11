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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll get(vector<ll> &v,int k)
{
  ll **dp = new ll*[v.size()];
  for(int i=0;i<v.size();i++) {dp[i] = new ll[2];dp[i][0] = dp[i][1] = 0;}
  dp[0][0] = 0;
  dp[0][1] = v[0];
  for(int i=1;i<v.size();i++)
  {
    if(i>k) dp[i][1] = max(dp[i-k-1][0],dp[i-k-1][1]) + v[i];
    else dp[i][1] = v[i];
    dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
  }
  int n = v.size();
  // t(n,dp[0][0],dp[0][1]);
  return max(dp[n-1][1],dp[n-1][0]);
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    vector<ll> even,odd;
    for(int i=0;i<n;i++)
    {
      ll a;
      scll(a);
      if(a%2==1)
      {
        odd.pu(a);
        even.pu(0);
      }
      else 
      {
        even.pu(a);
        odd.pu(0);
      }
    }
    ll a = get(odd,k);
    ll b = get(even,k);
    printf("%lld\n",a+b);
  }
  return 0;
}

// 1,2,3,4,6,8,8,9
