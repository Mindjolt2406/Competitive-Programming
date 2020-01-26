/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s) {
        this->t = t;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};


int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n,k;
    cin>>n>>k;
    set<int> s;
    vector<pair<int,pair<int,int> > >w;

    vector<vector<pair<int,ll> > > adj(n+2);

    int boo = 0; // For the trivial answer = -1 case

    for(int i=0;i<n;i++)
    {
      int x,a,b;
      cin>>x>>a>>b;
      if(a==0 && b==k) boo = 1;
      s.insert(x);
      w.pu(mp(x,mp(a,b)));
    }

    if(boo) {cout<<"Case #"<<h<<": -1\n"; continue;}

    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());

    // t(w); 
    int src = 0, dest = n+1;

    vector<int> counter(100010,-1);

    unordered_map<pair<int,int>,ll,pair_hash> d;
    Dinic din(n+2,0,n+1);
    int boo1 = 0, boo2 = 0;

    for(int i=0;i<w.size();i++)
    {
      int index = i+1;
      if(w[i].se.fi==0)
      {
        din.add_edge(0,index,INF);
        boo1 = 1;
      }

      if(w[i].se.se==k)
      {
        din.add_edge(index,n+1,INF);
        boo2 = 1;
      }

      for(int j=w[i].se.fi;j<w[i].se.se;j++) 
      {
        if(counter[j]!=-1) 
        {
          if(d.find(mp(index,counter[j]))==d.end()) d[mp(index,counter[j])] = 0;

          d[mp(index,counter[j])]++;
          counter[j] = index;
        }
        else counter[j] = index;
      }

      for(auto it : d)
      {
        // t(w,it);
        // t(it.fi.fi,it.fi.se,it.se);
        din.add_edge(it.fi.fi,it.fi.se,it.se);
        din.add_edge(it.fi.se,it.fi.fi,it.se);
        // adj[it.fi.fi].pu(mp(it.fi.se,it.se));
        // adj[it.fi.se].pu(mp(it.fi.fi,it.se));
      }

      d.clear();
    }

    ll ans = din.flow();
    // t(ans);
    cout<<"Case #"<<h<<": "<<ans<<"\n";
    // else cout<<"Case #"<<h<<": "<<-1<<endl;

  }
  return 0;
}

/*
1
7 30
10 0 10
20 0 10
5 8 21
15 7 20
25 9 22
10 20 30
20 20 30

1
3 9
33 0 6
66 0 9
99 3 9

 */

