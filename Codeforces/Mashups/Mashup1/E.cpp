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
  int*l = (int*)calloc(26,sizeof(int));
  for(int i=0;i<26;i++) sc(l[i]);
  string s;
  scr(s);
  vector<ll> v;
  ll sum1 = 0;
  map<pair<ll,char>,ll > d;
  map<pair<ll,char>,ll> :: iterator it;
  ll count = 0; 
  for(int i=0;i<s.size();i++) 
  {
    int c = s[i]-'a';
    ll c1 = l[c];
    v.pu(sum1+c1);
    if(d.find(mp(sum1,s[i]))!=d.end()) count+=d[mp(sum1,s[i])];
    if(d.find(mp(sum1+c1,s[i]))!=d.end()) d[mp(sum1+c1,s[i])]++;
    else d[mp(sum1+c1,s[i])] = 1;
    sum1+=c1;
  }
  cout<<count<<endl;
  return 0;
}

