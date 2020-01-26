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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

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
    ans+=value;
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
int NODES = 0;
int n;
node tree[8*N], a[N];

node newLeaf(int val)
{
  int index = NODES++;
  tree[index].assign(val);
  return tree[index];
}

node newParent(int left,int right)
{
  // Left and Right are the seg tree array indices, not the original array indices
  int index = NODES++;
  tree[index].beg = left, tree[index].end = right;

  tree[index].combine(tree[left],tree[right]);
  return tree[index];
}



node build(int pos = 0,int l = 0,int r = n-1)
{
  tree[pos].beg = l, tree[pos].end = r;
  if(l==r)
  {
    return tree[pos] = newLeaf(a[l]);
  }

  int left = 
}


int main()
{
  __;
  
  return 0;
}

