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

int getRoot(int N) {
    for (int i = 0; i < N; i++) {
        if ((1LL * i * (i + 1)) >= 2 * N)
            return i;
    }

    return N;
}

inline ll getSum(vector<ll> &pref, int i, int j) {
    return pref[j] - ((i == 0) ? 0 : pref[i - 1]);
}

ll dp[100010][320] = {0};
// ll blockSums[100010][320] = {0};

inline ll min(ll x, ll y) { return x < y ? x : y; }

bool check(int blockSize, int n, vector<ll> &pref) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= blockSize; j++)
            dp[i][j] = INF;

    // dp[i][j] -> From indices 0 .. i, what is the smallest block
    // of [lj, rj] you could create? (lj <= i). Either try creating
    // one now, or use an existing one(from i - 1). dp[i][0] is 0 by
    // default, so anyone can create a block of size 1.

    // vector<vector<ll>> dp(n, vector<ll>(blockSize + 1, INF));
    // for (int i = 0; i < n; i++)
    //     dp[i][0] = 0;

    // dp[0][blockSize] = blockSums[0][blockSize];
    dp[0][blockSize] = getSum(pref, 0, blockSize - 1);

    for (int i = 1; i < n; i++) {
        // Try making a block of size j starting from i.
        for (int j = 1; j <= blockSize; j++) {
            // Don't create one, just use an existing block.
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);

            // You can always create a large block (of size currBlockSize).
            if (j == blockSize) {
                if (i + blockSize - 1 < n)
                    dp[i][j] =
                        min(dp[i][j], getSum(pref, i, i + blockSize - 1));
                continue;
            }

            // Otherwise, look at j + 1, and construct it.
            if (i - (j + 1) >= 0 && i + j - 1 < n) {
                int prevIndex = i - (j + 1);
                int blockSum = getSum(pref, i, i + j - 1);
                if (blockSum > dp[prevIndex][j + 1])
                    dp[i][j] = min(dp[i][j], blockSum);
            }
        }
    }

    // t(blockSize);
    // t(dp);
    bool isPossible = (dp[n - 1][1] != INF);
    return isPossible;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    vector<ll> pref(n);
    pref[0] = v[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + v[i];
    }

    int blockSize = getRoot(n);
    // vector<vector<ll>> blockSums(
    //     n, vector<ll>(1)); // blockSums[i][size]. 0 is nothing.
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n && j < i + blockSize; j++) {
    //         blockSums[i].push_back(getSum(pref, i, j));
    //     }
    // }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= blockSize; j++)
            dp[i][j] = INF;

    // dp[i][j] -> From indices 0 .. i, what is the smallest block
    // of [lj, rj] you could create? (lj <= i). Either try creating
    // one now, or use an existing one(from i - 1). dp[i][0] is 0 by
    // default, so anyone can create a block of size 1.

    // vector<vector<ll>> dp(n, vector<ll>(blockSize + 1, INF));
    // for (int i = 0; i < n; i++)
    //     dp[i][0] = 0;

    // dp[0][blockSize] = blockSums[0][blockSize];
    dp[n - 1][1] = getSum(pref, n - 1, n - 1);

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j <= blockSize; j++) {
            // Don't create one, just use an existing block.
            dp[i][j] = min(dp[i + 1][j], dp[i][j]);

            // You can start a size 1 block anywhere.
            if (j == 1) {
                dp[i][j] = min(dp[i][j], getSum(pref, i, i));
                continue;
            }

            int rIndex = i + j - 1;
            if (rIndex + 1 < n) {
                ll currSum = getSum(pref, i, i + j - 1);
                if (dp[rIndex + 1][j - 1] != INF &&
                    dp[rIndex + 1][j - 1] > currSum)
                    dp[i][j] = min(dp[i][j], currSum);
            }
        }
    }

    for (int i = 0; i < n; i++)

    int maxK = 1;
    for (int j = 1; j <= blockSize; j++) {
        if (dp[0][j] != INF)
            maxK = j;
    }

    cout << maxK << "\n";
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

/*
1
5
9 6 7 9 7

*/