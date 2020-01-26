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

bool sorter(const pair<int,int> &a,const pair<int,int> &b)
{
  if(a.se > b.se) return true;
  else if(a.se == b.se && a.fi<b.fi) return true;
  return false;
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<pair<int,int> > v(n),w(n);
  set<int> s;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    s.insert(a); s.insert(b);
    v[i] = mp(a,b);
  }

  int counter = 0;
  map<int,int> d;
  for(auto it : s) {d[it] = counter; counter++;}

  for(int i=0;i<n;i++) {w[i].fi = d[v[i].fi]; w[i].se = d[v[i].se];}

  vector<int> get(1e6);
  sort(w.begin(),w.end(),sorter);
  for(int i=0;i<w.size();i++)
  {
    int a = w[i].fi, b = w[i].se;
    if(get[a]!=0)
    {
      for(int j=a;j<=b && w[j]==0;j++)
      {
        get[j] = b;
      }
    }
    else {cout<<"NO"<<endl;}
  }

  int i = 0,ans = 0;
  while(i<=counter)
  {
    i = get[i];
    i++;
    ans++;
  }

  cout<<ans<<endl;
  return 0;
}

