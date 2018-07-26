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

pair<ld,ld> f(ld a,ld b)
{
  return mp(0.6*a-0.8*b,0.8*a+0.6*b);
}

int main()
{
  pair<ld,ld> p = mp(3,4);
  for(int i=0;i<30;i++)
  {
    p = f(p.first,p.second);
    cout<<p.first<<" "<<p.second<<endl;
  }
  return 0;
}
