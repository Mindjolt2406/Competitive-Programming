#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define mt make_tuple
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

const int N = 1 << 17;
int n,total;

struct node{
	int key;
  pair<int,int> p;
	void assign(int a,int b){
    p.first = a;
    p.second = b;
    key = min(a,total-a);
	}
	void update(int value){
    cout<<"key before: "<<key<<endl;
		key += value;
    if(key>=total)key-=total;
    else if(key<0) key+=total;
    cout<<"key after: "<<key<<endl;
    cout<<"value: "<<value<<" total: "<<total<<endl;
	}
	void combine(node &left, node &right){
    if(left.key>right.key)
    {
      key = left.key;
      p.first = left.p.first;
      p.second  = left.p.second;
    }
    else
    {
      key = right.key;
      p.first = right.p.first;
      p.second  = right.p.second;
    }
		// p.first = max(left.p.first,right.p.first);
    // if(p.first==left.p.first) {p.second = left.p.second;key = left.key;}
    // else {p.second = right.p.second;key = right.key;}
	}
};

int a[N], lazy[N];
node *tree;

// [l, r)
void build(int id = 1, int l = 0, int r = n)
{
	if(l+1 == r){
    cout<<"l: "<<l<<" id: "<<id<<endl;
		tree[id].assign(a[l]-a[0],l);
    cout<<tree[id].key<<endl;
		return;
	}
	int left = id<<1, right = left+1, mid = (l+r)>>1;

	build(left, l, mid); build(right, mid, r);

	tree[id].combine(tree[left], tree[right]);
	return;
}

// point update -> update(index, value);
// void update(int index, int val, int id = 1, int l = 0, int r = n)
// {
// 	if(l+1 == r){
// 		tree[id].assign(val,l);
// 		return;
// 	}
// 	int left = id<<1, right = left+1, mid = (l+r)>>1;
//
// 	if(index < mid) update(index, val, left, l, mid);
// 	else update(index, val, right, mid, r);
//
// 	tree[id].combine(tree[left], tree[right]);
// }


// range update and  utility functions
void upd(int id,int l,int r,int x)
{ //	update the current node and its index in the lazy array
	lazy[id] += x;
	tree[id].update((r - l) * x);
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
  cout<<"x: "<<x<<" y: "<<y<<" l: "<<l<<" r: "<<r<<endl;
	if(x >= r or l >= y) return;
	if(x <= l && r <= y){
		upd(id, l, r, val);
    cout<<"x: "<<x<<"y: "<<y<<endl;
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
node query(int x, int y, int id = 1, int l = 0, int r = n)
{
	// if(x >= r or l >= y) {node n;n.key = -1;n.p = mp(-1,-1);return n;}
	// if(x <= l && r <= y) return tree[id];
  //
	// shift(id, l, r);	//use this with lazy propogation
  //
	// int left = id<<1, right = left+1, mid = (l+r)>>1;
  //
  // // node n1 = new node;
  // // node n2 = new node;
  // // node n = new node;
  // node n1 = query(x, y, left, l, mid);
  // node n2 = query(x, y, right, mid, r);
  // // node*n = new node[];
  // // tree[id].combine(&n1,&n2);
  // if(n1.key>n2.key) return n1;
  // else return n2;
  // // return tree[id];
  // // pair<int,int> c = query(x, y, left, l, mid);
  // // pair<int,int> d = query(x, y, right, mid, r);
  // // if(c.first>d.first) {tree[id].p.first = c.first;tree[id].p.second = c.second;}
  // // else {tree[id].p.first = d.first; tree[id].p.second = d.second;}
  // // return tree[id].p;
	// // return max(query(x, y, left, l, mid),query(x, y, right, mid, r));
  return tree[1];
}

void changeto(int x,int c)
{
  int d = min(a[max(x,c)] - a[min(x,c)+1],total-a[max(x,c)] - a[min(x,c)+1]);
  if(x>c)
  {
    update(c+1,n+1,-1*d);
    update(0,c+1,d);
  }
  else
  {
    update(c+1,n+1,d);
    update(0,c+1,-1*d);
  }
}

int main()
{
  typedef struct node node;
  cin>>n;
  a[0] = 0;
  for(int i=0;i<n;i++) {cin>>a[i];}
  for(int i=1;i<n;i++) a[i] += a[i-1];
  for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++) {lazy[i] = 0;total+=a[i];}
  tree = (node*)calloc(2*N,sizeof(node));
  build();
  // for(int i=1;i<=2*n;i++) cout<<tree[i].p.first<<" ";cout<<endl;
  for(int i=1;i<=15;i++) cout<<"i: "<<i<<" key: "<<tree[i].key<<" pair: "<<tree[i].p.first<<" "<<tree[i].p.second<<endl;
  int q;
  cin>>q;
  stack<int > *v = new stack<int >[n+1];
  int c = -1;
  for(int i=0;i<q;i++)
  {
    int b;
    cin>>b;
    cout<<"b: "<<b<<endl;
    if(b==1)
    {
      int x,w;
      cin>>x>>w;
      x--;
      if(x!=c)changeto(x,c);
      // node n = new node;
      node p1 = query(1,n);
      int y = p1.p.second;
      cout<<"y: "<<y<<endl;
      // int y = changeto(x);
      v[y].push(w);
      y--;
      update(y,y+1,w);
      c = x;
    }
    else if(b==2)
    {
      int x,w;
      cin>>x>>w;
      x--;
      v[x].push(w);
      update(x,x+1,w);
    }
    else if(b==3)
    {
      int x;
      cin>>x;
      x--;
      changeto(x,c);
      // node n = new node;
      node p1 = query(1,n);
      int y = p1.p.second;
      // int y = getmax();
      y--;
      cout<<"y: "<<y<<endl;
      int u = v[y].top();
      v[y].pop();
      // subtract(u);
      update(y,y+1,-1*u);
      c = x;
    }
    else
    {
      cout<<"here"<<endl;
      int x;
      cin>>x;
      changeto(x,c);
      // node n = new node;
      node p1 = query(1,n);
      int y = p1.key;
      cout<<p1.key<<endl;
      c = x;
    }
    for(int i=1;i<=15;i++) cout<<"i: "<<i<<" key: "<<tree[i].key<<" pair: "<<tree[i].p.first<<" "<<tree[i].p.second<<" lazy[i]: "<<lazy[i]<<endl;
  }
  // for(int i=1;i<=15;i++) cout<<"i: "<<i<<" key: "<<tree[i].key<<" pair: "<<tree[i].p.first<<" "<<tree[i].p.second<<endl;
	return 0;
}

/*
5
1 1 1 1 1
1
1 1 5
2 4
*/
