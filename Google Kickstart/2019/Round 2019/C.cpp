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

vector<pair<int,int> > v;

const int N = 1 << 20;

struct node{
	int cnt = 0;
	void assign(int value){
		cnt = value;
	}
	void update(int value){
		cnt = value;
	}
	void combine(node &left, node &right){
		cnt = left.cnt + right.cnt;
	}
};

int n, a[N], lazy[N];
node tree[2*N];

// [l, r)
void build(int id = 1, int l = 0, int r = n)
{
	if(l+1 == r){
		tree[id].assign(a[l]);
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;

	build(left, l, mid); build(right, mid, r);

	tree[id].combine(tree[left], tree[right]);
	return;
}


// range update and  utility functions
void upd(int id,int l,int r,int x)
{ //	update the current node and its index in the lazy array
	lazy[id] |= x;
	tree[id].update((r-l)*x);
}

void shift(int id,int l,int r)
{ //propogate update information to the children
	if(lazy[id] and l+1 < r){
		int mid = (l+r)/2;
		upd(id * 2, l, mid, lazy[id]);
		upd(id * 2 + 1, mid, r, lazy[id]);
		lazy[id] = 0; // passing is done, reset the index in the lazy array
	}
}

// range update -> update(x, y, val);
void update(int x, int y, int val, int id = 1, int l = 0, int r = n)
{
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
		return;
	}

	shift(id, l, r); // pass the updates to the children

	int left = id<<1, right = left+1, mid = (l+r)>>1;

	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);

	tree[id].combine(tree[left], tree[right]);
	return;
}

// range query -> query(x, y);
// for point query, traverse like in point update
int query(int x, int y, int id = 1, int l = 0, int r = n)
{
	if(x >= r or l >= y) return 0;
	if(x <= l && r <= y) return tree[id].cnt;

	shift(id, l, r);	//use this with lazy propogation

	int left = id<<1, right = left+1, mid = (l+r)>>1;

	return query(x, y, left, l, mid) + query(x, y, right, mid, r);
}

int find(int m)
{
  for(int i=0;i<n;i++) a[i] = 0;
  build();
  vector<bool> flag(n);
  int index = -1,min2 = INF;
  vector<int> keep;
  for(int j=0;j<m;j++)
  {
    int max1 = -1;
    for(int i=0;i<m;i++)
    {
      if(flag[i]) continue;
      int a = v[i].fi, b = v[i].se;
      int val = query(b,b+1);
      int c = b-a+1 - query(a,b+1);
      // t(a,b,query(a,b+1));
      max1 = max(max1,c);
      if(max1==c) index = i;
      // t(i,max1,c,index);
    }
    keep.push_back(index);
    // min2 = min(max1,min2);
    flag[index] = true;
    update(v[index].fi,v[index].se+1,1);
    // t(max1,index);
    // t(max1,min2,v[index].fi,v[index].se);
  }
  pr(keep);
  reverse(keep.begin(),keep.end());
  for(int i=0;i<n;i++) a[i] = 0;
  build();
  int min1 = INF;
  for(int i=0;i<m;i++)
  {
    int a = v[keep[i]].fi, b = v[keep[i]].se;
    int c = query(a,b+1); 
    c = b+1-a-c;
    t(i,c,a,b);
    min1 = min(min1,c);
    update(a,b+1,1);
  }
  return min1;
}

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      a--;b--;
      v.push_back(mp(a,b));
    }
    int ans = find(m);
    v.clear();
    memset(tree,0,2*N);
    memset(a,0,N);
    memset(lazy,0,N);
    cout<<"Case #"<<h<<": "<<ans<<endl;
  }
  return 0;
}

