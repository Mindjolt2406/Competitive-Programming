/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
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

const int N = 100100;
int p[N], sz[N];
vector<int > adj[N] = {};
map<int,int> adj2[N] = {};

void create(int x){
        p[x] = x;
        sz[x] = 1;
        return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

map<pair<int,int> , int> weight;

void add(int u,int w)
{
  if(adj2[u].count(w))
  {
    adj2[u][w]++;
  }
  else adj2[u][w] = 1;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<pair<int,pair<int,int> > >edge;
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    edge.pu(mp(c,mp(a,b)));
    weight[mp(a,b)] = weight[mp(b,a)] = c;
    add(a,weight[mp(a,b)]);
    add(b,weight[mp(b,a)]);
  }

  sort(edge.begin(),edge.end());
  map<int,int> counter;

  for(int i=0;i<n;i++) create(i);

  set<pair<int,int> > done;

  for(int i=0;i<n-1;i++)
  {
    int u = edge[i].se.fi, v = edge[i].se.se;
    int pu = find(u), pv = find(v);
    if(pu!=pv)
    {
      merge(u,v);
      // done.insert(mp(u,v));
      // done.insert(mp(v,u));
      adj[v].pu(u);
      adj[u].pu(v);
      // adj[u].pu(v);
      // if(counter.find(edge[i].fi)==counter.end()) 
      // {
      //   counter[edge[i].fi] = 1;
      // }
      // else counter[edge[i].fi]++;
    }
  }

  int sum1 = 0;
  // for(auto it : counter)
  // {
  //   if(it.se == 1) sum1+= it.fi;
  // }

  set<pair<int,int> > ans_edge;

  for(int i=0;i<n;i++)
  {
    int min1 = INF,idx = -1;
    for(auto v : adj[i])
    {
      if(weight[mp(i,v)]<min1)
      {
        min1 = weight[mp(i,v)];
        idx = v;
      }
    }

    if(min1!=INF && adj2[i][min1]==1)
    {
      pair<int,int> p = mp(min(i,idx),max(i,idx));
      ans_edge.insert(p);
    }
  }


  cout << ans_edge.size() << endl;
  return 0;
}

