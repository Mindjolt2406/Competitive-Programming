#include<iostream>
#include<algorithm>
using namespace std;

long find(long*,int,int);
int main()
{
  long n,q;
  cin>>n>>q;
  long l[n];
  for(int i=0;i<n;i++)cin>>l[i];
  while(q--)
  {
    //for(int i=0;i<n;i++)cout<<l[i]<<" ";
    //cout<<endl;
    long a;
    cin>>a;
    if(a==1)
    {
      long b,c;
      cin>>b>>c;
      l[b-1] = c;
    }
    else
    {
      int beg,end;
      cin>>beg>>end;
      cout<<find(l,beg-1,end-1)<<endl;
    }
  }
  return 0;
}

long find(long*l,int beg,int end)
{
  if((end-beg+1)<3) return 0;
  long* c = (long*)calloc(end-beg+1,sizeof(long));
  for(int i=beg;i<end+1;i++)c[i-beg]=l[i];
  sort(c,c+end-beg+1);
  reverse(c,c+end-beg+1);
  int a=c[0],b=c[1];
  int index = -1;
  //for(int i=0;i<end-beg+1;i++)cout<<c[i]<<" ";
  //cout<<endl;
  for(int i=2;i<end-beg+1;i++)
  {
    //cout<<c[i]<<" "<<a<<" "<<b<<endl;
    if(c[i]<=a-b){a = c[i-1];b = c[i];}
    else {index = i;break;}
  }
  if(index==-1)return 0;
  else
  {
    return c[index]+c[index-1]+c[index-2];
  }
}
