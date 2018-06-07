#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long int max(long long int a,long long int b)
{
  return (a>b) ? a : b;
}

long long int factor(long long int n,long long int *p)
{
  long long int count = 0;
  for(long long int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      p[count] = i;
      p[count+1] = n/i;
      count+=2;
    }
  }
  p = (long long int*)realloc(p,count);
  // for(long long int i=0;i<count;i++) prlong long intf("%d ",p[i]);
  // prlong long intf("\n");
  return count;
}

long long int check(long long int n,long long int **l, long long int a, long long int b)
{
  // cout<<"a: "<<a<<" b: "<<b<<endl;
  if(a>n || b>n) return -1;
  long long int x1,x2,y1,y2;
  long long int max1 = 0;
  for(long long int i=0;i<n-a+1;i++)
  {
    for(long long int j=0;j<n-b+1;j++)
    {
      x1 = i;y1 = j;
      x2 = i+a-1;y2 = j+b-1;
      if(x1==0 && y1==0) max1 = max(max1,l[x2][y2]);
      else if(x1==0) max1 = max(max1,l[x2][y2] - l[x2][y1-1]);
      else if(y1==0) max1 = max(max1,l[x2][y2] - l[x1-1][y2]);
      else  max1 = max(max1,l[x2][y2] - l[x1-1][y2] - l[x2][y1-1] + l[x1-1][y1-1]);
    }
  }
  return max1;
}

int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
  {
    long long int n;
    scanf("%lld",&n);
    long long int max1 = -1;
    long long int sum1 = 0;
    long long int **l = (long long int**)calloc(n,sizeof(long long int*));
    for(long long int i=0;i<n;i++) l[i] = (long long int*)calloc(n,sizeof(long long int*));
    for(long long int i=0;i<n;i++) for(long long int j=0;j<n;j++)
    {
      scanf("%lld",&l[i][j]);
      if(l[i][j]) sum1++;
    }
    // cout<<"sum1: "<<sum1<<endl;
    if(sum1==0 || sum1==1){ printf("0\n"); continue;}
    // Making l a prefix matrix
    for(long long int i=0;i<n;i++)
    {
      for(long long int j=0;j<n;j++)
      {
        if(i==0 && j==0) continue;
        else if(i==0) l[i][j] = l[i][j-1] + l[i][j];
        else if(j==0) l[i][j] = l[i-1][j] + l[i][j];
        else l[i][j] = l[i][j] + l[i-1][j] + l[i][j-1] - l[i-1][j-1];
      }
    }
    long long int *p = (long long int*)calloc(sum1,sizeof(long long int));
    long long int k = factor(sum1,p);
    for(long long int i=0;i<k;i+=2)
    {
      long long int a = p[i],b = p[i+1];
      // cout<<"a: "<<a<<"b: "<<b<<endl;
      max1 = max(max1,check(n,l,a,b));
      max1 = max(max1,check(n,l,b,a));
    }
    if(max1!=-1) printf("%lld\n",sum1-max1);
    else printf("-1\n");
   }
  return 0;
}
