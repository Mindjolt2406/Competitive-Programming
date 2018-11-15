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
#define sc(n) scanf("%d",&n)
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

ll power(ll x,ll y, ll p)
{
  ll res = 1;
  while(y)
  {
    if(y%2==1) {res*=x;res%=p;}
    x*=x;
    x%=p;
    y>>=1;
  }
  return res;
}

int main()
{
  int a,b,c;
  while(sc(a)!=EOF)
  {
    sc(b);sc(c);
    printf("%lld\n",power(a,b,c));
  }
  return 0;
}
