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


ll f(ll n,ll val,vector<int> &v,vector<int> &w)
{
  ll cnt = 0;
  if(v.size() < w.size())
  {
    for(int i=0;i<v.size();i++)
    {
      cnt += (n/val) + (n%val >= v[i]);
    }
    return n-cnt;
  }
  else
  {
    for(int i=0;i<w.size();i++)
    {
      cnt += (n/val) + (n%val >= w[i]);
    }
    return cnt;
  }
}

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}


int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    bool flag = false;
    int a,b,q;
    cin >> a >> b >> q;
    // cin >> a >> b;
    if(a>b) swap(a,b);

    vector<int> v,w;
    ll val = (a*b)/(gcd(a,b));
    // int cnt = 0;
    for(int i=0;i<val;i++)
    {
      if((i%a)%b == (i%b)%a) 
      {
        v.pu(i);
        // cnt++;
      }
      else w.pu(i);
    }

    // t(cnt,val-cnt);

    while(q--)
    {

      ll l,r;
      cin >> l >> r;
      cout << f(r,val,v,w) - f(l-1,val,v,w) << " ";
    }
    cout << endl;

  }
  return 0;
}

/*
2
4 6 5
1 1
1 3
1 5
1 7
1 9
7 10 2
7 8
100 200

*/