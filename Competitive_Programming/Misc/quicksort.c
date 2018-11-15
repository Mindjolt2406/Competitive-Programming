#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void quicksort(int*,int,int);
void swap(int*,int,int);
int partition(int* ,int,int,int);
int main()
{
  srand(time(0));
  int n;
  scanf("%d",&n);
  int l[n];
  for (int i=0;i<n;i++)
  {
    scanf("%d",&l[i]);
  }
  quicksort(l,0,n-1);
  for(int i=0;i<n;i++)
  {
    printf("%d ",l[i]);
  }
  printf("\n");
  return 0;
}

void quicksort(int* l,int i,int j)
{
  int pivot = 0;
  if (j-i==1)
  {
    if(l[i]<l[j]) swap(l,i,j);
  }
  else if(i<j)
  {
    pivot = (rand()%(j-i+1))+i;
    for(int k=i;k<j+1;k++)
    {
      printf("%d ",l[k]);
    }
    printf("\n");
    printf("%d =i, %d =j,%d = pivot\n",i,j,pivot);
    int c;
    c = partition(l,i,j,pivot);
    for(int k=i;k<j+1;k++)
    {
      printf("%d ",l[k]);
    }
    printf("\n");
    printf("c = %d",c);
    printf("----------------\n");
    quicksort(l,i,c);
    quicksort(l,c+1,j);
   //int *p=&l[i],*q=&j;
  }
  
 //return;
}

int partition(int* l, int i,int j,int pivot)
{
  int a=i,b=j;
  while(a<=b)
  {
    while(l[a]<l[pivot]) a++;
    while(l[b]>l[pivot]) b--;
    
    /*if(((l[a]>=l[pivot] && l[b]<l[pivot])||(l[a]>l[pivot]&&l[b]<=l[pivot]))l[a]>=l[pivot] && l[b]<=l[pivot] && a<b)
    {
      if (pivot==a) {pivot = b;a--;swap(l,a+1,b);}
      else if (pivot==b) {pivot = a;b++;swap(l,a,b-1);}
      else swap(l,a,b);
      a++;b--;
    }*/
    if(a<b)
    {
      printf("%d %d a b\n",a,b);
      swap(l,a,b);
      a++;
      b--;
    }
  }
  return MIN(a,b);
}

void swap(int *l,int a,int b)
{
  int temp = l[a];
  l[a] = l[b];
  l[b] = temp;
}
