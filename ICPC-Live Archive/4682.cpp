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

const int MAXLOG = 33;

typedef struct node
{
  node *left, *right;
  int data;
} node;

node* generate(ll key)
{
  node* n = new node;
  n->left = NULL; n->right = NULL;
  n->data = key;
  return n;
}

node* insert(node *root, ll n,ll level = MAXLOG)
{
  ll a = (n >> (level+1))&1;
  // t(a,n,level);
  if(root==NULL) root = generate(a);

  if(level>=0)
  {
    ll b = (n >> (level))&1;
    if(b) {root->right = insert(root->right,n,level-1);}
    else {root->left = insert(root->left,n,level-1);}
  }
  return root;
}

ll query(node *root,ll n,ll level = MAXLOG)
{
  ll count  = 0;
  if(root==NULL) return 0;
  ll a = (n>>level)&1;
  // if(a!=root->data) count+=(1<<level);

  if(level<0) return 0;
  if(a) // Go left
  {
    if(root->left) 
    {
      // t(n,level);
      count+=(1<<level);
      count+= query(root->left,n,level-1);
    }
    else 
    {
      count+= query(root->right,n,level-1);
    }
  }
  else // Go right
  {
    if(root->right) 
    {
      count+=(1<<level);
      count+= query(root->right,n,level-1);
    }
    else count+= query(root->left,n,level-1);
  }
  // t(count,level);
  return count;
}

int main()
{
  __;
  node *root = NULL;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<ll> v(n+1);
    v[0] = 0;
    for(ll i=1;i<v.size();i++) cin>>v[i];
    for(ll i=1;i<v.size();i++) v[i]^=v[i-1];

    ll max1 = 0;
    for(ll i=0;i<v.size();i++) 
    {
      max1 = max(max1,v[i]);
      ll a = query(root,v[i]);
      // t(a,v[i],max1);
      root = insert(root,v[i]);
      max1 = max(max1,a);
    }

    cout<<max1<<endl;
    root = NULL;
  }
  // cout<<endl;
  // t(root->left->left->data);
  return 0;
}

/*
2
5
3 7 7 7 0
5
3 8 2 6 4

1
5
3 7 7 7 0

*/
