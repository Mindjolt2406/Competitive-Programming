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
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

bool sorter(pair<int,int> p1, pair<int,int> p2)
{
  if(p1.fi < p2.fi) 
  {
    return true;
  }
  if(p1.fi == p2.fi) 
  {
    if(p1.se > p2.se) return true;
  }
  return false;
}

ll compute(multiset<ll> &l1, multiset<ll> &r1, multiset<ll> &l2, multiset<ll> &r2)
{
  // t(*l1.rbegin(),*r1.begin(),*l2.rbegin(),*r2.begin());
  return max(0,-*l1.rbegin()+*r1.begin()+1) + max(0,-*l2.rbegin()+*r2.begin()+1);
}

void f(vector<pair<int,int > > &v, ll &ans)
{
  multiset<ll> l1,r1,l2,r2;
  for(int i=0;i<v.size();i++) {l2.insert(v[i].fi);r2.insert(v[i].se);}

  for(int i=0;i<v.size()-1;i++)
  {
    ll a = v[i].fi, b = v[i].se;
    l1.insert(a);
    r1.insert(b);
    l2.erase(l2.find(a));
    r2.erase(r2.find(b));
    ll temp = compute(l1,r1,l2,r2);
    // t(i,temp);
    ans = max(ans,temp);
  }
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<pair<int,int> > v;
  ll ans = 0;
  int idx = -1;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    v.pu(mp(a,b));
  }

  sort(v.begin(),v.end(),sorter);
  // t(v);
  int max1 = 0;
  for(int i=0;i<v.size();i++)
  {
    int a = v[i].fi, b = v[i].se;
    if(max1 < b-a+1) 
    {
      max1 = b-a+1;
      idx = i;
    }
  }

  ans = max1;
  int temp_l = 0, temp_r = INF;
  for(int i=0;i<v.size();i++)
  {
    if(i!=idx)
    {
      temp_l = max(temp_l,v[i].fi);
      temp_r = min(temp_r,v[i].se);
    }
  }
  ans = ans+max(0,temp_r-temp_l+1);
  // t(ans);
  f(v,ans);

  for(int i=0;i<v.size();i++)
  {
    pair<ll,ll> p = v[i];
    v[i].se = p.fi;
    v[i].fi = p.se;
  }

  f(v,ans);
  cout << ans << endl;
  return 0;
}

