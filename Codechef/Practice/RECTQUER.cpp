#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n][n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>l[i][j];
  int arr[n][n][11];
  arr[0][0][l[0][0]]++;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      // Initialising
      for(int k = 0;k<11;k++) arr[i][j][k] = 0;
      // Taking care of edges and corners
      if(i==0 && j==0) arr[0][0][l[0][0]]++;
      else if(i==0)
      {
        for(int k=0;k<11;k++) arr[i][j][k] = arr[i][j-1][k];
        arr[i][j][l[i][j]]++;
      }
      else if(j==0)
      {
        for(int k=0;k<11;k++) arr[i][j][k] = arr[i-1][j][k];
        arr[i][j][l[i][j]]++;
      }
      else
      {
        for(int k=0;k<11;k++)
        {
          arr[i][j][k] = arr[i-1][j][k] + arr[i][j-1][k] - arr[i-1][j-1][k];
        }
        arr[i][j][l[i][j]]++;
      }
    }
  }
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     cout<<"i: "<<i<<" j: "<<j<<" l[i][j]: "<<l[i][j]<<" - ";
  //     for(int k=1;k<11;k++) cout<<arr[i][j][k]<<" ";
  //     cout<<endl;
  //   }
  // }
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1-=1;y1-=1;x2-=1;y2-=1;
    int m[11];
    for(int k = 0;k<11;k++)
    {
      if(x1==0 && y1==0) m[k] = arr[x2][y2][k];
      else if(x1==0) m[k] = arr[x2][y2][k] - arr[x2][y1-1][k];
      else if(y1==0) m[k] = arr[x2][y2][k] - arr[x1-1][y2][k];
      else m[k] = arr[x2][y2][k] - arr[x1-1][y2][k] - arr[x2][y1-1][k] + arr[x1-1][y1-1][k];
    }
    int count = 0;
    for(int k=1;k<11;k++) if(m[k]) count++;
    cout<<count<<endl;
  }
}
