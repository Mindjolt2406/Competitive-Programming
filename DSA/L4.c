#include<stdio.h>
#include<stdlib.h>

int twosum(int*,int,int);
void sort(int* ,int,int);
void merge(int* ,int,int,int);
int main()
{
  int n;
  scanf("%d",&n);
  int* l = (int*)calloc(n,sizeof(int));
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&l[i]);
  }
  int boo = 0;
  for(int i=0;i<n;i++)
  {
    if(twosum(l,l[i],n)==1) {printf("YES\n");boo = 1;break;}
  }
  if (boo==0) printf("NO\n");
  return 0;
}

int twosum(int* l,int k,int n)
{
  int i=0,j=n-1;
  while(i<j)
  {
    if (l[i]+l[j]==k) return 1;
    else if(l[i]+l[j]<k) i++;
    else j--;
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
    printf("%d %d Indices \t",i,j);
    for(int k=i;k<j+1;k++)
    {
      printf("%d ",l[k]);
    }
    printf("\n");
  }
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
