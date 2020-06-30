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
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    // vector<vector<vector<bool> > > dp(152,vector<vector<bool> >(152,vector<bool>(15000)));
    // vector<vector<vector<bool> > > back(152,vector<vector<bool> >(152,vector<bool>(15000)));
    vector<string> w;
    int total = 0;
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      w.pu(s);
      int cnt1 = 0, cnt = 0;
      for(int j=0;j<s.size();j++) 
      {
        if(j<s.size()/2) 
        {
          cnt1 += s[j]-'0';
        }
        cnt += s[j]-'0';
      }
      if(cnt1 >= cnt-cnt1) reverse(w[i].begin(),w[i].end());
      v[i] = abs((cnt-cnt1)-cnt1);
      total += v[i];
    }

    vector<vector<bool> > dp(n,vector<bool>(total+1));
    vector<vector<bool> > back(n,vector<bool>(total+1));
    dp[0][0] = 1;
    dp[0][v[0]] = 1;
    back[0][v[0]] = 1;

    for(int i=1;i<n;i++)
    {
      for(int k=0;k<=total;k++)
      {
        if(dp[i-1][k])
        {
          back[i][k] = 0;
          dp[i][k] = 1;
        }
        else if(k >= v[i] && dp[i-1][k-v[i]])
        {
          back[i][k] = 1;
          dp[i][k] = 1;
        }
      }
    }

    int index = -1,diff = INF;
    for(int k=0;k<=total;k++)
    { 
      if(dp[n-1][k]) 
      {
        if(abs((total-k)-k) < diff)
        {
          diff = abs((total-k)-k);
          index = k;
        }
      }
    }

    vector<bool> reverser(n);

    int k = index;
    // t(total,k);
    for(int i=n-1;i>=0;i--)
    {
      if(back[i][k])
      {
        reverser[i] = 1;
        k -= v[i];
      }
    }

    // t(reverser);

    for(int i=0;i<w.size();i++)
    {
      if(reverser[i])
      {
        reverse(w[i].begin(),w[i].end());
      }
      cout << w[i] << endl;
    }
    // t(dp);
    // t(back);
  }
  return 0;
}

/*
1
6
100110
100111
111000
011001
100111
010001

*/