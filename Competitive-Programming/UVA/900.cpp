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
  ll l[60] = {0};
  l[0] = 1;
  l[1] = 1;
  for(int i=2;i<51;i++) l[i] = l[i-1]+l[i-2];
  int n;
  sc(n);
  while(n)
  {
    printf("%lld\n",l[n]);
    sc(n);
  }
  return 0;
}
