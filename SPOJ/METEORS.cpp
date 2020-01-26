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
  int n,m; // m is the number of states and n is the number of sectors
  cin >> n >> m;
  vector<vector<int> > own(n);
  vector<int> sample(n);

  for(int i=0;i<m;i++)
  {
    int a;
    cin >> a;
    a--;
    own[a].pu(i);
  }

  BIT bit;
  bit.init(m+10);

  for(int i=0;i<n;i++) cin >> sample[i];

  int t;
  cin >> t;
  vector<pair<pair<int,int>, ll> > que;
  for(int h=0;h<t;h++)
  {
    int x,y;
    ll z;
    cin >> x >> y >> z;
    x--; y--;
    que.pu(mp(mp(x,y),z));
  }

  queue<pair<pair<int,int> , vector<int> > > q;
  vector<int> search(n);
  for(int i=0;i<n;i++) search[i] = i;

  q.push(mp(mp(0,t-1),search));
  vector<int> ans(n,-1);

  int counter = -1;

  while(!q.empty())
  {
    pair<pair<int,int> , vector<int> > p = q.front();
    q.pop();
    vector<int> &v = p.se;
    int beg = p.fi.fi, end = p.fi.se;

    int mid = (beg + end) >> 1;

    if(counter > mid) // Remove the earlier queries
    {
      for(int i=counter;i>mid;i--)
      {
        pair<pair<int,int>, ll> p = que[i];
        int left = p.fi.fi, right = p.fi.se;
        ll val = -1*p.se;
        if(left<=right) 
        {
          bit.inc(left,val);
          bit.inc(right+1,-val);
        }
        else 
        {
          bit.inc(left,val);
          bit.inc(m,-val);
          bit.inc(0,val);
          bit.inc(right+1,-val);
        }
      }
      counter = mid;
    }
    else
    {
      for(int i=counter+1;i<=mid;i++)
      {
        pair<pair<int,int>, ll> p = que[i];
        int left = p.fi.fi, right = p.fi.se;
        ll val = p.se;
        if(left<=right) 
        {
          bit.inc(left,val);
          bit.inc(right+1,-val);
        }
        else 
        {
          bit.inc(left,val);
          bit.inc(m,-val);
          bit.inc(0,val);
          bit.inc(right+1,-val);
        }
      }

      counter = mid;
    }

    vector<int> left,right;
    for(int i=0;i<v.size();i++)
    {
      int idx = v[i];
      ll sum1 = 0;
      for(int j=0;j<own[idx].size();j++)
      {
        int part = own[idx][j];
        sum1 += bit.sum(part);
      }

      if(sum1 >= sample[idx])
      {
        ans[idx] = mid+1;
        if(beg<=mid-1) left.pu(idx);
      }
      else
      {
        if(end >= mid+1) right.pu(idx);
      }
    }

    if(left.size()) q.push(mp(mp(beg,mid-1),left));
    if(right.size()) q.push(mp(mp(mid+1,end), right));
  }

  for(int i=0;i<n;i++) 
  {
    if(ans[i]+1) cout << ans[i] << endl;
    else cout << "NIE" << endl;
  }
  return 0;
}

