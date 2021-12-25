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
ll max(ll x, ll y) {return x > y ? x : y;}

ll calculateCostMask(vector<pair<int, int>> &point, int mask, int n) {
    ll minX = INF, maxX = 0, minY = INF, maxY = 0;
    for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
            auto currPoint = point[i];
            minX = min(minX, currPoint.fi);
            maxX = max(maxX, currPoint.fi);
            minY = min(minY, currPoint.se);
            maxY = max(maxY, currPoint.se);
        }
    }

    if (maxX == 0)
        return 0;
    else
        return (maxX - minX + 1) * (maxY - minY + 1);
}

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    vector<pair<int, int>> points(n);
    for (auto &point : points)
        cin >> point.fi >> point.se;
    
    // vector<vector<ll>> dp(k, vector<ll>(1 << n, INF));
    vector<ll> dp(1 << n, INF);
    vector<ll> cost(1 << n, 0);

    for (int mask = 0; mask < (1 << n); ++mask) {
        cost[mask] = calculateCostMask(points, mask, n);
    }

    dp[0] = 0;

    for (int k1 = 0; k1 < k; k1++) {
        for (int mask = (1 << n) - 1; mask >= 0; mask--) {
            for (int submask = mask; submask; submask = ((submask - 1) & mask)) {
                // t(mask, otherMask, prod);
                dp[mask] = min(dp[mask], dp[mask ^ submask] + cost[submask]);
            }
        }
    }

    // t(dp);

    cout << dp[(1 << n) - 1] << endl;
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
