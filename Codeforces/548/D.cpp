/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

long long int size;
bitset<100010> bs;
vector<map<int,int> > factors(100010);
vi prime;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

void sieve(ll upperbound)
{
  size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    // factors[i][1] = 1;
    if(bs[i])
    {
      for(ll j = i;j<size;j+=i) 
      {
        ll k = j;
        while(k%i==0)
        {
          if(factors[j].find(i)==factors[j].end()) factors[j][i] = 1;
          else factors[j][i]++;
          k/=i;
        }
        bs[j] = false;
      }
    }
    prime.pu((int)i);
  }
}

int countDivisors(int n)
{
  map<int,int> d = factors[n];
  int count = 1;
  for(auto it : d) count*=(it.second+1);
  return count;
}

int main()
{
  __;
  sieve(100001);
  // for(auto it : factors[4]) t(it.first, it.second,countDivisors(4));
  vector<int> divisors(100004);
  for(int i=1;i<1e5+2;i++)
  {
    divisors[i] = countDivisors(i)-1;
    // t(i,divisors[i]);
  }
  divisors[1] = 1;
  int n;
  cin>>n;
  vector<ll> dp(n+1);
  for(int i=n;i>=1;i--)
  {
    // int boo = 0;
    if(i!=1) dp[i] = power(i,(i-1)*(i-1),MOD-2);
    for(int j=2*i;j<=n;j+=i)
    {
      // boo = 1;
      // j is a divisor of i
      int k = j/i;
      int k2 = divisors[k];
      //k2/m is the probability that you can get from j to i
      // if(k2==0) k2++;
      t(k2,i,j);
      ll c = power(k2,n,MOD-2);
      dp[i]+=(1+(dp[j])*c)%MOD;
      dp[i]%=MOD;
    }
  }

  cout<<dp[1]<<endl;
  for(int i=0;i<5;i++) t(i,dp[i]);
  t(power(3,4,MOD-2));
  return 0;
}

