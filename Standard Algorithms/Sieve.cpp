#include<bitset>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

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

bool isPrime(ll N)
{
  if(N<size) return bs.test(N);
  for(int i=0;i<prime.size();i++) if(N%prime[i]==0) return false;
  return true;
}

// int main()
// {
//   sieve(10000000);
//   ll n;
//   cin>>n;
//   cout<<isPrime(n)<<endl;
// }

int main()
{
  ll n = 470598593461;
  for(int i=2;i<sqrt(n)+1;i++)
  {
    if(isPrime(i) && n%i == 0 && isPrime(n/i)) cout << i << " " << n/i << endl;
  }

}
