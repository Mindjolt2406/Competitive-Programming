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

typedef struct node
{
  node *left, *right;
  node* data[26] = {0};
  int lose,win;
} node;

node* generate()
{
  node* n = new node;
  n->left = NULL; n->right = NULL;
  n->lose = 1;
  n->win = 0;
  return n;
}

node* insert(node *root, string &s,int level)
{
  if(root==NULL) root = generate();

  if(level>0) 
  {
    int b = s[s.size()-level] - 'a';
    // t(b,level,s);
    root->data[b] = insert(root->data[b],s,level-1);
  }

  // Taking mex of all the numbers
  int counter1[28] = {0},counter2[28] = {0};
  bool leaf = true;
  for(int i=0;i<26;i++) 
  {
    if(root->data[i])
    {
      counter1[root->data[i]->win]++;
      counter2[root->data[i]->lose]++;
      leaf = false;
    }
  }
  if(leaf) return root;
  int i=0;
  for(;i<28;i++) if(!counter1[i]) break;
  root->win = i;
  i = 0;
  for(;i<28;i++) if(!counter2[i]) break;
  root->lose = i;
  // t(root->val,level,s);
  return root;
}


int main()
{
  __;  
  int n,k;
  cin>>n>>k;
  node* root = NULL;
  for(int i=0;i<n;i++) 
  {
    string s;
    cin>>s;
    root = insert(root,s,s.size());
  }
  int a = root->win, b = root->lose;
  // t(a);
  if(a==0) 
  {
    // First guy cannot win in any game no matter what he does
    cout<<"Second"<<endl; // Correct
  }
  else
  {
     // First guy can win
     if(b!=0) // First guy has the capacity to lose as well 
     {
       // He keeps losing until the last game, when he wins
       cout<<"First"<<endl;
     }
     else // First guy does not have the capacity to lose, and can only win
     {
       // First guy wins, then the second guy wins and so on
       if(k%2==1) cout<<"First"<<endl;
       else cout<<"Second"<<endl; 
     }
  }
  return 0;
}

