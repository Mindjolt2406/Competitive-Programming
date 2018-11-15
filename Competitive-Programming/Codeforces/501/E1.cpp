#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int checkstar(char**l, int i,int j,int n,int m,int** checker)
{
  int a = i,b = j;
  int a1 = 0,a2 = 0,a3 = 0,a4 = 0;
  // vector<pair<int,int> > v;
  while(a>=0 && a<n && b>=0 && b<m)
  {
    if(l[a][b]=='*') a--;
    else {a1 = abs(i-a)-1;break;}
  }
  a1 = abs(i-a)-1;
  a = i;b = j;
  while(a>=0 && a<n && b>=0 && b<m)
  {
    if(l[a][b]=='*') a++;
    else {a2 = abs(i-a)-1;break;}
  }
  a2 = abs(i-a)-1;
  a = i;b = j;
  while(a>=0 && a<n && b>=0 && b<m)
  {
    if(l[a][b]=='*') b--;
    else {a3 = abs(j-b)-1;break;}
  }
  a3 = abs(j-b)-1;
  a = i;b = j;
  while(a>=0 && a<n && b>=0 && b<m)
  {
    if(l[a][b]=='*') b++;
    else {a4 = abs(j-b)-1;break;}
  }
  a4 = abs(j-b)-1;
  int c = min(a1,min(a2,min(a3,a4)));
  if(c!=0)
  {
    checker[i][j] = 1;
    for(int k = i-c;k<=i+c;k++) checker[k][j] = 1;
    for(int k = j-c;k<=j+c;k++) checker[i][k] = 1;
  }
  // cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
  // cout<<"i: "<<i<<" j: "<<j<<" c: "<<c<<endl;
  return c;
}

int main()
{
  int n,m;
  sc(n);sc(m);
  char** l= new char*[n];
  for(int i=0;i<n;i++) l[i] = new char[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>l[i][j];
  int** checker = new int*[n];
  for(int i=0;i<n;i++) checker[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) checker[i][j] = 0;
  int** star = new int*[n];
  for(int i=0;i<n;i++) star[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) star[i][j] = 0;
  vector<tuple<int,int,int> > v;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(l[i][j]=='*')
      {
        int c = checkstar(l,i,j,n,m,checker);
        if(c) v.pu(mt(i+1,j+1,c));
      }
    }
  }
  int boo = 1;
  for(int i=0;i<n;i++)
  {
    int boo1 = 1;
    for(int j=0;j<m;j++)
    {
      if(l[i][j]=='*' && checker[i][j]) continue;
      else if(l[i][j]=='*'){boo1 = 0;break;}
    }
    if(!boo1) {boo = 0;break;}
  }
  // for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<checker[i][j]<<" ";cout<<endl;}
  if(boo)
  {
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
      tuple<int,int,int> t = v[i];
      printf("%d %d %d\n",get<0>(t),get<1>(t),get<2>(t));
    }
  }
  else cout<<-1<<endl;
  return 0;
}
