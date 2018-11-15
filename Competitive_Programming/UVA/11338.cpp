#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);

using namespace std;

int gcd(int a,int b)
{
  while(b)
  {
    int c = a%b;
    a = b;
    b = c;
  }
  return a;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int a,b;
    sc(a);sc(b);
    ll c = a*b;
    if(c%(a*a)==0) printf("%d %d\n",a,b);
    else printf("-1\n");
  }
  return 0;
}
