#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) { for(auto it : v) os << it << " "; os << endl; return os; } 
template <typename T,typename U>ostream& operator<<(ostream& os, const map<T,U>& v) { for(auto it : v) os << it << " "; os << endl; return os; } 

const int N = 2e5+10;

int tourCounter = 0;
vector<pair<int,int> > range(N);
vector<vector<int> > adj(N),adj2(N);
vector<int> par(N);

void dfs(int u = 0, int p = -1)
{
  par[u] = p;
  tourCounter++;
  range[u].fi = tourCounter-1;
  for(auto v : adj[u])
  {
    if(v-p) dfs(v,u);
  }
  tourCounter++;
  range[u].se = tourCounter-1;
}

void dfs2(set<int> &s, map<int,int> &d, vector<ll> &cost, vector<ll> &B, vector<int> &ans, map<int,int> &mapping, ll prevCost = 0, int depth = 1, int u = 0, int p = -1)
{
  ll prev = prevCost;
  prev += cost[u];
  s.insert(prev);
  if(!d.count(prev)) d[prev] = depth;

  bool isLeaf = true;
  for(auto v : adj2[u])
  {
    if(v-p)
    {
      dfs2(s,d,cost,B,ans,mapping, prev,depth+1,v,u);
      isLeaf = false;
    }
  }

  if(isLeaf)
  {
    int idx = mapping[u];
    // t(idx,B[idx],u,s,d);
    auto it = s.lower_bound(B[idx]);
    if(it != s.end()) ans[idx] = d[*it];
  }
  s.erase(prev);
  d.erase(prev);
}
int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      adj[a].pu(b);
      adj[b].pu(a);
    }

    vector<ll> A(n), B(n), P(n);
    for(int i=0;i<n;i++) {cin >> P[i]; P[i]--;}
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];

    dfs();

    set<pair<ll,ll> > possRange;
    possRange.insert(range[0]);
    map<pair<ll,ll> , int> getIndex;
    map<int,int > mapping;
    getIndex[range[0]] = 0;
    vector<ll> cost(5*n);

    int counter = 1;
    for(int i=0;i<n;i++)
    {
      int idx = P[i];
      // for(auto it : possRange) cerr << it << " "; cerr << endl;

      auto it = possRange.upper_bound(mp(range[idx].fi,INF));
      it--;
      possRange.erase(*it);

      int pairIndex = getIndex[*it];
      pair<int,int> p = *it;

      cost[pairIndex] = A[idx];

      if(p.fi < range[idx].fi) 
      {
        possRange.insert(mp(p.fi,range[idx].fi-1));
        getIndex[mp(p.fi,range[idx].fi-1)] = counter;
        adj2[counter].pu(pairIndex);
        adj2[pairIndex].pu(counter);
        counter++;
      }
      if(p.se > range[idx].se) 
      {
        possRange.insert(mp(range[idx].se+1,p.se));
        getIndex[mp(range[idx].se+1,p.se)] = counter;
        adj2[counter].pu(pairIndex);
        adj2[pairIndex].pu(counter);
        counter++;
      }
      for(auto v : adj[idx])
      {
        if(v-par[idx])
        {
          if(range[v].fi >= range[idx].fi && range[v].se <= range[idx].se) 
          {
            possRange.insert(range[v]);
            getIndex[range[v]] = counter;
            adj2[counter].pu(pairIndex);
            adj2[pairIndex].pu(counter);
            counter++;
          }
        }
      }
      
      adj2[counter].pu(pairIndex);
      adj2[pairIndex].pu(counter);
      mapping[counter] = i;
      counter++;
    }

    // for(auto it : getIndex) cerr << it << " "; cerr << endl;
    // for(auto it : mapping) cerr << it << " "; cerr << endl;
    // t(cost);
    // for(int i=0;i<5;i++) t(i,adj2[i]);

    set<int> s;
    map<int,int> d;
    vector<int> ans(n,-1);
    dfs2(s,d,cost,B,ans,mapping);
    
    for(auto it : ans) cout << it << " "; cout << endl;

    for(int i=0;i<n;i++)
    {
      par[i] = 0;
      adj[i].clear();
      range[i] = mp(0,0);
    }
    for(int i=0;;i++)
    {
      if(adj2[i].empty()) break;
      adj2[i].clear();
    }
    tourCounter = 0;
  }
  return 0;
}

/*
1
3
1 2
2 3
1 2 3
1 2 3
1 3 6


2
3
1 2
2 3
1 2 3
1 2 3
1 3 6
3
1 2
1 3
1 2 3
5 6 3
4 10 12

*/