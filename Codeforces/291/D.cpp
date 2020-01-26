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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

const int M1 = 1e9+7;
const int M2 = 1e9+9;
const int P1 = 133;
const int P2 = 144;
const int N = 6e5+100;
vector<ll> pow1(N),pow2(N);

void calc_hash(pair<vector<int>&,vector<int>& > &p, string &s)
{
  int n = s.size();

  vector<int> v(n), w(n);

  v[0] = w[0] = s[0];

  for(int i=1;i<n;i++)
  {
    v[i] = (s[i]*pow1[i])%M1 + v[i-1];
    v[i] %= M1;

    w[i] = (s[i]*pow2[i])%M2 + w[i-1];
    w[i] %= M2;
  }
  // ll cnt1 = 0, cnt2 = 0;
  // for(int i=0;i<n;i++) 
  // {
  //   cnt1 *= P1;
  //   cnt1 += s[n-i-1];
  //   cnt1 %= M1;

  //   cnt2 *= P2;
  //   cnt2 += s[n-i-1];
  //   cnt2 %= M2;

  //   v[i] = cnt1; w[i] = cnt2;
  // }

  p.fi = v;
  p.se = w;
  return;
}

pair<int,int> get_hash(pair<vector<int> &,vector<int> & > & p, string &s, int i,int j)
{
  int n = s.size();

  vector<int> v = p.fi, w = p.se;
  // Edge cases only for this particular problem
  if(j < 0) return mp(0,0);
  if(i == n) return mp(0,0);
  if(i==0) return mp(v[j],w[j]);

  // Prefix sum part
  ll c1 = v[j] - v[i-1] + M1 , c2 = w[j] - w[i-1] + M2;
  if(c1 >= M1) c1 -= M1;
  if(c2 >= M2) c2 -= M2;

  // Multiply by the inverse
  c1 *= power(power(P1,i,M1),M1-2,M1);
  c1 %= M1;

  c2 *= power(power(P2,i,M2),M2-2,M2);
  c2 %= M2;

  return mp(c1,c2);
}


int main()
{
  __;
  int n,m;
  cin>>n>>m;
  unordered_set<pair<int,int>,pair_hash > d;

  pow1[0] = pow2[0] = 1;
  for(int i=1;i<N;i++) 
  {
    pow1[i] = pow1[i-1]*P1;
    pow2[i] = pow2[i-1]*P2;

    pow1[i] %= M1;
    pow2[i] %= M2;
  }


  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    pair<vector<int> &, vector<int>& > p;
    calc_hash(p,s);

    d.insert(get_hash(p,s,0,s.size()-1));
  }

  // for(auto it : d) t(it);

  for(int i=0;i<m;i++)
  {
    string s;
    cin>>s;
    pair<vector<int> &, vector<int> &> p;
    calc_hash(p,s);

    bool boo = false;

    for(int i=0;i<s.size();i++)
    {
      pair<ll,ll> p1 = get_hash(p,s,0,i-1);
      pair<ll,ll> p2 = get_hash(p,s,0,s.size()-1);
      pair<ll,ll> p3 = get_hash(p,s,0,i);


      p2.fi = p2.fi - p3.fi + p1.fi + M1;
      p2.se = p2.se - p3.se + p1.se + M2;
      p2.fi %= M1; p2.se %= M2;

      if(s[i]!='a') 
      {
        ll c1 = p2.fi + 'a'*pow1[i];
        ll c2 = p2.se + 'a'*pow2[i];
        c1 %= M1;
        c2 %= M2;
        
        if(d.find(mp(c1,c2))!=d.end()) boo = true;
      }

      if(s[i]!='b') 
      {
        ll c1 = p2.fi + 'b'*pow1[i];
        ll c2 = p2.se + 'b'*pow2[i];
        c1 %= M1;
        c2 %= M2;

        if(d.find(mp(c1,c2))!=d.end()) boo = true;
      }

      if(s[i]!='c') 
      {
        ll c1 = p2.fi + 'c'*pow1[i];
        ll c2 = p2.se + 'c'*pow2[i];
        c1 %= M1;
        c2 %= M2;
        if(d.find(mp(c1,c2))!=d.end()) boo = true;
      }
    }

    if(boo) cout << "YES" <<endl;
    else cout << "NO" << endl;
  }
  return 0;
}

/*
1 1
aaaaa
aacaa

1 1
aabcabab
aabcabaa

 */
