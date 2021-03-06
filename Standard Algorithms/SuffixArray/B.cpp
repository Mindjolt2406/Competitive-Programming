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

void countSort(vector<pair<pair<int,int>,int> > &v, bool flag = false)
{
  // flag = false -> sort buy second element
  // else sort by first element

  int n = v.size();
  vector<pair<pair<int,int>,int> > ans(n);
  vector<int> counter(n);
  vector<int> index(n);

  for(int i=0;i<n;i++)
  {
    if(flag) counter[v[i].fi.fi]++;
    else counter[v[i].fi.se]++;
  }

  int cumIndex = 0;
  for(int i=1;i<n;i++)
  {
    index[i] = index[i-1] + counter[i-1];
  }

  for(int i=0;i<n;i++)
  {
    int value = (flag) ? v[i].fi.fi : v[i].fi.se;
    ans[index[value]] = v[i];
    index[value]++;
  }

  v = ans;
  if(!flag) countSort(v,true);
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

  vector<pair<pair<int,int> ,int> > posSorter(n);
  int k = 0;
  while((1<<k) < n)
  {
    int sortLen = (1<<k);
    for(int i=0;i<n;i++)
    {
      posSorter[i] = mp(mp(currEquivPos[i],currEquivPos[(i+sortLen)%n]),i);
    }

    // sort(posSorter.begin(),posSorter.end());
    countSort(posSorter);

    for(int i=0;i<n;i++) ansPos[i] = posSorter[i].se;

    int equivCls = -1;   
    pair<int,int> prevEquivCls = mp(-1,-1);
    for(int i=0;i<n;i++)
    {
      equivCls = (prevEquivCls == posSorter[i].fi) ? equivCls : equivCls+1;
      prevEquivCls = posSorter[i].fi;
      currEquivPos[ansPos[i]] = equivCls;
    }

    k++;
  }
  // for(int i=0;i<n;i++) if(posSorter[i].se < originalN) ans.pu(posSorter[i].se);
}

int main()
{
  __;
  string s;
  cin >> s;

  vector<int> ans;
  suffixArray(s,ans);
  for(auto it : ans) cout << it << " "; cout << endl;

  return 0;
}
