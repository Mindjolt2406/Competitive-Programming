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

bitset<20000000> bs,bs1;
ll size = 16000000;
int prime[16000000] = {0};
map<int,int> d;

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

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

void sieve()
{
  bs.set();
  for(int i=0;i<size;i++) prime[i] = 0;
  bs[0] = bs[1] = false;
  for(ll i=2;i<size;i++)
  {
    if(bs[i])
    {
      if(bs1[i]) prime[i]+=d[i];
      for(ll j = 2*i;j<size;j+=i)
      {
        bs[j] = false;
        if(bs1[j]) 
        {
          prime[i]+=d[j];
        }
      }
    } 
  }
}

int main()
{
  int n;
  sc(n);
  bs1.reset();
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  ll g = l[0];
  for(int i=1;i<n;i++) g = gcd(min(g,l[i]),max(g,l[i]));
  for(int i=0;i<n;i++) 
  {
    l[i]/=g;
    if(d.find(l[i]) == d.end()) d[l[i]] = 1;
    else d[l[i]] ++;
  }
  for(int i=0;i<n;i++) bs1[l[i]] = true;
  sieve();
  int max1 = -1;
  for(int i=0;i<size;i++) max1 = max(max1,prime[i]);
  if(max1==0) cout<<-1<<endl;
  else cout<<n-max1<<endl; 
  return 0;
}

