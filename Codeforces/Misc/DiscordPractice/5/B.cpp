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

const int N = 3e5+10;
vector<vector<int> > adj(N);
vector<vector<int> > adj2(N);
vector<int> vis(N), depth(N), vis2(N);

void dfs1(int u = 0, int depthNode = 0) {
    vis[u] = 1;
    depth[u] = depthNode;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs1(v, depthNode+1);
        }
    }
}

void dfs2(int u = 0) {
    vis2[u] = 1;
    for(auto v : adj2[u]) {
        if(!vis2[v]) {
            dfs2(v);
        }
    }
}

int main() {
    __;
    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector<pair<int, pair<int, int> > > edges(m);
    // adj.resize(n);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].fi >> edges[i].se.fi >> edges[i].se.se;
        edges[i].se.fi--;
        edges[i].se.se--;
    }

    vector<pair<int, pair<int, int> > > edges2 = edges;
    sort(edges2.begin(), edges2.end());
    // reverse(edges2.begin(), edges2.end());

    for(auto edge : edges2) {
        adj[edge.se.fi].pu(edge.se.se);
        if(edge.fi == 2) {
            adj[edge.se.se].pu(edge.se.fi);
        }
    }

    dfs1(s);

    string finalAns1, finalAns2;
    // adj2.resize(n);
    for(auto edge : edges) {
        if(edge.fi == 2) {
            int u = edge.se.fi, v = edge.se.se;
            if(depth[v] > depth[u]) {
                finalAns1 += '+';
                adj2[edge.se.se].pu(edge.se.fi);
            } else {
                finalAns1 += '-';
                adj2[edge.se.fi].pu(edge.se.se);
            }
        } else {
            adj2[edge.se.fi].pu(edge.se.se);
        }
    }
    // t(adj, adj2);

    dfs2(s);

    for(auto it : finalAns1) {
        finalAns2 += (it == '+' ? '-' : '+');
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i]) cnt1++;
        if(vis2[i]) cnt2++;
    }

    cout << cnt1 << endl << finalAns1 << endl;
    cout << cnt2 << endl << finalAns2 << endl;

    return 0;
}
