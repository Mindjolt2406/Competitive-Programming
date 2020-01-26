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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v(n+1,-1);
  vector<bool> check(n+1);

  for(int i=0;i<s.size();i++)
  {
    if(i==0 && s[i] == '<') v[0] = 0;
    else if(i==0 && s[i] == '>') check[i] = true;
    else if(i>0)
    {
      if(s[i-1] == '>' && s[i] == '<') v[i] = 0;
      else if(s[i-1] == '<' && s[i] == '>') check[i] = true;
    } 
  }

  if(s[n-1] == '>') v[n] = 0;
  else if(s[n-1] == '<') check[n] = true;

  for(int i=0;i<v.size();i++)
  {
    // Simulate left
    if(v[i] == 0)
    {
      int sum1 = 0;
      for(int j=i-1;j>=0;j--)
      {
        sum1++;
        v[j] = max(v[j],sum1);
        if(check[j]) break;
      }

      sum1 = 0;
      for(int j=i+1;j<=n;j++)
      {
        sum1++;
        v[j] = max(v[j],sum1);
        if(check[j]) break;
      }
    }
  }



  ll sum1 = 0;
  for(int i=0;i<=n;i++) sum1 += v[i];
  // t(v);
  // t(check);

  cout << sum1 << endl;
  return 0;
}

