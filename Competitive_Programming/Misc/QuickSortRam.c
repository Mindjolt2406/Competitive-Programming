#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int *a, int l, int r);
int partition(int *a, int l, int r);
int randpart(int *a, int l, int r);
int main()
{
  srand(time(0));
  int n;
  scanf("%d", &n);
  int a[10000];
  for(int i=0;i<n;++i)
    a[i]=rand()%10000;
  quicksort(a,0,n-1);
  for(int i=0;i<n;++i)
    printf("%d ", a[i]);
  return 0;
}
void quicksort(int *a, int l, int r)
{
  int q;
  if(l<r)
  {
    q=randpart(a,l,r);
    quicksort(a,l,q-1);
    quicksort(a,q+1,r);
  }
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
