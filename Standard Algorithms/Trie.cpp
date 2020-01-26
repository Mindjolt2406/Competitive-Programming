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
  // int data[28] = {0};
} node;

node* generate(int key = 0)
{
  node* n = new node;
  n->left = NULL; n->right = NULL;
  n->data = key;
  return n;
}

node* insert(node *root, int n,int level = MAXLOG)
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

// node* insert(node *root, string &s,int level)
// {
//   if(root==NULL) root = generate();

//   if(level>0) 
//   {
//     int b = s[s.size()-level] - 'a';
//     // t(b,level,s);
//     root->data[b] = insert(root->data[b],s,level-1);
//   }

//   return root;
// }

node* query(node *root,int n,int level)
{
  
}

int main()
{
  __;
  
  return 0;
}

