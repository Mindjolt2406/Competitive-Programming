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
const int N = 1e5 + 10;
vector<int> spf;

void sieve() {
    spf.assign(N, 0);
    spf[0] = spf[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!spf[i]) {
            spf[i] = i;
            for (ll j = 1LL * i * i; j < N; j += i) {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}

vector<int> computeLastIndex(vector<int> &v) {
    int n = v.size();
    vector<int> lastIndex(n, N);
    vector<int> lastPrimeIndex(N, N);

    for (int i = n - 1; i >= 0; i--) {
        int minIndex = INF;
        int tempNum = v[i];
        vector<int> primes;
        while (tempNum != 1) {
            int currPrime = spf[tempNum];
            minIndex = min(minIndex, lastPrimeIndex[currPrime]);
            primes.push_back(currPrime);
            tempNum /= currPrime;
        }

        for (auto prime : primes)
            lastPrimeIndex[prime] = i;

        minIndex--;
        lastIndex[i] = min(minIndex, (i == n - 1 ? INF : lastIndex[i + 1]));
    }

    return lastIndex;
}

int main() {
    __;
    sieve();

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    vector<int> lastIndex = computeLastIndex(v);
    t(lastIndex);

    // for (int i = n - 1; i >= 0; i--) {
    //     for (int j = 1; i + (1 << j) < n; j++) {
    //         int parentIndex = i + j;
    //         dp[i][j] =
    //     }
    // }
    // // t(lastIndex);

    // while (q--) {
    //     int leftIndex, rightIndex;
    //     cin >> leftIndex >> rightIndex;
    //     leftIndex--;
    //     rightIndex--;

    //     int counter = 0;

    //     cout << counter << endl;
    // }
    return 0;
}
