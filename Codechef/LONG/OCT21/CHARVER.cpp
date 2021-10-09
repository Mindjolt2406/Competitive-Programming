// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
#define EPS 1e-6
#define ll int
#define int long long int
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

void multiplyMatrixVec(vector<vector<int>> &mat, vector<int> &vec,
                       vector<int> &res) {
    int n = vec.size();

    res.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i] += (1LL * mat[i][j] * vec[j]) % MOD;
            res[i] %= MOD;
        }
    }
}

void multiplyConstantAndAdd(vector<int> &curr, int c, vector<int> &res) {
    int n = curr.size();

    for (int i = 0; i < n; i++) {
        res[i] += (1LL * curr[i] * c) % MOD;
        res[i] %= MOD;
    }
}

void checkZero(vector<int> &res) {
    bool isZero = true;
    for (auto it : res)
        if (it)
            isZero = false;

    cout << (isZero ? "YES" : "NO") << "\n";
}

void solve() {
    int m;
    cin >> m;
    vector<int> v(m);
    for (auto &x : v)
        cin >> x;

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<vector<int>> matMultiply(11);
    matMultiply[0].resize(n, 1);
    // matMultiply[0][0] = 1;

    for (int i = 1; i < m; i++)
        multiplyMatrixVec(mat, matMultiply[i - 1], matMultiply[i]);

    // t(matMultiply);

    vector<int> res(n);
    for (int i = 0; i < m; i++)
        multiplyConstantAndAdd(matMultiply[i], v[i], res);

    checkZero(res);
}

int32_t main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
2
3
-2 -5 1
2
1 2
3 4
3
-2 -5 1
2
1 1
1 1

*/