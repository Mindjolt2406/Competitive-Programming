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

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  ll n,a,b,c;
  scll(n);scll(a);scll(b);scll(c);
  if(n%4==0) cout<<0<<endl;
  else if(4-n%4==1) cout<<min(min(a,b+c),3*c)<<endl;
  else if(4-n%4==2) cout<<min(min(b,2*a),2*c)<<endl;
  else if(4-n%4==3) cout<<min(min(3*a,c),a+b)<<endl;
  return 0;
}

