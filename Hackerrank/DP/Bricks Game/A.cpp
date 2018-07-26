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

ll max(ll a,ll b,ll c)
{
  ll d = a>b?a:b;
  ll e = d>c?d:c;
  return e;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int *l= new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    reverse(l,l+n);
    if(n<=4)
    {
      int i=0;
      ll sum1 = 0;
      while(n-- && i<3)
      {
        sum1+=l[n-i-1];
        i++;
      }
      printf("%lld\n",sum1);
      continue;
    }
    ll *opt = new ll[n];
    ll *next = new ll[n];
    opt[0] = l[0];
    opt[1] = l[0]+l[1];
    opt[2] = l[0]+l[1]+l[2];
    opt[3] = l[1]+l[2]+l[3];
    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = l[0];
    for(int i=4;i<n;i++)
    {
      ll a = l[i] + next[i-1];
      ll b = l[i] + l[i-1] + next[i-2];
      ll c = l[i] + l[i-1] + l[i-2] + next[i-3];
      opt[i] = max(a,b,c);
      if(opt[i]==a) next[i] = opt[i-1];
      else if(opt[i]==b) next[i] = opt[i-2];
      else next[i] = opt[i-3];
    }
    printf("%lld\n",opt[n-1]);
  }
  return 0;
}
