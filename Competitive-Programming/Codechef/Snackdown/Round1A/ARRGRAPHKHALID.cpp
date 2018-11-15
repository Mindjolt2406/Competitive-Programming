#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(n) for(int i=0;i<n;i+=1)
#define prarr(a,n) rep(n) printf("%d ",a[i] );printf("%s\n"," " );
#define sc(a) scanf("%d",&a);
#define scl(a) scanf("%lld",&a);
#define scf(a) scanf("%f",&a);
#define ff first
#define ss second
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31, 37, 41, 43, 47};
int main()
{
  int t;
  bool pp[51][51]={0};
  for(int i=2;i<=50;i++)
  {
          for(int j=0;j<15;j++)
          {
                  if(i%primes[j]==0) pp[i][primes[j]]=1;
          }
  }
  // for(int i=0;i<51;i++)
  // {
  //         for(int j=0;j<51;j++)
  //         {
  //                 printf("%d ",pp[i][j] );
  //         }
  //         printf("%s\n","" );
  // }
  sc(t);
  while(t--)
  {
          int a[51]={0};
          int n;
          int dict[51]={0};
          sc(n);
          rep(n) {sc(a[i]);dict[a[i]]++;}
          vector<int> connected={};
          int deg[51]={0};
          vector<int> ps;
          for(int j=0;j<15;j++)
          {
                  bool fd=0;
                  rep(n)
                  {
                          if(pp[a[i]][primes[j]])fd=1;
                          // printf("%d %d %d\n",a[i],primes[j],pp[a[i]][primes[j]] );
                  }
                  if(!fd) ps.push_back(primes[j]);
                  // for(int j=i;j<n;j++)
                  // {
                  //         deg[a[i]]+=__gcd(a[i],a[j])==1?1:0;
                  //         deg[a[j]]+=__gcd(a[i],a[j])==1?1:0;
                  // }
          }
          vector<pii> vd={};
          vector<int> vm[51]={};
          rep(n){vd.push_back({deg[a[i]],a[i]});}
          sort(vd.begin(),vd.end());
          int maxd=-1,maxv=-1;
          bool vis[51]={0};
          connected.push_back(vd[vd.size()-1].ss);
          // rep(50){if(deg[i]>maxd){maxd=deg[i],maxv=i;}}
          // connected.push_back(maxv);vis[maxv]=1;
          // rep(n){if(__gcd(maxv,a[i])==1){connected.push_back(a[i]);vis[a[i]]=1;}}
          bool vis1[51]={0};
          for(int i=0;i<connected.size();i++)
          {
                  vis[connected[i]]=1;
                  if(!vis1[connected[i]])
                  {
                          for(int j=0;j<n;j++)
                          {
                                  if(!vis[j]&&__gcd(connected[i],a[j])==1)
                                  {connected.push_back(a[j]);vis[a[j]]=1;vis1[a[j]]=1;}
                          }
                          vis1[connected[i]]=1;
                          // prarr(connected,connected.size());
                          // printf("%d %d\n",maxd,maxv );
                  }
          }
          if(connected.size()==n)
          {
                  printf("0\n");
                  prarr(a,n);
          }
          else
          {
                  printf("1\n");
                  sort(a,a+n);
                  // printf("%d\n",(int)ps.size() );
                  a[n-1]=ps[ps.size()-1];
                  // prarr(ps,ps.size());
                  prarr(a,n);
          }
          continue;
          }
          return 0;
  }