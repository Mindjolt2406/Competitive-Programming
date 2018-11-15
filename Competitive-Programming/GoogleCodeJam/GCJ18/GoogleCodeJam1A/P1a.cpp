#include<iostream>
#include<vector>
#define pu push_back
using namespace std;

int count1(int** l,int a,int b,int c,int d)
{
  int count = 0;
  count+=l[c][d];
  if(a>=0)count-=l[a][d];
  if(b>=0)count-=l[c][b];
  if(a>=0 && b>=0)count+=l[a][b];
  // cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<" count: "<<count<<endl;
  return count;
}

void build(int** l, int n,int m)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int count = 0;
      if(i>0) count+=l[i-1][j];
      if(j>0) count+=l[i][j-1];
      if(i>0 && j>0) count -=l[i-1][j-1];
      l[i][j]+=count;
    }
  }
}
int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int **l = new int *[n];
    for(int i=0;i<n;i++) l[i] = new int[m];
    vector <int> v1,v2;
    v1.pu(-1);v2.pu(-1);
    int count = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        char c;
        cin>>c;
        if(c=='.')l[i][j] = 0;
        else {l[i][j] = 1;count++;}
      }
    }
    int* d = (int*)calloc(n,sizeof(int));
    int* e = (int*)calloc(m,sizeof(int));
    int* f = (int*)calloc(n,sizeof(int));
    int* g = (int*)calloc(m,sizeof(int));
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(l[i][j]==1) {d[i]++;e[j]++;}
      }
    }
    build(l,n,m);
    // for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<l[i][j]<<" "; cout<<endl;}
    f[0] = d[0];
    g[0] = e[0];
    for(int i=1;i<n;i++)f[i] =f[i-1]+ d[i];
    for(int j=1;j<m;j++)g[j]+=g[j-1] + e[j];
    // for(int i=0;i<n;i++)cout<<f[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<m;i++)cout<<g[i]<<" ";
    // cout<<endl;
    int counta=0,countb=0;
    if(count==0) {cout<<"Case #"<<h<<": POSSIBLE"<<endl;continue;}
    if(count/(a+1)==0 || count/(b+1)==0) {cout<<"Case #"<<h<<": IMPOSSIBLE"<<endl;continue;}
    for(int i=0;i<n;i++)
    {
      if(d[i]!=0 && f[i]%(count/(a+1))==0 ) {counta++;v1.pu(i);}
      // cout<<"f[i]: "<<f[i]<<" count: "<<count<<" a+1: "<<a+1<<endl;
    }
    for(int j=0;j<m;j++)
    {
      if(e[j]!=0 && g[j]%(count/(b+1))==0 ) {countb++;v2.pu(j);}
    }
    // cout<<counta<<" "<<countb<<endl;
    if(v1[v1.size()-1]!=n-1)v1.pu(n-1);
    if(v2[v2.size()-1]!=m-1)v2.pu(m-1);
    // for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";
    // cout<<endl;
    int c = count1(l,v1[0],v2[0],v1[1],v2[1]);
    int boo = 1;
    for(int i=1;i<v1.size();i++)
    {
      for(int j=1;j<v2.size();j++)
      {
        if(c!=count1(l,v1[i-1],v2[j-1],v1[i],v2[j])) {boo = 0;break;}
      }
    }
    // cout<<"boo: "<<boo<<endl;
    if((count%(a+1)!=0 || counta!=a+1 || count%(b+1)!=0 || countb!=b+1 || boo==0)&& count!=0) cout<<"Case #"<<h<<": IMPOSSIBLE"<<endl;
    else cout<<"Case #"<<h<<": POSSIBLE"<<endl;
  }
  return 0;
}
