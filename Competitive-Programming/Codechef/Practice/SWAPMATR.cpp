#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
#define INF 1000000001
using namespace std;

void factor(int n,vector< pair<int,int> > &v)
{
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      v.pu(m(i,n/i));
    }
  }
}

int check(int n,int **l, int a, int b)
{
  cout<<"a: "<<a<<" b: "<<b<<endl;
  if(a>n || b>n) return -1;
  int x1,x2,y1,y2;
  int max1 = 0;
  for(int i=0;i<n-a+1;i++)
  {
    for(int j=0;j<n-b+1;j++)
    {
      x1 = i;y1 = j;
      x2 = i+a-1;y2 = j+b-1;
      if(x1==0 && y1==0) max1 = max(max1,l[x2][y2]);
      else if(x1==0) max1 = max(max1,l[x2][y2] - l[x2][y1-1]);
      else if(y1==0) max1 = max(max1,l[x2][y2] - l[x1-1][y2]);
      else  max1 = max(max1,l[x2][y2] - l[x1-1][y2] - l[x2][y1-1] + l[x1-1][y1-1]);
    }
  }
  return max1;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int max1 = -1;
    int **l = new int*[n];
    for(int i=0;i<n;i++) l[i] = new int[n];
    int sum1 = 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
      cin>>l[i][j];
      if(l[i][j]) sum1++;
    }
    // cout<<"sum1: "<<sum1<<endl;
    if(sum1==0 || sum1==1){ cout<<0<<endl; continue;}
    // Making l a prefix matrix
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==0 && j==0) continue;
        else if(i==0) l[i][j] = l[i][j-1] + l[i][j];
        else if(j==0) l[i][j] = l[i-1][j] + l[i][j];
        else l[i][j] = l[i][j] + l[i-1][j] + l[i][j-1] - l[i-1][j-1];
      }
    }
    vector < pair<int,int> > v;
    factor(sum1,v);
    for(int i=0;i<v.size();i++)
    {
      pair <int,int> p = v[i];
      int a = p.first,b = p.second;
      // cout<<"a: "<<a<<"b: "<<b<<endl;
      max1 = max(max1,check(n,l,a,b));
      max1 = max(max1,check(n,l,b,a));
    }
    if(max1!=-1) cout<<sum1 - max1<<endl;
    else cout<<-1<<endl;
   }
  return 0;
}
