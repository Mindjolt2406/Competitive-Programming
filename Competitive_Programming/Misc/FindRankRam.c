#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int findrank(int *a, int l, int r, int x);
int partition(int *a, int l, int r);
int randpart(int *a, int l, int r);
int main()
{
  srand(time(0));
  int n,x;
  scanf("%d %d", &n, &x);
  int a[10000];
  for(int i=0;i<n;++i)
    a[i]=rand()%10000;
  printf("\n");
  for(int i=0;i<n;++i)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  int z=findrank(a,0,n-1,x);
  printf("%d ", z);
  return 0;
}
int findrank(int *a, int l, int r, int x)
{
  int q;
  if(l<r)
  {
    q=randpart(a,l,r);
    if(r-q+1==x) return a[q];
    else if(r-q+1<x)
    findrank(a,l,q-1,x-(r-q+1));
    else if(r-q+1>x) findrank(a,q+1,r,x);
  }
  else return a[r];
}
int partition(int *a, int l, int r)
{
  int x=a[r];
  int i=l-1;
  for(int j=l;j<r;++j)
  {
    if(a[j]<x)
    {
      i++;
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  int temp=a[i+1];
  a[i+1]=a[r];
  a[r]=temp;
  return i+1;
}
int randpart(int *a, int l, int r)
{
  int q=rand()%(r-l);
  q+=l;
  int temp=a[q];
  a[q]=a[r];
  a[r]=temp;
  return partition(a,l,r);
}
