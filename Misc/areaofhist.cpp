#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int*,int);
void nextleast(int*,int,int*);
void print(int*,int);
int main() 
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  int left[n];
  int right[n];
  nextleast(l,n,left);
  reverse(l,n);
  nextleast(l,n,right);
  //reverse(right,n);
  //Chucking the -1s
  //print(right,n);
  for(int i=0;i<n;i++)
  {
    if (left[i]==-1)left[i] = n;
    if (right[i]==-1)right[i] = -1;
    else(right[i] = n-1-right[i]);
    right[i]+=1;
  }
  
  reverse(right,n);
  int max = 0;
  int k = 0;
  for(int i=0;i<n;i++)
  {
    k = l[n-1-i]*(left[i]-right[i]);
    if(k>max)max = k;
  }
  //print(left,n);
  //print(right,n);
  cout<<max;
  return 0;
}
void reverse(int*l,int n)
{
  int *m = (int *) calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    m[i] = l[n-1-i];
  }
  for(int i=0;i<n;i++)
  {
    l[i] = m[i];
  }
  free(m);
}

void nextleast(int*l,int n,int* finally)
{
  int *m = (int *) calloc(n,sizeof(int));
  int index = -1;
  //int *finally = (int *) calloc(n,sizeof(int));
  int *mindex = (int *) calloc(n,sizeof(int));
  for(int i=0;i<n;i++) finally[i] = -1;
  for(int i=0;i<n;i++)
  {
    if(index==-1){index+=1;m[index] = l[i];mindex[index] = i;}
    else if(m[index]<=l[i]) {index+=1;m[index] = l[i];mindex[index] = i;}
    else if(m[index]>l[i])
    {
      while (m[index]>l[i]&&index>-1) {finally[mindex[index]] = i;m[index] = 0;mindex[mindex[index]] = -1;index-=1;}
      index+=1;
      m[index] = l[i];
      mindex[index] = i;
    }
  }
}

void print(int*l,int n)
{
  for(int i=0;i<n;i++) cout<<l[i]<<" ";
  cout<<"\n";
}
