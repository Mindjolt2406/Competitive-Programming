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
        // auto h1 = std::hash<T1>{}(p.fi*1e5 + p.se);
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 + h2;
    }
};

const int N = 1e5+10;
vector<int> adj[N] = {};
unordered_map<pair<int,int> , int, pair_hash> d;
int sz[N] = {};

int dfs(int u = 0,int p = -1)
{
  sz[u] = 1;
  for(auto v : adj[u]) if(v-p) sz[u] += dfs(v,u);
  return sz[u];
}

int main()
{
  __;
  int n;
  cin>>n;
  vector<pair<int,int> > edge;
  for(int i=0;i<n-1;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
    d[mp(a,b)] = d[mp(b,a)] = c;
    edge.pu(mp(a,b));
  }

  dfs();
  ll cnt = 0;
  for(auto it : edge)
  {
    int a = it.fi, b = it.se;
    if(sz[b] > sz[a]) swap(a,b);
    ll sza = sz[a], szb = sz[b];

    sza = n - szb;
    cnt += sza*szb*d[mp(a,b)];
  }

  ld total = 1LL * n * (n-1);
  total /= 6;

  int q;
  cin>>q;
  while(q--)
  {
    int index , val;
    cin >> index >> val;
    index--;
    int a = edge[index].fi, b = edge[index].se;

    ll dif = d[mp(a,b)] - val;
    d[mp(a,b)] = val;

    if(sz[b] > sz[a]) swap(a,b);
    ll sza = sz[a], szb = sz[b];

    sza = n - szb;

    cnt -= sza * szb * (dif);

    cout << setprecision(12);
    cout << cnt/total << "\n";
  }
  return 0;
}

