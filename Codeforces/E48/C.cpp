// Upsolved
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

ll max(ll a, ll b)
{
  if(a>b) return a;
  return b;
}

int main()
{
  int n;
  sc(n);
  ll*a = new ll[n];
  ll*b = new ll[n];
  ll*c = new ll[n];
  for(int i=0;i<n;i++) scll(a[i]);
  for(int i=0;i<n;i++) scll(b[i]);
  for(int i=0;i<n;i++) c[i] = a[i]+b[i];
  for(int i=1;i<n;i++) c[i] += c[i-1];
  ll a1 = 0,a2 = 0;
  ll count = 0;
  for(int i=0;i<n;i++)
  {
    a1+=count*a[i];
    count++;
    if(i>=1) a2 += count*b[i];
  }
  for(int i=n-1;i>=0;i--)
  {
    a1+=count*b[i];
    // cout<<"a1: "<<a1<<"count: "<<count<<endl;
    count++;
    if(i>=1) a2+=count*a[i];
  }
  // if(n==300000)cout<<a1<<" "<<a2<<" "<<count<<endl;
  ll max1 = a1;
  a2+=b[0]*1;
  ll a3 = 0,a4 = 0;
  count--;
  for(int i=0;i<n;i++)
  {
    if(i%2==0)
    {
      if(i>=2)
      {
        // cout<<"i: "<<i<<" a1: "<<a1<<endl;
        a1+=2*a[i-1];
        // cout<<"i: "<<i<<" a1: "<<a1<<endl;
        a1-=(b[i-2]*(2*n-1) + b[i-1]*(2*n-2));
        // cout<<"i: "<<i<<" a1: "<<a1<<endl;
        a1+=b[i-2]*(2*i-3)+b[i-1]*(2*i-2);
        // cout<<"i: "<<i<<" a1: "<<a1<<endl;
        a1+=(c[n-1]-c[i-1])*2;
        // cout<<"i: "<<i<<" a1: "<<a1<<endl;
        // a1+=2*a[i-2];
      }
      // cout<<"i: "<<i<<" a1: "<<a1<<endl;
      max1 = max(max1,a1);
    }
    else
    {
      if(i>=3)
      {
        a2+=b[i-1]*2;
        a2-=(a[i-2]*(2*n-1) + a[i-1]*(2*n-2));
        a2+=a[i-2]*(2*i-3) + a[i-1]*(2*i-2);
        a2+=(c[n-1]-c[i-1])*2;
      }
      // cout<<"i: "<<i<<" a2: "<<a2<<endl;
      max1 = max(max1,a2);
    }
    // cout<<"i: "<<i<<" max1: "<<max1<<endl;
  }
  printf("%lld\n",max1);
  return 0;
}
