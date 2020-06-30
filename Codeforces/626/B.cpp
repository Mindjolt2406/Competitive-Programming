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
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n),b(m);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<m;i++) cin >> b[i];

  vector<int> v,w;
  int sum1 = 0;
  for(int i=0;i<n;i++)
  {
    if(a[i] == 0)
    {
      if(sum1) 
      {
        v.pu(sum1);
        sum1 = 0;
      }
    }
    else sum1++;
  }

  if(sum1) v.pu(sum1);

  sum1 = 0;
  for(int i=0;i<m;i++)
  {
    if(b[i] == 0)
    {
      if(sum1) 
      {
        w.pu(sum1);
        sum1 = 0;
      }
    }
    else sum1++;
  }

  if(sum1) w.pu(sum1);

  // t(v,w);

  ll cnt = 0;
  vector<int> div;
  for(int i=1;i<=(int)sqrt(k);i++)
  {
    if(k%i == 0)
    {
      div.pu(i);
      if(i != k/i) div.pu(k/i);
    }
  }

  for(int i=0;i<div.size();i++)
  {
    int u = div[i];
    ll sum1 = 0;
    for(int j=0;j<v.size();j++)
    {
      sum1 += max(0,v[j]-u+1);
    }

    int v = k/u;
    ll sum2 = 0;
    for(int j=0;j<w.size();j++)
    {
      sum2 += max(0,w[j]-v+1);
    }
    // t(u,v);

    cnt += sum1*sum2;
  }

  cout << cnt << endl;
  return 0;
}
