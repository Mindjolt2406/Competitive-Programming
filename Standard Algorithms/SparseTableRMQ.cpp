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

typedef struct SparseTable 
{
  static const int MAXN = 2e5+10;
  static const int K = 20;
  vector<vector<ll> > st;
  vector<ll> log;

  SparseTable()
  {
    st.resize(MAXN,vector<ll>(K+1));
    log.resize(MAXN);
  }

  void init(vector<int> &v)
  {
    for (int i = 0; i < v.size(); i++)
      st[i][0] = v[i];

    for (int j = 1; j <= K; j++)
      for (int i = 0; i + (1 << j) <= v.size(); i++)
        st[i][j] = f(st[i][j-1],st[i + (1 << (j - 1))][j - 1]);
  }

  void initMin(vector<int> &v)
  {
    init(v);
    log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
      log[i] = log[i/2] + 1;
  }

  ll f(ll x, ll y)
  {
    return min(x,y);
  }

  ll min(ll x, ll y) {return (x<y) ? x : y;}

  ll querySum(int l, int r)
  {
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
      if ((1 << j) <= r - l + 1) {
        sum += st[l][j];
        l += 1 << j;
      }
    }
    return sum;
  }

  ll queryMin(int l, int r)
  {
    int j = log[r - l + 1];
    ll minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
    return minimum;
  }
} Sparse;

int main()
{
  __;
  SparseTable sp;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  sp.initMin(v);

  int q;
  cin >> q;
  while(q--)
  {
    int l,r;
    cin >> l >> r;
    cout << sp.queryMin(l,r) << endl;
  }
  return 0;
}
