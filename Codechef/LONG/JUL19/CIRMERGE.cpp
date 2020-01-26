/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

ll sum(int i,int j,vector<ll> &pref)
{
  if(i<=j)
  {
    if(i==0) return pref[j];
    return pref[j] - pref[i-1];
  }

  else
  {
    return pref[pref.size()-1] - pref[i-1] + pref[j];
  }
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<ll> v(n),pref(n);
    for(int i=0;i<n;i++) cin>>v[i];
    pref[0] = v[0];

    for(int i=1;i<n;i++) pref[i]+=pref[i-1] + v[i];
    // t(pref);

    vector<vector<ll> > dp(n,vector<ll> (n,INF));

    for(int i=0;i<n;i++) dp[i][i] = 0;
    // for(int i=0;i<n-1;i++) dp[i][i+1] = v[i]+v[i+1];
    dp[n-1][0] = v[n-1] + v[0];

    for(int sz=0;sz<n;sz++)
    {
      for(int i=0;i<n;i++)
      {
        int j = sz+i;
        if(j>=n) j-=n;

        if(dp[i][j]!=INF) continue;
        // t(i,j);

        if(i<j)
        {
          for(int k=i;k<j;k++)
          {
            dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + sum(i,j,pref));
            // t(i,j,k,dp[i][j],sum(i,j,pref));
          }
        }
        else
        {
          int k = i;
          // bool boo = true;
          int a = i, b = j;
          while(k!=j)
          {
            dp[i][j] = min(dp[i][j],dp[i][k] + dp[(k+1)%n][j] + sum(i,j,pref));
            k++;
            k%=n;
          }
        }
      }
    }

    ll min1 = dp[0][n-1];
    for(int i=0;i<n-1;i++) min1 = min(min1,dp[i+1][i]);

    cout<<min1<<endl;

    // for(int i=0;i<n;i++) for(int j=0;j<n;j++) t(i,j,dp[i][j]);
  }
  return 0;
}

