// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1e18
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

ll min(ll x, ll y) {return x < y ? x : y;}

void dijkstra(int s, vector<vector<pair<ll, ll>>> &adj, vector<ll> &d, vector<ll> &p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> v(2 * n, vector<ll>(2* n));
    for (auto &vec : v) {
        for (auto &x : vec)
            cin >> x;
    }

    ll ans = 0;
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            ans += v[i][j];
            v[i][j] = 0;
        }
    }

    int START_NODE = 0, END_NODE = 4 * n * n - 1;
    vector<vector<pair<ll, ll>>> adj(4 * n * n);

    vector<ll> dx = {-1, 1, 0, 0};
    vector<ll> dy = {0, 0, 1, -1};
    int SIZE = 2 * n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int currNode = 2 * n * i + j;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;
                if (x >= 0 && y >= 0 && x < n && y < n) {
                    int nextNode = 2 * x * n + y;
                    adj[currNode].push_back({nextNode, v[x][y]});
                }
            }
        }
    }

    for (int i = n; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            int currNode = 2 * n * i + j;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;
                if (x >= n && y >= 0 && x < 2 * n && y < n) {
                    int nextNode = 2 * x * n + y;
                    adj[currNode].push_back({nextNode, v[x][y]});
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            int currNode = 2 * n * i + j;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;
                if (x >= 0 && y >= n && x < n && y < 2 * n) {
                    int nextNode = 2 * x * n + y;
                    adj[currNode].push_back({nextNode, v[x][y]});
                }
            }
        }
    }

    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            int currNode = 2 * n * i + j;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;
                if (x >= n && y >= n && x < 2 * n && y < 2 * n) {
                    int nextNode = 2 * x * n + y;
                    adj[currNode].push_back({nextNode, v[x][y]});
                }
            }
        }
    }

    vector<pair<int, int>> special = {{0, 0}, {n - 1, n - 1}, {n - 1, 0}, {0, n - 1},{n, n}, {n, 2 * n - 1}, {2 * n - 1, n}, {2 * n - 1, 2 * n - 1}};

    for (auto it : special) {
        int i = it.fi, j = it.se;
        int currNode = i * 2 * n + j;
        for (int k = 0; k < 4; ++k) {
            int x = (dx[k] + i + SIZE) % SIZE, y = (dy[k] + j + SIZE) % SIZE;
            int nextNode = x * 2 * n + y;
            adj[currNode].push_back({nextNode, v[x][y]});
            adj[nextNode].push_back({currNode, v[i][j]});
        }
    }

    vector<ll> dist;
    vector<ll> par;

    dijkstra(START_NODE, adj, dist, par);

    // t(adj, dist);
    cout << dist[END_NODE] + ans << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
2
0 0 4 2
0 0 2 4
4 2 4 2
2 4 2 4

*/
