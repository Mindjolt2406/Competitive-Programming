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

vector<int> w(1000010),pref(1000010);

int get(int n)
{
  if(n>0) return pref[n]-pref[n-1];
  else return pref[n-1];
}

int find(int n)
{
  int counter = 0;
  for(int i=1;i<=1000000;i++)
  {
    int b = get(i+1);
    int c = w[i];
    if(w[i]>n) counter+=w[i]-n;
  }
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> v(n);
    int count = 0;
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
      if(v[i]<=1000000) w[v[i]]++;
      else count++;
    }

    pref[0] = w[0];
    for(int i=1;i<=1e6;i++) pref[i]+=pref[i-1]+w[i];

    int beg = 0, end = n;
    while(beg<=end)
    {
      int mid = (beg+end)/2;

    }
  }
  return 0;
}

