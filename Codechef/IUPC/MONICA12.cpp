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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

map<pair<int,int>,ll> d;

ll f(int b,int k,vector<vector<int> > &v)
{
  if(k==1) return 1;
  if(b==1) return 1;
  if(d.find(mp(k,b))!=d.end()) return d[mp(k,b)];
  else
  {
    ll a = 0;
    for(int i=0;i<v[k].size();i++)
    {
      if(v[k][i]==1) {a++;a%=MOD;continue;}
      d[mp(b-1,v[k][i])] = f(b-1,v[k][i],v);
      a+=d[mp(b-1,v[k][i])];
      t(b-1,v[k][i],d[mp(b-1,v[k][i])]);
      a%=MOD;
    }
    return a;
  }

}

int main()
{
  __;
  int b,n,k;
  cin>>n>>b>>k;
  vector<vector<int> > v(101);
  for(int i=1;i<=100;i++)
  {
    for(int j=1;j<=100;j++)
    {
      if(i%j==0) v[i].pu(j);
    }
  }
  
  cout<<f(b,k,v)<<endl;
  return 0;
}

