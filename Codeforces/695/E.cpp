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
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) { os << "["; for (auto it : v) { os << it; ; os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

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

const int N = 2e5+10;
vector<int> start(N), finish(N), par(N);
vector<vector<int> > adj(N);

int timer = 0;

void dfsTime(int u = 0, int p = -1) {
    start[u] = timer++;
    par[u] = p;
    for(auto v : adj[u]) {
        if(v - p) {
            dfsTime(v, u);
        }
    }
    finish[u] = timer++;
}

bool checkVertexBefore(vector<set<int> > &colVertex, int u, int colour) {
    return (*colVertex[colour].begin() < start[u]); 
}

bool checkVertexAfter(vector<set<int> > &colVertex, int u, int colour) {
    return (*colVertex[colour].rbegin() > finish[u]);
}

bool checkVertexTree(vector<set<int> > &colVertex, int u, int colour) {
    bool noColourSubtree = colVertex[colour].lower_bound(start[u]) == colVertex[colour].upper_bound(finish[u]);
    return !noColourSubtree;
}

void updateBefore(BIT &bit, int u) {
    bit.inc(0, 1);
    bit.inc(start[u], -1);
}

void updateAfter(BIT &bit, int u) {
    bit.inc(finish[u] + 1, 1);
}

void updateSelf(BIT &bit, int u) {
    bit.inc(start[u], 1);
    bit.inc(start[u] + 1, -1);
    bit.inc(finish[u], 1);
    bit.inc(finish[u] + 1, -1);
}

void updateSubTree(BIT &bit, int u) {
    bit.inc(start[u] + 1, 1);
    bit.inc(finish[u], -1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pu(b);
        adj[b].pu(a);
    }

    map<int, int> getCol;
    vector<int> colour(n);
    vector<set<int> > colVertex(n);

    for(int i = 0; i < n; i++) {
        if(!getCol.count(v[i])) {
            getCol[v[i]] = i;
        }
        colour[i] = getCol[v[i]];
    }

    dfsTime();

    for(int i = 0; i < n; i++) {
        colVertex[colour[i]].insert(start[i]);
        colVertex[colour[i]].insert(finish[i]);
    }

    // t(colour, colVertex);

    BIT bit;
    bit.init(2 * N); // Indices are entry and exit times

    for(int i = 0; i < n; i++) {
        // If anyone outside
        if(checkVertexBefore(colVertex, i, colour[i]) || checkVertexAfter(colVertex, i, colour[i])) {
            // t(i);
            updateSubTree(bit, i);
        }

        // If anyone in the subtree
        for(auto child : adj[i]) {
            if(child != par[i]) {
                if(checkVertexTree(colVertex, child, colour[i])) {
                    // t(i, child);
                    updateBefore(bit, child);
                    updateAfter(bit, child);
                }
            }
        }

        // If more than one kind of number, self cannot be a legitimate root
        if(colVertex[colour[i]].size() > 2) { 
            updateSelf(bit, i);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(bit.sum(start[i]) == 0) {
            // t(i);
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    __;
    solve();
    return 0;
}

/*
5
2 5 3 1 4
1 2
1 3
2 4
2 5

*/