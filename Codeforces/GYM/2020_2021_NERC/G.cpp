#include<bits/stdc++.h>
 
typedef long long ll;
typedef long double lld;
using namespace std;
 
#define endl "\n"
#define fi first
#define se second
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define pii pair<int, int>
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}
 
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
 
template <typename T>
ostream &operator<<(ostream &out, set<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T>
ostream &operator<<(ostream &out, multiset<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << "\n" << (i->first) <<  ":"  << (i->second);
    return out;
}
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
// #define int ll
 
int n, k;
vector<vector<int>> g;
vector<int> par;
vector<int> mark;

int lastnode;
int mxlen;

int lr, otr;

void dfs1(int v, int p, int len = 0) {
    // tr(v, p, len);
    if (len > mxlen) {
        mxlen = len;
        lastnode = v;
    }
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs1(u, v, len + 1);
    }
}

vector<int> ans;

void dfs2(int v, int p) {
    ans.push_back(v);
    
    if (mark[v] == 0) {
        otr--;
    } else {
        lr--;
    }
    // tr(v, p, otr, lr);

    int mrkn = -1;

    for (auto u : g[v]) {
        if (u == p) continue;
        if (mark[u] == 0 && otr > 0) {
            dfs2(u, v);
        } else if (mark[u] == 1) {
            mrkn = u;
        }
    }

    if (mrkn != -1 && lr > 0) {
        dfs2(mrkn, v);
    }

    if (mark[v] == 0) {
        ans.push_back(p);
    }
    
}



void solve() { 
    cin >> n >> k;
    g.clear();
    g.resize(n + 1);
    mark.clear();
    mark.resize(n + 1);
    par.clear();
    par.resize(n + 1);
    ans.clear();
    for (int i = 0; i < n - 1; i++) {
        int p; cin >> p;
        par[i + 2] = p;
        g[i + 2].push_back(p);
        g[p].push_back(i + 2);
    }
    mxlen = -1;
    dfs1(1, 0);
    
    int curr = lastnode;
    while (curr != 0) {
        mark[curr] = 1;
        curr = par[curr];
    }

    lr = min(k, mxlen + 1);
    otr = k - lr;

    // tr(lr, otr);
    dfs2(1, 0);

    cout << (int)ans.size() -1 << endl;
    cout << ans << endl;

}
 
int32_t main() { _
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
}
