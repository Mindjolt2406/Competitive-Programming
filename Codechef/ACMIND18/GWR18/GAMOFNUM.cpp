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
bitset<1000010> bs;
vi prime;
vector<pair<ll,ll> > counter[1000100];

void sieve(ll upperbound)
{
  size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      counter[i].pu(mp(i,1));
      for(ll j = 2*i;j<size;j+=i) 
      {
        bs[j] = false;
        ll k = j;
        int count =0 ;
        while(k%i==0) {count++;k/=i;}
        if(count!=0) counter[j].pu(mp(i,count));
      }
    }
    // prime.pu((int)i);
  }
}

int findmex(vector<ll> v)
{
  sort(v.begin(),v.end());
  int count = 0;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]!=count) return count;
    count++;
  }
  return count;
}

int main()
{
  sieve(1000000);
  counter[1].pu(mp(1,0));
  vector<ll> mex(1000100);
  for(int i=2;i<=1000000;i++)
  {
    vector<pair<ll,ll> > v = counter[i];
    vector<int> mex1;
    int k = i;
    for(int j=0;j<v.size();j++)
    {
      k = i;
      k/=v[j].fi;
      for(int x=1;x<v[j].fi;x++) mex1.pu(mex[x*k]);
    }
    int a = findmex(mex);
    mex[i] =a;
  }
  // for(int i=1;i<20;i++) t(i,counter[i]);
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    vector<int> v(n);
    for(int i=0;i<n;i++) sc(v[i]);
    int count = 0;
    vector<int> sg;
    for(int i=0;i<v.size();i++) 
    {
      sg.pu(mex[v[i]]);
    }
    for(int i=0;i<n;i++) count^=sg[i];
    if(count!=0) printf("Alice\n");
    else printf("Bob\n");
  }
  return 0;
}

