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

int main()
{
  __;
  string s;
  cin >> s;
  vector<int> suffix,lcp;
  suffixArray(s,suffix);
  lcpArray(suffix,s,lcp);

  vector<pair<int,int> > ans;
  vector<int> indexCounter(suffix.size());
  vector<int> suffixSize(suffix.size());
  for(int i=0;i<suffix.size();i++) suffixSize[i] = s.size() - suffix[i];

  for(int i=0;i<suffix.size();i++)
  {
    if(indexCounter[i] >= suffixSize[i]) continue;
    string strSuffix = s.substr(suffix[i],suffixSize[i]);

    // Remove all common ones first
    while(indexCounter[i] < lcp[i])
    {
      // lcp[i] talks about the next prefix
      
      // Temporary vector to contain similar substrings to sort them by position
      vector<pair<int,int> > temp;
      temp.pu(mp(suffix[i],suffix[i]+indexCounter[i]));
      int j = i;
      while(j<lcp.size()-1 && lcp[j] > indexCounter[i])
      {
        j++;
        temp.pu(mp(suffix[j],suffix[j]+indexCounter[i]));
        indexCounter[j]++;
      }

      sort(temp.begin(),temp.end());
      for(auto it : temp) ans.pu(it);
      indexCounter[i]++;
    }
    
    // Handle the different ones
    while(indexCounter[i] < suffixSize[i])
    {
      ans.pu(mp(suffix[i],suffix[i]+indexCounter[i]));
      indexCounter[i]++;
    }
  }

  // for(auto it : ans) cout <<  s.substr(it.fi, it.se-it.fi+1) << " " << it << endl;
  for(auto it : ans) cout << it.fi << " " << it.se << endl;
  return 0;
}
