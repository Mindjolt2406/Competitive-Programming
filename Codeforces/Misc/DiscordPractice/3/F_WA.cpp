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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 3010;
vector<vector<int> > adj(N);
vector<ll> sz(N), par(N);

void dfs(int u = 0, int p = -1) {
    par[u] = p;
    sz[u] = 1;
    for(auto v : adj[u]) {
        if(v - p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCnt(int u, int parent) {
    int cnt = 1;
    for(auto v : adj[u]) {
        if(v - parent) {
            cnt += getCnt(v, u);
        }
    }

    return cnt;
} 

int main() {
    __;
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pu(v);
        adj[v].pu(u);
    }

    sz.resize(n);
    dfs();
    // t(sz);
    ll max1 = 0, maxIndex = -1;
    ll ans = 0;
    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        if(par[i] != -1) {
            ll curr = sz[i] * (n - sz[i]);
            // t(i, curr);
            if(curr > max1) {
                max1 = curr;
                maxIndex = i;
            }
        }
    }

    parent[maxIndex] = par[maxIndex];
    parent[par[maxIndex]] = maxIndex;
    ans += max1;

    int left = maxIndex, right = parent[maxIndex];
    while(true) {
        ll max1 = -1, maxIndex = -1, parentIndex = -1;
        ll leftCnt = getCnt(left, parent[left]);
        ll rightCnt = getCnt(right, parent[right]);
        // t(leftCnt, rightCnt);
        for(auto v : adj[left]) {
            if(v != parent[left]) {
                ll curr = rightCnt * getCnt(v, left);
                if(curr > max1) {
                    max1 = curr;
                    maxIndex = v;
                    parentIndex = left;
                }
            }
        }

        for(auto v : adj[right]) {
            if(v != parent[right]) {
                ll curr = leftCnt * getCnt(v, right);
                if(curr > max1) {
                    max1 = curr;
                    maxIndex = v;
                    parentIndex = right;
                }
            }
        }

        // t(left, right, maxIndex, parentIndex, max1);
        if(max1 == -1) break;
        ans += max1;
        if(max1 == 1) break;
        if(parentIndex == left) {
            parent[maxIndex] = left;
            left = maxIndex;
        } else {
            parent[maxIndex] = right;
            right = maxIndex;
        }
    }

    cout << ans << endl;
    return 0;
}
