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

void add(int n,map<int,set<int> > &d)
{
  int k = n;
  while(n)
  {
    d[k].insert(n);
    n>>=1;
  }
}

int retnext(int n,int key, map<int,set<int> > &d)
{
  if(key == n) return -1;
  t(n,key,*d[n].upper_bound(key));
  return *d[n].upper_bound(key);
}

bool tryshift(int key, int val,map<int,int> &ans,map<int,set<int> > &d)
{
  t(key,val);
  int n = ans[key];
  int next = retnext(n,key,d);
  while(next != -1)
  {
    if(next > val) 
    {
      next = retnext(n,next,d);
      return false;
    }
    if(tryshift(next,val,ans,d))
    {
      t(next,n);
      ans[next] = n;
      return true;
    }
    next = retnext(n,next,d);
  }
  return false;

  if(next == -1) return false;
  else if(next>=val) return false;
  else if(ans.find(next)==ans.end()) 
  {
    t(next,n);
    ans[next] = n;
    return true;
  }
  else
  {
    
  }
}

void add2(int n, map<int,set<int> > &d,map<int,int> &ans)
{
  set<int> s = d[n];
  int temp = n;
  for(auto it = s.rbegin();it!= s.rend(); it++)
  {
    t(n,*it);
    if(ans.find(*it) == ans.end()) temp = *it;
    else if(tryshift(*it,temp,ans,d)) 
    {
      temp = *it;
    }
    else break;
  }
  ans[temp] = n;
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  sort(v.begin(),v.end());

  // For reference
  map<int,set<int> > d;
  for(int i=0;i<n;i++) add(v[i],d);

  // Key alloted -> Number
  map<int,int> ans;
  // Number -> Key alloted
  map<int,int> no; // Updated only in the end

  for(int i=0;i<v.size();i++)
  {
    int a = v[i];
    t(i,v[i]);
    add2(v[i],d,ans);
    for(auto it : ans)  t(it);
  }

  for(auto it : ans) 
  {
    if(no.find(it.se)==no.end()) no[it.se] = it.fi;
  }

  for(int i=0;i<n;i++) cout << no[v[i]] << " ";
  cout << endl;

  return 0;
}

