// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
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

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> mat(9);
    mat[1].push_back({1, 1});
    mat[2] = {{3, 1}, {4, 1}};
    mat[3] = {{1, 1}, {2, 2}};
    mat[4] = {{2, 4}};
    mat[5] = {{2, 2}, {3, 1}, {4, 2}};
    mat[6] = {{2, 2}, {3, 1}, {4, 2}, {24, 1}};
    mat[7] = {{1, 3}, {2, 2}, {3, 1}, {4, 1}};
    mat[8] = {{1, 2}, {2, 3}, {3, 1}, {4, 1}, {5, 1}};

    vector<pair<int, int>> ans;
    if (n <= 8) {
        ans = mat[n];
    } else {
        vector<pair<int, int>> v;
        v.push_back({n, 1});
        if (n - 9) {
            v.push_back({2, n - 9});
        } 
        v.push_back({1, 4});
        v.push_back({3, 4});
        ans = v;
    }

    ll sum1 = 0, sum2 = 0;
    for (auto it : ans) {
        sum2 += it.se;
        sum1 += 1LL * it.fi * it.fi * it.se;
    }

    assert(sum2 == n);

    if (n >= 9) {
        assert(sum1 == ((n + 2) * (n + 2ll)));
    }

    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it.fi << " " << it.se << "\n";
    }
}

int main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
        // cout << endl;
    }
    return 0;
}
