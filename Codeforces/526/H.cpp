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
};

typedef struct Rect {
    ll x, y, weight;

    bool operator<(Rect &rect) { return this->x < rect.x; }
} Rect;

int main() {
    __;
    int n;
    cin >> n;
    vector<Rect> rects(n);
    for (auto &rect : rects)
        cin >> rect.x >> rect.y >> rect.weight;

    sort(rects.begin(), rects.end());

    vector<ll> dp(n);
    DynamicLiChaoTree<ll, 1, (ll)1e9, 0> liTree;
    liTree.init();

    for (int i = 0; i < n; i++) {
        auto rect = rects[i];
        // From a previous rectangle.
        dp[i] = liTree.query(rect.y) + rect.x * rect.y - rect.weight;
        // rects[i] is the first rectangle.
        dp[i] = max(dp[i], rect.x * rect.y - rect.weight);

        if (i != n - 1)
            liTree.add(-rect.x, dp[i]);
    }

    ll maxArea = -INF;
    for (auto dpVal : dp)
        maxArea = max(maxArea, dpVal);

    cout << maxArea << "\n";
    return 0;
}