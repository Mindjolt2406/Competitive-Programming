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


typdef struct node
{
  int start,end;
  int pending;
  bool flag;
  node(): start(0),end(0),pending(0),flag(false) {} // For default values

  void combine(node &n1, node&n2)
  {
    // Both normal merging and lazy merging happens here
    // Eg, merging left and right nodes and their lazy values
    // total = n1.toal+n2.total+n1.pending+n2.pending
  }
  void assignLeaf(ll value)
  {
    // Assigns the leaf value while building
  }

  ll query() // The parameter which is the answer
  {
    // Eg. return maxsum
  }

  void addUpdate(int value)
  {
    // It's a function of pending and value
    pending+=value;
  }

  void applyUpdate()
  {
    // Function of total, pending, length of the array
    // Reset pending
    total+=pending*(end-start+1);
    pending = 0; 
    flag = false;
  }

  int getPending() // Needed while querying
  {
    return pending;
  }

  void hasUpdate() // Does it have any lazy updates to do?
  {
    // Example
    return flag;
  }

  

} node;

typdef struct SegTree
{ 
  // Vector of nodes
  // Size of the tree
  vector<node> tree;
  int n;

  SegTree(vector<int> &v, int n)
  {
    this->n = n;
    tree.assign(2*n);
    this->v = v;
  }

  void build(vector<int> &v,int beg,int end,int pos)
  {
    tree[pos].beg = beg; tree[pos].emd = end;
    if(beg==end)
    { 
      tree[pos].assignLeaf(v[beg]);
      return tree[pos];
    }

    int mid = (beg+end)>>1;
    int leftIndex = pos<<1, rightIndex = pos<<1+1;

    build(v,beg,mid,leftIndex);
    build(v,mid+1,end,rightIndex); 

    tree[pos].combine(tree[leftIndex],tree[rightIndex]);
  }

  void shift(int pos, int l, int r)
  {
    if(tree[pos].flag)
    {

    }
  }

  node query(int beg,int end,int pos)
  {
    node ans;
    if(tree[pos].beg==beg && tree[pos].end==end)
    {
      if(tree[pos].hasUpdate()) 
      {
        ans = tree[pos];
        ans.applyUpdate();
      }
      return tree[pos];
    }

    int mid = (beg+end)>>1;
    int leftIndex = pos<<1, rightIndex = pos<<1+1;

    if(end<=mid) query(beg,mid,leftIndex);
    else if(beg>mid) query(mid+1,end,rightIndex);
    else
    {
      node left = query(beg,mid,leftIndex);
      node right = query(mid+1,end,rightIndex);
    }

    ans.beg = left.beg; ans.end = right.end;
    ans.combine(tree[leftIndex],tree[rightIndex]);

    if(tree[pos].hasUpdate()) 
    {
      ans.addUpdate(tree[pos].getPending());
      ans.applyUpdate();
    }
    return ans;
  }

  void update(int value,int beg,int end,int pos)
  {
    if(tree[pos].beg==beg && tree[pos].end==end)
    {
      tree[pos].upd(pos,beg,end,value);
    }

    int mid = (beg+end)>>1;
    int leftIndex = pos<<1, rightIndex = pos<<1+1;

    if(end<=mid) update(value,beg,end,leftIndex);
    else if(beg>mid) update(value,beg,end,rightIndex);
    else
    {
      update(value,beg,mid,leftIndex);
      update(value,mid+1,end,rightIndex);
    }

    tree[pos].combine(tree[leftIndex],tree[rightIndex]);
  }
} seg;

int main()
{
  __;
  
  return 0;
}

