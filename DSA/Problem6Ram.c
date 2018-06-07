#include<stdio.h>
#include<stdlib.h>
int findrank(int *a, int l, int r, int x);
int partition(int *a, int l, int r);
int randpart(int *a, int l, int r);
int main()
{
  FILE *fp;
  long n,k;
  scanf("%ld %ld", &n, &k);
  int *a=(int*)malloc(2*k*sizeof(int));
  fp=fopen("input.txt","r");
  for(int i=0;i<2*k;++i)
  fscanf(fp,"%d",&a[i]);
  long freq=(n-2*k)/k;
  int median,temp,counter=1;
  for(int i=0;i<freq;i++)
  {
    median=findrank(a,0,2*k-1,k);
    for(int j=0;j<2*k;++j)
    {
      if(a[j]>median)
      {
        fscanf(fp,"%d",&temp);
        a[j]=temp;
      }
    }
  }
  median=findrank(a,0,2*k-1,k);
  int *ans=(int*)malloc(k*sizeof(int)+2); //For Extra space
  int anspos=0;
  for(int j=0;j<2*k;++j)
  {
    if(a[j]<=median)
    {
      ans[anspos++]=a[j];
      // printf("LOL %d\n",counter++);
    }
  }
  for(int i=0;i<k;++i)
  printf("%d ", ans[i]);
  printf("\n");
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
