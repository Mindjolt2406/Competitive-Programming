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
#define endl "\n"
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

ll min(ll x, ll y) 
{
  if(x<y) return x;
  return y;
}

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  ll ans = INF;
  int index=  -1;

  void assign(ll value)
  {
    ans = value;
    index = beg;
  }
  void update(ll value)
  {
    ans = value;
  }
  void combine(node &n1, node &n2)
  {
    ans = min(n1.ans,n2.ans);
    index = ans==n1.ans ? n1.index : n2.index; 
    // t(n1.ans,n2.ans,n1.index,n2.index,index);
  }
  ll query()
  {
    return ans;
  }
} node;

const int N = 3e5+10;
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

void update(int index, int value, int pos = 0, int l = 0,int r = n-1)
{
  if(l==r)
  {
    tree[pos].assign(value);
    a[l] = value;
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

void finish()
{
  memset(a,0,n);
  memset(tree,0,min(8*n,sizeof(tree)));
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    vector<stack<int> > adj1(n+1);

    vector<int> b(n),c(n),invc(n); // c is the mapping from the ith element in b to the c[i]th element in a
    // vector<int> b(n),c(n),invc(n); // c is the mapping from the ith element in b to the c[i]th element in a

    for(int i=0;i<n;i++) {cin>>a[i];}
    for(int i=0;i<n;i++) {cin>>b[i];}

    {
      vector<int> a2(n),b2(n);
      for(int i=0;i<n;i++) {a2[i] = a[i]; b2[i] = b[i];}

      sort(a2.begin(),a2.end());
      sort(b2.begin(),b2.end());
      if(a2!=b2) {cout<<"NO"<<endl; finish(); continue;}
    }


    for(int i=0;i<n;i++) adj1[a[i]].push(i);
    // for(int i=0;i<n;i++) adj2[b[i]].push(i);

    for(int i=n-1;i>=0;i--)
    {
      c[i] = adj1[b[i]].top();
      adj1[b[i]].pop();

      // d[i] = adj2[a[i]].top();
      // adj2[a[i]].pop();
    }

    for(int i=0;i<n;i++) invc[c[i]] = i;

    build();
    // t(c);

    // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n"<<endl;

    int boo = false;
    for(int i=0;i<n;i++)
    {
      int val = b[i];
      node temp = query(0,c[i]);
      int ans = temp.query();
      int index = temp.index;
      // t(i,c[i],ans,index);
      update(c[i],INF);
      // swap(c[invc[index]],c[invc[i]]);
      // swap(invc[index],invc[i]);


      // cout<<"c: ";
      // for(int i=0;i<n;i++) cout<<c[i]<<" "; cout<<endl;
      // cout<<"a_new: ";
      // for(int i=0;i<n;i++) cout<<a[c[i]]<<" "; cout<<endl;
      // cout<<"a: ";
      // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
      // t(i,index,val,ans);
      // cout<<endl;

      if(val>ans) {boo = true; break;}
      
    }
    if(boo) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    finish();
  }
  return 0;
}

/*
1
7
1 7 1 4 4 5 6
1 1 4 4 5 7 6

 */
