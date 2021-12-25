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

ll calc(vector<ll> &v, int i, int j, int k) {
    return (v[j] - v[i]) * (v[k] - v[j]);
}

ll max(ll x, ll y) { return x > y ? x : y; }

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;

    ll sum1 = 0;
    for (int i = 0; i < n - 2; i++) {
        set<int> s;
        for (int j = i + 2; j < n; j++) {
            s.insert(2 * (v[j - 1]));
            ll total = v[i] + v[j];
            ll currMax = 0, currValue = 0;

            {
                auto it = s.lower_bound(total);
                if (it != s.end()) {
                    ll val = *it / 2;
                    ll tempVal = (v[j] - val) * (val - v[i]);
                    if (tempVal > currMax)
                        currValue = val;
                    currMax = max(currMax, tempVal);
                }
            }

            {
                auto it = s.lower_bound(total);
                if (it != s.begin()) {
                    it--;
                    ll val = *it / 2;
                    ll tempVal = (v[j] - val) * (val - v[i]);
                    if (tempVal > currMax)
                        currValue = val;
                    currMax = max(currMax, tempVal);
                }
            }

            // auto it = s.lower_bound(currValue);
            // while (it != s.begin()) {
            //     it--;
            //     s.erase(it);
            // }
            t(v[i], v[j], currValue, i, j, currMax);
            sum1 += currMax;
        }
    }

    cout << sum1 << "\n";
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
