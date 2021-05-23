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

class OneGcd
{
  public:
    ll get(ll a, ll b, ll p)
    {
      return b/p - a/p + (a%p == 0);
    }

    vector<int> solve(vector<ll> x, vector<int> y)
    {
      vector<int> ans;
      for(int i=0;i<x.size();i++)
      {
        vector<int> v = {2,3,5,7,30,42,70,105};
        vector<int> w = {6,10,14,15,21,35,210};

        ll l = x[i], r = y[i]+x[i]-1;

        ll prod = 1;
        if(y[i] % 2 == 0) prod *= 2;
        if(y[i] % 3 == 0) prod *= 3;
        if(y[i] % 5 == 0) prod *= 5;
        if(y[i] % 7 == 0) prod *= 7;


        int cnt = 0;
        for(int j=0;j<v.size();j++)
        {
          if(prod % v[j] != 0) continue;
          cnt += get(l,r,v[j]);
        }      

        for(int j=0;j<w.size();j++)
        {
          if(prod % w[j] != 0) continue;
          cnt -= get(l,r,w[j]);
        }

        cnt = r-l+1 - cnt;
        ans.pu(cnt);
      }
      return ans;
    }
};

int main()
{
  __;
  OneGcd o;
  cout << o.solve({10},{15}) << endl;
  return 0;
}
