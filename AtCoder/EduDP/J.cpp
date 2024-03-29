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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}

ld recur(int i, int j, int k, vector<vector<vector<ld>>> &dp, int N) {
    if (i + j + k == 0)
        return dp[i][j][k] = 0;

    if (dp[i][j][k] != -1) 
        return dp[i][j][k];

    dp[i][j][k] = 0;
    // 1 -> 0.
    if (i > 0)
        dp[i][j][k] += i * (1 + recur(i-1, j, k, dp, N));

    // 2 -> 1.
    if (j > 0) 
        dp[i][j][k] += j * (1 + recur(i+1, j-1, k, dp, N));

    // 3 -> 2.
    if (k > 0)
        dp[i][j][k] += k * (1 + recur(i, j+1, k-1, dp, N));

    dp[i][j][k] += (N - i - j - k);
    dp[i][j][k] /= (i + j + k);

    return dp[i][j][k];
}

int main() {
    __;
    int n;
    cin >> n;
    vector<ld> v(n);
    for (auto &x : v)
        cin >> x;

    vector<int> counter(4);
    for (auto x : v)
        counter[x]++;

    vector<vector<vector<ld>>> dp(n+1, vector<vector<ld>>(n+1, vector<ld>(n+1, -1)));

    cout << fixed << setprecision(10);
    cout << recur(counter[1], counter[2], counter[3], dp, n) << endl;
    return 0;
}
