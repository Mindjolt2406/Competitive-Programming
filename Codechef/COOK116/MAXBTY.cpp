#include<bits/stdc++.h>
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
  ll leftsum = -1e16;
  ll rightsum = -1e16;
  ll sum = -0;
  ll maxsum = -1e16;
  void assign(ll value)
  {
    sum = value;
    leftsum = rightsum = maxsum = sum;
  }
  void update(ll value)
  {
    sum = value;
    leftsum = rightsum = maxsum = sum;
  }
  void combine(node &n1, node &n2)
  {
    leftsum = max(n1.leftsum,n1.sum+n2.leftsum);
    rightsum = max(n2.rightsum,n2.sum+n1.rightsum);
    sum = n1.sum+n2.sum;
    maxsum = max(max(leftsum,rightsum),n1.rightsum+n2.leftsum);
    maxsum = max(max(maxsum,n1.maxsum),n2.maxsum);
  }
  ll queryleft()
  {
    return leftsum;
  }

  ll queryright()
  {
    return rightsum;
  }
} node;

const int N = 1e5+10;
int n;
ll a[N] = {0};
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
void update(int index, ll value, int pos = 0, int l = 0,int r = n-1)
{
  if(l==r)
  {
    tree[pos].update(value);
    return;
  }

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  if(index<=mid) update(index,value,left,l,mid);
  else update(index,value,right,mid+1,r);

  tree[pos].combine(tree[left],tree[right]);
}

node query(int x,int y,int pos = 0, int l = 0, int r = n-1)
{
  node ans,n1,n2;
  ans.beg = l, ans.end = r;
  // t(l,r,x,y); 
  // if(l>y || r<x) return ans;
  if(r<x || l>y) return ans;
  if(l>=x && r<=y) return tree[pos];

  // shift(pos,l,r); // Only needed for lazy propagation

  int left = (pos<<1)+1, right = left+1, mid = (l+r)>>1;

  n1 = query(x,y,left,l,mid); n2 = query(x,y,right,mid+1,r);
  ans.combine(n1,n2);
  return ans;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int q;
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i];
    build();

    while(q--)
    {
      string s;
      int l,r;
      cin >> s;
      if(s == "Q")
      {
        int l,r;
        cin >> l >> r;
        l--; r--;
        ll leftsum = 0, rightsum = 0;

        if(l > 0) leftsum = query(0,l-1).queryright();
        if(r < n-1) rightsum = query(r+1,n-1).queryleft();
        leftsum = max(leftsum,0);
        rightsum = max(rightsum,0);
        ll centresum = query(l,r).sum;

        cout << leftsum + centresum + rightsum << endl;
      }
      else
      {
        int index;
        ll val;
        cin >> index >> val;
        index--;
        update(index,val);
        // cout << "After update" << endl;
        // cout << query(index,index).sum << endl;
      }
    }
    memset(a,0,sizeof(a));
    memset(tree,0,sizeof(tree));
  }
  return 0;
}

/*
2
6 3
1 -3 4 5 -6 7
Q 6 6
U 6 -7
Q 6 6
5 5
-1 2 -2 1 -3
Q 3 5
Q 2 4
U 1 1
Q 2 4
Q 3 5

*/