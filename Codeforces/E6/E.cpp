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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


typedef struct node
{
  // Any variable
  int beg = 0,end = 0,pos = 0;
  ll col = 0;

  void assign(ll value)
  {
    col = (1LL << value);
  }
  void update(ll value)
  {
    col = (1LL << value);
  }
  void combine(node &n1, node &n2)
  {
    col = n1.col | n2.col;
  }
  ll query()
  {
    return __builtin_popcountll(col);
  }
} node;

const int N = 8e5+100;
int final_n;
ll a[N] = {0}, lazy[4*N] = {0};
node tree[4*N];

void build(int pos = 0, int l =0, int r = final_n-1)
{
  // if(l>=final_n || r<0) return;
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
// void update(int index, int value, int pos = 0, int l = 0,int r = final_n-1)
// {
//   if(l==r)
//   {
//     tree[pos].update(value);
//     return;
//   }

//   int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

//   if(index<=mid) update(index,value,left,l,mid);
//   else update(index,value,right,mid+1,r);

//   tree[pos].combine(tree[left],tree[right]);
// }

// Range update
void upd(int pos, int l,int r,ll x)
{
  lazy[pos] = x; // Assosciative lazy function
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

void update(int x,int y,ll val, int pos = 0, int l = 0, int r = final_n-1)
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

node query(int x,int y,int pos = 0, int l = 0, int r = final_n-1)
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

int tourCounter = 0;
vector<pair<int,int> > range(4e5+10);
vector<vector<int> > adj(4e5+10);

void dfs(vector<int> &colours,int u = 0, int p = -1)
{
  a[tourCounter] = colours[u];
  tourCounter++;
  range[u].fi = tourCounter-1;
  for(auto v : adj[u])
  {
    if(v-p) dfs(colours,v,u);
  }
  a[tourCounter] = colours[u];
  tourCounter++;
  range[u].se = tourCounter-1;
}

int main()
{
  __;
  int n,q;
  cin >> n >> q;
  vector<int> colours(n);
  for(int i=0;i<n;i++) cin >> colours[i];
  
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs(colours);
  final_n = tourCounter;
  build();


  while(q--)
  {
    int a,vert;
    cin >> a >> vert;
    vert--;
    if(a==1) 
    {
      int col;
      cin >> col;
      update(range[vert].fi,range[vert].se,col);
    }
    else
    {
      cout << query(range[vert].fi,range[vert].se).query() << endl;
    }
  }

  // memset(lazy,0,sizeof(lazy));
  // memset(tree,0,sizeof(tree));
  // memset(a,0,sizeof(a));
  return 0;
}

/*
10 10
39 50 50 7 39 7 46 7 39 7
10 7
7 3
3 5
3 4
6 4
1 4
1 8
8 2
2 9
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10

*/