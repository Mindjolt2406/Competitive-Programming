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


using namespace std;

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,a,b1;
    sc(n);sc(a);sc(b1);
    vector<int> b(n+1),w(n+1);
    for(int i=1;i<=n;i++)
    {
      sc(w[i]);sc(b[i]);
    }

    w[n] = w[n]%2;
    for(int i=n-1;i>0;i--)
    {
      if(w[i]%2==0 || w[i+1]%2==0) w[i] = 0;
      else w[i] = 1; 
    }

    int xor1= 0;
    xor1= b[n]%2;

    for(int i=1;i<n;i++)
    {
      xor1^=b[i]&w[i+1];
    }

    int xorodd = xor1^(w[1]&1);
    int xoreven = xor1; //w[1]&0

    ll xodd,xeven;
    xeven = b1/2 - (a-1)/2;
    xodd = (b1-a+1) - xeven;

    ll countodd = 0,counteven = 0;
    if(xorodd) countodd+=xodd;
    else counteven+=xodd;

    if(xoreven) countodd+=xeven;
    else counteven+=xeven;

    cout<<counteven<<" "<<countodd<<endl;
  }
  return 0;
}

