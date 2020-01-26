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
#define vi vector<int>
#define vll vector<long long int>
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
  vector<vector<vector<int> > > v(n,vector<vector<int> > (m,vector<int> (10)));
  vector<vector<vector<pair<int,int> > >  > w(n,vector<vector< pair<int,int> > >(10,vector<pair<int,int> > (2)));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int a;
      cin>>a;
      for(int k=1;k<=10;k++)
      {
        v[i][j][k-1] = a&1;
        a>>=1;
      }
    }
    for(int k=0;k<10;k++)
    {
      for(int j=0;j<m;j++)
      {
        if(v[i][j][k]==0) w[i][k][0] = mp(1,j);
        else w[i][k][1] = mp(1,j);
      }
    }
  }

  int flag = 0;
  for(int k=0;k<10;k++)
  {
    vector<pair<int,int> > x;
    int boo = 0;
    int count = 0;
    pair<int,int> p;
    for(int i=0;i<n;i++)
    {
      if(w[i][k][0].fi==w[i][k][1].fi && w[i][k][0].fi==1)
      {
        boo = 1;
        p = mp(i,w[i][k][1].se);
      }
      else
      {
        if(w[i][k][1].fi)
        {
          count++;
          x.pu(mp(i,w[i][k][1].se));
        }
        else x.pu(mp(i,w[i][k][0].se));
      }
    }
    if(count%2==0 && boo) 
    {
      flag = 1;
      for(int i=0;i<n;i++)
      {
        if(w[i][k][0].fi==w[i][k][1].fi && w[i][k][0].fi==1)
        {
          if(p.fi==i && p.se==w[i][k][1].se) x.pu(mp(i,w[i][k][1].se));
          else x.pu(mp(i,w[i][k][0].se));
        }
      }
    }
    else if(count%2==1)
    {
      flag = 1;
      for(int i=0;i<n;i++)
      {
        if(w[i][k][0].fi==w[i][k][1].fi && w[i][k][0].fi==1)
        {
          x.pu(mp(i,w[i][k][0].se));
        }
      }
    }
    if(flag) 
    {
      cout<<"TAK"<<endl;
      sort(x.begin(),x.end());
      for(int i=0;i<x.size();i++) cout<<x[i].se+1<<" ";cout<<endl;
      break;
    }
  }
  if(!flag) cout<<"NIE"<<endl;
  return 0;
}

