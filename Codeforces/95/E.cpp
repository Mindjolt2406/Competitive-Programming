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
  vector<vector<pair<int,int> > > vert,horiz;
  map<pair<int,int> , vector<pair<int,int> > > diag1,diag2;
  vert.resize(n+1); // Rows are equal, sorted based on columns
  horiz.resize(n+1); // Columns are equal, sorted based on rows
  vector<pair<int,int> > v(m);
  vector<int > w(m);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    v[i] = mp(a,b);
    vert[a].pu(mp(b,i));
    horiz[b].pu(mp(a,i));
    int c = min(a,b);
    diag1[mp(a-c,b-c)].pu(mp(a,i));
    diag2[mp(0,b+a)].pu(mp(a,i));
    // diag1[a+b].pu(mp(a,i));
    // diag2[abs(a-b)].pu(mp(a,i));
  }

  for(int i=0;i<vert.size();i++) sort(vert[i].begin(),vert[i].end());
  for(int i=0;i<horiz.size();i++) sort(horiz[i].begin(),horiz[i].end());
  // for(int i=0;i<diag1.size();i++) sort(diag1[i].begin(),diag1[i].end());
  // for(int i=0;i<diag2.size();i++) sort(diag2[i].begin(),diag2[i].end());

  for(int i=0;i<vert.size();i++)
  {
    // t(i);
    for(int j=1;j<((int)vert[i].size())-1;j++)
    {
      // t(j);
      // t(i,j,vert[i][j].fi,vert[i][j].se);
      w[vert[i][j].se]+=2;
    }
    if(vert[i].size()>1) w[vert[i][0].se]++;
    if(vert[i].size()>1) w[vert[i][vert[i].size()-1].se]++;
  }

  // pr(w);
  for(int i=0;i<horiz.size();i++)
  {
    for(int j=1;j<((int)horiz[i].size())-1;j++)
    {
      w[horiz[i][j].se]+=2;
    }
    if(horiz[i].size()>1) w[horiz[i][0].se]++;
    if(horiz[i].size()>1) w[horiz[i][horiz[i].size()-1].se]++;
  }

  // pr(w);

  for(auto v : diag1)
  {
    sort(v.se.begin(),v.se.end());
    for(int j=1;j<((int)v.se.size())-1;j++)
    {
      w[v.se[j].se]+=2;
    }
    if(v.se.size()>1) w[v.se[0].se]++;
    if(v.se.size()>1) w[v.se[v.se.size()-1].se]++;
  }

  for(auto v : diag2)
  {
    sort(v.se.begin(),v.se.end());
    for(int j=1;j<((int)v.se.size())-1;j++)
    {
      w[v.se[j].se]+=2;
    }
    if(v.se.size()>1) w[v.se[0].se]++;
    if(v.se.size()>1) w[v.se[v.se.size()-1].se]++;
  }

  // for(int i=0;i<diag2.size();i++)
  // {
  //   for(int j=1;j<((int)diag2[i].size())-1;j++)
  //   {
  //     w[diag2[i][j].se]+=2;
  //   }
  //   if(diag2[i].size()>1) w[diag2[i][0].se]++;
  //   if(diag2[i].size()>1) w[diag2[i][diag2[i].size()-1].se]++;
  // }
  // pr(w);

  // for(int i=0;i<v.size();i++) t(i,v[i].fi,v[i].se);
  int counter[9] = {0};

  for(int i=0;i<w.size();i++) counter[w[i]]++;

  for(int i=0;i<9;i++) cout<<counter[i]<<" "; cout<<endl;
  return 0;
}

