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

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    set<pair<int,int> > s2;
    set<int> s3;
    for(int i=0;i<n;i++)
    {
      int a,b;
      cin>>a>>b;
      s3.insert(a+b);
      int g = gcd(a,b);
      a/=g;b/=g;
      if(s2.find(mp(a,b))==s2.end()) 
      {
        s2.insert(mp(a,b));
        v.pu(mp(a,b));
      }

    }

    sort(v.begin(),v.end());
    // for(auto a : v) t(a.fi,a.se);
    set<pair<int,int> > s;
    for(int i=0;i<v.size();i++)
    {
      for(int j=0;j<v.size();j++)
      {
        if(i!=j)
        {
          ll a = v[i].fi, b = v[i].se, c = v[j].fi, d = v[j].se;
          ll e = a-c, f = d-b;
          // t(a,b,c,d,e,f);
          e = abs(e); f = abs(f);
          int g = gcd(abs(e),abs(f));
          // g = abs(g);
          e/=g;f/=g;
          if(e*f>0) s.insert(mp(e,f));
        }
      }
    }

    // for(auto v : s) t(v.fi,v.se);
    int a = s.size();
    // if(s3.size()==n) a++;
    a++;
    cout<<"Case #"<<h<<": "<<a<<endl;
  }
  return 0;
}

