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

bool check(int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true; 
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void addEdge(vector<vector<int> > &adj, int firstIndex, int secondIndex) {
    t(firstIndex, secondIndex);
    adj[2 * firstIndex + 1].pu(2 * secondIndex);
    adj[2 * secondIndex + 1].pu(2 * firstIndex);
}

void addAll(vector<vector<int> > &adj, int firstIndex, int secondIndex) {
    addEdge(adj, firstIndex, secondIndex);
    addEdge(adj, secondIndex, firstIndex);
}

bool dfs1(int u, vector<vector<int> > &adj, vector<int> &vis, vector<int> &order) {
    vis[u] = 0;
    order.pu(u);
    for(auto v : adj[u]) {
        if(vis[v] == -1) {
            dfs1(v, adj, vis, order);
        }
    }
}



void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int cntW = 0, cntB = 0;
    vector<vector<int> > indexWhite(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'W') {
                indexWhite[i][j] = cntW++;
            }
            else if(v[i][j] == 'B') cntB++;
        }
    }

    if(cntW != 2 * cntB) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<int> > adj(2 * cntW);

    int indexW = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'B') {
                int firstIndex = -1, secondIndex = -1;
                for(int k = 0; k < 4; k++) {
                    int x = dx[k] + i, y = dy[k] + j;
                    if(check(x, y, n, m) && v[x][y] == 'W') {
                        if(k & 1) firstIndex = indexWhite[x][y];
                        else secondIndex = indexWhite[x][y];
                    }

                    if(k == 1 || k == 3) {
                        if(firstIndex == -1 && secondIndex == -1) {
                            cout << "NO" << endl;
                            return;
                            // addAll(adj, firstIndex, secondIndex);
                        } else if(firstIndex == -1 || secondIndex == -1) {

                        } else {
                            addEdge(adj, firstIndex, secondIndex);
                        }
                        firstIndex = secondIndex = -1;
                    }
                }
            }
        }
    }

    t(adj);
 
    vector<int> vis(2 * cntW, -1), order;

    for(int i = 0; i < 2 * cntW; i++) {
        if(vis[i] == -1) {
            dfs1(i, adj, vis, order);
        }
    }
    for(int i = 0; i < 2 * cntW; i++) {
        if(vis[i] == -1) {
            bool currFlag = dfs(i, adj, vis);
            if(!currFlag) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}