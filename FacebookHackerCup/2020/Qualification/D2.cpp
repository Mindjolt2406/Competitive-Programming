#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll min(ll x, ll y) {return x<y?x:y;}

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  ll ans = INF;
  void assign(ll value)
  {
    ans = value;
  }
  void update(ll value)
  {
    ans = value;
  }
  void combine(node &n1, node &n2)
  {
    ans = min(n1.ans,n2.ans);
  }
  ll query()
  {
    return ans;
  }
} node;

const int N = 1e6+100;
int n;
vector<ll> a;
vector<node> tree;

void build(int pos = 0, int l = 0, int r = n-1)
{
  // if(l>=n || r<0) return;
  tree[pos].beg = l, tree[pos].end = r;
  if(l==r) 
  {
    tree[pos].assign(a[l]);
    return;
  }

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;
  build(left,l,mid); build(right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

// Point updates
void update(int index, ll value, int pos = 0, int l = 0,int r = n-1)
{
  if(l==r)
  {
    tree[pos].update(value);
    return;
  }

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  if(index<=mid) update(index,value,left,l,mid);
  else update(index,value,right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

node query(int x,int y,int pos = 0, int l = 0, int r = n-1)
{
  node ans,n1,n2;
  if(r<x || l>y) return ans;
  if(l>=x && r<=y) return tree[pos];

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  n1 = query(x,y,left,l,mid); n2 = query(x,y,right,mid+1,r);
  ans.combine(n1,n2);
  return ans;
}

void dfs(vector<vector<int> > &adj, vector<int> &par, int u = 0,int p = -1)
{
  par[u] = p;
  for(auto v : adj[u]) if(v-p) dfs(adj,par,v,u);
}

void bfs(vector<vector<int> > &adj, vector<int> &path, vector<int> &bfs_ances, vector<ll> &mark)
{
  queue<pair<int ,int> > q;
  for(auto it : path) q.push(mp(it,it));
  int dist = 0;
  for(int i=0;i<path.size();i++) mark[path[i]] = i;

  while(!q.empty())
  {
    pair<int,int>  p = q.front();
    int u = p.fi, ancestor = p.se;

    q.pop();

    bfs_ances[u] = ancestor;

    for(auto v : adj[u])
    {
      if(mark[v] == INF)
      {
        mark[v] = mark[u]-1;
        q.push(mp(v,ancestor));
      }
    }
  }
}

void solve()
{
  int m,start,dest;
  cin >> n >> m >> start >> dest;
  start--; dest--;

  a.resize(n,INF);
  tree.resize(4*n);

  vector<vector<int> > adj(n);
  vector<ll> cost(n);
  vector<int> par(n),bfs_ances(n);
  vector<ll> mark(n,INF);

  for(int i=0;i<n;i++)
  {
    int parent;
    ll cost_temp;
    cin >> parent >> cost_temp;
    cost[i] = cost_temp;
    parent--;
    if(parent+1)
    {
      adj[i].pu(parent);
      adj[parent].pu(i);
    }
  }

  dfs(adj,par,start);

  vector<int> path;
  int temp = dest;
  while(temp != start)
  {
    path.pu(temp);
    temp = par[temp];
  }
  path.pu(temp);
  
  reverse(path.begin(),path.end());
  bfs(adj,path,bfs_ances,mark);

  vector<vector<int> > adj_ances(n);
  for(int i=0;i<n;i++)
  {
    adj_ances[bfs_ances[i]].pu(i);
  }

  vector<pair<int,int> > v;
  for(int i=0;i<n;i++) v.pu(mp(mark[i],i));
  sort(v.begin(),v.end());

  map<int,int> mapper,ind;
  for(int i=0;i<v.size();i++)
  {
    if(mapper.count(v[i].fi) == 0) mapper[v[i].fi] = i;
    a[i] = INF;
    ind[v[i].se] = i;
  }

  mapper[v.back().fi+1] = v.size();

  build();

  vector<ll> dp(n,INF);

  dp[start] = 0;
  update(ind[start],0);

  cost[start] = 0;

  for(auto it : path)
  {
    // Get the answer for the current node and all nodes 
    ll x = query(mapper[mark[it]-m],mapper[mark[it]+1]-1).query();
    if(it != start) dp[it] = x;

    if(cost[it] != 0) update(ind[it],dp[it]+cost[it]);
    else if(it != start) update(ind[it],INF);

    for(auto it2 : adj_ances[it])
    {
      if(it == it2) continue;
      int temp_m =  (2*mark[it]-mark[it2]-m);
      if(temp_m > mark[it]) continue;
      ll x = query(mapper[temp_m],mapper[mark[it]+1]-1).query();
      dp[it2] = x;
    }


    for(auto it2 : adj_ances[it])
    {
      if(cost[it2] != 0) update(ind[it2],dp[it2]+cost[it2]);
      else if(it2 != start) update(ind[it2],INF);
    }
  }

  if(dp[dest] != INF) cout << dp[dest] << endl;
  else cout << -1 << endl;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}