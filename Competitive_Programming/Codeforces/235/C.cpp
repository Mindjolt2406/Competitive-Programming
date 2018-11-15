#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  if(m<n-1 || m>2*n+2) cout<<-1<<endl;
  else
  {
    int* l = (int*)calloc(n+1,sizeof(int));
    for(int i=1;i<n;i++)l[i] = 1;
    if(m<=n+1)
    {
      int c = abs(n+1-m);
      if(!c) {l[0] = 1;l[n] = 1;}
      else if(c==1) l[0] = 1;
    }
    else if(m<=(2*n+2))
    {
      l[0] = 1;l[n] = 1;
      for(int i=0;i<(m-n-1);i++)l[i]++;
    }
    string k;
    for(int i=0;i<=n;i++)
    {
      if(l[i]==1) k+='1';
      else if(l[i]==2) k+="11";
      if(i!=n) k+='0';
    }
    cout<<k<<endl;
  }
}
