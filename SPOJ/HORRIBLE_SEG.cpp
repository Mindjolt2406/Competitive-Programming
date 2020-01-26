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
  int beg,end;
  int pending;
  bool flag;
  ll total;
  node(): beg(0),end(0),pending(0),flag(false) {} // For default values

  void combine(node &n1, node&n2)
  {
    total = n1.total+n2.total;
    total+=n1.pending*(n1.end-n1.beg+1);
    total+=n2.pending*(n2.end-n2.beg+1);


  }
  void assignLeaf(ll value)
  {
    // Assigns the leaf value while building
    total = value; 
  }

  ll query() // The parameter which is the answer
  {
    return total;
  }

  void addUpdate(int value)
  {
    // It's a function of pending and value
    pending+=value;
  }

  void applyUpdate()
  {
    // Function of total, pending, length of the array
    // Pass it on to children? No need cuz that's supposed to happen in merge
    // Reset pending
    total+=pending*(end-beg+1);
    pending = 0; 
    // flag = false;
  }

  bool hasUpdate() // Does it have any lazy updates to do?
  {
    return flag;
  }

  void upd(int id, int l, int r, int value)
  {
    if(l>r) return;
    flag = true;
    pending+=value;
    applyUpdate();
  }

} node;

typedef struct SegTree
{ 
  vector<ll> v;
  int n;
  vector<node> tree;

  SegTree(vector<ll> &v, int n)
  {
    this->n = n;
    tree = vector<node>(2*n);
    this->v = v;
  }

  void build(vector<int> &v,int beg,int end,int pos)
  {
    tree[pos].beg = beg; tree[pos].end = end;
    if(beg==end)
    { 
      tree[pos].assignLeaf(v[beg]);
      return;
    }

    int mid = (beg+end)>>1;
    int leftIndex = pos<<1, rightIndex = (pos<<1)+1;

    build(v,beg,mid,leftIndex);
    build(v,mid+1,end,rightIndex); 

    tree[pos].combine(tree[leftIndex],tree[rightIndex]);
  }

  void shift(int pos,int beg,int end)
  {
    if(tree[pos].flag && beg<=end)
    {
      int mid = (beg+end)>>1;
      tree[pos].upd(pos<<1,beg,mid,tree[pos].pending);
      tree[pos].upd((pos<<1)+1,mid+1,end,tree[pos].pending);
      tree[pos].flag = false;
      tree[pos].pending = 0;
    }
  }

  node query(int beg,int end,int pos = 0)
  {
    node ans;
    if(tree[pos].beg==beg && tree[pos].end==end)
    {
      return tree[pos];
    }

    shift(pos,beg,end);

    int mid = (beg+end)>>1;
    int leftIndex = pos<<1, rightIndex = (pos<<1)+1;

    node left,right;
    if(end<=mid) query(beg,mid,leftIndex);
    else if(beg>mid) query(mid+1,end,rightIndex);
    else
    {
      left = query(beg,mid,leftIndex);
      right = query(mid+1,end,rightIndex);
    }

    ans.beg = left.beg; ans.end = right.end;
    ans.combine(tree[leftIndex],tree[rightIndex]);

    // if(tree[pos].hasUpdate()) 
    // {
    //   ans.addUpdate(tree[pos].getPending());
    //   ans.applyUpdate();
    // }
    return ans;
  }

  void update(int value,int beg,int end,int pos = 0)
  {
    if(tree[pos].beg==beg && tree[pos].end==end)
    {
      tree[pos].upd(pos,beg,end,value);
    }

    shift(pos,beg,end);

    int mid = (beg+end)>>1;
    int leftIndex = pos<<1, rightIndex = (pos<<1)+1;

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
  int t;
  cin>>t;
  while(t--)
  {
    int n,q;
    cin>>n>>q;
    vector<ll> v(n);
    seg st(v,n);
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
        st.update(d,b,c);
      }
      else
      {
        cout<<st.query(b,c).query()<<endl;
      }
    }
  }
  return 0;
}

