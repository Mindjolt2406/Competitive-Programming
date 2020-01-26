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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ld min(ld x, ld y)
{
  if(x<y) return x;
  return y;
}

int compare(int d,int k,int n)
{
  if(k==1) return k;
  else if(d>=10) return n;
  else 
  {
    for(int i=1;i<d;i++)
    {
      ll c = pow(k,i);
      if(n<=c) return n; 
    }
    return pow(k,d);
  }
}

int main()
{
  int n,k,d;
  sc(n);sc(k);sc(d);
  ll a = 1;
  for(int i=0;i<d;i++) 
  {
    a*=k;
    if(a>=INF) break;
  }
  if(a<n){cout<<-1<<endl;return 0;}
  for(int i=0;i<d;i++)
  {
    int counter = 1,count =0;
    int a = compare(d-i-1,k,n);
    // t(d-i-1,k,n,a);
    int a1 = a;
    while(count!=n)
    {
      for(int j=0;j<k;j++)
      {
        if(count==n) break;
        for(int k1=0;k1<a;k1++)
        {
          cout<<counter<<" ";
          count++;
          if(count==n) break;
        }
        counter%=k;
        counter++;
        // if(counter==0) counter = k;
      }
    }
    
    cout<<endl;
  }
  return 0;
}

