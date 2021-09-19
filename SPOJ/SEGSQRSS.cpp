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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  // Default for null nodes
  ll sumSq = 0;
  ll sum = 0;
  ll num = 0;

  void assign(ll value) {
    sumSq = value * value;
    sum = value;
    num = 1;
  }

  void updateAssign(ll value) {
    sumSq = num * value * value;
    sum = num * value;
  }

  void updateIncrement(ll value) {
      sumSq += sum * 2 * value + num * value * value;
      sum += num * value;
  }

  void combine(node &n1, node &n2) {
    sumSq = n1.sumSq + n2.sumSq;
    sum = n1.sum + n2.sum;
    num = n1.num + n2.num;
  }

  ll query() {
    return sumSq;
  }

} node;

typedef struct SegTree {
    int n;
    vector<ll> a;
    vector<ll> lazyAssign, lazySum;
    vector<node> tree;

    void init(int n) {
        this -> n = n;
        a.resize(n);
        lazyAssign.resize(4*n, -INF);
        lazySum.resize(4*n);
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

    // Range update
    void upd(int pos, int l,int r,ll assignVal, ll sumVal) {
        if(assignVal != -INF) {
            lazySum[pos] = 0;
            lazyAssign[pos] = assignVal;
            tree[pos].updateAssign(assignVal);
        }

        lazySum[pos] += sumVal; // Associative lazy function
        tree[pos].updateIncrement(sumVal);
    }

    void shift(int pos, int l, int r)
    {
        if(((lazyAssign[pos] != -INF) || lazySum[pos]) && l < r) {
            int mid = (l+r)>>1, left = (pos<<1)+1, right = left+1;
            upd(left,l,mid,lazyAssign[pos], lazySum[pos]);
            upd(right,mid+1,r,lazyAssign[pos], lazySum[pos]);
            lazyAssign[pos] = -INF; // Identity of the function
            lazySum[pos] = 0;
        }
    }

    void update(int x,int y,ll val, int type, int pos, int l, int r) {
        // t(l,r,x,y);
        if(l>y || r<x) return;
        if(l>=x && r<=y) {
            if(type == 0) upd(pos, l, r, val, 0);
            else upd(pos, l, r, -INF, val);
            return;
        }

        shift(pos,l,r);
        int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

        update(x,y,val,type, left,l,mid);
        update(x,y,val,type, right,mid+1,r);

        tree[pos].combine(tree[left], tree[right]);
    }

    void update(int x, int y, ll val, int type) {
        update(x, y, val, type, 0, 0, n-1);
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    SegTree segTree;
    segTree.init(v);

    while(q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--; r--;

        if(type == 2) {
            ll ans = segTree.query(l, r).query();
            cout << ans << endl;
        } else {
            ll x;
            cin >> x;
            segTree.update(l, r, x, type);
        }
    }
}

int main() {
    __;
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++) {
        cout << "Case " << h << ": " << endl;
        solve();
    }
    return 0;
}

/*
-10 4 -6 9 9 -5 8 3

-10 11 1 14 12 -2 4 1
