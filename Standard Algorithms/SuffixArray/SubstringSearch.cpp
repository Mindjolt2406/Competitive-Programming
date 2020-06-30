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

  for(auto it : currEquivPos)
  {
    counter[it]++;
  }

  int cumIndex = 0;
  for(int i=1;i<n;i++)
  {
    index[i] = index[i-1] + counter[i-1];
  }

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
    // t(sortLen,currEquivPos);

    for(int i=0;i<n;i++)
    {
      ansPos[i] = (ansPos[i] - sortLen + n) %n;
    }

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

int main()
{
  __;
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans;
  suffixArray(s,ans);

  int q;
  cin >> q;
  while(q--)
  {
    string query;
    cin >> query;

    int beg = 1, end = n, ansIndex = -1;
    while(beg <= end)
    {
      int mid = (beg+end) >> 1;
      int startIndex = ans[mid];
      // t(s.substr(startIndex,s.size()),query,beg,mid,end);
      if(s.substr(startIndex,min(s.size()-startIndex,query.size())) < query)
      {
        beg = mid+1;
      }
      else if(s.substr(startIndex,min(s.size()-startIndex,query.size())) > query)
      {
        end = mid-1;
      }
      else 
      {
        ansIndex = mid;
        break;
      }
    }

    if(ansIndex+1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
