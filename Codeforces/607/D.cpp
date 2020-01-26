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


int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > v(n,vector<int> (m));
    int totalP = 0;
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      for(int j=0;j<m;j++)
      {
        if(s[j] == 'A') v[i][j] = 1;
        else 
        {
          totalP ++;
          v[i][j] = 0;
        }
      }
    }

    // Edges for all As
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for(int i=0;i<n;i++)
    {
      if(v[i][0]) cnt1++;
      if(v[i][m-1]) cnt2++;
    }

    for(int j=0;j<m;j++)
    {
      if(v[0][j]) cnt3++;
      if(v[n-1][j]) cnt4++;
    }

    bool check2 = false;
    for(int i=0;i<n;i++)
    {
      int sum1 = 0;
      for(int j=0;j<m;j++)
      {
        sum1 += v[i][j];
      }
      if(sum1 == m) check2 = true;
    }

    for(int j=0;j<m;j++)
    {
      int sum1 = 0;
      for(int i=0;i<n;i++)
      {
        sum1 += v[i][j];
      }
      if(sum1 == n) check2 = true;
    }

    if(!totalP) cout << 0 << endl;
    else if(cnt1 == n || cnt2 == n || cnt3 == m || cnt4 == m) 
    {
      cout << 1 << endl;
    }
    else if(check2)
    {
      cout << 2 << endl;
    }
    else if(v[0][0] || v[0][m-1] || v[n-1][0] || v[n-1][m-1])
    {
      cout << 2 << endl;
    }
    else if(cnt1 || cnt2 || cnt3 || cnt4) 
    {
      cout << 3 << endl;
    }
    else if(totalP != n*m) 
    {
      cout << 4 << endl;
    }
    else cout << "MORTAL" << endl;
  }
  return 0;
}

