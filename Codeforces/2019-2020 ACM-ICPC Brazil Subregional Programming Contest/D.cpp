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

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  int index = -1;
  ll ans = 0;

  void assign(ll value,int index1)
  {
    ans = value;
    index = index1;
  }

  void update(ll value)
  {
    ans+=value;
  }

  void combine(node &n1, node &n2)
  {
    if(n1.ans > n2.ans)
    {
      ans = n1.ans;
      index = n1.index;
    }
    else
    {
      ans = n2.ans;
      index = n2.index;
    }
  }

  ll query_ans()
  {
    return ans;
  }

  int query_index()
  {
    return index;
  }

} node;

const int N = 4e5+10;
int n;
ll a[N] = {0}, b[N] = {0}, lazy[4*N] = {0};
node tree[4*N];

void build(int pos = 0, int l =0, int r = n-1)
{
  // if(l>=n || r<0) return;
  tree[pos].beg = l, tree[pos].end = r;
  if(l==r) 
  {
    tree[pos].assign(a[l],b[l]);
    return;
  }

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;
  build(left,l,mid); build(right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

// Range update
void upd(int pos, int l,int r,ll x)
{
  lazy[pos]+=x; // Assosciative lazy function
  tree[pos].update(x); // How much this contributes to the node
}

void shift(int pos, int l, int r)
{
  if(lazy[pos] && l<r)
  {
    int mid = (l+r)>>1, left = (pos<<1)+1, right = left+1;
    upd(left,l,mid,lazy[pos]);
    upd(right,mid+1,r,lazy[pos]);
    lazy[pos] = 0; // Identity of the function
  }
}

void update(int x,int y,ll val, int pos = 0, int l = 0, int r = n-1)
{
  // t(l,r,x,y);
  if(l>y || r<x) return;
  if(l>=x && r<=y)
  {
    upd(pos, l, r, val);
    return;
  }

  shift(pos,l,r);
  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  update(x,y,val,left,l,mid);
  update(x,y,val,right,mid+1,r);

  tree[pos].combine(tree[left], tree[right]);
}

node query(int x = 0,int y = n-1,int pos = 0, int l = 0, int r = n-1)
{
  node ans,n1,n2;
  // t(l,r,x,y); 
  // if(l>y || r<x) return ans;
  if(r<x || l>y) return ans;
  if(l>=x && r<=y) return tree[pos];

  shift(pos,l,r); // Only needed for lazy propagation

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  n1 = query(x,y,left,l,mid); n2 = query(x,y,right,mid+1,r);
  ans.combine(n1,n2);
  return ans;
}


int timer = 0;
vector<int> depth(N);
vector<bool> taken(N); // Cancelled nodes
vector<int> in(N);
vector<int> out(N);
vector<int> adj[N] = {};

void dfs(int u = 0,int p = -1)
{
  if(p+1)
  {
    depth[u] = depth[p] + 1;
  }

  t(u,timer);
  a[timer] = depth[u];
  b[timer] = u;
  // a[timer]
  in[u] = timer;
  timer++;

  for(auto v : adj[u])
  {
    if(v-p) dfs(v,u);
  }

  // update(timer,timer,depth[u]);
  // a[timer] = depth[u];
  // b[timer] = u;
  out[u] = timer;
  timer++;
}

int main()
{
  __;
  int k;
  cin >> n >> k;

  vector<int> par(N);
  for(int i=1;i<n;i++)
  {
    cin >> par[i];
    par[i]--;
    adj[par[i]].pu(i);
  }

  dfs();

  n*=2;

  build();

  for(int i=0;i<n;i++) t(i,depth[i],in[i],out[i],par[i]);
  for(int i=0;i<2*n;i++) t(i,query(i,i).query_ans(),query(i,i).query_index());

  int answer = 0;
  while(k--)
  {
    node temp = query();
    answer += temp.query_ans() + 1; // Depth is number of edges

    // Only care about in

    // Update the children of everyone else
    int node_index = temp.query_index();

    t(node_index,temp.query_ans()+1);
    if(!k)
    {
      _;_;
      for(int i=0;i<2*n;i++) t(i,query(i,i).query_ans(),query(i,i).query_index());
      _;_;
    }
    while(true)
    {
      if(taken[node_index]) break;

      taken[node_index] = true;

      for(auto v : adj[node_index])
      {
        if(taken[v])
        {
          continue;
        }

        t(v,in[v],out[v],-(query(in[v],in[v]).query_ans()+1));
        update(in[v],out[v],-(query(in[v],in[v]).query_ans()+1)); // Subtract depth right
      }

      int depth_node = query(in[node_index],in[node_index]).query_ans();

      update(in[node_index],in[node_index],-(depth_node+1)); // Update to -1
      t(query(in[node_index],in[node_index]).query_ans(),node_index);

      node_index = par[node_index];
    }
  }

  cout << answer << endl;
  return 0;
}

/*
8 2
1 1 2 3 4 4 6 


10 3
1 1 2 2 3 3 4 4 5
*/