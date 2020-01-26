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
  int n;
  cin >> n;
  vector<vector<bool> > v(n,vector<bool>(n));

  for(int i=0;i<n;i++)
  {
    string s;
    cin >> s;
    for(int j=0;j<s.size();j++) v[i][j] = s[j]-'0';
  }

  for(int i=0;i<n;i++) v[i][i] = true;

  int m;
  cin >> m;
  vector<int> w(m);
  for(int i=0;i<m;i++) {cin >> w[i]; w[i]--;}
  vector<int> dp(m,INF);
  vector<int> back(m,-1); // For i>0 back[i] = -1 means go to the previous. otherwise stop
  vector<int> trace(m,-1);

  dp[0] = 1;
  dp[1] = 2;
  back[1] = -1;

  for(int i=2;i<m;i++)
  {
    int k = max(-1,i-101);
    k = max(k,back[i-1]);

    for(int j=i-2;j>k;j--)
    {
      if(v[w[j]][w[i]]) {back[i] = j;trace[i] = j+1; break;}

      if(dp[j] + 1 < dp[i])
      {
        dp[i] = dp[j] + 1;
        k = max(k,back[j]);
        trace[i] = j;
      }
      // t(i,j,k);

    }

    if(dp[i] == INF) dp[i] = dp[i-1] + 1;
  }

  cout << dp[m-1] << endl;

  // for(int i=0;i<m;i++) cout << dp[i] << " "; cout << endl;
  // for(int i=0;i<m;i++) cout << trace[i] << " "; cout << endl;

  vector<int> ans;
  int index = m-1;
  while(index>=0)
  {
    ans.pu(w[index]+1);
    if(trace[index] == -1) 
    {
      index--;
    }
    else index = trace[index];
  }

  reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}

