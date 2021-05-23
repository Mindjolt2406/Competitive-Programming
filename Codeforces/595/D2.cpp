#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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

typedef struct BIT //int
{
  vector<int> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  int sum(int i)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, int delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  int getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
} BIT;

int main()
{
  __;
  int n,k;
  cin >> n >> k;

  vector<pair< pair<int,int>, int> > v(n);
  for(int i=0;i<n;i++) 
  {
    cin >> v[i].fi.fi >> v[i].fi.se;
    v[i].se = i+1;
  }

  sort(v.begin(),v.end());

  BIT bit;
  bit.init(2e5+10);

  int index = 0;
  set<pair<int,pair<int,int> > > rightIndex; // <right, <left,index> > 
  vector<int> ans;
  for(int i=1;i<=2e5;i++)
  {
    while(index < v.size() && v[index].fi.fi <= i)
    {
      int left = v[index].fi.fi, right = v[index].fi.se;
      rightIndex.insert(mp(right,mp(left,v[index].se)));
      bit.inc(left,1);
      bit.inc(right+1,-1);
      index++;
    }

    int sum1 = bit.sum(i);
    while(sum1 > k)
    {
      auto it = *rightIndex.rbegin();
      bit.inc(it.se.fi,-1);
      bit.inc(it.fi+1,1);
      ans.pu(it.se.se);
      sum1--;
      rightIndex.erase(it);
    }
  }

  cout << ans.size() << endl;
  for(auto it : ans) cout << it << " "; cout << endl;
  return 0;
}
