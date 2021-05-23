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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

typedef struct Treap
{
  bool value, toPropXor, toPropRev, toPropSort;
  int priority;
  int sz;

  int prefSizeOne, suffSizeOne, maxSizeOne;
  int prefSizeZero, suffSizeZero, maxSizeZero;
  Treap *left, *right;

  Treap(bool data)
  {
    // Constructor
    left = NULL;
    right = NULL;
    sz = 1;
    value = data;
    toPropXor = toPropRev = toPropSort = 0;
    prefSizeOne = suffSizeOne = maxSizeOne = data;
    prefSizeZero = suffSizeZero = maxSizeZero = !data;
    priority = rng() % MOD;
  }
} Treap;

void recalc(Treap * root);
void propageTreap(Treap* root);

void printInOrderTraversal(Treap* root)
{
  if(root == NULL) return;

  propageTreap(root);
  recalc(root);
  printInOrderTraversal(root->left);
  cout << root->value << " ";
  printInOrderTraversal(root->right);
}

int getSize(Treap* root)
{
  return (root ? root->sz : 0);
}

int getPrefSizeOne(Treap* root)
{
  return (root ? root->prefSizeOne : 0);
}

int getPrefSizeZero(Treap* root)
{
  return (root ? root->prefSizeZero : 0);
}

int getSuffSizeOne(Treap* root)
{
  return (root ? root->suffSizeOne : 0);
}

int getSuffSizeZero(Treap* root)
{
  return (root ? root->suffSizeZero : 0);
}

int getMaxSizeOne(Treap* root)
{
  return (root ? root->maxSizeOne : 0);
}

int getMaxSizeZero(Treap* root)
{
  return (root ? root->maxSizeZero : 0);
}

bool getPropXor(Treap* root)
{
  return (root ? root->toPropXor : 0);
}

bool getPropRev(Treap* root)
{
  return (root ? root->toPropRev : 0);
}

bool getPropSort(Treap* root)
{
  return (root ? root->toPropSort : 0);
}

pair<Treap*, Treap*> cut(Treap* root, int leftSize)
{
  if(root == NULL) return mp((Treap*) NULL, (Treap*)NULL);
  // Propagate if necessary
  propageTreap(root);

  if(getSize(root->left) >= leftSize)
  {
    pair<Treap*, Treap*> res = cut(root->left, leftSize);
    root->left = res.second;
    recalc(root);
    return mp(res.first, root);
  }
  else
  {
    int newSize = leftSize - getSize(root->left) - 1;
    pair<Treap*, Treap*> res = cut(root->right, newSize);
    root->right = res.first;
    recalc(root);
    return mp(root,res.second);
  }
}

Treap* merge(Treap* leftRoot, Treap* rightRoot)
{
  if(leftRoot == NULL) return rightRoot;
  if(rightRoot == NULL) return leftRoot;

  // Propagate if necessary
  propageTreap(leftRoot);
  propageTreap(rightRoot);

  if(leftRoot->priority < rightRoot->priority)
  {
    leftRoot->right = merge(leftRoot->right, rightRoot);
    recalc(leftRoot);
    return leftRoot;
  }
  else
  {
    rightRoot->left = merge(leftRoot, rightRoot->left);
    recalc(rightRoot);
    return rightRoot;
  }
}

