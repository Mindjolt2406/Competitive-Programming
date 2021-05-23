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

const int N = 2e5 + 10;
vector<int> sz(N), vis(N), parent(N);
vector<ll> dp(N), fact(N), inv(N);
vector<vector<int> > adj(N), adj2(N);

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
            if (y & 1)
                    res = (res*x) % p;
            y = y>>1; // y = y/2
            x = (x*x) % p;
    }
    return res;
}

void precompute() {
    fact[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
        inv[i] = power(fact[i], MOD-2, MOD);
    }
}

ll C(int n, int r) {
    if(r < n) return 0;

    return (((fact[n] * inv[r]) % MOD) * inv[n-r]) % MOD;
}

void dfs(int u = 0, int p = -1) {
    sz[u] = 1;
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(v-p) {
            adj2[u].pu(v);
            if(!vis[v]) {
                dfs(v, u);
            }
            sz[u] += sz[v];
        }
    }
}

void dfs2(int u = 0, int p = -1) {
    int total = sz[u] - 1;
    vector<ll> child;
    for(auto v : adj2[u]) {
        if(v-p) {
            dfs2(v, u);
            child.pu(v);
        }
    }

    if(child.size() == 0) {
        dp[u] = 1;
    } else if(child.size() == 1) {
        dp[u] += dp[child[0]];
    } else {
        dp[u] = (((C(total, sz[child[0]]) * dp[child[0]]) % MOD ) * dp[child[1]]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    stack<int> s;
    s.push(0);
    bool flag = true;
    adj.resize(n);
    adj2.resize(n);
    sz.resize(n);
    vis.resize(n);
    dp.resize(n);
    parent.resize(n,-1);
    for(int i = 1; i < n; i++) {
        if(v[i] > v[i-1] + 1) {
            flag = false;
            break;
        } else if(v[i] > v[i-1]) {
            s.push(1);
            adj[i-1].pu(i);
        } else if(v[i] <= v[i-1]) {
            int diff = v[i-1] - v[i] + 1;
            int last = -1;
            while(diff--) {
                if(s.empty()) {
                    flag = false;
                    break;
                }
                last = s.top();
                s.pop();
            }
            if(!flag) break;

            if(!s.empty()) {
                int u = s.top();
                s.push(i);
                adj[u].pu(i);
            }

            adj[i].pu(last);
        }
    }

    t(adj);

    _;
    if(!flag) {
        cout << 0 << endl;
        return ;
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i);
    }

    int root = -1, rootSz = 0;
    for(int i = 0; i < n; i++) {
        if(sz[i] > rootSz) {
            rootSz = sz[i];
            root = i;
        }
    }

    t(root);
    t(adj2);

    dfs2(root);
    t(dp);

    cout << dp[root] << endl;
}

int main() {
    precompute();
    __;
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}


function simpleBranchAlgo(Graph G, Set B, int k) {
    Set R = getRSet(G, B, k);
    bool domSetPoss = false;
    for (vertex : R) {
        G'' = markWhiteNeighbours(G, B, vertex);
        G'' = deleteVertexFromGraph(G'', vertex);
        domSetPoss ||=  simpleBranchAlgo(G'', B, k - 1);
    }
    return domSetPoss;
}

// |B| <= (4d + 2)k
function bruteForce(Graph G, Set B, int k) {
    Set partitionSet = generateAllVertexPartitions(G, k);
    for(partition : partitionSet) {
        If every block dominated by a vertex 
            Return true
    }
    Return false
}

function effBranchAlgo(Graph G, Set B, int k) {
    if(B is empty) return true;
    if(k == 0) return false;
    if(|B| <= (4d+2)k) {
        return bruteForce(G, B, k);
    } else {
        Set R = getRSet(G, B, k);
        bool domSetPoss = false;
        for (vertex : R) {
            G'' = markWhiteNeighbours(G, B, vertex);
            G'' = deleteVertexFromGraph(G'', vertex);
            domSetPoss ||=  effBranchAlgo(G'', B, k - 1);
        }
        return domSetPoss;
    }
}
