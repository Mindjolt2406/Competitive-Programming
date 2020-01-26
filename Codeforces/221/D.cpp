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

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<vector<int> > v(n,vector<int>(m));

  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++) v[i][j] = s[j]-'0';
  }

  // Number of 1s on the left including yourself
  for(int i=0;i<n;i++)
  {
    int cnt = 0;
    for(int j=0;j<m;j++)
    {
      if(v[i][j]) cnt++;
      else cnt = 0;
      v[i][j] = cnt;
    }
  }

  int max1 = 0;

  for(int j=0;j<m;j++)
  {
    vector<int> w;
    for(int i=0;i<n;i++)
    {
      w.pu(v[i][j]);
    }
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());

    int sofar;
    for(int i=0;i<w.size();i++)
    {
      sofar = w[i];
      max1 = max(max1,sofar*(i+1));
    }
  }

  cout<<max1<<endl;
  return 0;
}

