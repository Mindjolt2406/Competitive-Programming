// Do research a better way to implement this
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


int main()
{
  __;
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<int> left(n), right(n);

  set <pair<int,int> > s;
  map<int,vector<int> > d,e;
  
  // s.insert(mp(v[0],0));
  // _;
  for(int i=0;i<n;i++) // Right
  {
    if(d.find(v[i])==d.end()) {s.insert(mp(v[i],i));d[v[i]] = {};}
    else d[v[i]].pu(i);

    
    vector<pair<int,int> > w;
    for(auto p : s)
    {
      // t(p);
      if(v[i]%p.fi==0) 
      {
        right[p.se]++;        
      }
      else w.pu(p);
      if(i==n-1) w.pu(p);
    }

    for(int i=0;i<w.size();i++) 
    {
      for(int j=0;j<d[w[i].fi].size();j++) right[d[w[i].fi][j]] = right[w[i].se]-abs(w[i].se-d[w[i].fi][j]);
      s.erase(w[i]);
      d[w[i].fi].clear();
      d.erase(w[i].fi);
    }
  }

  s.clear();
  // for(auto it : d) it.se.clear();
  // d.clear();
  // _;
  for(int i=n-1;i>=0;i--) // Left
  {
    // for(auto it : e) cout<<it.fi<<" "; cout<<endl;
    if(e.find(v[i])==e.end()) {s.insert(mp(v[i],i));e[v[i]] = {};}
    else {e[v[i]].pu(i);}

    vector<pair<int,int> > w;
    for(auto p : s)
    {
      if(v[i]%p.fi==0) 
      {
        left[p.se]++;        
      }
      else w.pu(p);
      if(i==0) w.pu(p);
    }

    for(int i=0;i<w.size();i++) 
    {

      for(int j=0;j<e[w[i].fi].size();j++) left[e[w[i].fi][j]] = left[w[i].se]-abs(w[i].se-e[w[i].fi][j]);
      s.erase(w[i]);
      e[w[i].fi].clear();
      e.erase(w[i].fi);
    }
  }

  // _;
  // cout<<"left: ";
  // pr(left);
  // cout<<"right: ";
  // pr(right);
  int max1 = 1;
  for(int i=0;i<n;i++)
  {
    max1 = max(max1,left[i]+right[i]-1);
  }

  set<int> w;
  for(int i=0;i<n;i++)
  {
    if(left[i]+right[i]-1==max1)
    {
      w.insert(i-left[i]+1);
    }
  }

  // sort(w.begin(),w.end());
  cout<<w.size()<<" "<<max1-1<<endl;
  for(auto it : w) cout<<it+1<<" "; cout<<endl;
  return 0;
}

