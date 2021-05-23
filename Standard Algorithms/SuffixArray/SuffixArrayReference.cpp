#include<bits/stdc++.h>
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

void countSort(vector<int> &ansPos, vector<int> currEquivPos)
{
  int n = ansPos.size();
  vector<int> ansNew(n);
  vector<int> counter(n);
  vector<int> index(n);

  for(auto it : currEquivPos) counter[it]++;

  int cumIndex = 0;
  for(int i=1;i<n;i++) index[i] = index[i-1] + counter[i-1];

  for(int i=0;i<n;i++)
  {
    int value = currEquivPos[ansPos[i]];
    ansNew[index[value]] = ansPos[i];
    index[value]++;
  }

  ansPos = ansNew;
}

void suffixArray(string &s, vector<int> &ansPos)
{
  s += '$';

  int n = s.size();
  ansPos.resize(n);
  vector<int> currEquivPos(n);

  // Sort the length 1 elements
  {
    vector<pair<char,int> > tempSort;
    for(int i=0;i<n;i++) tempSort.pu(mp(s[i],i));
    sort(tempSort.begin(),tempSort.end());
    for(int i=0;i<n;i++) ansPos[i] = tempSort[i].se;
    int equivCls = -1;   
    char prevEquivCls = 0;
    for(int i=0;i<n;i++)
    {
      equivCls = (prevEquivCls == tempSort[i].fi) ? equivCls : equivCls+1;
      prevEquivCls = tempSort[i].fi;
      currEquivPos[ansPos[i]] = equivCls;
    }
  }
  int k = 0;
  while((1<<k) < n)
  {
    int sortLen = (1<<k);

    for(int i=0;i<n;i++) ansPos[i] = (ansPos[i] - sortLen + n) %n;

    countSort(ansPos,currEquivPos);
    int equivCls = -1;   
    pair<int,int> prevEquivCls = mp(-1,-1);
    vector<int> currEquivPosNew(n);
    for(int i=0;i<n;i++)
    {
      pair<int,int> currEquivCls = mp(currEquivPos[ansPos[i]],currEquivPos[(ansPos[i]+sortLen)%n]);
      equivCls = (prevEquivCls == currEquivCls) ? equivCls : equivCls+1;
      prevEquivCls = currEquivCls;
      currEquivPosNew[ansPos[i]] = equivCls;
    }
    currEquivPos = currEquivPosNew;
    k++;
  }
}

void lcpArray(vector<int> &suffixArray,string &s,vector<int> &lcp)
{
  int n = suffixArray.size();
  vector<int> inv(n);
  for(int i=0;i<n;i++) inv[suffixArray[i]] = i;

  lcp.resize(n);
  int prevMatch = 0;
  for(int i=0;i<n-1;i++)
  {
    if(inv[i] == n-1) continue;
    int strIndex1 = i;
    int strIndex2 = suffixArray[inv[i]+1];
    prevMatch = max(prevMatch-1,0);
    while(s[strIndex1+prevMatch] == s[strIndex2+prevMatch]) // Breaks when encounters $. Don't worry about index errors
    {
      prevMatch++;
    }
    lcp[inv[i]] = prevMatch;
  }
}

static const int MAXN = 2e5+100;
static const int K = 18;
vector<vector<int> > st_lcp(MAXN,vector<int>(K+1));
vector<vector<int> > st_lcs(MAXN,vector<int>(K+1));
vector<int> stlog(MAXN);

typedef struct SparseTable 
{
  vector<vector<int> > st;
  SparseTable(vector<vector<int> > &st,vector<int> &v)
  {
    // st.resize(MAXN,vector<int>(K+1));
    // stlog.resize(MAXN)
    this->st = st;
    initMin(v);
  }

  void init(vector<int> &v)
  {
    for (int i = 0; i < v.size(); i++)
      st[i][0] = v[i];

    for (int j = 1; j <= K; j++)
      for (int i = 0; i + (1 << j) <= v.size(); i++)
        st[i][j] = min(st[i][j-1],st[i + (1 << (j - 1))][j - 1]);
  }

  void initMin(vector<int> &v)
  {
    init(v);
    stlog[1] = 0;
    for (int i = 2; i <= MAXN; i++)
      stlog[i] = stlog[i/2] + 1;
  }

  ll min(ll x, ll y) {return (x<y) ? x : y;}

  int queryMin(int l, int r)
  {
    int j = stlog[r - l + 1];
    int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
    return minimum;
  }
} Sparse;

vector<int> suffix,lcp,prefix,lcs,inv_suffix,inv_prefix;

int main()
{
  __;
  string s;
  suffixArray(s,suffix);
  lcpArray(suffix,s,lcp);
  Sparse sp_lcp(st_lcp,lcp);

  // For lcs -> perform on the reversed string and reverse the inv_prefix array. 
  suffixArray(rev_s,prefix);
  lcpArray(prefix,rev_s,lcs);
  Sparse sp_lcs(st_lcs,lcs);

  inv_prefix.resize(prefix.size());
  inv_suffix.resize(suffix.size());
  // Inverting prefix and suffix
  for(int i=0;i<suffix.size();i++)
  {
    inv_prefix[prefix[i]] = i;
    inv_suffix[suffix[i]] = i;
  }

  // t(inv_prefix);
  reverse(inv_prefix.begin(),inv_prefix.end());
  inv_prefix.erase(inv_prefix.begin());
  return 0;
}