void recalc(Treap * root)
{
  if(root == NULL) return;

  root->sz = 1;
  root->sz += getSize(root->left);
  root->sz += getSize(root->right);

  int leftSize = getSize(root->left);
  int leftPrefSizeOne = getPrefSizeOne(root->left);
  int leftPrefSizeZero = getPrefSizeZero(root->left);
  int leftSuffSizeOne = getSuffSizeOne(root->left);
  int leftSuffSizeZero = getSuffSizeZero(root->left);
  int leftMaxSizeOne = getMaxSizeOne(root->left);
  int leftMaxSizeZero = getMaxSizeZero(root->left);
  
  int rightSize = getSize(root->right);
  int rightPrefSizeOne = getPrefSizeOne(root->right);
  int rightPrefSizeZero = getPrefSizeZero(root->right);
  int rightSuffSizeOne = getSuffSizeOne(root->right);
  int rightSuffSizeZero = getSuffSizeZero(root->right);
  int rightMaxSizeOne = getMaxSizeOne(root->right);
  int rightMaxSizeZero = getMaxSizeZero(root->right);

  if(getPropXor(root->left))
  {
    swap(leftPrefSizeOne, leftPrefSizeZero);
    swap(leftSuffSizeOne, leftSuffSizeZero);
    swap(leftMaxSizeOne, leftMaxSizeZero);
  }

  if(getPropXor(root->right))
  {
    swap(rightPrefSizeOne, rightPrefSizeZero);
    swap(rightSuffSizeOne, rightSuffSizeZero);
    swap(rightMaxSizeOne, rightMaxSizeZero);
  }

  if(getPropRev(root->left))
  {
    swap(leftPrefSizeOne, leftSuffSizeOne);
    swap(leftPrefSizeZero, leftSuffSizeZero);
  }

  if(getPropRev(root->right))
  {
    swap(rightPrefSizeOne, rightSufffSizeZero);
    swap(rightPrefSizeZero, rightSuffSizeZero);
  }


  root->prefSizeOne = leftPrefSizeOne;
  if(leftSize == leftMaxSizeOne)
  {
    if(root->value) root->prefSizeOne = leftSize + 1 + rightPrefSizeOne;
  }

  root->suffSizeOne = rightSuffSizeOne;
  if(rightSize == rightMaxSizeOne)
  {
    if(root->value) root->suffSizeOne = rightSize + 1 + leftSuffSizeOne;
  }

  root->maxSizeOne = max(leftMaxSizeOne, rightMaxSizeOne);
  if(root->value)
  {
    root->maxSizeOne = max(root->maxSizeOne, leftSuffSizeOne + 1 + rightPrefSizeOne);
  }

  root->prefSizeZero = leftPrefSizeZero;
  if(leftSize == leftMaxSizeZero)
  {
    if(!root->value) root->prefSizeZero = leftSize + 1 + rightPrefSizeZero;
  }

  root->suffSizeZero = rightSuffSizeZero;
  if(rightSize == rightMaxSizeZero)
  {
    if(!root->value) root->suffSizeZero = rightSize + 1 + leftSuffSizeZero;
  }

  root->maxSizeZero = max(leftMaxSizeZero, rightMaxSizeZero);
  if(!root->value)
  {
    root->maxSizeZero = max(root->maxSizeZero, leftSuffSizeZero + 1 + rightPrefSizeZero);
  }
}

void propageTreap(Treap* root)
{
  if(root == NULL) return;
  if(root->toPropXor == false) return;
  // t(root->toPropXor, root->value);
  if(root->left != NULL) root->left->toPropXor ^= 1;
  if(root->right != NULL) root->right->toPropXor ^= 1;

  root->value ^= 1;
  root->toPropXor = false;
  recalc(root);
}

Treap* build(string &s)
{
  int n = s.size();
  vector<Treap*> treaps(n);
  for(int i=0;i<n;i++)
  {
    auto c = s[i];
    if(c == '0') treaps[i] = new Treap(0);
    else treaps[i] = new Treap(1);
  }

  Treap* finalRoot = NULL;
  for(auto treap : treaps) 
  {
    finalRoot = merge(finalRoot, treap);
  }
  return finalRoot;
}

int queryLength(Treap* root, int l, int r, int index)
{
  pair<Treap*, Treap*> leftmid_right = cut(root, r+1);
  Treap* leftmid = leftmid_right.fi, *right = leftmid_right.se;

  pair<Treap*, Treap*> left_mid = cut(leftmid, l);
  Treap* left = left_mid.fi, *mid = left_mid.se;

  // int ans = mid->maxSizeOne;
  mid->toPropXor = mid->toPropXor ^ 1;
  // printInOrderTraversal(mid); cout << endl;

  Treap* finalRoot = NULL;
  finalRoot = merge(finalRoot, left);
  finalRoot = merge(finalRoot, mid);
  finalRoot = merge(finalRoot, right);

  root = finalRoot;

  // return max(root->maxSizeOne, root->maxSizeZero);
  propageTreap(root);
  return max(root->maxSizeOne, root->maxSizeZero);
}

int main()
{
  __;
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;

  Treap* root = build(s);

  // cout << getMaxSizeOne(root) << endl;
  // printInOrderTraversal(root); cout << endl;

  while(q--)
  {
    int index;
    cin >> index;
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << queryLength(root, l, r, index) << endl;
  }
  return 0;
}

/*
8 8
00000000
1 1 3
1 2 7
1 2 4
1 5 6
1 5 5
1 1 8

‎‎‎‎‎
1 1 3
3
1 5 8
4
1 1 8
1
1 2 3
3
1 3 4
1

*/