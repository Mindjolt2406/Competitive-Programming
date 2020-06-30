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

const int N = 2e5+100;

vector<int> adj[N] = {};
vector<int> par(N);
vector<int> st(N),fin(N);

int timer = 0;
void dfs(int u = 0,int p = -1)
{
  par[u] = p;
  st[u] = timer++;
  for(auto v : adj[u]) 
  {
    if(v-p)
    {
      dfs(v,u);
    }
  }
  fin[u] = timer++;
}

bool check(pair<int,int> &p1, pair<int,int> &p2)
{
  if(p2.fi <= p1.fi && p1.se <= p2.se) return true;
  return false;
}

int main()
{
  __;
  int n,q;
  cin >> n >> q;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs();

  while(q--)
  {
    int m;
    cin >> m;
    vector<pair<int,int> > v(m);
    for(int i=0;i<m;i++) cin>>v[i].se;
    for(int i=0;i<m;i++)
    {
      v[i].se--;
      if(v[i].se) v[i].se = par[v[i].se];
    }

    for(int i=0;i<m;i++) v[i].fi = st[v[i].se];
    
    sort(v.begin(),v.end());
    bool boo = true;
    for(int i=1;i<m;i++)
    {
      pair<int,int> p1 = mp(st[v[i].se],fin[v[i].se]);
      pair<int,int> p2 = mp(st[v[i-1].se],fin[v[i-1].se]);
      if(!check(p1,p2))
      {
        boo = false;
        break;
      }
    }
    if(boo) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
