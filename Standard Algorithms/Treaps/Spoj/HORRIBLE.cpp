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
  ll value;
  ll sum;
  int priority;
  int sz;
  ll toProp;
  Treap *left, *right;

  Treap(int data)
  {
    // Constructor
    left = NULL;
    right = NULL;
    sz = 1;
    toProp = 0;
    sum = 0;
    value = data;
    priority = rng() % MOD;
  }
} Treap;

int getSize(Treap* root)
{
  return (root ? root->sz : 0);
}


void printInOrderTraversal(Treap* root)
{
  if(root == NULL) return;

  printInOrderTraversal(root->left);
  cout << root->value << " ";
  printInOrderTraversal(root->right);
}

void recalc(Treap * root);
void propageTreap(Treap* root);

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

// Operation w.r.t the question
Treap* swapSubArray(Treap* root, int a, int b,int n)
{
  if(b<=a) return root;

  int leftSize = b-a;
  int rightSize = n-b;
  int size = min(leftSize, rightSize);

  // int al = a, ar = al+size-1, bl = b, br = br+size-1;
  pair<Treap*, Treap*> tempRight = cut(root, b); 
  Treap *remLeft = tempRight.first, *remRight = tempRight.second;

  pair<Treap*, Treap*> rightRes = cut(remRight, size);
  Treap *secondArr = rightRes.first, *extremeRight = rightRes.second;

  pair<Treap*, Treap*> temp1 = cut(remLeft, a);
  Treap *extremeLeft = temp1.first, *remMiddle = temp1.second;

  pair<Treap*, Treap*> leftRes = cut(remMiddle, size);
  Treap *firstArr = leftRes.first, *middleArr = leftRes.second;

  // extremeLeft firstArr middleArr secondArr extremeRight

  Treap* finalRoot = extremeLeft;
  finalRoot = merge(finalRoot, secondArr);
  finalRoot = merge(finalRoot, middleArr);
  finalRoot = merge(finalRoot, firstArr);
  finalRoot = merge(finalRoot, extremeRight);

  return finalRoot;
}

void propageTreap(Treap* root)
{
  if(root == NULL) return;
  if(root->toProp == 0) return;

  root->value += root->toProp;
  if(root->left != NULL) root->left->toProp += root->toProp;
  if(root->right != NULL) root->right->toProp += root->toProp;

  root->toProp = 0;
  recalc(root);
}

ll getSum(Treap* root)
{
  return (root ? root->sum : 0);
}

ll query(Treap* root, int l, int r, int index, int value = 0)
{
  pair<Treap*, Treap*> leftmid_right = cut(root, r+1);
  Treap* leftmid = leftmid_right.fi, *right = leftmid_right.se;

  pair<Treap*, Treap*> left_mid = cut(leftmid, l);
  Treap* left = left_mid.fi, *mid = left_mid.se;

  // int ans = mid->maxSizeOne;
  ll ansSum = 0;
  if(index == 0) mid->toProp += value;
  else ansSum = getSum(mid);

  Treap* finalRoot = NULL;
  finalRoot = merge(finalRoot, left);
  finalRoot = merge(finalRoot, mid);
  finalRoot = merge(finalRoot, right);

  root = finalRoot;

  propageTreap(root);
  return ansSum;
}

void recalc(Treap * root)
{
  if(root == NULL) return;

  root->sz = 1;
  root->sz += getSize(root->left);
  root->sz += getSize(root->right);

  root->sum = root->value + getSum(root->left) + getSum(root->right);
  if(root->left != NULL) root->sum += root->left->toProp * getSize(root->left);
  if(root->right != NULL) root->sum += root->right->toProp * getSize(root->right);
}

Treap* build(int n)
{
  vector<Treap*> treaps(n);
  for(int i=0;i<n;i++)
  {
    treaps[i] = new Treap(0);
  }

  Treap* finalRoot = NULL;
  for(auto treap : treaps) finalRoot = merge(finalRoot, treap);
  return finalRoot;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,q;
    cin >> n >> q;
    Treap* root = build(n);

    while(q--)
    {
      int index, l, r;
      cin >> index >> l >> r;
      l--; r--;

      if(index == 0)
      {
        int val;
        cin >> val;
        query(root, l, r, index, val);
      }
      else 
      {
        cout << query(root, l, r, index) << "\n";
      }
    }
  }
  return 0;
}

/*
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8


*/
