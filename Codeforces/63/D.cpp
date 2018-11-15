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
  int x,y,n,d;
  sc(x);sc(y);sc(n);sc(d);
  vector<pair<int,int> >v;
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    v.pu(mp(a,b));
  }
  for(int i=0;i<pow(2,n);i++)
  {
    
  }
  return 0;
}
