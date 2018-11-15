#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  if(k>2*(n-2)) cout<<"NO"<<endl;
  else
  {
    char l[4][n];
    for(int i=0;i<4;i++) for(int j=0;j<n;j++) l[i][j] = '.';
    if(k==2*(n-2)) {l[1][n/2] = '#';l[2][n/2] = '#'; k-=2;}
    if(k%2==1) {l[1][n/2] = '#';k-=1;}
    int j = 1;
    int i = 1;
    while(k)
    {
      // for(int i=0;i<4;i++){ for(int j=0;j<n;j++) cout<<l[i][j]; cout<<endl;}
      // cout<<"i: "<<i<<" j: "<<j<<endl;
      if(n/2 - i ==0){j++;i=1;continue;}
      if(j>2) break;
      l[j][n/2-i] = '#';
      l[j][n/2 + i] = '#';
      k-=2;
      i++;
    }
    if(j>2) cout<<"NO"<<endl;
    else{
    cout<<"YES"<<endl;
    for(int i=0;i<4;i++){ for(int j=0;j<n;j++) cout<<l[i][j]; cout<<endl;}}
  }
  return 0;
}
