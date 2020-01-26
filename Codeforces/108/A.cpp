#include<iostream>
#include<set>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  char c[n][m];
  int l[n][m];
  set <int> s;
  for(int i=0;i<n;i++) for (int j = 0; j < m; j++) {cin>>(c[i][j]);}
  for(int i=0;i<n;i++) for (int j = 0; j < m; j++) {l[i][j] = (c[i][j]-'0');}
  for(int i=0;i<m;i++)
  {
    int max = 0;
    for(int j=0;j<n;j++)
    {
      //cout<<l[j][i]<<" ";
      if(l[j][i]>max)max = l[j][i];
    }
    //cout<<max;
    for(int j=0;j<n;j++)
    {
      if(l[j][i]==max)s.insert(j);
    }
    //cout<<endl;
  }

  cout<<s.size()<<endl;
}
