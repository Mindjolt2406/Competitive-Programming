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


// I've done utter crap for this one. Need to rethink this one completely
struct BIT
{
  // CHANE STUFF TO LL IF NEEDED
  // here
  vector<ll> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  ll sum(int i)
  {
    // here up and down
    ll res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, ll delta)
  {
    // delta changes to ll if needed
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  ll getsum(int l,int r)
  {
    // The return value changes to ll if needed
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(v[i],1);
  }
};

int main()
{
  typedef struct BIT fen;
  int n;
  sc(n);
  // vector<ll> v;
  set<ll> s;
  set<ll> :: iterator it;
  map<ll,int> d;
  vector<pair<int,ll> > v1;
  for(int i=0;i<n;i++)
  {
    ll a,b,c;
    sc(a);scll(b);scll(c);
    b = b*1000000000 + c;
    s.insert(b);
    v1.pu(mp(a,b));
  }
  int count = 1;
  for(it=s.begin();it!=s.end();it++)
  {
    ll c = *it;
    if(d.find(c)==d.end()) {d[c] = count;count++;}
  }
  vector<ll> v;
  for(int i=0;i<v1.size();i++)
  {
    a = a*1000000000 + d[b];
    s.insert(a);
    v.pu(a);
  }
  d.clear();
  count = 1;
  for(it = s.begin();it!=s.end();it++)
  {
    ll c = *it;
    if(d.find(c)==d.end()) {d[c] = count;count++;}
  }
  vector<int> v2;
  for(int i=0;i<v.size();i++) v2.pu(d[v[i]]);
  fen bit;
  bit.init(v2);

  return 0;
}

