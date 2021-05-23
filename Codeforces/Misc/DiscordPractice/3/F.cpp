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

const int N = 3010;
vector<vector<ll> > counter(N, vector<ll>(N)), dp(N, vector<ll>(N, -1));
vector<vector<int > > parent(N, vector<int>(N));
vector<int> sz(N), par(N);
vector<vector<int> > adj(N);

ll max(ll x, ll y) {return x > y ? x : y;}

void dfs(int n, int u = 0, int p = -1) {
    sz[u] = 1;
    par[u] = p;
    for(auto v : adj[u]) {
        if(v - p) {
            dfs(n, v, u);
            sz[u] += sz[v];
            counter[u][v] = n - sz[v];
        }
    }

    if(p != -1) counter[u][p] = sz[u];
}

ll recur(int i, int j) {
    // if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    // t(i, j, parent[i][j]);
    int parI = parent[i][j], parJ = parent[j][i];

    dp[i][j] = counter[i][parI] * counter[j][parJ];
    ll max1 = 0;
    for(auto v : adj[i]) {
        if(v != parent[i][j]) {
            parent[v][j] = i;
            parent[j][v] = parent[j][i];
            // t(i, v, j, parent[i][j], i);
            max1 = max(max1, recur(v, j));
        }
    }

    for(auto v : adj[j]) {
        if(v != parent[j][i]) {
            parent[v][i] = j;
            parent[i][v] = parent[i][j];
            // t(i, v, j, parent[i][j], j);
            max1 = max(max1, recur(v, i));
        }
    }

    dp[i][j] += max1;
    return dp[i][j];
}

int main() {
    __;
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pu(v);
        adj[v].pu(u);
    }

    // dp.resize(n);
    // counter.resize(n);
    // parent.resize(n);
    // for(int i = 0; i < n; i++) {
    //     dp[i].resize(n);
    //     counter[i].resize(n);
    //     parent[i].resize(n);
    // }
    dfs(n);

    // t(counter);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(par[i] == -1) continue;
        parent[i][par[i]] = par[i];
        parent[par[i]][i] = i;
        // t(i, par[i]);
        ans = max(ans, recur(i, par[i]));
    }

    // t(dp);
    // t(parent);
    cout << ans << endl;
    return 0;
}
