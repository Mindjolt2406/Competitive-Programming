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

ll max(ll x, ll y)
{
  if(x > y) return x;
  return y;
}

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  ll ans = 0;
  bool taken = false;

  void assign(ll value,bool taken_val)
  {
    ans = value;
    taken = taken_val;
    if(!taken) ans = -INF;
  }
  void update(ll value)
  {
    ans+=value;
  }
  void combine(node &n1, node &n2)
  {
    if(n1.taken && n2.taken)
    {
      ans = max(n1.ans,n2.ans);
    }
    else if(n1.taken)
    {
      ans = n1.ans;
    }
    else if(n2.taken)
    {
      ans = n2.ans;
    }
    else ans = -INF;
    taken = n1.taken || n2.taken;
  }
  ll query()
  {
    return ans;
  }
} node;

const int N = 1e6+10;
int n;
ll a[N] = {0}, lazy[4*N] = {0};
bool b[N] = {0};
node tree[4*N];

void build(int pos = 0, int l =0, int r = N-5)
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

void update(int x,int y,ll val, int pos = 0, int l = 0, int r = N-5)
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

node query(int x,int y,int pos = 0, int l = 0, int r = N-5)
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

int main()
{
  __;
  int m,p;
  cin >> m >> n >> p;
  vector<pair<int,ll> > attack(m);
  for(int i=0;i<m;i++) cin >> attack[i].fi >> attack[i].se;
  vector<pair<int,ll> > defense(n);
  for(int i=0;i<n;i++) cin >> defense[i].fi >> defense[i].se;

  vector<pair<pair<int,int> , ll > > v(p);
  for(int i=0;i<p;i++) cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se;

  // Base array for the segment tree
  for(int i=0;i<n;i++)
  {
    a[defense[i].fi] -= defense[i].se; 
    b[defense[i].fi] = true;
  }
  
  // Build the seg tree
  build();

  // _;
  sort(attack.begin(),attack.end());
  sort(v.begin(),v.end());

  int left = 0;
  ll max_profit = -INF;
  for(int i=0;i<m;i++)
  {
    // t(i);
    ll cost = 0;
    cost -= attack[i].se;
    
    // Update the required monsters which can be killed using weapon i
    while(left != p && attack[i].fi > v[left].fi.fi)
    {
      // t(i,left,attack[i].fi,v[left].fi.fi);
      update(v[left].fi.se+1,N-5,v[left].se);
      left++;
    }

    // Get the best armor
    ll ans = query(0,N-5).query();
    // t(ans);
    cost += ans;
    max_profit = max(cost,max_profit);
  }

  cout << max_profit << endl;
  return 0;
}
