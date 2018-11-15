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
#define scc(c) scanf("%c",&c);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n;
    sc(n);
    // char **l = new char*[3];
    // for(int i=0;i<2;i++) l[i] = new char[n];
    string*l = new string[3];

    for(int i=0;i<3;i++) scr(l[i]);
    int boo = 0;
    for(int i=0;i<n;i++) if(l[1][i]=='#') {boo = 1;break;}
    if(l[0][0]=='#' || l[n-1][2]=='#' || boo || n%2==1) {printf("Case #%d: 0\n",h);continue;}
    ll ans = 1;
    for(int i=0;i<n-2;i+=2)
    {
      int count = 2;
      if(l[0][i+1]=='#' || l[0][i+2]=='#') count--;
      if(l[2][i+1]=='#' || l[2][i+2]=='#') count--;
      ans*=count;
      ans%=MOD;
    }
    printf("Case #%d: %lld\n",h,ans);
  }
  return 0;
}
