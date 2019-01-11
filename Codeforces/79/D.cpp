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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll getsum(ll*v, int i,int j)
{
  if(i!=0) return v[j]-v[i-1];
  return v[j];
}

int main()
{
  int n,m;
  sc(n);sc(m);
  int c = 2*m+10;
  map<ll,ll> d;
  vector<vector<ll> > v;
  v.resize(c);
  vector<pair<ll,ll> > w;
  vector<ll> vmin;
  for(int i=0;i<m;i++)
  {
    ll a,b;
    scll(a);scll(b);
    d[a] = 1;d[b] = 1;
    w.pu(mp(a,b));
  }
  if(d.find(n)==d.end()) {cout<<0<<endl;return 0;}
  

  int count = 0;
  for(auto it: d)
  {
    d[it.first] = count;
    count++;
  }

  sort(w.begin(),w.end());

  for(int i=0;i<w.size();i++)
  {
    pair<ll,ll> p = w[i];
    v[d[p.se]].pu(d[p.fi]);
  }

  for(int i=0;i<v.size();i++) sort(v[i].begin(),v[i].end());

  ll *dp = new ll[c];
  for(int i=0;i<c;i++) dp[i] = 0;
  if(d.find(0)!=d.end()) dp[0] = 1;
  ll *dpref = new ll[c];
  for(int i=0;i<c;i++) dpref[i] = 0;
  if(dp[0]) dpref[0] = 1;
  for(int i=1;i<v.size();i++)
  {
    dpref[i]+=dpref[i-1];
    dpref[i]%=MOD;
    if(!v[i].empty())
    {
      for(int j=0;j<v[i].size();j++)
      {
        ll a = getsum(dpref,v[i][j],i);
        // t(i,v[i][0],a);
        a+=MOD;
        a%=MOD;
        dp[i] += a;
        dp[i]%=MOD;
      }
    }
    dpref[i] += dp[i];
    dpref[i]%=MOD;
  }

  cout<<dp[d[n]]<<endl;
  return 0;
}

