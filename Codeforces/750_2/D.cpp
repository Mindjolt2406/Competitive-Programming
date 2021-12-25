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

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

pair<ll, ll> min(pair<ll, ll> p1, pair<ll, ll> p2) { return p1 < p2 ? p1 : p2; }

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;

    ll sum1 = 0;
    for (int i = 1; i < n; i++) {
        sum1 += v[i];
    }

    sum1 += v[0];

    pair<ll, ll> min1 = {INF, -1};
    vector<pair<ll, ll>> pairs(n);
    for (int i = 0; i < n; i++) {
        sum1 -= v[i];
        if (sum1 != 0) {
            ll g = gcd(sum1, v[i]);
            ll sum2 = sum1 / g;
            ll firstNum = v[i] / g;

            min1 = min(min1, mp(abs(firstNum) * (n - 1) + abs(sum2), i));
            pairs[i] = mp(firstNum, sum2);
        }
        sum1 += v[i];
    }

    // t(min1, pairs[min1.second]);

    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        if (i == min1.se) {
            b[i] = -pairs[min1.se].second;
        } else {
            b[i] = pairs[min1.se].first;
        }
    }

    ll sum2 = 0, sum3 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += (1LL * v[i] * b[i]);
        sum3 += abs(b[i]);
    }

    assert(sum2 == 0);
    assert(sum3 <= 1e9);

    for (auto x : b)
        cout << x << " ";
    cout << "\n";
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
