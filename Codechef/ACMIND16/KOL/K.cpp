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

ld get_slope(pair<ld,ld> p1, pair<ld,ld> p2)
{
  return (p2.se - p1.se) / (p2.fi - p1.fi);
}

struct sorter
{
  bool operator ()(const pair<ld,int> &p1, const pair<ld,int> &p2) const
  {
    if(p1.fi < p2.fi) return true;
    if(p1.fi == p2.fi && p2.se < p1.se) return true;
    return false;
  }
};

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++)
    {
      int a,b;
      cin >> a >> b;
      v[i] = mp(a,b);
    }

    sort(v.begin(),v.end());

    // dp[i] stores the sorted pairs of < slope, outcome > , sorted by outcome
    vector<set< pair<ld,int> , sorter> > dp(n);

    for(int i=n-1;i>=0;i--)
    {
      vector<pair<ld,int> > w;
      w.pu(mp(-INF,1));
      for(int j=n-1;j>i;j--)
      {
        ld slope = get_slope(v[i],v[j]);
        auto it = dp[j].upper_bound(mp(slope,INF));
        it--;
        
        if(it == dp[j].end()) continue;
        int outcome = 1 + it->se;
        w.pu(mp(slope,outcome));

        t(v[i],v[j],mp(slope,outcome));
      }

      // Check slope
      sort(w.begin(),w.end());
      int max_cum = 0;
      for(int j=0;j<w.size();j++)
      {
        max_cum = max(max_cum,w[j].se);
        w[j].se = max_cum;
      }

      t(w);

      for(int j=0;j<w.size();j++)
      {
        dp[i].insert(w[j]);
      }
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    {
      for(auto it : dp[i]) ans = max(ans,it.se);
    }

    cout << ans << endl;
  }
  return 0;
}

