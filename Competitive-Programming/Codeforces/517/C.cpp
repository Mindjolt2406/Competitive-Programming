#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
// #define int ll
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int32_t main()
{
  ll a,b;
  scll(a);scll(b);
  ll c = a+b,d = -1;
  for(ll i=1;i<100000;i++)
  {
    if((i*(i+1))/2 <=c) d = i;
    else break;
  }
  vector<ll> v;
  for(ll i=1;i<=d;i++) v.pu(i);
  vector<ll> v1,v2;
  for(ll i=v.size()-1;i>=0;i--)
  {
    if(b>=v[i]) {b-=v[i];v2.pu(v[i]);}
    else v1.pu(v[i]);
  }
  cout<<v1.size()<<endl;
  for(ll i=0;i<v1.size();i++) cout<<v1[i]<<" ";if(v1.size()) cout<<endl;
  cout<<v2.size()<<endl;
  for(ll i=0;i<v2.size();i++) cout<<v2[i]<<" ";if(v2.size()) cout<<endl;
  return 0;
}