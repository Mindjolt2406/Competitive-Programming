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
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int n,k;
  sc(n);sc(k);
  if(k==1) {cout<<n<<endl;return 0;}
  vector<int> v;
  int c = n,c1 = k-1;
  int prod = n;
  for(int i=2;i<=c;i++)
  {
    if(n%i==0)
    {
      while(n%i==0 && c1 && prod>1)
      {
        v.pu(i);
        n/=i;
        c1--;
      }
    }
    if(c1==0 && n!=1) 
    {
      for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
      cout<<n<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}

