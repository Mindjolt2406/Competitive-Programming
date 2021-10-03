// clang-format off
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
// clang-format on

template <typename T, T minX, T maxX, T defVal, bool maximum = true>
struct DynamicLiChaoTree {
  private:
    struct Line {
        T a, b;
        inline T calc(T x) const { return a * x + b; }
    };
    struct Node {
        Line line = {0, maximum ? defVal : -defVal};
        Node *lt = nullptr, *rt = nullptr;
    };
    Node *root;
    void update(Node *cur, T l, T r, T u, T v, Line nw) {
        if (v < l || r < u)
            return;
        T mid = (l + r) >> 1;
        if (u <= l && r <= v) {
            if (cur->line.calc(l) >= nw.calc(l))
                swap(cur->line, nw);
            if (cur->line.calc(r) <= nw.calc(r)) {
                cur->line = nw;
                return;
            }
            if (nw.calc(mid) >= cur->line.calc(mid)) {
                if (!cur->rt)
                    cur->rt = new Node();
                update(cur->rt, mid + 1, r, u, v, cur->line);
                cur->line = nw;
            } else {
                if (!cur->lt)
                    cur->lt = new Node();
                update(cur->lt, l, mid, u, v, nw);
            }
        } else {
            if (!cur->rt)
                cur->rt = new Node();
            if (!cur->lt)
                cur->lt = new Node();
            update(cur->lt, l, mid, u, v, nw);
            update(cur->rt, mid + 1, r, u, v, nw);
        }
    }

    void flattenTree(set<pair<ll, ll>> &lines, Node *node) {
        if (node == NULL)
            return;
        Line currLine = node->line;
        // Add the original line back (we negated while adding).
        lines.insert(mp(-currLine.a, -currLine.b));
        flattenTree(lines, node->lt);
        flattenTree(lines, node->rt);
    }

  public:
    // change l,r to add segment
    void add(T a, T b, T l = minX, T r = maxX) {
        if (!maximum)
            a = -a, b = -b;
        update(root, minX, maxX, l, r, {a, b});
    }
    T query(T x) {
        Node *cur = root;
        T res = cur->line.calc(x);
        T l = minX, r = maxX, mid;
        while (cur) {
            res = max(res, cur->line.calc(x));
            mid = (l + r) >> 1;
            if (x <= mid)
                cur = cur->lt, r = mid;
            else
                cur = cur->rt, l = mid + 1;
        }
        if (!maximum)
            res = -res;
        return res;
    }
    void init() { root = new Node; }

    void flattenTree(set<pair<ll, ll>> &lines) { flattenTree(lines, root); }
};

void dfs(
    vector<vector<int>> &adj, vector<ll> &dp,
    vector<DynamicLiChaoTree<ll, (ll)-1e5, (ll)1e5, (ll)INF, false>> &liTrees,
    vector<ll> &a, vector<ll> &b, int u = 0, int p = -1) {
    bool isLeaf = true;
    for (auto v : adj[u]) {
        if (v - p) {
            dfs(adj, dp, liTrees, a, b, v, u);
            isLeaf = false;
        }
    }

    if (!isLeaf) {
        int n = adj[u].size();
        vector<set<pair<ll, ll>>> flattenedLines(n);
        pair<int, int> maxTreeSize = make_pair(-1, -1);
        for (int i = 0; i < n; i++) {
            int v = adj[u][i];
            if (v - p) {
                liTrees[v].flattenTree(flattenedLines[i]);
                maxTreeSize = max(maxTreeSize,
                                  make_pair((int)flattenedLines[i].size(), v));
            }
        }

        // Only Node object gets copied here.
        liTrees[u] = liTrees[maxTreeSize.second];

        // Add all the other lines from other children in the root LiChao Tree.
        for (int i = 0; i < n; i++) {
            int v = adj[u][i];
            if (v - p && v - maxTreeSize.second) {
                for (auto line : flattenedLines[i])
                    liTrees[u].add(line.first, line.second);
            }
        }

        // Query for min from tree.
        dp[u] = liTrees[u].query(a[u]);
    }

    // Add current line to the tree.
    liTrees[u].add(b[u], dp[u]);
}

int main() {
    __;
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dp(n);
    vector<DynamicLiChaoTree<ll, (ll)-1e5, (ll)1e5, (ll)INF, false>> liTrees(n);
    for (auto &liTree : liTrees)
        liTree.init();
    dfs(adj, dp, liTrees, a, b);

    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << "\n";
    return 0;
}
