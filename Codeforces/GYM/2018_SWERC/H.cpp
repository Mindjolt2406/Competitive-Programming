// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll int
#define int long long int
// #define ll long long int
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
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {os << "{"; for(auto it : s) {os << it << ", ";} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
// clang-format on

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

typedef struct Node {
    int d0 = 0, d1 = 0, d2 = 0;

    bool operator<(const Node &n2) const { return this->d0 > n2.d0; }

} Node;

ostream &operator<<(ostream &os, const Node &node) {
    return os << "d0: " << node.d0 << " d1: " << node.d1 << " d2: " << node.d2;
}

int32_t main() {
    __;
    int n;
    cin >> n;
    adj.resize(n);

    int m;
    cin >> m;
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }

    vector<int> parent(n);
    vector<int> dist0(n), dist1(n), dist2(n);
    dijkstra(0, dist0, parent);
    dijkstra(1, dist1, parent);
    dijkstra(2, dist2, parent);

    vector<Node> v;
    for (int i = 0; i < n; i++) {
        Node node;
        node.d0 = dist0[i];
        node.d1 = dist1[i];
        node.d2 = dist2[i];
        v.push_back(node);
    }

    sort(v.begin(), v.end());
    t(v);

    multiset<pair<int, Node>> s;
    for (int i = 0; i < n; i++) {
        auto currPair = make_pair(-v[i].d1, v[i]);
        auto it = s.upper_bound(currPair);
        vector<pair<int, Node>> toDelete;
        while (it != s.begin()) {
            it--;
            auto checkPair = *it;
            t(checkPair, currPair);
            if (v[i].d1 <= checkPair.se.d1 && v[i].d2 <= checkPair.se.d2) {
                if (checkPair.se.d0 > v[i].d0 || checkPair.se.d1 > v[i].d1 ||
                    checkPair.se.d2 > v[i].d2) {
                    toDelete.push_back(checkPair);
                }
            } else
                break;
        }

        for (auto it : toDelete)
            s.erase(s.find(it));

        s.insert(currPair);
        t(s);
    }

    cout << s.size() << endl;
    return 0;
}
