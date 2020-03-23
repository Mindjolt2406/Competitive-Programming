#include<bits/stdc++.h>
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 1e5+10;
vector<int> adj[N] = {};
int MAXLOG = 25;
vector<vector<int> >  parent(N,vector<int>(MAXLOG,-1));
int height[N] = {0};
vector<ll>  pref(N);
vector<int> colour(N);
vector<ll> arr(N);
vector<int> timer(N);
vector<set<pair<int,int> > > order(N); // <time,index> 
// vector<set<pair<int,int> > > orderl(N); // <time,index> 
// vector<set<pair<int,int> , greater<pair<int,int> > > > orderu(N);

int start_time = 1;

void dfs(int u = 0,int p = -1,ll above = 0)
{
  timer[u] = start_time++;

  pref[u] = arr[u] + above;
  for(auto v : adj[u])
  {
    if(v-p) dfs(v,u,pref[u]);
  }
}

void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  if(p+1) height[u] = height[p]+1;
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(p-v) dfsLCA(v,u);
}

int LCA(int u,int v)
{
  // height means depth here
  if(height[v]>height[u]) swap(u,v);

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) u = parent[u][i];
  }

  // height[u]==height[v]
  if(u==v) return u;
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i]) 
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[v][0];
}

ll ans = 0;

void insert(int colour, int index, bool remove = false)
{
  int h = -1, vert = -1;
  order[colour].insert(mp(timer[index],index));
  auto it1 = order[colour].find(mp(timer[index],index));
  auto it2 = order[colour].find(mp(timer[index],index));
  it2++;

  if(it1 != order[colour].begin())
  {
    it1--;
    vert = LCA(it1->se,index);
    h = height[vert];
  }
  if(it2 != order[colour].end())
  {
    int temp_vert = LCA(it2->se,index);
    int temp_h = height[temp_vert];

    if(temp_h > h) 
    {
      vert = temp_vert;
      h = temp_h;
    }
  }
  
  // int sub_vert = (vert != -1) ? LCA(index,vert) : -1;
  // ll sum1 = (sub_vert != -1) ? pref[index] - pref[sub_vert] : pref[index];
  ll sum1 = (vert != -1) ? pref[index] - pref[vert] : pref[index];

  if(remove)
  {
    ans -= sum1;
    order[colour].erase(mp(timer[index],index));
  }
  else
  {
    ans += sum1;
  }
}


int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      adj[a].pu(b);
      adj[b].pu(a);
    }
    for(int i=0;i<n;i++) cin >> colour[i];
    for(int i=0;i<n;i++) cin >> arr[i];

    dfs();
    dfsLCA();

    // for(int i=0;i<n;i++) cout << pref[i] << " "; cout << endl;
    for(int i=0;i<n;i++)
    {
      insert(colour[i],i);
    }

    // cout << ans << endl;
    while(q--)
    {
      int index,col;
      cin >> index >> col;
      index--;
      insert(colour[index],index,true);
      // cout << ans << endl;
      colour[index] = col;
      insert(col,index);
      cout << ans << endl;
    }

    // Reinitialise variables
    for(int i=0;i<N;i++) 
    {
      adj[i].clear();
      for(int j=0;j<MAXLOG;j++) parent[i][j] = -1;
      pref[i] = colour[i] = arr[i] = timer[i] = height[i] = 0;
      order[i].clear();
    }
    start_time = 1;
    ans = 0;
  }
  return 0;
}

/*
2
10 6
1 2
1 3
2 4
2 5
3 6
3 7
3 10
7 8
7 9
1 2 2 1 1 3 4 4 3 4
1 2 2 1 1 3 4 4 3 4
1 1
2 3
4 2
2 1
8 2
10 3
10 6
1 2
1 3
2 4
2 5
3 6
3 7
3 10
7 8
7 9
1 2 2 1 1 3 4 4 3 4
0 0 0 0 0 0 0 0 0 0
1 1
2 3
4 2
2 1
8 2
10 3

*/