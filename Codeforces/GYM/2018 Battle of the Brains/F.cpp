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
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

long long int size;
bitset<10000010> bs;
vector<int> counter(1000020);
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
      for(ll j = 2*i;j<size;j+=i) 
      {
        bs[j] = false;
        int k = j;
        int count = 0;
        while(k%i==0) {count++; k/=i;}
        counter[j]+=count;
      }
    }
    prime.pu((int)i);
  }
}

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  __;
  sieve(1000010);
  vector<int> v(1000010);
  int count = 0;
  bs[1] = true;
  for(int i=1;i<=1e6;i++)
  {
    if(counter[i]<=2) count++;
    v[i] = count;
  }
  // for(int i=0;i<20;i++) t(i,v[i]);

  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n;
    cin>>n;
    int a = v[n];
    int g = gcd(a,n);
    a/=g; n/=g;
    printf("Case %d: %d/%d\n",h,a,n);
  }
  return 0;
}

