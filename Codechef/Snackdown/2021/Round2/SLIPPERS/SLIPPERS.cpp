// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
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

typedef struct node {
    // Any variable
    int beg = 0, end = 0;
    // Default for null nodes
    ll ans = 0;

    void assign(ll value) { ans = value; }

    void update(ll value) { ans = (ans + value) % MOD; }

    void combine(node &n1, node &n2) { ans = (n1.ans + n2.ans) % MOD; }

    ll query() { return ans; }

} node;

typedef struct SegTree {
    int n;
    vector<ll> a;
    vector<ll> lazy;
    vector<node> tree;

    void init(int n) {
        this->n = n;
        a.resize(n);
        lazy.resize(4 * n);
        tree.resize(4 * n);
        // build(0, 0, n-1);
    }

    void init(vector<ll> &v) {
        this->n = v.size();
        init(n);
        for (int i = 0; i < n; i++)
            a[i] = v[i];
        build(0, 0, n - 1);
    }

    void build(int pos, int l, int r) {
        // if(l>=n || r<0) return;
        tree[pos].beg = l, tree[pos].end = r;
        if (l == r) {
            tree[pos].assign(a[l]);
            return;
        }

        int left = (pos << 1) + 1, right = left + 1, mid = (l + r) >> 1;
        build(left, l, mid);
        build(right, mid + 1, r);

        tree[pos].combine(tree[left], tree[right]);
    }

    // Range update
    void upd(int pos, int l, int r, ll x) {
        lazy[pos] = (lazy[pos] + x) % MOD; // Associative lazy function
        tree[pos].update(x); // How much this contributes to the node
    }

    void shift(int pos, int l, int r) {
        if (lazy[pos] && l < r) {
            int mid = (l + r) >> 1, left = (pos << 1) + 1, right = left + 1;
            upd(left, l, mid, lazy[pos]);
            upd(right, mid + 1, r, lazy[pos]);
            lazy[pos] = 0; // Identity of the function
        }
    }

    void update(int x, int y, ll val, int pos, int l, int r) {
        // t(l,r,x,y);
        if (l > y || r < x)
            return;
        if (l >= x && r <= y) {
            upd(pos, l, r, val);
            return;
        }

        shift(pos, l, r);
        int left = (pos << 1) + 1, right = left + 1, mid = (l + r) >> 1;

        update(x, y, val, left, l, mid);
        update(x, y, val, right, mid + 1, r);

        tree[pos].combine(tree[left], tree[right]);
    }

    // For point updates.
    // void update(int x, ll val) {
    //     update(x, val, 0, 0, n-1);
    // }

    void update(int x, int y, ll val) { update(x, y, val, 0, 0, n - 1); }

    node query(int x, int y, int pos, int l, int r) {
        node ans, n1, n2;
        // if(l>y || r<x) return ans;
        if (r < x || l > y)
            return ans;
        if (l >= x && r <= y)
            return tree[pos];

        shift(pos, l, r); // Only needed for lazy propagation

        int left = (pos << 1) + 1, right = left + 1, mid = (l + r) >> 1;

        n1 = query(x, y, left, l, mid);
        n2 = query(x, y, right, mid + 1, r);
        ans.combine(n1, n2);
        return ans;
    }

    node query(int x, int y) { return query(x, y, 0, 0, n - 1); }
} SegTree;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    SegTree seg;
    seg.init(2e5 + 100);

    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;

    seg.update(0, 0, 1);
    seg.update(v[0], v[0], 1);
    ll currSum = 2;

    for (int i = 1; i < n; i++) {
        // t(i, v[i], seg.query(v[i], 2e5 + 10).query());
        dp[i][1] = (currSum - seg.query(v[i], 2e5 + 10).query() + MOD) % MOD;
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        seg.update(v[i], v[i], dp[i][1]);
        currSum = (currSum + dp[i][1]) % MOD;
    }

    // t(dp);

    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
}

int main() {
    __;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
