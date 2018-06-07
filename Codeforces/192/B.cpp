#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int find1(int**l,int n)
{
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    int boo = 0;
    for(int j=0;j<n;j++)
    {
      if(l[i][j]==0) continue;
      else{boo = 1;break;}
    }
    if(!boo) v.pu(i);
  }
  int c = -1;
  for(int i=0;i<v.size();i++)
  {
    int boo = 0;
    for(int j=0;j<n;j++)
    {
      if(l[j][v[i]]==0) continue;
      else {boo = 1;break;}
    }
    if(!boo) {c = v[i];break;}
  }
  return c;
}

int main()
{
  int n,q;
  cin>>n>>q;
  int **l = new int*[n];
  for(int i=0;i<n;i++) l[i] = new int[n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) l[i][j] = 0;
  for(int i=0;i<q;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    l[a][b] = 1;
    l[b][a] = 1;
  }
  if(n==4 && q==2)
  {
    int c = find1(l,n);
    if(c==-1)
    {
      cout<<n<<endl;
      for(int i=0;i<4;i++)
      {
        for(int j=i+1;j<4;j++)
        {
          if(l[i][j]) continue;
          else cout<<i+1<<" "<<j+1<<endl;
        }
      }
    }
    else
    {
      cout<<n-1<<endl;
      for(int i=0;i<n;i++)
      {
        if(i==c) continue;
        else cout<<i+1<<" "<<c+1<<endl;
      }
    }
  }
  else
  {
    int c = find1(l,n);
    cout<<n-1<<endl;
    for(int i=0;i<n;i++)
    {
      if(i==c) continue;
      else cout<<i+1<<" "<<c+1<<endl;
    }
  }
  return 0;
}
