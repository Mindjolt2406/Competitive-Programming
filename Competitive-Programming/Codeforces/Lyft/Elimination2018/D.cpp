// Implement this. DON'T CLOSE IT
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

long long int size;
bitset<10000010> bs;
vi prime;

void sieve(ll upperbound)
{
  size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      for(ll j = i*i;j<size;j+=i) bs[j] = false;
    }
    prime.pu((int)i);
  }
}

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  sieve(3000000);
  cout<<"here"<<endl;
  int n;
  sc(n);
  ll *l = new ll[n];
  map<ll,int> d,dprime;
  map<ll,int> :: iterator it; 
  vector<ll> v;
  for(int i=0;i<n;i++) scll(l[i]);
  cout<<"here1"<<endl;
  ll prod = 1;
  for(int i=0;i<n;i++)
  {
    ll k = l[i];
    int boo = 1;
    for(int j=0;j<prime.size();j++)
    {
      // cout<<"j: "<<j<<"prime: "<<prime[j]<<endl;
      if(prime[j]<=1500000000 && prime[j]*prime[j]==k)  
      {
        if(d.find(prime[j])==d.end()) d[prime[j]] = 3;
        else d[prime[j]]+=3;
        boo = 1;break;
      }
      else if(prime[j]<=2000000 && prime[j]*prime[j]*prime[j]==k) 
      {
        if(d.find(prime[j])==d.end()) d[prime[j]] = 4;
        else d[prime[j]]+=4;
        boo = 1;break;
      }
      else if(prime[j]<=38000 && prime[j]*prime[j]*prime[j]*prime[j]==k) 
      {
        if(d.find(prime[j])==d.end()) d[prime[j]] = 5;
        else d[prime[j]]+=5;
        boo = 1;break;
      }
      else boo = 0;
      // cout<<"here2"<<endl;
    }
    cout<<"prod: "<<prod<<endl;
    cout<<"here"<<endl;
    if(!boo) 
    {
      if(d.find(k)!=d.end()) d[k]++;
      else d[k] = 1;
      for(it=d.begin();it!=d.end();it++) v.pu(it->first);
      for(int i=0;i<v.size();i++)
      {
        int boo = 1;
        for(int j=i+1;j<v.size();j++)
        {
          ll g = gcd(v[i],v[j]);
          if(g!=1)
          {
            boo = 0;
            if(dprime.find(g)!=d.end()) dprime[g]+=2;
            else dprime[g] = 2;
          }
        }
        if(boo) {prod*=4*d[v[i]];prod%=MOD;}
      }
    }
  }
  for(it = dprime.begin();it!=dprime.end();it++)  
  {
    cout<<it->first<<" ";
    int c = it->second/2+1;
    cout<<c<<endl;
    prod*=(c+1);prod%=MOD;
  }
  cout<<prod<<endl;
  return 0;
}

