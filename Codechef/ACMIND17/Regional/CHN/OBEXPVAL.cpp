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
    int n,k; // k is E
    sc(n);sc(k);
    vector<int> v(n);
    for(int i=0;i<n;i++) sc(v[i]);

    int cas1 = 0,cas2 = 1,cas3 = 1,index = -1,min1 = INF,max1 = -1,minindex = -1,maxindex = -1;
    // Case 1
    for(int i=0;i<n;i++)
    {
      if(k==v[i]) {cas1 = 1;index = i;}
      if(k<=v[i]) {cas2 = 0;}
      if(k>=v[i]) {cas3 = 0;} 
      if(v[i]<min1)
      {
        min1 = v[i];
        minindex = i;
      }
      if(v[i]>max1)
      {
        max1 = v[i];
        maxindex = i;
      } 
    }

    if(cas1)
    {
      for(int i=0;i<n;i++)
      {
        if(i!=index) cout<<0<<" ";
        else cout<<1<<" ";
      }
      cout<<endl;
      continue;
    }

    if(cas2 || cas3)
    {
      cout<<-1<<endl;
      continue;
    }

    cout<<setprecision(12);
    int x1 = max1, x2= min1;
    for(int i=0;i<n;i++)
    {
      if(i==minindex)
      {
        cout<<(x1 - (ld)k)/(x1-x2)<<" ";      
      }
      else if(i==maxindex)
      {
        cout<<((ld)k - x2)/(x1-x2)<<" ";
      }
      else cout<<0<<" ";
    }
    cout<<endl;
  } 
  return 0;
}

