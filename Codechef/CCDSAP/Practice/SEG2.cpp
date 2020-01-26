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

typedef struct node
{
  int beg,end;
  int ans = 0;
  
  void assign(int value)
  {
    ans = value;
  }
  void update(int value)
  {
    ans+=value;
  }
  void combine(node &n1, node &n2)
  {
    this->ans = n1.ans+n2.ans;
  }
  int query(node &n1)
  {
    return n1.ans;
  }
} node;

const int N = 1e5;
int lazy[N] = {0}, a[N] = {0};
node tree[4*N] = {0};
int n;

// 
void build(int pos = 0, int l = 0, int r = n-1)
{
  tree[pos].beg = l; tree[pos].end = r;
  if(l==r)
  {
    tree[pos].assign(a[l]);
    return;
  }

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  build(left,l,mid);
  build(right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

void update(int index,int val, int pos = 0,int l = 0,int r = n-1)
{
  if(l==r) 
  {
    tree[pos].update(val);
    return;
  }

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  if(index<=mid) update(index,val,left,l,mid);
  else update(index,val,right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

void upd(int pos, int l, int r, int x)
{
  lazy[pos]+=x; // Assosciative lazy function
  tree[pos].update((r-l+1)*x); // Total constribution to the answer
}

void shift(int pos, int l, int r)
{
  if(lazy[pos] && l<r)
  {
    int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;
    upd(left,l,mid,lazy[pos]);
    upd(right,mid+1,r,lazy[pos]);
    lazy[pos] = 0;
  }
}

void update(int x,int y,int val, int pos = 0,int l = 0,int r = n-1)
{
  if(y<l || x>r) return;
  if(l>=x && y<=r)
  {
    upd(pos,l,r,val);
    return;
  }

  shift(pos,l,r);
  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  update(x,y,val,left,l,mid);
  update(x,y,val,right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

node query(int x,int y,int pos = 0,int l = 0,int r = n-1)
{
  node ans,n1,n2;
  if(r<x || l>y) return ans;
  if(l>=x && y<=r) return tree[pos];

  shift(pos,l,r);

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  n1 = query(x,y,left,l,mid);
  n2 = query(x,y,right,mid+1,r);
  return ans;
}

int main()
{
  __;
  
  return 0;
}

