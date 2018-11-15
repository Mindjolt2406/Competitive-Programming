#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

bitset<1000010> bs;
int size;
vi prime;

void sieve()
{
  bs.set();
  bs.set(0,false);bs.set(1,false);
  // cout<<"ehre"<<endl;
  for(ll i=2;i<1000001;i++)
  {
    if(bs.test((size_t)i))
    {
      // cout<<"here "<<i<<endl;
      for(ll j=i*i;j<1000001;j+=i)
      {
        // cout<<"here: "<<j<<endl;
        bs.set((size_t)j,false);
      }
      prime.pu(i);
      // cout<<i<<endl;
    }
  }
}

int main()
{
  sieve();
  int n;
  cin>>n;
  while(n)
  {
    int boo = 0;
    for(int i=0;i<prime.size();i++)
    {
      int c = n-prime[i];
      // cout<<prime[i]<<" "<<c<<endl;
      if(bs.test(c)) {cout<<n<<" = "<<prime[i]<<" + "<<c<<endl;boo = 1;break;}
    }
    if(!boo) cout<<"Goldbach's conjecture is wrong."<<endl;
    cin>>n;
  }
  return 0;
}
