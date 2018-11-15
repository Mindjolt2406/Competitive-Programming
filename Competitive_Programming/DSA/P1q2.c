#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int l[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&l[i]);
  }
  int beg=0,end=n-1,mid = n/2;
  while(1)
  {
    int k = mid;
    if (mid==0) {printf("0\n"); break;}
    else if(mid==n-1) {printf("%d\n",n-1);break;}
    else
    {
      if (l[mid]>=l[mid+1]&&l[mid-1]<=l[mid])
      {
        //printf("%d %d %d",l[mid-1],l[mid],l[mid+1]);
        printf("%d\n",mid);
        break;
      }
      else if(l[mid]<=l[mid+1]&&l[mid-1]<=l[mid])
      {
        beg = mid;
        mid = (beg+end)/2;
      }
      else
      {
        end = mid;
        mid = (beg+end)/2;
      }
    }
    if (k==mid)mid+=1;
  }
  return 0;
}
