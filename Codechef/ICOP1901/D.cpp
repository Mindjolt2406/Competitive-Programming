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
    int n;
    sc(n);
    int *l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    ll m[1000001] = {0};
    m[2] = 1;
    for(int i=3;i<1000001;i++)
    {
      m[i]+=m[i-1]+(i*(i-1))/2;
    }
    
  }
  return 0;
}
