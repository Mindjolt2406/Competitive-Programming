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

ll power(ll x, ll y, ll p)
{
	ll res = 1;      // Initialize result
	x = x % p;  // Update x if it is more than or
	while (y > 0)
	{
			if (y & 1)
					res = (res*x) % p;
			y = y>>1; // y = y/2
			x = (x*x) % p;
	}
	return res;
}

const int N = 3e5+10;
const int BASE = 135;
vector<ll> expPower(N);

void precompute()
{
  expPower[0] = 1;
  for(int i=1;i<N;i++)
  {
    expPower[i] = (BASE * expPower[i-1]) % MOD;
  }
}

ll getPower(int i)
{
  return expPower[i];
}

typedef struct Treap
{
  char currCharacter;
  int priority;
  int sz;
  ll hash;
  ll revHash;
  bool isPalindrome;
  Treap *left, *right;

  Treap(char data)
  {
    // Constructor
    left = NULL;
    right = NULL;
    sz = 1;
    currCharacter = data;
    hash = data;
    revHash = data;
    isPalindrome = true;
    priority = rng() % MOD;
  }
} Treap;

void printInOrderTraversal(Treap* root)
{
  if(root == NULL) return;

  printInOrderTraversal(root->left);
  cout << root->currCharacter << " ";
  printInOrderTraversal(root->right);
}

int getSize(Treap* root)
{
  return (root ? root->sz : 0);
}

ll getHash(Treap* root)
{
  return (root ? root->hash : 0);
}

ll getRevHash(Treap* root)
{
  return (root ? root->revHash : 0);
}

ll addMod(ll a, ll b)
{
  ll c = a+b;
  return (c >= MOD ? c - MOD : c);
}

void recalc(Treap * root)
{
  if(root == NULL) return;

  // Recalculate size of the subtree rooted at root
  root->sz = 1;
  root->sz += getSize(root->left);
  root->sz += getSize(root->right);

  ll leftHash = (getHash(root->left) * getPower(getSize(root->right) + 1)) % MOD;
  ll midHash = (root->currCharacter * getPower(getSize(root->right))) % MOD;
  root->hash = addMod(addMod(getHash(root->right),midHash), leftHash);

  ll rightRevHash = (getRevHash(root->right) * getPower(getSize(root->left) + 1)) % MOD;
  ll midRevHash = (root->currCharacter * getPower(getSize(root->left))) % MOD;
  root->revHash = addMod(addMod(getRevHash(root->left),midRevHash), rightRevHash);

  root->isPalindrome = (root->revHash == root->hash);
}

pair<Treap*, Treap*> cut(Treap* root, int leftSize)
{
  if(root == NULL) return mp((Treap*) NULL, (Treap*)NULL);
  // Propagate if necessary

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

bool isPalindrome(Treap* root, int l, int r)
{
  l--; r--;
  pair<Treap*, Treap*> left_MidRight = cut(root, l);
  Treap *left = left_MidRight.first, *midRight = left_MidRight.second;

  pair<Treap*, Treap*> mid_Right = cut(midRight, (r-l+1));
  Treap *mid = mid_Right.first, *right = mid_Right.second;

  bool isPalindrome = mid->isPalindrome;

  Treap* finalRoot = NULL;
  finalRoot = merge(finalRoot, left);
  finalRoot = merge(finalRoot, mid);
  finalRoot = merge(finalRoot, right);

  return isPalindrome;
}


Treap* insertTreap(Treap* root, char value, int pos)
{
  pos--;
  pair<Treap*, Treap*> left_Right = cut(root, pos);
  Treap* newTreap = new Treap(value);

  Treap* leftTreap =  left_Right.first, *rightTreap = left_Right.second;

  Treap* finalRoot = NULL;
  finalRoot = merge(finalRoot, leftTreap);
  finalRoot = merge(finalRoot, newTreap);
  finalRoot = merge(finalRoot, rightTreap);

  return finalRoot;
}


Treap* deleteTreap(Treap* root, int l, int r)
{
  l--; r--;
  pair<Treap*, Treap*> left_MidRight = cut(root, l);
  Treap *left = left_MidRight.first, *midRight = left_MidRight.second;

  pair<Treap*, Treap*> mid_Right = cut(midRight, (r-l+1));
  Treap *mid = mid_Right.first, *right = mid_Right.second;

  return merge(left, right);
}

Treap* build(string &s)
{
  int n = s.size();
  vector<Treap*> treaps(n);
  for(int i=0;i<n;i++)
  {
    treaps[i] = new Treap(s[i]);
  }

  Treap* root = NULL;
  for(auto treap : treaps)
  {
    root = merge(root, treap);
  }

  return root;
}

int main()
{
  __;
  precompute();
  int n,q;
  cin >> n >> q;

  string s;
  cin >> s;

  Treap* root = build(s);

  while(q--)
  {
    int queryIndex;
    cin >> queryIndex;
    
    if(queryIndex == 1)
    {
      int l,r;
      cin >> l >> r;
      root = deleteTreap(root, l, r);
    }
    else if(queryIndex == 2)
    {
      char c;
      int pos;
      cin >> c >> pos;
      root = insertTreap(root, c, pos);
    }
    else
    {
      int a,b;
      cin >> a >> b;
      cout << (isPalindrome(root, a, b) ? "yes" : "no") << endl;
    }
  }
  return 0; 
}

/*
5 1
aaaaa
1 1 1

*/