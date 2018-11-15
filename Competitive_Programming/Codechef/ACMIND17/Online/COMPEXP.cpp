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
    ld n,k;
    scld(n);scld(k);
    printf("%.10Lf\n",(n-((n-1)/k))*2);
    // cout<<setprecision(10);
    // cout<<(n-((n-1)/k))*2<<endl;
  }
  return 0;
}

