#include<stdio.h>
#include<stdlib.h>

void sort(int* ,int,int);
void merge(int* ,int,int,int);
long long int count = 0;
int main()
{
  int t;
  scanf("%d",&t);
  char s[5];
  for(int _=0;_<t;_++)
  {
    int n;
    count = 0;
    // scanf("%s",s);
    scanf("%d",&n);
    int l[n];
    for(int i=0;i<n;i++)
    {
      scanf("%d",&l[i]);
    }
    //int **p;
    //*p = &(*l);
    //printf("%d",l[0]);
    sort(l,0,n-1);
    // for(int i=0;i<n;i++)
    // {
    //   printf("%d ",l[i]);
    // }
    // printf("\n");
    printf("%lld\n",count);
  }
  return 0;
}

void sort(int *l,int i,int j)
{
  //int *l = *p;
  if(i<j)
  {
    int c = (i+j)/2;
    sort(l,i,c);
    sort(l,c+1,j);
    merge(l,i,c,j);
  }
    // printf("%d %d Indices \t",i,j);
    // for(int k=i;k<j+1;k++)
    // {
    //   printf("%d ",l[k]);
    // }
    // printf("\n");
    // printf("%lld\n",count);
}

void merge(int*l,int i,int c,int j)
{
  //int *l = *p;
  int*m = (int*)calloc((j-i+1),sizeof(int));
  int x=i,y=c+1;
  int k=0;
  while(k<j-i+1)
  {
    if(y==j+1)
    {
      while(x<=c)
      {
        m[k] = l[x];
        count+=(y-c-1);
        x++;
        k++;
      }
      continue;
    }
    else if(x==c+1)
    {
      while(y<=j)
      {
        m[k] = l[y];
        y++;
        k++;
      }
      continue;
    }
    else if(l[x]<l[y])
    {
      m[k] = l[x];
      count+=(y-c-1);
      x++;
    }
    else if(l[y]<=l[x])
    {
      m[k] = l[y];
      y++;
    }
    k++;
  }
  //Copying
  for(int k=0;k<j-i+1;k++)
  {
    l[k+i] = m[k];
  }
}
