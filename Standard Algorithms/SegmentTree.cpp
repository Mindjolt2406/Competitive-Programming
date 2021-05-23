typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  // Default for null nodes
  ll ans = INF;

  void assign(ll value) {
    ans = value;
  }

  void update(ll value) {
    ans += value;
  }

  void combine(node &n1, node &n2) {
    ans = min(n1.ans, n2.ans);
  }

  ll query() {
    return ans;
  }

} node;

typedef struct SegTree {
    int n;
    vector<ll> a;
    vector<ll> lazy;
    vector<node> tree;

    void init(int n) {
        this -> n = n;
        a.resize(n);
        lazy.resize(4*n);
        tree.resize(4*n);
        // build(0, 0, n-1);
    }

    void init(vector<ll> &v) {
        this -> n = v.size();
        init(n);
        for(int i = 0; i < n; i++) a[i] = v[i];
        build(0, 0, n-1);
    }

    void build(int pos, int l , int r) {
        // if(l>=n || r<0) return;
        tree[pos].beg = l, tree[pos].end = r;
        if(l==r) {
            tree[pos].assign(a[l]);
            return;
        }

        int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;
        build(left,l,mid); build(right,mid+1,r);

        tree[pos].combine(tree[left],tree[right]);
    }

    // Point updates
    // void update(int index, int value, int pos = 0, int l = 0,int r = n-1) {
    //   if(l==r) {
    //     tree[pos].update(value);
    //     return;
    //   }

    //   int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

    //   if(index<=mid) update(index,value,left,l,mid);
    //   else update(index,value,right,mid+1,r);

    //   tree[pos].combine(tree[left],tree[right]);
    // }

    // Range update
    void upd(int pos, int l,int r,ll x) {
        lazy[pos]+=x; // Associative lazy function
        tree[pos].update(x); // How much this contributes to the node
    }

    void shift(int pos, int l, int r)
    {
        if(lazy[pos] && l<r) {
            int mid = (l+r)>>1, left = (pos<<1)+1, right = left+1;
            upd(left,l,mid,lazy[pos]);
            upd(right,mid+1,r,lazy[pos]);
            lazy[pos] = 0; // Identity of the function
        }
    }

    void update(int x,int y,ll val, int pos, int l, int r) {
        // t(l,r,x,y);
        if(l>y || r<x) return;
        if(l>=x && r<=y) {
            upd(pos, l, r, val);
            return;
        }

        shift(pos,l,r);
        int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

        update(x,y,val,left,l,mid);
        update(x,y,val,right,mid+1,r);

        tree[pos].combine(tree[left], tree[right]);
    }

    void update(int x, int y, ll val) {
        update(x, y, val, 0, 0, n-1);
    }

    node query(int x,int y,int pos, int l, int r) {
        node ans,n1,n2;
        // if(l>y || r<x) return ans;
        if(r<x || l>y) return ans;
        if(l>=x && r<=y) return tree[pos];

        shift(pos,l,r); // Only needed for lazy propagation

        int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

        n1 = query(x,y,left,l,mid); n2 = query(x,y,right,mid+1,r);
        ans.combine(n1,n2);
        return ans;
    }

    node query(int x, int y) {
        return query(x, y, 0, 0, n-1);
    }
} SegTree;