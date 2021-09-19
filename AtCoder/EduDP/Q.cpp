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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}

ll max(ll x, ll y) {return x > y ? x : y;}

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  // Default for null nodes
  ll ans = 0;

  void assign(ll value) {
    ans = value;
  }

  void update(ll value) {
    ans = value;
  }

  void combine(node &n1, node &n2) {
    ans = max(n1.ans, n2.ans);
  }

  ll query() {
    return ans;
  }

} node;

typedef struct SegTree {
    int n;
    vector<ll> a;
    vector<node> tree;

    void init(int n) {
        this -> n = n;
        a.resize(n);
        tree.resize(4*n);
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
    void update(int index, ll value, int pos, int l,int r) {
      if(l==r) {
        tree[pos].update(value);
        return;
      }

      int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

      if(index<=mid) update(index,value,left,l,mid);
      else update(index,value,right,mid+1,r);

      tree[pos].combine(tree[left],tree[right]);
    }

    // For point updates.
    void update(int x, ll val) {
        update(x, val, 0, 0, n-1);
    }

    node query(int x,int y,int pos, int l, int r) {
        node ans,n1,n2;
        // if(l>y || r<x) return ans;
        if(r<x || l>y) return ans;
        if(l>=x && r<=y) return tree[pos];

        int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

        n1 = query(x,y,left,l,mid); n2 = query(x,y,right,mid+1,r);
        ans.combine(n1,n2);
        return ans;
    }

    node query(int x, int y) {
        return query(x, y, 0, 0, n-1);
    }
} SegTree;

int main() {
    __;
    int n;
    cin >> n;
    vector<int> heights(n), weights(n);
    for (auto &height : heights) 
        cin >> height;
    for (auto &weight : weights) 
        cin >> weight;
    
    vector<int> heightSorted = heights;
    sort(heightSorted.begin(), heightSorted.end());
    map<int, int> heightIndex;
    for (int i = 0; i < n; i++)
        heightIndex[heightSorted[i]] = i;

    SegTree segTree;
    segTree.init(n);

    for (int i = 0; i < n; i++) {
        int currIndex = heightIndex[heights[i]];
        int currWeight = weights[i];

        ll currAns = segTree.query(0, currIndex - 1).query();
        currAns += currWeight;
        segTree.update(currIndex, currAns);
    }

    cout << segTree.query(0, n-1).query() << endl;
    return 0;
}