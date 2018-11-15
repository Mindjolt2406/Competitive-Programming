#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000000000000001
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

ll min(ll x,ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  int n;
  sc(n);
  ll*l = new ll[2*n];
  for(int i=0;i<2*n;i++) scll(l[i]);
  sort(l,l+2*n);
  ll min1 = INF;
  for(int i=0;i<n;i++)
  {
    if(i==0) min1 = min(min1,(l[n-1]-l[0])*(l[2*n-1]-l[n]));
    // else if(i==n) min1 = min(min1,l[])
    else min1 = min(min1,(l[n-1+i]-l[i])*(l[2*n-1]-l[0]));
  }
  printf("%lld\n",min1);
  return 0;
}
