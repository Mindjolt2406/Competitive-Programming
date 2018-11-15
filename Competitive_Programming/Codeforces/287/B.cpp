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
  ll r,x1,y1,x2,y2;
  scll(r);scll(x1);scll(y1);scll(x2);scll(y2);
  ld c = sqrt((ld)pow(abs(y1-y2),2)+(ld)pow(abs(x1-x2),2));
  int count;
  cout<<setprecision(15);
  // cout<<(c/(2*r))<<" "<<(int)(c/(2*r))<<endl;

  if(c/(2*r) - (int)(c/(2*r))< 0.000000000000001) count = (int)(c/(2*r));
  else {count = (int)(c/(2*r)) + 1;}
  cout<<count<<endl;
  return 0;
}
