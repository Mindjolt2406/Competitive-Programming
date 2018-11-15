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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int n;
  sc(n);
  ll sum1 =0,sum2 = 0;
  for(int i=0;i<n;i++)
  {
    ll a;
    scll(a);
    sum1+=a;
  }
  vector<ll> v;
  for(int i=0;i<n;i++)
  {
    ll a;
    scll(a);
    // sum2+=a;
    v.pu(a);
  }
  sort(v.begin(),v.end());
  ll a = v[v.size()-1];
  ll b = v[v.size()-2];
  if(a+b>=sum1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}

