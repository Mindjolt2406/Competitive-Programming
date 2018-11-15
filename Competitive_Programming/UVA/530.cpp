#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
//9:49 - 10:11
using namespace std;

// A cheaper yet a shorter solution is to simply compute nCk by looping n-k+1 times,
// multiplying and dividing terms from the numerator and denominator respectively

map <pair<int,int>,int> dp;

int C(int n,int k)
{
  // cout<<"n: "<<n<<" k: "<<k<<endl;
  pair<int,int> p = mp(n,k);
  pair<int,int> p1 = mp(n,n-k);
  if(n==0) return 0;
  else if(k==0 || n==k) return 1;
  else if(k==1 || n-k==1) return n;
  if(dp.find(p)!=dp.end()) return dp[p];
  else if(dp.find(p1)!=dp.end()) return dp[p1];
  dp[p] =  C(n-1,min(k-1,n-k)) + C(n-1,min(k,n-k-1));
  dp[p1] = dp[p];
  // cout<<p.first<<" "<<p.second<<" "<<dp[p]<<endl;
  return dp[p];
}
int main()
{
  int a,b;
  sc(a);
  while(a)
  {
    sc(b);
    printf("%d\n",C(a,b));
    sc(a);
  }
  return 0;
}
