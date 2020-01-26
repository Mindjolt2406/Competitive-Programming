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

// int l[N][N], m[N][N] ,arr[N][N];

void multiply(ll**l,ll**m,ll**arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                arr[i][j]+=(l[i][k]*m[k][j])%MOD;
                arr[i][j]%=MOD;
            }
        }
    }
}

void zero(ll **l, int n)
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) l[i][j] = 0;
}

void copy(ll**arr,ll**m,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j] = arr[i][j];
        }
    }
    zero(arr,n);
}


void pow(ll**l,int n,ll y)
{
    
    if(y==0) 
    {
      zero(l,n);
      for(int i=0;i<n;i++) l[i][i] = 1;
      return;
    }
    y--;
    ll**m = new ll*[n];
    for(int i=0;i<n;i++) m[i] = new ll[n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) m[i][j] = l[i][j];
    ll**arr = new ll*[n];
    for(int i=0;i<n;i++) arr[i] = new ll[n];
    zero(arr,n);
    while(y)
    {
        if(y&1)
        {
            multiply(l,m,arr,n);
            copy(arr,l,n);
        }

        multiply(m,m,arr,n);
        copy(arr,m,n);
        y>>=1;
    }
}


int main()
{
  __;
  ll n,m;
  cin>>n>>m;
  ll **l = new ll*[m+1];
  for(int i=0;i<=m;i++) l[i] = new ll[m+1];

  for(int i=0;i<=m;i++) for(int j=0;j<=m;j++) l[i][j] = 0;

  l[0][0] = 1;
  l[0][m-1] = 1;
  for(int i=0;i<m;i++) l[i+1][i] = 1; 

  if(n<m) cout<<1<<endl;
  else if(n==m) cout<<2<<endl;
  else
  {
    // for(int i=0;i<=m;i++)
    // {
    //   for(int j=0;j<=m;j++)
    //   {
    //     cout<<l[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    pow(l,m+1,n-m);
    ll sum1 = 0;
    for(int i=0;i<m;i++) {sum1+=l[0][i];sum1%=MOD;}
    sum1+=l[0][0];sum1%=MOD;
    cout<<sum1<<endl;
    // for(int i=0;i<=m;i++)
    // {
    //   for(int j=0;j<=m;j++)
    //   {
    //     cout<<l[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
  }
  return 0;
}

