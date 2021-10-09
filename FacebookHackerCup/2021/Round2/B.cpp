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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}

const int N = 1e6;
int MAXLOG = 28;

void dfsLCA(vector<vector<int>> &adj, vector<int>&height, vector<vector<int>> &parent, int u = 0,int p = -1)
{
  // t(u);
  if(p+1) height[u] = height[p]+1;
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(p-v) dfsLCA(adj, height, parent, v,u);
}

int LCA(vector<vector<int>> &adj, vector<int>&height, vector<vector<int>> &parent, int u,int v)
{
  // height means depth here
  if(height[v]>height[u]) swap(u,v);

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) u = parent[u][i];
  }

  // height[u]==height[v]
  if(u==v) return u;
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i]) 
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[v][0];
}

void dfsAns(vector<vector<int>> &adj, vector<int> &pathCounter, int &currAns, int u = 0, int p = -1) {
    for (auto v : adj[u]) {
        if (v - p) {
            dfsAns(adj, pathCounter, currAns, v, u);
            pathCounter[u] += pathCounter[v];
        }
    }

    currAns += (pathCounter[u] == 0);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> height(n);
    vector<vector<int>> parent(n, vector<int>(MAXLOG, -1));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> freqCities(n);
    for (int i = 0; i < n; i++) {
        int freq;
        cin >> freq;
        freq--;
        freqCities[freq].push_back(i);
    }

    dfsLCA(adj, height, parent);

    vector<int> pathCounter(n);
    for (int i = 0; i < n; i++) {
        if (freqCities[i].size()) {
            int currLca = freqCities[i][0];
            for (int j = 1; j < freqCities[i].size(); j++) {
                currLca = LCA(adj, height, parent, currLca, freqCities[i][j]);
            }

            for (auto node : freqCities[i]) {
                pathCounter[node]++;
                pathCounter[currLca]--;
            }
        }
    }

    int currAns = 0;
    dfsAns(adj,pathCounter, currAns);

    cout << currAns - 1 << "\n";
}

int main() {
    __;
    int t;
    cin >> t;
    for (int h = 1; h <= t; h++) {
        t(h);
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}
