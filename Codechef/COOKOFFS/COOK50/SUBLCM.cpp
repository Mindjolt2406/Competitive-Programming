// I haven't implemented this
// The main thing here is that dp[n] = dp[n-1]+ 1 if there is no number in the subarray given by dp[n-1] which isn't coprime to 
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
vector<int>* allPrimes;

void sieve(ll upperbound)
{
  allPrimes = new vector<int>[1000010];
  size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      allPrimes[i].pu(i);
      for(ll j = 2*i;j<size;j+=i) {bs[j] = false;allPrimes[j].pu(i);}
    }
    prime.pu((int)i);
  }
}

int main()
{
  int t;
  sc(t);
  sieve(1000005);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n+1];
    int*dp = new int[n+1];
    for(int i=0;i<n;i++) dp[i] = INF;
    dp[0] = 1;
    for(int i=0;i<n;i++) sc(l[i]);
    unordered_map<int,int> primeToIndex;
    for(int i=0;i<n;i++)
    {
      if(i!=0)
      {
        int boo = 0;
        for(int j=0;j<allPrimes[l[i]].size();j++)
        {
          int p = allPrimes[l[i]][j];
          // t(i,l[i],p);
          if(primeToIndex.find(p) != primeToIndex.end() && primeToIndex[p]>=i-dp[i-1]) { dp[i] = min(dp[i],i-primeToIndex[p]);boo = 1;}
        }
        // t(boo,i);
        if(!boo) dp[i] = dp[i-1]+1;
      }

      for(int j=0;j<allPrimes[l[i]].size();j++)
      {
        primeToIndex[allPrimes[l[i]][j]] = i;
      }
    }
    int max1 = -1;
    for(int i=0;i<n;i++)
    {
      if(dp[i]!=1) max1 = max(max1,dp[i]);
    }
    printf("%d\n",max1);
    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";cout<<endl;
  }
  return 0;
}

