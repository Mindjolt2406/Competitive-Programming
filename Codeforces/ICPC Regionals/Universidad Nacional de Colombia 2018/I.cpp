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
  int n,m;
  sc(n);sc(m);
  for(int i=0;i<m;i++)
  {
    ll a,b;
    scll(a);scll(b);
    b%=n;
    ll c = 1<<b;
    c--;
    c<<=(n-b);
    c&=a;
    c>>=(n-b);
    ll d = 1<<(n-b);
    d--;
    d&=a;
    d<<=b;
    c|=d;
    cout<<c<<endl;
  }
  return 0;
}
