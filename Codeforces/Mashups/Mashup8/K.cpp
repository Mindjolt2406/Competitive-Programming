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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

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

bool check(int i,int j,int n)
{
  if(i<=0 || j<=0 || i>n || j>n) return false;
  return true;
}

void f(int a,int b,int n,vector<pair<int,int> > &w)
{
  if(check(a,b,n)) w.pu(mp(a,b));
}

int main()
{
  __;
  int n,q;
  cin>>n>>q;
  vector<int> v2(n),v(n);
  for(int i=0;i<n;i++) 
  {
    cin>>v2[i];
    v[v2[i]-1] = i+1;
  }

  // Store all the pairs for future offline queries
  vector<pair<int,int> > w; 

  // Store the rectangles in the order of the input
  vector<vector<int> > rect(q,vector<int> (4)); 
  unordered_map<pair<int,int> ,int, pair_hash> dict;
  // map<pair<int,int> ,int> dict;

  // BIT to answer the offline queries
  BIT bit; 
  bit.init(2e5+10);

  for(int h=0;h<q;h++)
  {
    int a,b,c,d;
    cin>>b>>a>>d>>c;
    rect[h][0] = a, rect[h][1] = b, rect[h][2] = c, rect[h][3] = d;

    f(a-1,b-1,n,w);
    f(a-1,d,n,w);
    f(a-1,n,n,w);
    f(c,b-1,n,w);
    f(c,d,n,w);
    f(c,n,n,w);
    f(n,b-1,n,w);
    f(n,d,n,w);
    f(n,n,n,w);
  }

  sort(w.begin(),w.end());

  int top = 0;
  
  // for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) w.pu(mp(i,j));

  for(int i=0;i<w.size();i++)
  {
    int a = w[i].fi;
    while(top<a)
    {
      bit.inc(v[top],1);
      top++;
    }

    dict[w[i]] = bit.sum(w[i].se);
  }

  // for(auto it : dict)
  // {
  //   t(it);
  // }

  for(int i=0;i<rect.size();i++) 
  {
    int a = rect[i][0];
    int b = rect[i][1];
    int c = rect[i][2];
    int d = rect[i][3];
    ll a1,a2,a3,a4,a5,a6,a7,a8,a9;
    a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = 0;

    // a1
    if(check(a-1,b-1,n)) a1 = dict[mp(a-1,b-1)];

    // a2
    if(check(a-1,d,n)) 
    {
      a2 = dict[mp(a-1,d)];
      a2 -= a1;
    }

    //a3
    if(check(a-1,n,n)) 
    {
      a3 = dict[mp(a-1,n)];
      a3 -= (a2 + a1);
    }

    //a4
    if(check(c,b-1,n)) 
    {
      a4 = dict[mp(c,b-1)];
      a4 -= a1;
    }

    //a5 
    a5 = dict[mp(c,d)];
    a5 -= (a1 + a2 + a4);

    //a6
    a6 = dict[mp(c,n)];
    a6 -= (a1 + a2 + a3 + a4 +a5);

    // a7
    if(check(n,b-1,n)) 
    {
      a7 = dict[mp(n,b-1)];
      a7 -= (a1 + a4);
    }

    //a8
    a8 = dict[mp(n,d)];
    a8 -= (a1 + a2 + a4 + a5 + a7);

    //a9
    a9 = dict[mp(n,n)];
    a9 -= (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);

    ll ans = a1*(a5 + a6 + a8 + a9) + a2*(a4 + a5 + a6 + a7 + a8 + a9) + a3*(a4 + a5 + a7 + a8);
    ans += a4*(a5 + a6 + a8 + a9) + (a5*(a5-1))/2 + a5*(a6 + a7 + a8 + a9) + a6*(a7 + a8);

    cout<<ans<<"\n"; 

  } 
  return 0;
}

