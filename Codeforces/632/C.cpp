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

const int N = 2e5+10;

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  ll sum1 = 0;
  map<ll,vector< pair<int,int> > > d;
  d[0].pu(mp(0,0));
  for(int i=0;i<n;i++)
  {
    sum1 += v[i];
    if(d.count(sum1)) d[sum1].pu(mp(d[sum1].back().se,i+1));
    else d[sum1].pu(mp(i+1,i+1));
  }

  vector<vector<int> > idx(n+1);
  vector<int> enders(n+1);

  for(auto it : d)
  {
    vector<pair<int,int> > w = it.se;
    for(int i=0;i<w.size();i++)
    {
      if(w[i].fi == w[i].se && w[i].fi > 0 && v[w[i].fi-1] == 0)
      {
        enders[w[i].fi]++;
        idx[w[i].fi].pu(w[i].se);
      } 
      else if(w[i].fi != w[i].se)
      {
        enders[w[i].se]++;
        idx[w[i].fi].pu(w[i].se);
      }
    }
  }

  ll cnt = 0;
  int left = 0, right = 0;
  // t(enders);
  while(left <= n)
  {
    while(right <= n && enders[right] == 0)
    {
      right++;
    }
    // t(left,right);
    cnt += right-left-1;
    for(auto it : idx[left])
    {
      enders[it]--;
    }
    left++;
  }

  cout << cnt << endl;
  return 0;
}
