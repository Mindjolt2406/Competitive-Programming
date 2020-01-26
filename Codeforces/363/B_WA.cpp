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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<string> v(n),w(n);
  for(int i=0;i<n;i++) {cin>>v[i];w[i] = v[i];}
   
  int max1 = 0,max2 = 0;
  for(int i=0;i<n;i++)
  {
    int cnt = 0;
    for(int j=0;j<m;j++)
    {
      if(v[i][j]=='*') 
      {
        cnt++;
      }
    }

    if(cnt>max1) 
    {
      max1 = cnt;
      max2 = i;
    } 
  }

  int max3 = 0,max4 = 0;
  for(int j=0;j<m;j++)
  {
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
      if(i==max2) continue;
      if(v[i][j]=='*') cnt++;
    }

    if(cnt>max3)
    {
      max3 = cnt;
      max4 = j;
    }
  }

  for(int i=0;i<n;i++) v[i][max4] = '.';
  for(int j=0;j<m;j++) v[max2][j] = '.';
  // t(max2,max4);

  int cnt = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j]=='*') cnt++;
    }
  }

  if(cnt>0) 
  {
    int max3 = 0,max4 = 0;
    for(int j=0;j<m;j++)
    {
      int cnt = 0;
      for(int i=0;i<n;i++)
      {
        if(w[i][j]=='*') cnt++;
      }

      if(cnt>max3)
      {
        max3 = cnt;
        max4 = j;
      }
    }

    int max1 = 0,max2 = 0;
    for(int i=0;i<n;i++)
    {
      int cnt = 0;
      for(int j=0;j<m;j++)
      {
        if(j==max4) continue;
        if(v[i][j]=='*') 
        {
          cnt++;
        }
      }

      if(cnt>max1) 
      {
        max1 = cnt;
        max2 = i;
      } 
    }

    // t(max2,max4);
    for(int i=0;i<n;i++) w[i][max4] = '.';
    for(int j=0;j<m;j++) w[max2][j] = '.';
    // t(max2,max4);

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(w[i][j]=='*') cnt++;
      }
    }

    if(cnt>0) cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      cout<<max2+1<<" "<<max4+1<<endl;
    }
  }
  else
  {
    cout<<"YES"<<endl;
    cout<<max2+1<<" "<<max4+1<<endl;
  }
  
  return 0;
}

