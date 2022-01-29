// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define int ll
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
// template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

bool dp[70000][200] = {0};
int currMax[70000][200] = {0};
pair<int, int> back[70000][200];

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (auto &x : v)
        cin >> x;
    
    int MASK_N = (1ll << N);
    // vector<vector<bool>> dp(MASK_N, vector<bool>(K));
    // vector<vector<int>> currMax(MASK_N, vector<int>(K, -1));
    // vector<vector<pair<int, int>>> back(MASK_N, vector<pair<int, int>>(K, mp(-1, -1)));
    dp[0][0] = true;
    
    vector<vector<int>> pow10(N, vector<int>(10, 1));
    pow10[0][1] = 1;
    for (int i = 0; i < N; ++i) {
        if (i > 0)
            pow10[i][1] = (pow10[i - 1][1] * 10) % K;
        for (int j = 2; j < 10; ++j)
            pow10[i][j] = (j * pow10[i][1]) % K;
    }

    for (int mask = 1; mask < MASK_N; ++mask) {
        for (int j = 0; j < N; ++j) {
            if (mask & (1 << j)) {
                int pow10Index = __builtin_popcountll(mask) - 1;

                int oldMask = (mask ^ (1 << j));

                int currPow = pow10[pow10Index][v[j]];

                for (int mod = 0; mod < K; mod++) {
                    int oldMod = mod - currPow + K;
                    if (oldMod >= K)
                        oldMod -= K;

                    dp[mask][mod] = dp[oldMask][oldMod] || dp[mask][mod];
                    if (dp[oldMask][oldMod] && v[j] > currMax[mask][mod]) {
                        currMax[mask][mod] = v[j];
                        back[mask][mod] = mp(oldMask, oldMod);
                    }
                }
            }
        }
    }

    int maxMod = 0;
    for (int i = 0; i < K; ++i) {
        if (dp[MASK_N - 1][i])
            maxMod = i;
    }

    string ans; 
    int currMask = MASK_N - 1;
    int currMod = maxMod;
    for (int i = 0; i < N; ++i) {
        // t(currMask, currMod, currMax[currMask][currMod]);
        ans += currMax[currMask][currMod] + '0';
        auto p = back[currMask][currMod];
        currMask = p.fi, currMod = p.se;
    }

    // t(dp);
    // t(back);

    cout << ans << endl;
}

int32_t main() {
    __;
    solve();
    return 0;
}
