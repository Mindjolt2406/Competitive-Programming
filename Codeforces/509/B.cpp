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

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

ll min(ll x,ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  ll a,b,x,y;
  scll(a);scll(b);scll(x);scll(y);
  ll g = gcd(x,y);
  ll c = x/g;
  ll d = y/g;
  cout<<min(a/c,b/d)<<endl;
  return 0;
}
