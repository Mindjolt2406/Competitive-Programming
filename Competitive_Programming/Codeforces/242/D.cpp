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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int** declare(int n,int m)
{
  int**l = new int*[n];
  for(int i=0;i<n;i++) l[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) l[i][j] = 0;
  return l;
}

int find(int x1,int y1,int x2,int y2)
{
  
}

int main()
{
  int n,m,t;
  sc(n);sc(m);sc(t);
  int**l = declare(n,m);
  int** up = declare(n,m);
  int** down = declare(n,m);
  int** left = declare(n,m);
  int** right = declare(n,m);
  int tdown,tup, td;
  sc(td);sc(tup);sc(tdown);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) sc(l[i][j]);
  // Up
  for(int j=0;j<m;j++)
  {
    int sum1 = 0;
    up[n-1][j] = 0;
    for(int i=n-2;i>=0;i--)
    {
      if(l[i][j]>l[i+1][j]) sum1+=tup;
      else if(l[i][j]<l[i+1][j]) sum1+=tdown;
      else sum1+=td;
      up[i][j] = sum1;
    }
  }
  // Down
  for(int j=0;j<m;j++)
  {
    int sum1 = 0;
    down[0][j] = 0;
    for(int i=1;i<n;i++)
    {
      if(l[i][j]>l[i-1][j]) sum1+=tup;
      else if(l[i][j]<l[i-1][j]) sum1+=tdown;
      else sum1+=td;
      down[i][j] = sum1;
    }
  }
  // Right
  for(int i=0;i<n;i++)
  {
    int sum1 = 0;
    right[i][0] = 0;
    for(int j=1;j<m;j++)
    {
      if(l[i][j]>l[i][j-1]) sum1+=tup;
      else if(l[i][j]<l[i][j-1]) sum1+=tdown;
      else sum1+=td;
      right[i][j] = sum1;
    }
  }
  // Left
  for(int i=0;i<n;i++)
  {
    int sum1 = 0;
    left[i][m-1] = 0;
    for(int j=m-2;j>=0;j--)
    {
      if(l[i][j]>l[i][j+1]) sum1+=tup;
      else if(l[i][j]<l[i][j+1]) sum1+=tdown;
      else sum1+=td;
      left[i][j] = sum1;
    }
  }

  int x1 = -1,y1 = -1,x2 = -1,y2 = -1;
  // 1 element
  int min1 = INF;
  for(int i=1;i<n-1;i++)
  {
    for(int j=1;j<m-1;j++)
    { 
      int c = 0;
      c += right[i-1][j+1] - right[i-1][j-1];
      c += down[i+1][j+1] - down[i-1][j+1];
      c += left[i+1][j-1] - left[i+1][j+1];
      c += up[i-1][j-1] - up[i-1][j+1];
      if(abs(t-c)<min1)
      {
        x1 = i; y1 = j; x2 = i+2;y2 = j+2;
        cout<<"1x1"<<endl;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        cout<<"min1: "<<abs(t-c)<<endl;
      }
      min1 = min(min1,abs(t-c));
    }
  }
  // 1x2
  for(int i=1;i<n-1;i++)
  {
    for(int j=1;j<m-2;j++)
    {
      int c = 0;
      c += right[i-1][j+2] - right[i-1][j-1];
      c += down[i+1][j+2] - down[i-1][j+2];
      c += left[i+1][j-1] - left[i+1][j+2];
      c += up[i-1][j-1] - up[i-1][j+1];
      if(abs(t-c)<min1)
      {
        x1 = i; y1 = j; x2 = i+2;y2 = j+3;
        cout<<"1x2"<<endl;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        cout<<"min1: "<<abs(t-c)<<endl;
      }
      min1 = min(min1,abs(t-c));
    }
  }

  // 1x3
  for(int i=1;i<n-1;i++)
  {
    for(int j=1;j<m-3;j++)
    {
      int c = 0;
      c += right[i-1][j+3] - right[i-1][j-1];
      c += down[i+1][j+3] - down[i-1][j+3];
      c += left[i+1][j-1] - left[i+1][j+3];
      c += up[i-1][j-1] - up[i-1][j+1];
      if(abs(t-c)<min1)
      {
        x1 = i; y1 = j; x2 = i+2;y2 = j+4;
        cout<<"1x3"<<endl;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        cout<<"min1: "<<abs(t-c)<<endl;
      }
      min1 = min(min1,abs(t-c));
    }
  }

  // 2x1
  for(int i=1;i<n-2;i++)
  {
    for(int j=1;j<m-1;j++)
    {
      int c = 0;
      c += right[i-1][j+1] - right[i-1][j-1];
      c += down[i+2][j+1] - down[i-1][j+1];
      c += left[i+2][j-1] - left[i+2][j+1];
      c += up[i-1][j-1] - up[i-1][j+2];
      if(abs(t-c)<min1)
      {
        x1 = i; y1 = j; x2 = i+3;y2 = j+2;
        cout<<"2x1"<<endl;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        cout<<"min1: "<<abs(t-c)<<endl;
      }
      min1 = min(min1,abs(t-c));
    }
  }

  // 3x1
  for(int i=1;i<n-3;i++)
  {
    for(int j=1;j<m-1;j++)
    {
      int c = 0;
      c += right[i-1][j+1] - right[i-1][j-1];
      c += down[i+3][j+1] - down[i-1][j+1];
      c += left[i+3][j-1] - left[i+3][j+1];
      c += up[i-1][j-1] - up[i-1][j+3];
      if(abs(t-c)<min1)
      {
        x1 = i; y1 = j; x2 = i+4;y2 = j+2;
        cout<<"3x1"<<endl;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        cout<<"min1: "<<abs(t-c)<<endl;
      }
      min1 = min(min1,abs(t-c));
    }
  }
  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
  // cout<<min1<<endl;
  return 0;
}
