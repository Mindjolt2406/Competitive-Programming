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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int t;
  cin>>t;
  // t(t);
  for(int h=1;h<=t;h++)
  {
    // t(h);
    int n;
    cin>>n;
    vector<vector<int> > dp(n,vector<int> (n,INF));
    vector<vector<int> > dp2(n,vector<int> (n));

    for(int i=0;i<n;i++) dp[i][i] = 0;
    int q;
    cin>>q;
    vector<pair<int,pair<int,int>> > w;
    while(q--)
    {
      int a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      w.pu(mp(c,mp(a,b)));
    }

    sort(w.begin(),w.end());


    int boo = 0;

    for(int k=0;k<w.size();k++)
    {
      int cost = w[k].fi;
      int a = w[k].se.fi, b = w[k].se.se;

      // t(cost,a,b,dp[a][b]);
      if(cost>dp[a][b]) {boo = 1;break;}
      dp[a][b] = dp[b][a] = cost;
      dp2[a][b] = 1;
      // t(a,b,cost,dp[a][b]);

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(i==j) continue;
          int c = dp[i][a] + cost + dp[b][j];
          if(c>=INF) continue;
          if(dp[i][j]==INF) dp[i][j] = dp[j][i] = c;
          else if(dp2[i][j]==0 || dp[i][j]<=c) continue;
          else boo = 1;
          // t(i,j,dp[i][j],c,boo);
        } 
      }

      if(boo) break;

      // t(dp);
    }

    if(boo) cout<<"Case #"<<h<<": "<<"Impossible"<<"\n";
    else 
    {
      // _;
      int cnt = 0;
      int boo = 0;
      for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
          if(dp[i][j]!=INF && dp[i][j]!=0 && dp[i][j]<=1e6) cnt++;
        }
      }
      
      cout<<"Case #"<<h<<": "<<cnt<<endl;
      for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
          if(dp[i][j]!=INF && dp[i][j]!=0 && dp[i][j]<=1e6) cout<<i+1<<" "<<j+1<<" "<<dp[i][j]<<"\n";
        }
      }

    }
  }
  return 0;
}

/*
1
8 10
2 6 16
7 3 6
5 1 11
7 6 12
8 1 8
6 1 18
1 3 12
3 5 9
6 5 15
7 1 6


 */