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

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    int max1 = -1;
    int a = -1,b = -1;
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
        // For the subarray [i,j]
        int boo = 0;
        for(int k1=i;k1<=j;k1++)
        {
          int boo1 = 0;
          for(int k2=i;k2<=j;k2++)
          {
            if(k1!=k2)
            {
              // if(j==6 && i==3)t(l[k1],l[k2],k1,k2,gcd(l[k1],l[k2]));
              if(gcd(l[k1],l[k2])!=1) {boo1 = 1;break;}
            }
          }
          if(boo1) {boo = 1;break;}
        }
        if(!boo) {max1 = max(max1,(j-i+1));if(max1==j-i+1) a = i, b = j;}
      }
    }
    if(max1==1) cout<<-1<<endl;
    else {cout<<max1<<endl; t(a,b);}
  }
  return 0;
}

