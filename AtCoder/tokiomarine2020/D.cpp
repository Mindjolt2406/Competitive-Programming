#include<bits/stdc++.h>
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

ll max(ll x, ll y)
{
  return (x>y) ? x : y;
}

ll knapsack(vector<ll> &weight, vector<ll> &costs,ll max_weight)
{
  vector<vector<ll> > dp(20,vector<ll>(max_weight+1,-INF));
  for(int i=0;i<=max_weight;i++) dp[0][i] = 0;

  int n = weight.size()-1;
  for(int i=1;i<=n;i++)
  {
    dp[i][0] = 0;
    for(int j=1;j<=max_weight;j++)
    {
      if(j >= weight[i] && dp[i-1][j-weight[i]] != -INF) 
      {
        dp[i][j] = dp[i-1][j-weight[i]]+costs[i];
      }
      dp[i][j] = max(dp[i][j],dp[i-1][j]);
    }
  }
  return dp[n][max_weight];
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<ll> weight(n),value(n);
  for(int i=1;i<=n;i++) cin >> value[i] >> weight[i];
  int q;
  cin >> q;
  while(q--)
  {
    vector<ll> temp_weight(1),temp_value(1);
    int index,max_weight;
    cin >> index >> max_weight;
    while(index)
    {
      temp_weight.pu(weight[index]);
      temp_value.pu(value[index]);
      index >>= 1;
    }
    cout << knapsack(temp_weight,temp_value,max_weight) << endl;
  }
  return 0;
}
