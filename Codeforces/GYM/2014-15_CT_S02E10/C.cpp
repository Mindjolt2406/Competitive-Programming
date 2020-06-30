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
  int k;
  cin >> k;
  if(k == 2 || k == 5) 
  {
    cout << "Impossible" << endl;
    return 0;
  }
  else if(k == 0)
  {
    cout << 1 << " " << 0 << endl;
    return 0;
  }

  int n = -1;
  for(int i=2;i<=1e3;i++)
  {
    if((i*(i-1))/2 <= k)
    {
      n = i;
    }
  }

  int remove = k - ((n*(n-1))/2);
  // t(k,n,remove);
  int add = 0;
  bool add_edge = true;
  if(remove == n-1)
  {
    add = 1;
    add_edge = false;
    cout << n << " " << ((n-2) * (n-1))/2 << endl;
  }
  else
  {
    add = n-1-remove;
    cout << n << " " << add + ((n-2) * (n-1))/2 << endl;
  }

  
  for(int i=1;i<=n-1;i++)
  {
    for(int j=i+1;j<=n-1;j++)
    {
      if(add_edge == false)
      {
        if(i == n-2 && j == n-1) continue;
      }
      cout << i << " " << j << endl;
    }
  }

  for(int i=1;i<=add;i++)
  {
    cout << n << " " << i << endl;
  }

  return 0;
}
