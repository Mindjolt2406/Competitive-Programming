#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vll vector<long long ll>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  ll l[31] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,1073741824};
  set<ll> s1;
  ll prod = 1;
  for(ll i=0;i<31;i++)
  {
    s1.insert(prod);
    prod*=2;
  }
  ll n;
  scll(n);
  set<ll> s;
  ll* l1 = new ll[n];
  set<ll>::iterator it;
  map<ll,ll> d2;
  for(ll i=0;i<n;i++)
  {
    ll a;
    scll(a);
    l1[i] = a;
    d2[a] = 0;
    s.insert(a);
  }
  ll count = 0;
  map<ll,ll> d;
  for(int i=0;i<n;i++) d2[l[i]]++;
  map<ll,ll> :: iterator it1;
  for(it = s.begin();it!=s.end();it++)
  {
    ll a = *it;
    ll boo = 0;
    for(ll i=0;i<31;i++)
    {
      // cout<<a<<" "<<l[i]<<endl;
      if(l[i]-a>a && s.find(l[i]-a)!=s.end()) {boo = 1;d[a] = l[i]-a;d[l[i]-a] = a;break;}
      // else if(s.find(a+l[i])!=s.end()) {boo = 1;break;}
    }
    if(!boo && d.find(a)==d.end()) {count+=d2[l[a]];d[a] = -1;}
    // cout<<a<<endl;
  }
  cout<<count<<endl;
  // ll m[30] = {0};
  // for(ll i=0;i<n;i++) if(s1.find(l1[i])!=s1.end()) d2[l1[i]]++;
  // for(ll i=0;i<30;i++) if(s.find(l[i])!=s.end()) {cout<<"here"<<endl;m[i]++;}
  for(it = s1.begin();it != s1.end();it++) if(s.find(*it)!=s.end() && d[*it] == -1) count-=d2[*it];
  // for(ll i=0;i<30;i++) cout<<m[i]<<" ";cout<<endl;
  // for(ll i=0;i<30;i++) if(m[i]>1) count--;
  cout<<count<<endl;
  return 0;
}
