//This program is the brute forced hard coded version to problem XXOR which helped me to remove incorrect approaches to the problem as well as checked my algo when I got it
#include<iostream>
using namespace std;


void find(int*,int*,int,int);
int main()
{
  int l[5] = {9,5,3,11,8};
  for(int i=0;i<5;i++)cout<<l[i]<<" ";
  cout<<endl;
  cout<<"--------"<<endl;
  int c[5] = {l[0]};
  for(int i=1;i<5;i++)c[i]=c[i-1]+l[i];
  for(int i=0;i<5;i++)cout<<l[i]<<" ";
  cout<<endl;
  cout<<"--------"<<endl;
  for(int i=0;i<5;i++)
  {
    for(int j=i;j<5;j++)
    {
      int m[2] = {0};
      find(l,m,i,j);
      cout<<"Maximum: "<<*m<<" X: "<<*(m+1)<<" l: "<<i<<" r: "<<j<<" Cumulatve: "<<((c[j]-c[i])^(*(m+1)))<<endl;
    }
  }
  return 0;
}

void find(int*l, int*m,int beg,int end)
{
  int max = -1,index = -1;
  for(int i=0;i<16;i++)
  {
    int count = 0;
    for(int j=beg;j<=end;j++)
    {
      count = count + (l[j]^i);
    }
    if(count>max){max = count;index = i;}
  }
  m[0] = max;m[1] = index;
}
