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
int counter[100010] = {0};

void sieve(ll upperbound)
{
  size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      counter[i]++;
      for(ll j = 2*i;j<size;j+=i) {bs[j] = false;counter[j]++;}
    }
  }
}

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  sieve(100005);
  int t;
  sc(t);
  while(t--)
  {
    map<int,int> d;
    int n;
    sc(n);
    int in[100010] = {0};
    for(int i=0;i<n;i++) 
    {
      int a;
      sc(a);
      in[a]++;
    }

    int arr[100010] = {0};
    // for(auto it: d)
    // {
    //   t(it.first,counter[it.first]);
    //   for(int j=it.first;j<100010;j+=it.first) arr[j]+=it.second;
    // }

    for(int i=1;i<=100000;i++)
    {
      for(int j=i;j<=100000;j+=i)
      {
        if(in[j]) {arr[i]+=in[j];}
      }
    }

    ll max1 = -1;
    for(int i=1;i<=100000;i++)
    {
      max1 = max(max1,counter[i]*arr[i]);
    }
    printf("%lld\n",max1);

    // for(int i=1;i<=20;i++) t(i,arr[i],counter[i]);
  }
  return 0;
}

