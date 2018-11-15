#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 0.0000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;


int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

int main()
{
  int a,b;
  sc(a);sc(b);
  vector<pair<int,int> >*adj = new vector<pair<int,int> >[2000001];
  bitset<2000010> bs;
  bs.reset();
  for(int i=0;i<1001;i++)
  {
    // cout<<"i: "<<i<<endl;
    bs[i*i] = true;
  }
  for(int i=1;i<=1000;i++)
  {
    for(int j=1;j<=1000;j++)
    {
      int c = pow(i,2)+pow(j,2);
      // cout<<"i: "<<i<<" j: "<<j<<" ";
      // cout<<"c: "<<c<<endl;
      if(bs[(int)c])
      {
        c = sqrt(c);
        adj[(int)c].pu(mp(i,j));
        adj[(int)c].pu(mp(-1*i,j));
      }
    }
  }
  for(int i=1;i<=100;i++)
  {
    for(int j=0;j<adj[i].size();j++)
    {
      pair<int,int> p = adj[i][j];
      // cout<<"i: "<<i<<" "<<p.first<<" "<<p.second<<endl;
    }
  }
  if(adj[a].size()==0 || adj[b].size()==0)
  {
    // cout<<"here"<<endl;
    cout<<"NO"<<endl;
    return 0;
  }
  for(int i=0;i<adj[a].size();i++)
  {
    for(int j=0;j<adj[b].size();j++)
    {
      pair<int,int> p1 = adj[a][i];
      pair<int,int> p2 = adj[b][j];
      int x1 = p1.first,y1 = p1.second,x2 = p2.first,y2 = p2.second;
      // int g1 = gcd(min(abs(x1),abs(y1)),max(abs(x1),abs(y1)));
      // int g2 = gcd(min(abs(x2),abs(y2)),max(abs(x2),abs(y2)));
      int kx1 = x1,ky1 = y1;
      int kx= x2,ky = y2;
      if(y1*y2==-1*x1*x2 && y1!=y2)
      {
        cout<<"YES"<<endl;
        cout<<"0 0"<<endl;
        cout<<kx1<<" "<<ky1<<endl;
        cout<<kx<<" "<<ky<<endl;
        return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
