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
  int n,q;
  cin>>n>>q;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  vector<vector<int> > w(n,vector<int>(32));
  vector<vector<int> > x(n,vector<int>(32));
  vector<vector<int> > y(n,vector<int>(32,INF));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<32;j++)
    {
      w[i][j] = (v[i]>>j)&1;
    }
  }

  for(int j=0;j<32;j++)
  {
    int sofar = INF;
    for(int i=n-1;i>=0;i--)
    {
      x[i][j] = sofar;
      if(w[i][j]) sofar = i;
    }
  }

  for(int i=n-1;i>=0;i--)
  {
    for(int j=0;j<32;j++)
    {
      if(w[i][j]) y[i][j] = x[i][j];
      else
      {
        for(int k=0;k<32;k++)
        {
          if(w[i][k] && x[i][k]!=INF)
          {
            y[i][j] = min(y[i][j],y[x[i][k]][j]);
            if(w[x[i][k]][j]) y[i][j] = min(y[i][j],x[i][k]);
          }
        }
      }
    }
  }

  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<5;j++)
  //   {
  //     t(i,j,y[i][j]);
  //   }
  // }

  while(q--)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    int boo = 0;
    for(int j=0;j<32;j++)
    {
      if(w[b][j]) if(y[a][j]<=b && y[a][j]!=INF) {boo = 1;break;}
    }
    if(boo) cout<<"Shi"<<endl;
    else cout<<"Fou"<<endl;
  }

  
  return 0;
}

