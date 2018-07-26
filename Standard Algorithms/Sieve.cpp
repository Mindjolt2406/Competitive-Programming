#include<bitset>
#include<iostream>
#include<vector>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

long long int size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound)
{
  size = upperbound + 1;
  bs.reset();bs.flip();
  bs.set(0,false);
  bs.set(1,false);
  for(ll i = 2;i< size;i++)
  {
    if(bs.test((size_t)i))
    {
      for(ll j = i*i;j<size;j+=i) bs.set((size_t)j,false);
    }
    primes.pu((int)i);
  }
}

bool isPrime(ll N)
{
  if(N<size) return bs.test(N);
  for(int i=0;i<primes.size();i++) if(N%primes[i]==0) return false;
  return true;
}

int main()
{
  sieve(10000000);
  ll n;
  cin>>n;
  cout<<isPrime(n)<<endl;
}
