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

ll divc(ll a, ll b)
{
  if(a%b) return a/b +1;
  else return a/b;
}

int main()
{
  ll n,k,dist;
  scll(n);scll(k);scll(dist);
  if(k*n-k<dist || dist<k)cout<<"NO"<<endl;
  else
  {
    vector<ll> v;
    int boo = 0,start = 1;
    while(k)
    {
      ll c = divc(dist,k);
      if(!boo) {v.pu(start+c);start+=c;}
      else {v.pu(start-c);start-=c;}
      dist-=c;
      k--;boo++;boo%=2;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<v.size();i++) printf("%lld ",v[i]);
    printf("\n");
  }
  return 0;
}
