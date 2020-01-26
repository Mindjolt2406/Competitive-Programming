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

bool f(int a,int b,int x,int y,int z)
{
  int counta = (z-a)/x;
  if((z-a)%x!=0) counta++;
  if(a>=z) counta = 0;

  int countb = (z-b)/y;
  if((z-b)%y!=0) countb++; 
  if(b>=z) countb = 0;

  return counta > countb;
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,a,b,x,y,z;
    cin>>n>>a>>b>>x>>y>>z;
    vector<int> v(n);
    for(int i=0;i<v.size();i++) cin>>v[i];
    swap(a,b); swap(x,y);

    if(f(a,b,x,y,z)) cout<<0<<endl;
    else
    {
      set<int> s;
      map<int,int> d;
      for(int i=0;i<v.size();i++) 
      {
        s.insert(v[i]);
        if(d.find(v[i])==d.end()) d[v[i]] = 1;
        else d[v[i]]++;
      }

      int count = 0, boo = 1;
      while(!d.empty() && !f(a,b,x,y,z))
      {
        int c = *s.rbegin();
        b+=c;
        count++;
        d[c]--;
        if(d[c] == 0) {d.erase(c); s.erase(c);}
        c/=2;
        if(c!=0) 
        {
          s.insert(c);
          if(d.find(c)==d.end()) d[c] = 1;
          else d[c]++;
        }
        if(a>=z || b>=z) break;
      }

      if(!f(a,b,x,y,z)) cout<<"RIP"<<endl;
      else cout<<count<<endl;
    }
  }
  return 0;
}

