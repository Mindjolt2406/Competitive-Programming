#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000000000000001
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
  ll n,x,y;
  scll(n);scll(x);scll(y);
  string s;
  scr(s);
  int count0 = 0;
  int i=0;
  int boo = 1;
  while(i<n)
  {
    if(boo && s[i]=='0'){count0++;boo = 0;}
    else if(s[i]=='1') {boo = 1;}
    i++;
  }
  ll min1 = INF;
  // cout<<count0<<endl;
  for(int i=0;i<count0;i++)
  {
    // cout<<(count0-i)*x + i*y<<endl;
    min1 = min(min1,(i)*x + (count0-i)*y);
  }
  if(min1!=INF)cout<<min1<<endl;
  else cout<<0<<endl;
  return 0;
}
