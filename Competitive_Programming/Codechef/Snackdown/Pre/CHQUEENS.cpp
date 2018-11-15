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

using namespace std;

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int x,y,n,m;
    sc(n);sc(m);sc(x);sc(y);
    x--;y--;
    ll count = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(x==i && y==j) continue;
        if(x==i || y==j || abs(i-x)==abs(j-y))
        {
          int a = 0;
          if(x==i)
          {
            if(y>j) {a+=m-y-1;}
            else a+=y; 
          }
          else if(y==j)
          {
            if(x>i) a+=n-x-1;
            else a+=x;
          }
          else
          {
            if(x>i && y>j) a = min(n-x-1,m-y-1);
            else if(x>i && y<j) a = min(n-x-1,y);
            else if(x<i && y>j) a = min(x,m-y-1);
            else if(x<i && y<j) a = min(x,y);
          }
          count+=a;
          ll count1 = 0;
          count1+=(i)+(j)+(n-i-1)+(m-j-1);
          count1+=min(i,j)+min(j,n-i-1)+min(n-i-1,m-j-1)+min(m-j-1,i);
          // cout<<"i: "<<i<<" j: "<<j<<" a: "<<a<<" count1: "<<count1<<endl;
          count+= n*m - 1 - count1;
        }
        else
        {
          ll count1 = 0;
          count1+=(i)+(j)+(n-i-1)+(m-j-1);
          count1+=min(i,j)+min(j,n-i-1)+min(n-i-1,m-j-1)+min(m-j-1,i);
          count+= n*m - 2 - count1;
        }
        // cout<<"i: "<<i<<" j: "<<j<<" count: "<<count<<endl;
      }
    }
    printf("%lld\n",count);
  }
  return 0;
}

/*
1
3 3 2 2

*/
