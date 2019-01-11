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

ld f(ld h, ld l, ld r, ld k, ld x)
{
  return sqrt(pow(x,2) + pow(h,2)) + k*sqrt(pow(r-x,2) + pow(l,2));
}

ld g(ld h, ld l, ld r, ld k, ld x) // gets distance
{
  // t(x,h,r-x,l);
  return sqrt(pow(x,2) + pow(h,2)) + sqrt(pow(r-x,2) + pow(l,2));
}

ld ternary(ld h, ld l, ld r, ld k)
{
  ld beg = 0, end = r;
  ld mid;
  while(beg<=end)
  {
    mid = (beg+end)/2;
    ld a = f(h,l,r,k,mid-0.001);
    ld b = f(h,l,r,k,mid);
    ld c = f(h,l,r,k,mid+0.001);
    // t(a,b,c,mid);
    if(a>=b && b>=c) beg = mid+0.001;
    else if(a<=b && b<=c) end = mid-0.001;
    else return mid;
  }
  return mid;
}

int main()
{
  ld a,b,c,d;
  scld(a);scld(b);scld(c);scld(d);
  // a is h, b l, c  r, d k
  cerr<<setprecision(10);
  while(!(a==0 && b==0 && c==0 && d==0))
  {
    ld x = ternary(a,b,c,d);
    // t(x);
    printf("%.12Lf\n",g(a,b,c,d,x));
    scld(a);scld(b);scld(c);scld(d);
  }
  return 0;
}

