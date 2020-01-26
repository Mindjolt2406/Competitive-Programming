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
#define vi vector<int>
#define vll vector<long long int>
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


typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  ll ans = 0;
  void assign(ll value)
  {
    ans = value;
  }
  void update(ll value)
  {
    ans+=value;
  }
  void combine(node &n1, node &n2)
  {
    ans = n1.ans+n2.ans;
  }
  ll query()
  {
    return ans;
  }
} node;

const int N = 2e5+10;
int n;
ll a[N] = {0}, lazy[N] = {0};
node tree[2*N];

void build(int pos = 0, int l =0, int r = n-1)
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
// void update(int index, int value, int pos = 0, int l = 0,int r = n-1)
// {
  // if(l>=n || r<0) return;
//   if(l==r)
//   {
//     tree[pos].assign(value);
//     return;
//   }

//   int left = pos<<1, right = left+1, mid = (left+right)>>1;

//   if(index<=mid) update(index,value,left,l,mid);
//   else update(index,value,right,mid+1,r);

//   tree[pos].combine(tree[left],tree[right]);
// }

// Range update
void upd(int pos, int l,int r,ll x)
{
  lazy[pos]+=x; // Assosciative lazy function
  tree[pos].update((r-l+1)*x); // How much this contributes to the node
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

node query(int x,int y,int pos = 0, int l = 0, int r = n-1)
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
  int t;
  cin>>t;
  while(t--)
  {
    int q;
    cin>>n>>q;
    build();
    while(q--)
    {
      int a;
      cin>>a;
      int b,c;
      cin>>b>>c;
      b--;c--;
      if(a==0) 
      {
        ll d;
        cin>>d;
        update(b,c,d);
      }
      else
      {
        cout<<query(b,c).query()<<endl;
      }
    }

    memset(lazy,0,sizeof(lazy));
    memset(tree,0,sizeof(tree));
    memset(a,0,sizeof(a));

  }
  return 0;
}

/*
1
8 6
0 2 4 1000000000000000
0 4 8 2000000000000000
0 4 5 3000000000000000
1 8 8 
0 5 7 4000000000000000
1 4 8

*/
