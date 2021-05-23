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

// #define tr(...) cout<<_FUNCTION<<' '<<LINE<<" = ";trace(#VA_ARGS, __VA_ARGS_)
// template<typename S, typename T>
// ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

// template<typename T>
// ostream& operator<<(ostream& out,vector<T> const& v){
// ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

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

#define int ll

const int N = 2e5 + 100;

int n, m;
vector<vector<int>> g(N);
vector<int> arr;
int dist;
int par[N];
int fin[N];

void dfs(int v, int p, int d = 0) {
    fin[v] = d;
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v, d + 1);
    }
}


int solve() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0, 0);
        int lol = fin[arr[0]];
        int done = 0;
        for (int j = 0; j < m; j++) {
            if (lol != fin[arr[j]]) {
                done = 1;
                break;
            }
        }
        if (!done) {
            cout << "YES\n";
            cout << i << endl;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

int32_t main(){ _
    int t;
    // cin >> t;
    t = 1;
    while (t--) solve();
    return EXIT_SUCCESS;	
}