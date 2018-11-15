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
  ll *l = new ll[10000005];
  l[0] = 0;l[1] = 1;
  for(int i=2;i<10000003;i++) {l[i] = 2*l[i-1] + 3*l[i-2];l[i]%=MOD;}
  cout<<(3*l[n-1])%MOD<<endl;
  return 0;
}

