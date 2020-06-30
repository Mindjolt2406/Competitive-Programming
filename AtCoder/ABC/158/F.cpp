#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
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

const int N = 5e5+10;
vector<int> adj[N] = {};
vector<int> vis(N);

// ll cnt = 0;

ll dfs(int u = 0, int p = -1)
{
  // t(u);
  vis[u] = 1;
  ll temp = 1;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      // t(u,v);
      temp *= dfs(v,u);
      temp %= MOD;
    }
  }

  temp++;
  // cnt += temp;
  return temp;
}

int main()
{
  __;
  int n;
  cin >> n;
  map<int,int> d;
  map<int,int> intro;
  map<int,set<int> > del;
  set<int> s;
  vector<pair<int,int> > v;

  for(int i=0;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    s.insert(a);
    s.insert(a+b-1);
    v.pu(mp(a,a+b-1));
  }

  int temp = 0;
  for(auto it : s)
  {
    d[it] = temp;
    temp++;
  }

  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
  {
    v[i].fi = d[v[i].fi];
    intro[v[i].fi] = i;
    v[i].se = d[v[i].se];
    del[v[i].se].insert(i);
  }

  // t(v,temp);

  set<pair<int,int> > order;

  for(int i=0;i<temp;i++)
  {
    // Add first, delete later
    // t(i,del[i].size());
    if(intro.count(i))
    {
      int u = intro[i];
      if(!order.empty())
      {
        pair<int,int> p = *order.rbegin();
        adj[p.se].pu(u);
      }
      order.insert(mp(i,u));
    }

    for(auto it : del[i])
    {
      // t(i,it);
      order.erase(mp(v[it].fi,it));
    }
  } 

  ll cnt = 1;
  for(int i=0;i<n;i++)
  {
    if(!vis[i]) 
    {
      // t(i);
      cnt *= dfs(i);
      // t(cnt);
      cnt %= MOD;
    }
  }

  cout << cnt << endl;
  return 0;

}
