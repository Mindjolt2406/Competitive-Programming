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
  ll n,k;
  scll(n);scll(k);
  vector<ll> v;
  ll sum1 = 0;
  for(int i=0;i<n;i++)
  {
    ll a,b;
    scll(a);scll(b);
    v.pu(a-b);
    sum1+=a;
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  int i=0,count = 0;
  while(sum1>k && i<n)
  {
    // cout<<sum1<<" "<<v[i]<<endl;
    sum1-=v[i];
    count++;
    i++;
  }
  // cout<<v.size()<<endl;
  if(sum1>k) cout<<-1<<endl;
  else cout<<count<<endl;
  return 0;
}
