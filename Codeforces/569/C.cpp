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
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  deque<int> q;
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  vector<int> x;
  int max1 = -INF;
  for(int i=0;i<n;i++) 
  {
    cin>>v[i];
    q.pu(v[i]);
    max1 = max(max1,v[i]);
  }

  // bool boo = false;
  // for(int i=0;i<n;i++)
  // {
  //   if(v[i]==max1 && boo) x.pu(v[i]);
  //   else if(v[i]!=max1) x.pu(v[i]);

  //   if(v[i]==max1) boo = true;
  // }

  pr(x);
  vector<pair<int,int> > w;
  for(int i=0;i<n-1;i++)
  {
    int a = q.front();
    q.pop_front();
    int b = q.front();
    q.pop_front();
    // t(a,b);
    w.pu(mp(a,b));
    q.push_front(max(a,b));
    x.pu(min(a,b));
    q.pu(min(a,b));
  }

  // pr(x);
  while(m--)
  {
    ll a;
    cin>>a;
    a--;

    if(a<n-1) cout<<w[a].fi<<" "<<w[a].se<<endl;
    else
    {
      a%=(n-1);
      cout<<max1<<" "<<x[a]<<endl;
    }
  }
  return 0;
}

