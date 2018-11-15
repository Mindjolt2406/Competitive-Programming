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
  int t;
  sc(t);
  while(t--)
  {
    ll n;
    scll(n);
    vector<ll> v;
    for(int i=1;i<1000000;i++)
    {
      v.pu(i*i*i);
    }
    ll count = 0;
    for(int i=0;i<v.size();i++)
    {
      count+= n/v[i] - (int)(pow((float)n/v[i],(1.0)/3)) + 1; 
    }
    cout<<count<<endl;
  }
  return 0;
}
