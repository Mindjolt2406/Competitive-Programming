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

int n,m;

int check(int a,int b)
{
  if(a>=0 && b>=0 && a<n && b<m) return true;
  return false;
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  { 
    int k;
    cin>>n>>m>>k;
    map<pair<int,int>,int > d;
    for(int i=0;i<k;i++)
    {
      int a,b;
      cin>>a>>b;
      a--;b--;
      d[mp(a,b)] = 4;
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(auto it : d)
    {
      int i = it.first.first, j = it.first.se;
      for(int k=0;k<4;k++)
      {
        int a = dx[k]+i, b = dy[k]+j;
        if(check(a,b))
        {
          if(d.find(mp(a,b))!=d.end()) d[mp(i,j)]--;
        }
      } 
    }

    int count = 0;
    for(auto it : d) count+=it.se;

    cout<<count<<endl;
  }
  return 0;
}

