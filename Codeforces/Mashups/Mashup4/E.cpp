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

// int l[N][N], m[N][N] ,arr[N][N];

void multiply(ll**l,ll**m,ll**arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = -INF;
            for(int k=0;k<n;k++)
            {
                arr[i][j] = max(l[i][k]+m[k][j],arr[i][j]);
            }
        }
    }
}

void zero(ll **l, int n)
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) l[i][j] = 0;
}

void copy(ll**arr,ll**m,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j] = arr[i][j];
        }
    }
    zero(arr,n);
}


void pow(ll**l,int n,ll y)
{
  ll**m = new ll*[n];
  for(int i=0;i<n;i++) m[i] = new ll[n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) {m[i][j] = l[i][j];}
  zero(l,n);
  ll**arr = new ll*[n];
  for(int i=0;i<n;i++) arr[i] = new ll[n];
  zero(arr,n);
  while(y)
  {
    if(y&1)
    {
      multiply(l,m,arr,n);
      copy(arr,l,n);
    }

    multiply(m,m,arr,n);
    copy(arr,m,n);
    y>>=1;

    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //   {
    //     cout<<l[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
  }
}

ll max(ll x, ll y)
{
  if(x<y) return y;
  return x;
}

int main()
{
  int n,t;
  sc(n);sc(t);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  
  ll ** dp = new ll*[n];
  for(int i=0;i<n;i++) dp[i] = new ll[n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = 0;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(l[j]<l[i]) {dp[i][j] = -INF;continue;}
      dp[i][j] = 1;
      for(int k=0;k<j;k++)
      {
        if(l[k]<=l[j]) dp[i][j] = max(dp[i][j],dp[i][k] +1);
        // else break;
      }
    }
  }
  pow(dp,n,t);
  ll max1 = -1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      max1 = max(max1,dp[i][j]);
    }
  }
  cout<<max1<<endl;

  return 0;
}

