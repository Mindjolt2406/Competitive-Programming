#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long int l[21];
  int m[21];
  l[0] = 1;l[1] = 1;
  m[0] = 0;m[1] = 1;
  for(int i=2;i<21;i++) {l[i] = i*l[i-1];m[i] = 2*m[i-1]+i-2;}
  // for(int i=1;i<7;i++) cout<<l[i]+m[i]<<endl;
  cin>>n;
  cout<<m[n]+l[n]<<endl;
}
