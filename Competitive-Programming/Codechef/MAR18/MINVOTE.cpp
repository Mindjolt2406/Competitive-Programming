#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long l[n];
    for(int i=0;i<n;i++)cin>>l[i];
    long*a = (long*)calloc(n,sizeof(long));//Front cumulative and behind cumulative sums
    long*b = (long*)calloc(n,sizeof(long));
    long*c = (long*)calloc(n,sizeof(long));//The final +1 -1 array whose cumulative will be taken
    a[0] = l[0];
    b[n-1] = l[n-1];
    for(int i=1;i<n;i++)
    {
      a[i] = a[i-1]+l[i];
      b[n-1-i] = b[n-i]+l[n-1-i];
    }
    for(int i=0;i<n;i++)
    {
      int beg = i;
      int end = n-1;
      a[i]+=l[i];
      int index = -1;
      long k = a[i];
      while(beg<=end)
      {
        int mid = (beg+end)/2;
        if(mid==i && k<a[mid+1]){index = mid;break;}//Edge case 1(Literally)
        else if(mid==n-1 && k>=a[mid]){index = mid;break;}//Edge case 2
        else if(k>=a[mid]&&k<a[mid+1]){index = mid;break;}//Real
        else if(k<a[mid])end = mid-1;
        else if(k>=a[mid]&&k>=a[mid+1])beg = mid+1;
      }
      if(index<n-2)c[index+2]--;
      a[i]-=l[i];

      beg = 0;end = i;
      b[i]+=l[i];
      index = -1;
      k = b[i];
      while(beg<=end)
      {
        int mid = (beg+end)/2;
        if(mid==0)
        {
          if(k>=b[mid]){index = 0;break;}
          else beg = mid+1;
        }
        else if(mid==i && k<b[mid-1]){index = i;break;}
        else if(k>=b[mid]&&k<b[mid-1]){index = mid;break;}
        else if(k>b[mid])end = mid-1;
        else if(k<=b[mid]) beg = mid+1;
      }
      if(index>0)c[index-1]++;
      else c[index]++;
      b[i]-=l[i];
    }
    int count = c[0];
    for(int i=1;i<n;i++)c[i]+=c[i-1];
    for(int i=0;i<n;i++)cout<<c[i]-1<<" ";
    cout<<endl;
  }
  return 0;
}
