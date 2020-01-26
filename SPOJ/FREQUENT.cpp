/*
Rathin Bhargava
IIIT Bangalore

*/

// endl is not the fastest, use "\n"
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
#define endl "\n"
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

typedef struct node
{
  // Any variable
  int beg = 0,end = 0;
  int val = 0;
  int leftfreq = 0, rightfreq = 0, leftno = 0, rightno = 0, centreno = 0,centrefreq = 0, ansno = 0, ansfreq = 0;
  void assign(ll value)
  {
    leftfreq = rightfreq = centrefreq = ansfreq = 1;
    ansno = leftno = rightno = centreno = value;
  }
  void combine(node &n1, node &n2)
  {
    leftfreq = n1.leftfreq; leftno = n1.leftno;
    rightfreq = n2.rightfreq; rightno = n2.rightno;
    if(n1.leftno==n1.rightno && n1.rightno==n2.leftno)
    {
      leftfreq = n1.leftfreq+n2.leftfreq;
    }
    if(n2.leftno==n2.rightno && n1.rightno==n2.leftno)
    {
      rightfreq = n2.leftfreq+n1.rightfreq;
    }

    if(n1.rightno==n2.leftno)
    {
      centrefreq = n1.rightfreq + n2.leftfreq;
      centreno = n1.rightno;
    }

    if(n1.centrefreq>centrefreq) 
    {
      centrefreq = n1.centrefreq;
      centreno = n1.centreno;
    }

    if(n2.centrefreq>centrefreq)
    {
      centrefreq = n2.centrefreq;
      centreno = n2.centreno;
    }

    set<pair<int,int> > s = {mp(leftfreq,leftno),mp(rightfreq,rightno),mp(centrefreq,centreno)};
    pair<int,int> p = *s.rbegin();
    ansfreq = p.fi, ansno = p.se;
  }
  ll query()
  {
    return ansfreq;
  }
} node;

const int N = 1e5+10;
int n;
ll a[N] = {0};
node tree[4*N];

void build(int pos = 0, int l =0, int r = n-1)
{
  // t(l,r,pos);
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




int main()
{
  __;
  cin>>n;
  while(n)
  {
    int q;
    cin>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    build();
    // _;
    // for(int i=0;i<4*n;i++)   t(i,tree[i].ansfreq,tree[i].leftfreq,tree[i].rightfreq,tree[i].beg,tree[i].end);
    while(q--)
    {
      int b,c;
      cin>>b>>c;
      b--;c--;
      cout<<query(b,c).query()<<endl;
    }

    memset(tree,0,sizeof(tree));
    memset(a,0,sizeof(a));

    cin>>n;
  }
  return 0;
}