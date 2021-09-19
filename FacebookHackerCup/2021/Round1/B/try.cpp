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

// dp[i][j] = dp[i-1][j+1] + max(arr[i], arr[j]) 
//             OR dp[i-2][j] + arr[i]
//             OR dp[i][j+2] + arr[j]

ll recur(ll i, ll j, map<pair<int, int>, ll> &dp, vector<ll> &arr, int n, bool toMin) {
    if (i < -1 || j > n)
        return 0;

    if (dp.count(make_pair(i, j)))
        return dp[make_pair(i, j)];
        
    if (i == -1 && j == n)
        return dp[make_pair(i, j)] = 0;
        
    ll res = (toMin ? INF : 0);
    if (i >= 0) {
        if (toMin)
            res = min(res, recur(i-1, j, dp, arr, n, toMin ^ 1) + arr[i]);
        else 
            res = max(res, recur(i-1, j, dp, arr, n, toMin ^ 1) + arr[i]);
    }
    if (j < n) {
        if (toMin)
            res = min(res, recur(i, j+1, dp, arr, n, toMin ^ 1) + arr[i]);
        else 
            res = max(res, recur(i, j+1, dp, arr, n, toMin ^ 1) + arr[i]);
    }
    
    return dp[make_pair(i, j)] = res;
}

int main() {
    __;
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    
    ll minAns = INF;

    map<pair<int, int>, ll> dp;
    for (int i = 0; i < n; i++) {
        minAns = min(minAns, recur(i-1, i+1, dp, v, n, false));
    }

    for (auto it : dp) {
        t(it.fi, it.se);
    }

    cout << minAns << endl;
    return 0;
}
