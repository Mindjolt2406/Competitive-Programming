#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define MOD 100000007
#define INF 1000000001
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
  int l[500001] = {0};
  l[1] = 1;
  for(int i=2;i<500001;i++) {l[i] = l[i-1]+l[i-2];l[i]%=MOD;}
  while(t--)
  {
    int n;
    sc(n);
    printf("%d\n",l[n]);
  }
  return 0;
}
