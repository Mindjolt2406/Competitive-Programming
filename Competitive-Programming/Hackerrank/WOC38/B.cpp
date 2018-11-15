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
  ll n,k;
  map<ll,ll> d;
  map<ll,ll> :: iterator it;
  vector<ll> v;
  cin>>n>>k;
  for(int i=0;i<n;i++) {ll a;cin>>a;v.pu(a);}
  ll prod = 0;
  for(int i=0;i<n;i++)
  {
    prod = k*i;
    ll c = v[i]-prod;
    if(d.find(c)!=d.end()) d[c]++;
    else d[c] = 1;
  }
  ll max1 = 0;
  for(it = d.begin();it!=d.end();it++)
  {
    max1 = max(max1,it->second);
  }
  cout<<n-max1<<endl;
  return 0;
}
