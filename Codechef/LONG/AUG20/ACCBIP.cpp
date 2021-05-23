#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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

ll max(ll x, ll y) {return x>y?x:y;}

void addCost(vector<ll> &cost, vector<int>&v)
{
  int n = v.size();
  ll sum_before = 0, doubles_before = 0;
  for(int i=v.size()-1;i>=0;i--)
  {
    // t(i,v[i],sum_before,doubles_before);
    ll curr_doubles = doubles_before + sum_before*v[i];
    int orig = v[i];
    while(orig--)
    {
      cost.pu(doubles_before);
    }
    sum_before += v[i];
    doubles_before = curr_doubles;
  }

  reverse(cost.begin(),cost.end());
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,c,k;
    cin >> n >> c >> k;
    vector<pair<int, pair<int,int> > > v(n);
    vector<ll> weight(c);
    for(int i=0;i<n;i++) 
    {
      cin >> v[i].se.fi >> v[i].se.se >> v[i].fi;
      v[i].fi--;
    }
    for(int i=0;i<c;i++) cin >> weight[i];

    vector<map<int,int>  > distinct(c);
    for(auto it : v)
    {
      distinct[it.fi][it.se.fi]++;
    }

    vector<vector<int> > d(c);
    for(int i=0;i<c;i++)
    {
      map<int,int> e = distinct[i];
      for(auto it : e)
      {
        d[i].pu(it.se);
      }
      sort(d[i].begin(),d[i].end());
    }

    vector<vector<ll> > cost(c);
    ll total = 0;
    for(int i=0;i<c;i++)
    {
      addCost(cost[i],d[i]);
      for(auto it : cost[i]) total += it;
    }

    for(int col = 0;col<c;col++)
    {
      for(int i=1;i<cost[col].size();i++)
      {
        cost[col][i] += cost[col][i-1];
      }
    }

    vector<ll> dp(k+1,-INF);
    dp[0] = 0;
    for(int col=0;col<c;col++)
    {
      for(int i=k;i>=1;i--)
      {
        for(int j=0;j<cost[col].size();j++)
        {
          if(i >= weight[col]*(j+1))
          {
            if(dp[i-(weight[col]*(j+1))] != -INF) dp[i] = max(dp[i],dp[i-(weight[col]*(j+1))] + cost[col][j]);
          }
        }
      }
    }

    ll max1 = 0;
    for(auto it : dp)
    {
      max1 = max(max1,it);
    }

    cout << total-max1 << endl;
  }
  return 0;
}
