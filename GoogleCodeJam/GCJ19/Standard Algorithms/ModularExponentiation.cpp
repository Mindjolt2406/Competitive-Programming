#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// int l[N][N], m[N][N] ,arr[N][N];

void multiply(ll**l,ll**m,ll**arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                arr[i][j]+=(l[i][k]*m[k][j]);
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
    int n = 3;
    ll **l = new ll*[3];
    for(int i=0;i<3;i++) l[i] = new ll[3];
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) l[i][j] = 0;
    l[0][0] = l[1][1] = l[2][2] = 1;
    pow(l,n,1000000000000000000); // The only thing you need to do apart from making the array to be exponentiated
    for(int i=0;i<3;i++) {for(int j=0;j<3;j++) cout<<l[i][j]<<" ";cout<<endl;}
    return 0;
}
