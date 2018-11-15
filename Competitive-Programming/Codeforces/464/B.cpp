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
  scll(k);scll(n);
  ll *l = new ll[n];
  for(int i=0;i<n;i++) scll(l[i]);
  ll max1 = -1,ans1 = -1, ans2 = -1;
  for(int i=0;i<n;i++)
  {
    ll c = (k/l[i])*l[i];
    if(c>max1)
    {
      max1 = c;
      ans2 = k/l[i];
      ans1 = i+1;
    }
  }
  cout<<ans1<<" "<<ans2<<endl;
  return 0;
}
