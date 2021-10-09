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

ll max(ll x, ll y) { return x > y ? x : y; }

typedef struct node {
    // Any variable
    int beg = 0, end = 0;
    // Default for null nodes
    ll ans = -INF;

    void assign(ll value) { ans = value; }

    void update(ll value) { ans += value; }

    void combine(node &n1, node &n2) { ans = max(n1.ans, n2.ans); }

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
        lazy[pos] += x;      // Associative lazy function
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

int main() {
    __;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, int>>> intervalCost(n + 2);
    while (m--) {
        int l, r, a;
        cin >> l >> r >> a;
        intervalCost[l].push_back(make_pair(a, l - 1));
        intervalCost[r + 1].push_back(make_pair(-a, l - 1));
    }

    SegTree segTree;
    segTree.init(n + 1);

    for (int i = 1; i <= n + 1; i++) {
        for (auto cost : intervalCost[i])
            segTree.update(0, cost.second, cost.first);

        ll currVal = segTree.query(0, i - 1).query();
        segTree.update(i, i, currVal);
    }

    cout << segTree.query(0, n).query() << "\n";

    return 0;
}

/*
dp[i] = max_j dp[j] + C(j, i);

C(j, i) -> Weight of intervals starting within [l+1, r].
The effect of an interval starting at l affects the DP values from [0, l-1].
C(j, i+1) = C(j, i) + Intervals starting at i+1.
*/
