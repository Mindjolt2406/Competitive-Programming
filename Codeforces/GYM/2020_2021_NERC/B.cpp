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

int d, n;
vector<int> arr;

//1 indexed Hopcroft-Karp Matching in O(E sqrtV)

struct Hopcroft_Karp
{
	static const int inf = 1e9;

	int n;
	vector<int> matchL, matchR, dist;
	vector<vector<int> > g;

	Hopcroft_Karp(int n) :
		n(n), matchL(n+1), matchR(n+1), dist(n+1), g(n+1) {}

	void addEdge(int u, int v)
	{
		g[u].push_back(v);
	}

	bool bfs()
	{
		queue<int> q;
		for(int u=1;u<=n;u++)
		{
			if(!matchL[u])
			{
				dist[u]=0;
				q.push(u);
			}
			else
				dist[u]=inf;
		}
		dist[0]=inf;

		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:g[u])
			{
				if(dist[matchR[v]] == inf)
				{
					dist[matchR[v]] = dist[u] + 1;
					q.push(matchR[v]);
				}
			}
		}

		return (dist[0]!=inf);
	}

	bool dfs(int u)
	{
		if(!u)
			return true;
		for(auto v:g[u])
		{
			if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v]))
			{
				matchL[u]=v;
				matchR[v]=u;
				return true;
			}
		}
		dist[u]=inf;
		return false;
	}

	int max_matching()
	{
		int matching=0;
		while(bfs())
		{
			for(int u=1;u<=n;u++)
			{
				if(!matchL[u])
					if(dfs(u))
						matching++;
			}
		}
		return matching;
	}
};

void make(vector<int> &ans, int prev, int curr) {
    for (int i = 0; i < d; i++) {
        if (((prev & (1 << i)) == 0) && ((curr & (1 << i)) != 0)) {
            ans.push_back(i);
        }
    }
}
 
void solve() { 
    cin >> d >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int curr = 0;
        for (int j = 0; j < d; j++) {
            if (s[j] == '1') {
                curr += (1 << j);
            }
        }
        arr.push_back(curr);
    }


    Hopcroft_Karp hm(2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if ((arr[i] & arr[j]) == arr[i]) {
                    hm.addEdge(i + 1, j + n + 1);
                }
            }
        }
    }

    int m = hm.max_matching();

    vector<int> out(n + 1, -1), in(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (hm.matchL[i] != 0) {
            out[i] = hm.matchL[i] - n;
            in[out[i]] = i;
        }
    }

    vector<int> visited(n + 1, 0);
    
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 && in[i] == -1 && out[i] != -1) {
            if (!ans.empty()) {
                ans.push_back(-1);
            } 
            int prev = 0;

            int curr = arr[i - 1];

            int ind = i;
			// tr(i, curr, prev);
            while (curr != 0) {
                visited[ind] = 1;
                make(ans, prev, curr);
                prev = curr;
                ind = out[ind];
                if (ind == -1) break;
                curr = arr[ind - 1];
                // tr(prev, curr, ind);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
    	if (visited[i] == 0) {
    		if (!ans.empty()) {
    			ans.push_back(-1);
    		}
    		make(ans, 0, arr[i - 1]);
    	}
    }
    
    cout << (int)ans.size() << endl;
    for (int i : ans) {
    	if (i == -1) {
    		cout << 'R' << " ";
    	} else {
    		cout << i << " ";
    	}
    }

}
 
int32_t main() { _
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
}
