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
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  int t;
  cin>>t;
  cout<<setprecision(10);
  while(t--)
  {
    int a,b,c,d;
    cout<<"Q"<<" "<<0<<" "<<0<<endl;
    cout<<"Q"<<" "<<1e9<<" "<<0<<endl;
    cout<<"Q"<<" "<<1e9<<" "<<1e9<<endl;
    cout<<"Q"<<" "<<0<<" "<<1e9<<endl;
    cin>>a>>b>>c>>d;
    int e = (1e9 + a - b)/2;
    int f = (1e9 + a - d)/2;
    cout<<"Q"<<" "<<e<<" "<<0<<endl;
    cout<<"Q"<<" "<<0<<" "<<f<<endl;
    int x,y;
    cin>>y>>x;
    int x2 = 1e9 + a - b - x;
    int y2 = 1e9 + a - d - y;
    cout<<"A"<<" "<<x<<" "<<y<<" "<<x2<<" "<<y2<<endl;
    int ans;
    cin>>ans;
    if(ans<0) return 0;
  }
  return 0;
}

