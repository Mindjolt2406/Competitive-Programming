#include<stdio.h>
#include<stdlib.h>
#define INF 100000000
int main()
{
  int n;
  scanf("%d",&n);
  int l[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&l[i]);
  }
  int *a = calloc(sizeof(int),n);
  int *b = calloc(sizeof(int),n);
  int maxi=l[n-1],mini=l[0];
  for(int i=n-1;i>=0;i--)
  {
    if (maxi<l[i]) maxi = l[i];
    a[i] = maxi;
    if(l[n-1-i]<mini) mini = l[n-1-i];
    b[n-1-i] = mini;
  }
  int max1 = 0;
  for(int i=0;i<n;i++)
  {
    if(a[i]-b[i]>max1)max1 = a[i]-b[i];
  }
  printf("%d\n",max1);
  return 0;
}
