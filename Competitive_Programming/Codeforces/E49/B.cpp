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
  ll n,m;
  scll(n);scll(m);
  for(int i=0;i<m;i++)
  {
    ll a,b;
    scll(a);scll(b);
    ll count = 0;
    if((a+b)%2==0)
    {
      ll c = (a-1)*n+b;
      cout<<(c+1)/2<<endl;
    }
    else
    {
      ll c = (a-1)*n+b;
      // cout<<"c: "<<c<<endl;
      cout<<(c+1)/2+(n*n+1)/2<<endl;
    }
  }
  return 0;
}
