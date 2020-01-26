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

vector<int> v[10005] = {};
int sum1[10005] = {0};

int main()
{
  __;
  for(int i=1;i<=10000;i++)
  {
    for(int j=1;j<=sqrt(i);j++)
    {
      if(i%j==0) {v[i].pu(j); if(j!=i/j && j!=1) v[i].pu(i/j);}
    }
  }

  sum1[0] = -1;
  for(int i=1;i<=10000;i++)
  {
    int counter = 0;
    for(int j=0;j<v[i].size();j++) 
    {
      counter+=v[i][j];
    }
    sum1[i] = counter;
  }

  ll sum2 = 0;
  for(int i=1;i<=10000;i++)
  {
    if(sum1[i]<i)
    {
      int a = sum1[i];
      int b = sum1[a];
      if(b==i)
      {
        t(i,a,b);
        sum2+=i;
        sum2+=a;
      }
    }
  }
  cout<<sum2<<endl;

  return 0;
}

