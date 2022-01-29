// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define int long long int
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

int32_t main() {
    __;
    int h, m, a;
    cin >> h >> m >> a;
    int totalMinutes = h * m;
    int midIntervalSize = totalMinutes - 2 * a;
    int startMid = a + 1, endMid = midIntervalSize + a - 1, modVal = h - 1;

    if (endMid < startMid) {
        cout << h * m << endl;
    } else {
        int numMid = (endMid / modVal) - ((startMid - 1) / modVal);
        t(endMid, numMid, (endMid / modVal), (startMid - 1) / modVal);
        cout << (h * m) - (numMid * modVal) << endl;
    }
    return 0;
}

/*
How many numbers mod M lie between [A + k * D, B + k * D]

D = H * m
M = H - 1

Intervals don't intersect
A, B, k, D, M <= 1e9

A = 5, B = 20 D = 25, M = 4
[5, 20] -> 4
[30, 45] -> 4
[55, 70] -> 4
[80, 95] -> 4


h = 3, m = 5, a = 1
h * m = D = 15
M = 2
1, 13, 1
[2, 13] -> 6
[17, 28] -> 6

h = 4 m = 7 a = 3
h * m = D = 28
M = 3
3, 22, 3



wm = 2pi / M
wh = 2pi / H

Number of minutes to get to a difference of alpha 
alpha / (wm - wh) -> (A / (H - 1))

Time from [0, alpha] -> A / (H - 1)
Time from (alpha, 360 - 2 * alpha) -> (H*M - 2A) / (H - 1)
Time from [360 - 2 * alpha, 360] -> A / (H - 1)

*/
