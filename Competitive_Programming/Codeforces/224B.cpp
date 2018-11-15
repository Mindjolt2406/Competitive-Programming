#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  int left=0,right=0;
  int f[100001] = {0};
  for(int i=0;i<n;i++)
  {
    f[l[i]]+=1;
  }
  int counter=0;
  for(int i=0;i<100001;i++)
  {
    if(f[i]!=0)counter+=1;
  }
  if(counter<k){cout<<"-1 -1"<<endl;return 0;}
  int m[100001] = {0};
  m[l[0]]+=1;
  int count = 1;
  for (int i=1;i<n;i++)
  {
    right+=1;
    if(m[l[i]])
    {
      left+=1;
      m[l[i]]-=1;
    }
    else count+=1;
    if(count>=k)
    {
      //cout<<left<<" "<<right<<endl;
      int c = right;
      int boo=0;
      while(l[right-1]==l[c]){right-=1;boo=1;}
      if(boo)right+=1;
      c = left;
      boo = 0;
      while(l[left+1]==l[c]){left+=1;boo=1;}
      if(boo)left-=1;
      cout<<left+1<<" "<<right+1<<endl;
      return 0;
    }
  }
}
