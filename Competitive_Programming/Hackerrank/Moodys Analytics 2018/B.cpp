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

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    ll sum1 = 0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
      ll a,b;
      scll(a);scll(b);
      if(b-a>0) sum1+=b-a;
      else sum1-=(a-b);
    }
    if(sum1>0) printf("1\n");
    else printf("0\n");
  }
  return 0;
}
