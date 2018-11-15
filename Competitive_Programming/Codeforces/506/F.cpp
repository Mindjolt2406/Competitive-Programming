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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  ll a,b;
  scll(a);scll(b);
  ll a1 = a,b1 = b;
  a = min(a1,b1); b = max(a1,b1);
  // cout<<a<<" "<<b<<endl;
  vector<pair<ll,ll> > v1,v2,v3;
  for(int i=1;i<=sqrt(a);i++)
  {
    if(a%i==0)
    {
      v1.pu(mp(i,a/i));
    }
  }
  for(int i=1;i<=sqrt(b);i++)
  {
    if(b%i==0) v2.pu(mp(i,b/i));
  }
  ll c = a+b;
  for(int i=1;i<=sqrt(c);i++)
  {
    if(c%i==0) v3.pu(mp(i,c/i));
  }
  vector<pair<ll,pair<ll,ll> > > v;
  for(int i=0;i<v3.size();i++) v.pu(mp(2*(v3[i].first+ v3[i].second),v3[i]));
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++)
  {
    pair<ll,pair<ll,ll> > p = v[i];
    pair<ll,ll> p1 = p.second;
    ll a = p1.first, b = p1.second;
    for(int j=0;j<v1.size();j++)
    {
      pair<ll,ll> p2 = v1[j];
      ll a1 = p2.first,b1 = p2.second;
      if((a1<=a && b1<=b)|| (a1<=b && b1<=a)) { cout<<p.first<<endl;return 0;}
    }
    for(int j=0;j<v2.size();j++)
    {
      pair<ll,ll> p2 = v2[j];
      ll a1 = p2.first,b1 = p2.second;
      if((a1<=a && b1<=b)|| (a1<=b && b1<=a)) { cout<<p.first<<endl;return 0;}
    }
  }
  return 0;
}

