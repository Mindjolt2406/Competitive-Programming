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
  string s,t;
  scr(s);scr(t);
  int n1 = s.size(),n2 = t.size(),count = 0;
  while(n1>=0 && n2>=0)
  {
    if(s[n1-1]==t[n2-1]) {n1--;n2--;}
    else break;
  }
  count =(n1+n2);
  if(count<0) cout<<0<<endl;
  else cout<<count<<endl;
  return 0;
}
