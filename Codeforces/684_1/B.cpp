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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

void solve()
{
  int n,m,k;
  cin >> n >> m >> k;
  unordered_set<int> adj[n], adjEdge[n];
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].insert(b);
    adj[b].insert(a);
    adjEdge[a].insert(b);
    adjEdge[b].insert(a);
  }

  set<pair<int,int> > degVertex;
  int vertexDegMap[n];
  set<int> vertices;

  for(int i=0;i<n;i++)
  {
    vertices.insert(i);
    vertexDegMap[i] = adj[i].size();
    degVertex.insert(mp(adj[i].size(), i));
  }

  if(1LL*k*(k-1) > 2*m) {cout << -1 << endl; return;}

  vector<int> candidates[n];

  while(!degVertex.empty() && (*degVertex.begin()).fi < k)
  {
    pair<int,int> p = *degVertex.begin();
    int vert = p.se, deg = p.fi;
    if(deg == k-1)
    {
      for(auto v : adj[vert])
      {
        if(!vertices.count(v)) continue;
        candidates[vert].pu(v);
      }
      candidates[vert].pu(vert);
    }

    for(auto v : adj[vert])
    {
      int degV = vertexDegMap[v];
      degVertex.erase(mp(degV,v));

      vertexDegMap[v]--;

      adj[v].erase(vert);

      if(vertexDegMap[v] != 0) 
      {
        degVertex.insert(mp(degV-1,v));
      }
      else vertices.erase(v);
    }

    degVertex.erase(p);
    vertices.erase(vert);
    adj[vert].clear();
  }

  if(vertices.empty()) 
  {
    for(int i=0;i<n;i++)
    {
      if(candidates[i].size() != k) continue;
      int vert = i;

      bool flag = true;
      for(auto v : candidates[vert])
      {
        for(auto w : candidates[vert])
        {
          if(v == w) continue;
          if((adjEdge[v].find(w) == adjEdge[v].end()))  {flag = false; break;}
        }
        if(!flag) break;
      }

      if(flag)
      {
        cout << 2 << endl;
        for(auto v : candidates[vert]) cout << v+1 << " "; cout << endl;
        return;
      }
    }
    cout << -1 << endl;
  }
  else 
  {
    cout << 1 << " " << vertices.size() << endl;
    for(auto v : vertices) cout << v+1 << " "; cout << endl;
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
  return 0;
}

/*
1
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5

*/
