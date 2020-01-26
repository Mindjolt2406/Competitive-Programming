#include<iostream>
#include<algorithm>
using namespace std;


int recur(int*,int*,int,int);
int main()
{
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  int m[3] = {a,b,c};
  sort(m,m+3);
  int l[4001] = {0};
  int d = recur(l,m,n,0);
  int count = 0;
  /*for(int i=0;i<10;i++)
  {
    cout<<l[i]<<" ";
  }*/
  //cout<<endl;
  for(int i=0;i<4001;i++)
  {
    if (l[i]==1) count+=1;
  }
  cout<<l[0]<<endl;
  return 0;
}

int recur(int *l,int *m,int n,int count)
{
  if(n==0){l[0] = max(count,l[0]);return 1;}
  else if(n<0)return -1;
  for(int i=0;i<3;i++)
  {
    //cout<<n<<" "<<n-m[i]<<" "<<count<<endl;
    if(n-m[i]<0) {l[n] = -1;return -1;}
    //cout<<l[n-m[i]]<<" ";
    if(l[n-m[i]]>0 && n-m[i]>0) {l[n] = max(l[n-m[i]]-1,l[n]);return 1;}
    else if(l[n-m[i]]>=0)
    {
      cout<<n<<" "<<n-m[i]<<" "<<count<<endl;
      if(n-m[i]<0){l[n] = -1;return -1;}
      int k = recur(l,m,n-m[i],count+1);
      if(k==1){l[n] = max(l[n-m[i]]-1,l[n]);}
      else continue;
    }
  }
  l[n] = -1;
  return -1;
}
