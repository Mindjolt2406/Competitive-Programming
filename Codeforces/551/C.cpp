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

int main()
{
  __;
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(n%2==1) {cout<<":("<<endl;return 0;}
  if(s[0]==')' || s[n-1]=='(')  {cout<<":("<<endl;return 0;}
  int a = n/2-1, b = n/2-1;
  int sum2 = 0;
  for(int i=1;i<n-1;i++)
  {
    if(s[i]=='?') continue;
    else if(s[i]=='(') {a--;sum2++;}
    else {b--;sum2--;}
  }
  if(s[0]=='?') {s[0] = '(';}
  if(s[n-1]=='?') {s[n-1] = ')';}

  for(int i=1;i<n-1;i++)
  {
    // t(i,a,b);
    if(s[i]=='?' && a) {s[i] = '(';a--;}
    else if(s[i]=='?') {s[i] = ')'; b--;}
  }
  // s[1...n-2];
  // int sum1 = 0;
  // for(int i=1;i<n-1;i++)
  // {
  //   // t(i,sum1,sum2);
  //   if(s[i]=='(') {sum2--;sum1++;}
  //   else if(s[i]==')') {sum2++;sum1--;}
  //   else
  //   {
  //     if(sum1+sum2<=0) 
  //     {
  //       s[i] = '(';
  //       sum1++;
  //     }
  //     else
  //     {
  //       if(sum1>0) 
  //       {
  //         s[i] = ')';
  //         sum1--;
  //       }
  //       else
  //       {
  //         s[i] = '(';
  //         sum1++;
  //       }
  //     }
  //   }
  // }

  int sum3 = 0, boo = 0;
  for(int i=1;i<n-1;i++)
  {
    if(s[i]=='(') sum3++;
    else sum3--;
    if(sum3<0) {boo = 1;break;}
  }

  // t(s);
  if(boo || sum3!=0) cout<<":("<<endl;
  else cout<<s<<endl;
  return 0;
}

