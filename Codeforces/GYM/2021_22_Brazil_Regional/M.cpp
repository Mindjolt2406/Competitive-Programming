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

const int N = 2e5 + 10;
vector<vector<int>> adj(N);
vector<int> timer(N);
map<int, int> d;
int currTime = 0;

void dfs(int u = 0, int p = -1) {
    timer[u] = currTime;
    d[currTime] = u;
    currTime++;

    for (auto v : adj[u]) {
        if (v - p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto &p : queries) {
        cin >> p.fi >> p.se;
    }

    int counter = 1;
    vector<pair<int, pair<int, int>>> query2;
    for (auto p : queries) {
        int type = p.fi, x = p.se;
        x--;
        if (type == 1) {
            adj[x].push_back(counter);
            adj[counter].push_back(x);
            query2.push_back({type, {x, counter}});
            counter++;
        } else {
            query2.push_back({type, {x, x}});
        }
    }

    dfs();

    set<int> s;
    s.insert(timer[0]); // Count exists initially

    // for (int i = 0; i < counter; ++i) {
    //     t(i, adj[i], timer[i]);
    // }

    for (auto p : query2) {
        int type = p.fi, x = p.se.se;
        // t(type, x);
        if (type == 1) {
            s.insert(timer[x]);
        } else {
            s.erase(timer[x]);
            cout << d[(*s.begin())] + 1 << endl;
        }
    }
}

int main() {
    __;
    solve();
    return 0;
}
