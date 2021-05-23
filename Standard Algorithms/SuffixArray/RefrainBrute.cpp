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

typedef struct SparseTable 
{
  static const int MAXN = 2e5+10;
  static const int K = 20;
  vector<vector<int> > st;
  vector<int> log;

  SparseTable(vector<int> &v)
  {
    st.resize(MAXN,vector<int>(K+1));
    log.resize(MAXN);
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
    log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
      log[i] = log[i/2] + 1;
  }

  ll min(ll x, ll y) {return (x<y) ? x : y;}

  int queryMin(int l, int r)
  {
    int j = log[r - l + 1];
    int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
    return minimum;
  }
} Sparse;

ll max(ll x, ll y) {return (x>y) ? x : y;}

pair<ll,int> check(ll mid,Sparse &sp,int n)
{
  int prev = -1;
  ll max1 = -1;
  int maxIndex = -1;
  for(int i=0;i<=n;i++)
  {
    if(sp.queryMin(i,i) >= mid)
    {
      prev = (prev == -1) ? i : prev;
      ll temp_max = (i-prev+2)*mid;
      if(temp_max > max1)
      {
        max1 = temp_max;
        maxIndex = prev;
      }
    }
    else prev = -1;
  }
  return mp(max1,maxIndex);
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;
  string s;
  for(int i=0;i<n;i++)
  {
    char a;
    cin >> a;
    a--;
    s += a;
  }

  vector<int> suffix,lcp;
  suffixArray(s,suffix);
  lcpArray(suffix,s,lcp);
  Sparse sp(lcp);

  int ansIndex = -1, ansLen = -1;
  ll ans = -1;

  for(int mid=1;mid<=n;mid++)
  {
    pair<ll,int> tempAns = check(mid,sp,n);
    t(mid,tempAns,tempAns.fi/mid);
    if(tempAns.fi > ans)
    {
      ans = tempAns.fi;
      ansLen = mid;
      ansIndex = tempAns.se;
    }
  }

  // int beg = 1, end = n;
  // while(beg <= end)
  // {
  //   int mid = (beg+end) >> 1;
  //   pair<ll,int> leftAns = (mid==1) ? (pair<ll,int>) mp(0,0) : check(mid-1,sp,n);
  //   pair<ll,int> midAns = check(mid,sp,n);
  //   pair<ll,int> rightAns = (mid == n) ? (pair<ll,int>) mp(n,0) : check(mid+1,sp,n);

  //   // t(mid,leftAns,midAns,rightAns);
  //   if(midAns.fi >= leftAns.fi && midAns.fi >= rightAns.fi) 
  //   {
  //     ans = midAns.fi;
  //     ansIndex = midAns.se;
  //     ansLen = mid;
  //     break;
  //   }
  //   else if(leftAns.fi <= midAns.fi && midAns.fi <= rightAns.fi) beg = mid+1;
  //   else end = mid-1;
  // }

  if(n == max(ans,n))
  {
    cout << n << endl;
    cout << n << endl;
    for(int i=0;i<n;i++) cout << (char)(s[i]+1) << " "; cout << endl;
  }
  else
  {
    ansIndex = suffix[ansIndex];
    cout << ans << endl;
    cout << ansLen << endl;
    for(int i=ansIndex;i<ansIndex+ansLen;i++) cout << (char)(s[i]+1) << " "; cout << endl;
  }
  return 0; 
}

// lcp(inv[i],inv[i+k])
// lcp (i,i+k) = 2k or > 2k