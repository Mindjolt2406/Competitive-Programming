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

const int N = 100100;
int p[N], sz[N];
// vector<int> adj(N);

void create(int x){
        p[x] = x;
        sz[x] = 1;
        return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
  x = find(x); 
  y = find(y);
  if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

typedef struct query
{
  int x,y,z,idx;
} query;

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > edges(m);
  vector<query> que;

  for(int i=0;i<m;i++) 
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    edges[i] = mp(a,b);
  }

  int t;
  cin >> t;
  vector<int> ans(t);
  for(int h=0;h<t;h++)
  {
    int x,y,z;
    cin >> x >> y >> z;
    x--; y--;
    query temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    temp.idx = h;
    que.pu(temp);
  }

  // Of the form ( (beg, end) , vector)
  queue<pair<pair<int,int> ,  vector<query> > > q;
  q.push(mp(mp(0,m-1),que));

  // Initialise the DSU
  for(int i=0;i<n;i++) create(i);
  int dsu_counter = 0;

  while(!q.empty())
  {
    pair<pair<int,int> , vector<query> > p = q.front();
    q.pop();

    int beg = p.fi.fi, end = p.fi.se;
    int mid = (beg+end) >> 1;

    if(dsu_counter > mid) // Restart the dsu
    {
      // for(int i=0;i<=dsu_counter;i++) {create(edges[i].fi); create(edges[i].se);}
      for(int i=0;i<n;i++) create(i);
      dsu_counter = 0;
    }
    
    // t(dsu_counter,mid);
    for(int i=dsu_counter;i<=mid;i++) merge(edges[i].fi, edges[i].se);
    dsu_counter = mid;

    vector<query> que = p.se, left, right;

    for(int i=0;i<que.size();i++)
    {
      query temp = que[i];
      int temp_sz = find(temp.x) == find(temp.y) ? sz[find(temp.x)] : sz[find(temp.x)] + sz[find(temp.y)];

      // if(find(temp.x) == find(temp.y))
      // {
      //   temp_sz = sz[find(temp.x)];
      // }
      // else
      // {
      //   temp_sz = sz[find(temp.x)] + sz[find(temp.y)];
      // }

      if(temp_sz >= temp.z)
      {
        ans[temp.idx] = mid+1;
        if(beg<=mid-1) left.pu(temp);
      }
      else
      {
        if(mid+1 <= end) right.pu(temp);
      }

      
    }

    // t(dsu_counter,temp.x, temp.y, temp.z, temp_sz,p.fi);
    // t(mid);

    if(left.size()) q.push(mp(mp(beg,mid-1), left));
    if(right.size()) q.push(mp(mp(mid+1,end), right));
  }

  for(int i=0;i<t;i++) cout << ans[i] << endl;
  return 0;
}

