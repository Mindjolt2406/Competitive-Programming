#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void MM(long long int l[][2],long long int m[][2],long long int arr[][2],long long int p)
{
  for(long long int i=0;i<2;i++)
  {
    for(long long int j=0;j<2;j++)
    {
      for(long long int k=0;k<2;k++)
      {
        arr[i][j] += (l[i][k]*m[k][j])%p;
      }
    }
  }
}

void copy1(long long int l[][2],long long int m[][2])
{
  for(long long int i=0;i<2;i++)
  {
    for (long long int j = 0; j < 2; j++)
    {
      l[i][j] = m[i][j];
    }
  }
}

long long int fib(long long int m[][2], long long int*a, long long int*b,long long int j)
{
  long long int k = ((m[1][0]*b[0])%MOD + (m[1][1]*a[j])%MOD)%MOD;
  return k;
}

int main()
{
  long long int t;
  cin>>t;
  while(t--)
  {
    long long int d,e;
    cin>>d>>e;
    for(long long int i=0;i<d;i++) cin>>a[i];
    for(long long int i=0;i<d;i++) cin>>b[i];
    long long int a[d],b[d];
    long long int f = e;
    long long int l[2][2] = {{1,1},{1,0}};
    long long int id[2][2] = {{1,0},{0,1}};
    long long int m[2][2] = {{1,0},{0,1}};
    long long int arr[2][2] = {{0}};
    f-=1;
    // cout<<"f: "<<f<<endl;
    while(f)
    {
      if ((f)%2==1)
      {
        MM(l,m,arr,MOD);
        copy1(m,arr);
        for(long long int i=0;i<2;i++) for(long long int j=0;j<2;j++) arr[i][j] = 0;
      }
      f/=2;
      MM(l,l,arr,MOD);
      copy1(l,arr);
      for(long long int i=0;i<2;i++) for(long long int j=0;j<2;j++) arr[i][j] = 0;
    }
    long long int c = (m[1][0])%MOD;
    long long int dif = 0;
    for(long long int i=0;i<d;i++) {dif+=(b[i]-b[0])%MOD;}
    dif = (dif+MOD)%MOD;
    c = (c*dif)%MOD;
    long long int res = 0;
    long long int k = ((m[1][0]*b[0])%MOD + (m[1][1]*a[0])%MOD)%MOD;
    for(long long int i=0;i<d;i++)
    {
      res+= (d*fib(m,a,b,i))%MOD + c;
      res = (res+MOD)%MOD;
    }
    cout<<res<<endl;
  }
  return 0;
}
