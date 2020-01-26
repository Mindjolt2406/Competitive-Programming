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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=mp(INF,INF)) t(v[i]); else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<string> v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  vector<vector<vector<pair<int,int> > > >w(n, vector<vector<pair<int,int> > >(m,vector<pair<int,int> >(3,mp(0,-1))) ); 
  vector<vector<bool> > x(n,vector<bool>(m));

  for(int i=0;i<m;i++) 
  {
    int col = v[0][i]-'a';
    w[0][i][0] = mp(1,col);
  }

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int col = v[i-1][j]-'a';
      int cur = v[i][j]-'a';
      if(col==cur)
      {
        w[i][j][1] = w[i-1][j][1];
        w[i][j][2] = w[i-1][j][2];
        w[i][j][0] = mp(w[i-1][j][0].fi+1,col);
      }
      else
      {
        w[i][j][2] = w[i-1][j][1];
        w[i][j][1] = w[i-1][j][0];
        w[i][j][0] = mp(1,cur);
      }
    }
  }

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(w[i][j][0].fi==w[i][j][1].fi && w[i][j][2].fi >= w[i][j][0].fi)
      {
        w[i][j][2].fi = w[i][j][0].fi;
        x[i][j] = true;
        if(w[i][j][0].se == -1 || w[i][j][1].se ==-1 || w[i][j][2].se == -1) x[i][j] = false;
      }
      else x[i][j] = false;
    }
  }

  ll cnt = 0;
  for(int i=2;i<n;i++)
  {
    vector<int> col = {-1,-1,-1};
    int freq = -1;
    int index = 0;
    bool boo = false;
    if(x[i][0]) 
    {
      cnt++;
      freq = w[i][0][0].fi;
      col = {w[i][0][0].se,w[i][0][1].se,w[i][0][2].se};
      boo = true;
    }
    for(int j=1;j<m;j++)
    {
      vector<int> cur = {w[i][j][0].se,w[i][j][1].se,w[i][j][2].se};
      int cur_freq = w[i][j][0].fi;
      // if(i==9) t(freq,cur_freq);
      if(cur==col && cur_freq==freq && x[i][j] && boo) cnt+=(j-index+1);
      else
      {
        if(x[i][j]) 
        {
          cnt++;
          col = cur;
          freq = cur_freq;
          index = j;
          boo = true;
        }
        else boo = false;
      }
      // t(cnt,i,j,index);
    }
  }

  cout<<cnt<<endl;

  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<m;j++) cout<<x[i][j]<<" ";
  //   cout<<endl;
  // }

  // for(int i
  return 0;
}

