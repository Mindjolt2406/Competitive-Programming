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

ll max(ll x, ll y) { return x > y ? x : y; }

void getBits(int mask, vector<int> &indices) {
    int tempMask = mask;
    int currIndex = 0;
    while (tempMask) {
        if (tempMask & 1)
            indices.push_back(currIndex);
        tempMask >>= 1;
        currIndex++;
    }
}

ll getCost(int mask, vector<vector<ll>> &mat) {
    vector<int> indices;
    getBits(mask, indices);

    ll currCost = 0;
    for (int i = 0; i < indices.size(); i++) {
        for (int j = i + 1; j < indices.size(); j++) {
            currCost += mat[indices[i]][indices[j]];
        }
    }

    return currCost;
}

void computeCost(vector<ll> &cost, vector<vector<ll>> &mat, int N) {
    for (int mask = 0; mask < (1 << N); mask++) {
        cost[mask] = getCost(mask, mat);
    }
}

int constructOriginalSubMask(int subMask, vector<int> &indices) {
    int newSubMask = 0;
    int currIndex = 0;
    int tempSubMask = subMask;
    while (tempSubMask) {
        if (tempSubMask & 1)
            newSubMask = newSubMask | (1 << indices[currIndex]);
        tempSubMask >>= 1;
        currIndex++;
    }

    return newSubMask;
}

int main() {
    __;
    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    vector<ll> cost(1 << n);
    computeCost(cost, v, n);

    const int N = (1 << n);
    vector<ll> dp(1 << n);
    for (int mask = 0; mask < N; mask++) {
        int notMask = N - 1 - mask;
        vector<int> indices;
        getBits(notMask, indices);

        int bitsSize = indices.size();
        for (int subMask = 0; subMask < (1 << bitsSize); subMask++) {
            int newSubMask = constructOriginalSubMask(subMask, indices);
            int newMask = (mask | newSubMask);
            dp[newMask] = max(dp[newMask], dp[mask] + cost[newSubMask]);
        }
    }

    cout << dp[N - 1] << "\n";
    return 0;
}
