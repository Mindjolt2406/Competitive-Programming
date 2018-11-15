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
  int n;
  sc(n);
  vector<pair<ld,string> > v;
  for(int i=0;i<n;i++)
  {
    ld a;
    scld(a);
    string s;
    scr(s);
    a/=s.size();
    sort(s.begin(),s.end());
    v.pu(mp(a,s)); 
  }
  sort(v.begin(),v.end());
  bitset<3> bs;
  bs.reset();
  for(int i=0;i<n;i++)
  {
    pair<ld,string> p = v[i];
    ld a = p.first*p.second.size();
    for(int j=0;j<s.size();j++)
    {
      if(bs[s[j]-'a']==false)
    }
  }
  return 0;
}
