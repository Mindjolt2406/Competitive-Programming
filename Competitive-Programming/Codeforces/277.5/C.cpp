#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,sum1;
  cin>>n>>sum1;
  int c = sum1;
  if((sum1==0 && n>1) || sum1/9.0>n) {cout<<-1<<" "<<-1<<endl;return 0;}
  else if(sum1==0 && n==1){cout<<0<<" "<<0<<endl;return 0;}
  // if(length>3 || (pow(10,length)-1>= sum && pow(10,length-1)<sum))
  // {
  //   while(length)
  //   {
  //
  //   }
  // }
  int* l = (int*)calloc(n,sizeof(int));// Largest
  int* m = (int*)calloc(n,sizeof(int));// Smallest
  int i = n-1;
  while(i>=0 && sum1>9)
  {
    m[i] = 9;
    i--;
    sum1-=9;
  }
  if(sum1>9) cout<<-1<<" ";
  else
  {
    if(i==0) m[0] = sum1;
    else if(sum1==1) m[0] = 1;
    else
    {
      m[i] = sum1-1;
      m[0] = 1;
    }
    for(int i=0;i<n;i++)cout<<m[i];cout<<" ";
  }
  sum1 = c;
  i=0;
  while(i<n && sum1>9)
  {
    l[i] = 9;
    i++;
    sum1-=9;
  }
  if(sum1>9) cout<<-1<<endl;
  else
  {
    l[i] = sum1;
    for(int i=0;i<n;i++) cout<<l[i];cout<<endl;
  }
  return 0;
}
