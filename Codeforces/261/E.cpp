/*
Rathin Bhargava
IIIT Bangalore

*/

/*
How to execute stuff parallely? Simple, compute them separately and then join them to the final ans
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

const int N = 3e5+10;
vector<vector<pair<int,int> > > v(N,vector<pair<int,int> >(2,mp(0,0)));

int main()
{
  __;
  int n,q;
  cin>>n>>q;
  vector<tuple<int,int,int> > edges(q);
  for(int h=0;h<q;h++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    edges[h] = mt(c,a,b);
  } 
  sort(edges.begin(),edges.end());

  for(int i=0;i<q;i++)
  {
    tuple<int,int,int> t = edges[i];
    int c = get<0>(t), a = get<1>(t), b = get<2>(t);
    pair<int,int> p = mp(0,0);
    // t(a,b,c,v[a][0].se, v[a][1].se);
    if(c!=v[a][0].se)
    {
      p = mp(v[a][0].fi+1,c);
    }
    else if(c!=v[a][1].se) 
    {
      p = mp(v[a][1].fi+1,c);
    }

    if(p.fi>v[b][0].fi)
    {
      v[b][1] = v[b][0];
      v[b][0] = p;
    }
    else if(p.fi>v[b][1].fi)
    {
      v[b][1] = p;
    }
  }

  int max1 = 0;
  for(int i=0;i<n;i++) max1 = max(max1,v[i][0].fi);
  cout<<max1<<endl;
  return 0;
}

