/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

typedef struct BIT //ll
{
  vector<ll> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  ll sum(int i)
  {
    ll res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, ll delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  ll getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<ll> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
} BIT;

int main()
{
  __;
  int n;
  cin>>n;
  int counter = 1;
  while(!cin.eof())
  {
    cout<<"Case #"<<counter<<":"<<endl;
    vector<ll> v(n+1);
    for(int i=0;i<n;i++) cin>>v[i];
    set<int> s;
    for(int i=0;i<n;i++) if(v[i]!=1) s.insert(i);
    BIT bit;
    bit.init(v);
    int q;
    cin>>q;
    while(q--)
    {
      int a;
      cin>>a;
      if(a==0) // Update
      {
        int b,c;
        cin>>b>>c;
        b--;c--;
        if(b>c) swap(b,c);
        int a = b;
        // a = *s.lower_bound(a);
        while(a<=c && a>=b)
        {
          bit.inc(a,-1*v[a]);
          v[a] = sqrt(v[a]);
          bit.inc(a,v[a]);
          if(v[a]==1) s.erase(a);
          auto it = s.upper_bound(a);
          if(it==s.end()) break;
          a = *it;
        }
      }
      else
      {
        int b,c;
        cin>>b>>c;
        if(b>c) swap(b,c);
        b--;c--;
        cout<<bit.getsum(b,c)<<endl;
      }
    }
    cout<<endl;
    counter++;
    cin>>n;
  }
  return 0;
}

