// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
// #define MOD 1000000007
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

void dfs(vector<vector<int>> &adj, vector<ll> &dp, int MOD, int u = 0,
         int p = -1) {
    bool isLeaf = false;
    for (auto child : adj[u]) {
        if (child - p) {
            dfs(adj, dp, MOD, child, u);
        }
    }

    // Root is black.
    // Tree coming from multiple children -> Each child does not contribute,
    // or contributes a black subtree.
    dp[u] = 1;
    for (auto child : adj[u])
        if (child - p)
            dp[u] = ((1 + dp[child]) * dp[u]) % MOD;
}

void dfsProp(vector<vector<int>> &adj, vector<ll> &dp, vector<ll> &finalAns,
             int MOD, ll propValue = 0, int u = 0, int p = -1) {
    int N = adj[u].size();
    vector<ll> prefVal(N), suffVal(N);
    for (int i = 0; i < N; i++) {
        int childLeft = adj[u][i], childRight = adj[u][N - i - 1];
        ll valAddedLeft =
            ((childLeft == p ? propValue : dp[childLeft]) + 1) % MOD;
        prefVal[i] =
            (i == 0 ? valAddedLeft : (valAddedLeft * prefVal[i - 1]) % MOD);
        ll valAddedRight =
            ((childRight == p ? propValue : dp[childRight]) + 1) % MOD;
        suffVal[N - i - 1] =
            (i == 0 ? valAddedRight : (valAddedRight * suffVal[N - i]) % MOD);
    }

    finalAns[u] = suffVal[0];

    for (int i = 0; i < N; i++) {
        int child = adj[u][i];
        if (child - p) {
            ll leftVal = (i == 0 ? 1 : prefVal[i - 1]);
            ll rightVal = (i == N - 1 ? 1 : suffVal[i + 1]);
            ll prodVal = (leftVal * rightVal) % MOD;
            dfsProp(adj, dp, finalAns, MOD, prodVal, child, u);
        }
    }
}

int main() {
    __;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vector<ll> dp(n), finalAns(n);
    dfs(adj, dp, m);
    dfsProp(adj, dp, finalAns, m);

    for (int i = 0; i < n; i++)
        cout << finalAns[i] << "\n";
    return 0;
}
