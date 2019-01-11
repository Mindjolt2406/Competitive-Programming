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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


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

int main()
{
  sieve(10010);
  for(int i=2;i<=10000;i++) 
  {
    int k = i;
    while(k%2==0) k/=2;
    while(k%5==0) k/=5;
    if(k==1) bs[i] = false;
  }
  int l[10010] = {0};
  int max1 = 0;
  for(int i=2;i<=10000;i++)
  {
    if(bs[i]) 
    {
      l[i] = max1;
      max1 = i;
    } 
    else l[i] = max1;
  }

  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    cout<<l[n]<<endl;
  }
  return 0;
}

