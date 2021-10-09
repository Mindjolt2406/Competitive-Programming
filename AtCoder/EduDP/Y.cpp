// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
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

const int N = 2e5 + 10;
vector<ll> fact(N);
vector<ll> inv(N);

ll power(ll x, ll y, ll p) {
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void compute() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 2e5; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = power(fact[i], MOD - 2, MOD);
    }
}

ll C(int n, int r) { return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD; }

bool checkSquare(pair<int, int> curr, pair<int, int> other) {
    return curr.first <= other.first && curr.second <= other.second;
}

ll getCount(pair<int, int> start, pair<int, int> end) {
    ll y = end.se - start.se, x = end.fi - start.fi;
    return C(x + y, x);
}

int main() {
    __;
    compute();
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> squares(k);
    for (auto &sq : squares) {
        cin >> sq.first >> sq.second;
        sq.first--;
        sq.second--;
    }

    squares.push_back(make_pair(0, 0));

    map<pair<int, int>, ll> dp;

    sort(squares.begin(), squares.end(),
         [](pair<int, int> &s1, pair<int, int> &s2) {
             return s2.first + s2.second < s1.first + s1.second;
         });

    for (int i = 0; i < squares.size(); i++) {
        auto sq = squares[i];
        dp[sq] = getCount(sq, mp(n - 1, m - 1));
        for (int j = 0; j < i; j++) {
            if (checkSquare(sq, squares[j]))
                dp[sq] = (dp[sq] -
                          ((dp[squares[j]] * getCount(sq, squares[j])) % MOD) +
                          MOD) %
                         MOD;
        }
    }

    cout << dp[make_pair(0, 0)] << "\n";
    return 0;
}
