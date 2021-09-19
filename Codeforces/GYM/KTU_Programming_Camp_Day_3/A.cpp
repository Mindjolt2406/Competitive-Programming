#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 4001
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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}

typedef struct node
{
  // Any variable
  int beg = 0, end = 0;

  int pref0 = 0, pref1 = 0, suff0 = 0, suff1 = 0;
  bool totalXor = false;
  // Default for null nodes
  int ans = 0;

  void assign(int value) {
    if (value) {
        pref1 = suff1 = ans = totalXor = 1;
        pref0 = suff0 = 0;
    }
    else {
        pref0 = suff0 = 1;
        totalXor = ans = pref1 = suff1 = 0;
    }
  }

  void update(ll value) {
    assign(value);
  }

  void combine(node &n1, node &n2) {
    // Generate pref xors
    pref0 = n1.pref0 + (n1.totalXor ? n2.pref1 : n2.pref0);
    pref1 = n1.pref1 + (n1.totalXor ? n2.pref0 : n2.pref1);
    pref0 %= MOD; pref1 %= MOD;

    // Generate suffix xors
    suff0 = n2.suff0 + (n2.totalXor ? n1.suff1 : n1.suff0);
    suff1 = n2.suff1 + (n2.totalXor ? n1.suff0 : n1.suff1);
    suff0 %= MOD; suff1 %= MOD;

    // Xor of all values
    totalXor = n1.totalXor != n2.totalXor;

    // Calculating final answer
    ans = n1.ans + n2.ans + (1LL * n1.suff0 * n2.pref1) + (1LL * n1.suff1 * n2.pref0);
    ans %= MOD;
  }

  ll query() {
    return ans;
  }

} node;

typedef struct SegTree {
    int n;
    vector<bool> a;
    vector<node> tree;

    void init(int n) {
        this -> n = n;
        a.resize(n);
        tree.resize(4*n);
        // build(0, 0, n-1);
    }

    void init(vector<bool> &v) {
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
    void update(int index, int value, int pos, int l,int r) {
      if(l==r) {
        tree[pos].update(value);
        return;
      }

      int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

      if(index<=mid) update(index,value,left,l,mid);
      else update(index,value,right,mid+1,r);

      tree[pos].combine(tree[left],tree[right]);
    }

    node query(int x,int y,int pos, int l, int r) {
        node ans,n1,n2;
        // if(l>y || r<x) return ans;
        if(r<x || l>y) return ans;
        if(l>=x && r<=y) return tree[pos];

        // shift(pos,l,r); // Only needed for lazy propagation

        int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

        n1 = query(x,y,left,l,mid); n2 = query(x,y,right,mid+1,r);
        ans.combine(n1,n2);
        return ans;
    }

    void update(int x, ll val) {
        update(x, val, 0, 0, n-1);
    }

    // void update(int x, int y, ll val) {
    //     update(x, y, val, 0, 0, n-1);
    // }

    node query(int x, int y) {
        return query(x, y, 0, 0, n-1);
    }
} SegTree;

int main() {
    __;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    vector<SegTree> segTrees(10);

    vector<vector<bool>> bits(10, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        int tempVal = v[i];
        for (int j = 0; j < 10; j++) {
            bits[j][i] = tempVal & 1;
            tempVal >>= 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        segTrees[i].init(bits[i]);
    }
    
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, val;
            cin >> index >> val;
            index--;

            for (int i = 0; i < 10; i++) {
                segTrees[i].update(index, (val & 1));
                val >>= 1;
            }
        } else { // type == 2
            int l, r;
            cin >> l >> r;
            l--; r--;
            
            ll prodVal = 1;
            ll finalAns = 0;
            for (int i = 0; i < 10; i++) {
                finalAns += (1LL * prodVal * segTrees[i].query(l, r).query()) % MOD;
                finalAns %= MOD;
                prodVal <<= 1;
            }

            cout << finalAns << endl;
        }
    }
    return 0;
}
