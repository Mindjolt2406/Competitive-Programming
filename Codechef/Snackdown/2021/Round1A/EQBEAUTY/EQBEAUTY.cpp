// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define int long long int
// #define ll long long int
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
// template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
// template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
// template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

int min(int x, int y) { return x < y ? x : y; }

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
        x += 1e9;
    }

    sort(v.begin(), v.end());
    if (n == 2) {
        cout << 0 << "\n";
    } else if (n == 3) {
        cout << min(v[1] - v[0], v[2] - v[1]) << "\n";
    } else {
        int currAns = 1e18;

        if (n >= 4) {
            int a = v[0], b = v[1], c = v[n - 2], d = v[n - 1];
            // a-c, b-d
            // a-d, b-c
            currAns =
                min(abs(abs(c - a) - abs(d - b)), abs(abs(d - a) - abs(b - c)));
            currAns = min(abs(abs(d - a) - abs(c - b)), currAns);
        }

        multiset<int> s(v.begin(), v.end());
        // t(v);
        s.erase(s.find(v.back()));
        for (int i = 0; i < n; i++) {
            if (s.count(v[i]))
                s.erase(s.find(v[i]));
            // Current interval [v[0], v[i]] and [X, v[n - 1]].
            // Choose the appropriate value of X using a set.
            // X cannot be v[0] or v[i].
            int diff1 = v[i] - v[0];
            int optX = v[n - 1] - diff1;
            auto it = s.lower_bound(optX);
            if (it != s.end()) {
                int diff2 = v[n - 1] - *it;
                currAns = min(currAns, abs(diff1 - diff2));
                // t(i, v[i], v[0], v[n - 1], *it, abs(diff1 - diff2));
                auto it2 = it;
                it2++;
                if (it2 != s.end()) {
                    int diff2 = v[n - 1] - *it2;
                    // t(i, v[i], v[0], v[n - 1], *it, abs(diff1 - diff2));
                    currAns = min(currAns, abs(diff1 - diff2));
                }
                it2--;
            }

            if (it != s.begin()) {
                it--;
                int diff2 = v[n - 1] - *it;
                // t(i, v[i], v[0], v[n - 1], *it, abs(diff1 - diff2));
                currAns = min(currAns, abs(diff1 - diff2));
            }

            if (i)
                s.insert(v[i]);
        }
        cout << currAns << endl;
    }

    // }
}

int32_t main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
