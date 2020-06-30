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


int main()
{
  __;
  int x,y,n,m,r;
  cin >> x >> y >> n >> m >> r;
  multiset<ll> v,w,s;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.insert(a);
    if(v.size() > x) v.erase(v.find(*v.begin()));
  }

  for(int i=0;i<m;i++)
  {
    int a;
    cin >> a;
    w.insert(a);
    if(w.size() > y) w.erase(w.find(*w.begin()));
  }

  for(int i=0;i<r;i++)
  {
    int a;
    cin >> a;
    s.insert(a);
  }

  while(true)
  {
    if(s.empty() || (*s.rbegin() <= *v.begin() && *s.rbegin() <= *w.begin())) break;
    if(*v.begin() < *w.begin())
    {
      if(*s.rbegin() > *v.begin())
      {
        v.insert(*s.rbegin());
        s.erase(s.find(*s.rbegin()));
        v.erase(v.find(*v.begin()));
      }
    }
    else if(*s.rbegin() > *w.begin())
    {
      w.insert(*s.rbegin());
      s.erase(s.find(*s.rbegin()));
      w.erase(w.find(*w.begin()));
    }
  }

  ll sum1 = 0;
  for(auto it : v)
  {
    sum1 += it;
  }

  for(auto it : w)
  {
    sum1 += it;
  }

  cout << sum1 << endl;
  return 0;
}
