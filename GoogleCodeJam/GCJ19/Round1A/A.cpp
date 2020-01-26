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


vector<int> v25 = {0,8,1,9,2,5,3,6,4,7};
vector<int> v34 = {0,6,8,1,7,9,2,4,10,3,5,11};
vector<int> v35 = {0,7,14,3,6,13,4,11,9,2,5,12,1,10,8};
vector<int> v44 = {0,13,2,4,10,3,5,11,12,7,9,15,6,8,14,1};
bool flag = false;

void f25(int k = 0)
{
  for(int i=0;i<v25.size();i++)
  {
    int a = v25[i] + k;;
    int b = a/5;
    int c = a%5;
    b++;c++;
    // t(a,b,c);
    if(flag) swap(b,c);
    cout<<b<<" "<<c<<endl;
  }
}

void f34(int k = 0)
{
  for(int i=0;i<v34.size();i++)
  {
    int a = v34[i]+k;
    int b = a/4;
    int c = a%4;
    b++;c++;
    if(flag) swap(b,c);
    // t(a,b,c);
    cout<<b<<" "<<c<<endl;
  }
}

void f35(int k = 0)
{
  for(int i=0;i<v35.size();i++)
  {
    int a = v35[i]+k;
    int b = a/5;
    int c = a%5;
    b++;c++;
    if(flag) swap(b,c);
    cout<<b<<" "<<c<<endl;
  }
}

void f44(int k = 0)
{
  for(int i=0;i<v44.size();i++)
  {
    int a = v44[i]+k;
    int b = a/4;
    int c = a%4;
    b++;c++;
    if(flag) swap(b,c);
    cout<<b<<" "<<c<<endl;
  }
}

void f3(int m, int k1=0)
{
  vector<int> ans;
  vector<vector<int> > v(3,vector<int>(m));
  v[0][0] = 1;
  pair<int,int> start = mp(0,0);
  // ans.pu(0);
  int j = 3;
  for(int i=0;i<m;i++)
  { 
    j%=m;
    ans.pu(i);
    ans.pu(j+m);
    ans.pu(i+2*m);
    j++;
  }

  for(int i=0;i<ans.size();i++)
  {
    int a = ans[i]+k1;
    int b = a/m;
    int c = a%m;
    b++;c++;
    if(flag) swap(b,c);
    cout<<b<<" "<<c<<endl;
  }
}

void f2(int m,int k = 0)
{
  vector<int> ans;
  vector<pair<int,int> > v;
  int up = 0, down = up+3;
  while(up<m)
  {
    down%=m;
    // v.pu(mp(up,down));
    ans.pu(up);
    ans.pu(down+m);
    up++;
    down++;
  }

  for(int i=0;i<ans.size();i++)
  {
    int a = ans[i]+k;
    int b = a/m;
    int c = a%m;
    b++;c++;
    if(flag) swap(b,c);
    cout<<b<<" "<<c<<endl;
  }
}



int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    flag = false;
    int n,m;
    cin>>n>>m;
    if(n>m) {swap(n,m); flag = true;}
    if(n==2)
    {
      if(m<=4) cout<<"Case #"<<h<<": IMPOSSIBLE"<<endl;
      else
      {
        cout<<"Case #"<<h<<": POSSIBLE"<<endl;
        f2(m,0);
      }
    }
    else if(n==3)
    {
      if(m<=3) cout<<"Case #"<<h<<": IMPOSSIBLE"<<endl;
      else
      {
        cout<<"Case #"<<h<<": POSSIBLE"<<endl;
        if(m==4)
        {
          f34();
        }
        else
        {
          f3(m,0);
        }
      }
    }
    else if(n==4)
    {
      cout<<"Case #"<<h<<": POSSIBLE"<<endl;
      if(m==4)
      {
        f44();
      }
      else
      {
        f2(m,0);
        f2(m,2*m);
      }
    }
    else
    {
      cout<<"Case #"<<h<<": POSSIBLE"<<endl;
      if(n%2==0)
      {
        for(int i=0;i<n/2;i++)
        {
          f2(m,i*2*m);
        }
      }
      else
      {
        n-=3;
        for(int i=0;i<n/2;i++)
        {
          f2(m,i*2*m);
        }
        f3(m,n*m);
      }
    }
  }
  return 0;
}

