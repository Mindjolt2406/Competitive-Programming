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
    ans += value;
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
ll a[N] = {0}, lazy[4*N] = {0};
node tree[4*N];

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