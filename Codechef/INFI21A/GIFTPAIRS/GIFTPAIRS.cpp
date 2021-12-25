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

const int N = 1e3 + 10;
vector<ll> derangements(N);
vector<ll> fact(N);
vector<vector<ll>> dp(N, vector<ll>(N));

void calculateDerangements() {
    derangements[0] = 1;
    for (int i = 1; i < N; ++i) {
        derangements[i] = i * (derangements[i - 1]);
        if (i & 1)
            derangements[i] = (derangements[i] - 1 + MOD) % MOD;
        else 
            derangements[i] = (derangements[i] + 1) % MOD;
    }
}

void calculateFactorial() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}

void calculateDP() {
    calculateFactorial();
    calculateDerangements();
    dp[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i][0] = derangements[i];
    }

    // for (int i = 0; i < N; ++i) {
    //     dp[1][i] = (i * fact[i]) % MOD;
    // }

    for (int i = 0; i < N; ++i) {
        dp[0][i] = fact[i];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j] += (j * dp[i - 1][j - 1]) % MOD;
            dp[i][j] += (j * dp[i][j - 1]) % MOD;
            if (i >= 2) {
                dp[i][j] += ((i - 1) * dp[i - 2][j]) % MOD;
                dp[i][j] += ((i - 1) * dp[i - 1][j]) % MOD;
            }
            dp[i][j] %= MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
        x--;
    }
    
    vector<bool> isTaken(n);
    int zeroCounter = 0;
    int derangementCounter = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == -1)
            zeroCounter++;
        else {
            isTaken[v[i]] = true;
        }
    }

    if (!zeroCounter) {
        cout << 0 << "\n";
        return ;
    }

    // t(isTaken);

    for (int i = 0; i < n; ++i) {
        if (v[i] == -1 && !isTaken[i])
            derangementCounter++;
    }
    // t(derangementCounter);

    // t(derangementCounter, zeroCounter - derangementCounter);
    cout << dp[derangementCounter][zeroCounter - derangementCounter] << "\n";
}

int main() {
    __;
    calculateDP();
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         t(i, j, dp[i][j]);
    //     }
    // }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
