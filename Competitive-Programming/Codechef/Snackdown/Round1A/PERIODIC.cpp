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

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    for(int i=0;i<n;i++) {sc(l[i]);if(l[i]!=-1)l[i]--;}
    // Check for infinity
    int max1 = -1,boo = 0,res = 0,max2 = -1,lesser = 0,period = -1;
    for(int i=0;i<n;i++)
    {
      // cout<<max1<<" "<<max2<<endl;
      if(l[i]==-1 && !boo) continue;
      else if(l[i]!=-1)
      {
        if(l[i]<=max1) 
        {
          if(lesser)
          {
            int p = i-max2+max1-l[i];
            int a = p,b = period;
            int boo1 = 1;
            if(min(a,b)==0) boo1 = 0;
            // cout<<"p: "<<p<<" max1: "<<max1<<endl;
            if(p<=max1) boo =1;
            if((p!=period) && (period!=-1 && max(a,b)%min(a,b)!=0)) {boo = 1;}
            // else if(period%p==0) continue;
            else if(period==-1) period = p;
            else period = min(p,period);
            lesser = 0;
          }
          if(l[i]==max1) {max2 = i;lesser = 1;}
          else res = 1;
        }
        else if(l[i]>max1) {max1 = l[i];max2 = i;lesser = 1;}
      }
    }
    if(!res)
    {
      // cout<<"here"<<endl;
      // cout<<"period: "<<period<<endl;
      int i=0;
      while(l[i]==-1) i++;
      int c = l[i];
      int c1 = l[i],i1 = i,c2 = l[i],i2 = i;
      for(;i1<n;i1++)
      {
        if(c1==l[i1]) c1++;
        else if(l[i1]==-1) c1++;
        else {boo = 1;break;}
      }
      if(!boo) {printf("inf\n");continue;}
      boo = 0;
      for(;i<n;i++)
      {
        // cout<<"C: "<<c<<" l[i]: "<<l[i]<<endl;
        if(c==l[i]) c++;
        else if(l[i]==-1) c++;
        else {boo = 1;break;}
        c%=(period);
      }
      if(!boo) {printf("%d\n",period);continue;}
      boo = 0;
      for(;i2<n;i2++)
      {
        // cout<<"C: "<<c2<<" l[i]: "<<l[i2]<<endl;
        if(c2==l[i2]) c2++;
        else if(l[i2]==-1) c2++;
        else {boo = 1;break;}
        c2%=(max1+1);
      }
      int count = 0;
      for(int i=0;i<n;i++) if(l[i]==-1) count++;
      if(boo) printf("impossible\n");
      else if(max1>=n || max1==-1 || count==n-1) printf("inf\n"); 
      else printf("%d\n",max1+1);
      continue;
    }
    // cout<<"period: "<<period<<" "<<boo<<endl;
    if(boo) {printf("impossible\n");continue;}
    int i=0;
    while(l[i]==-1) i++;
    int c = l[i];
    for(;i<n;i++)
    {
      if(c==l[i]) c++;
      else if(l[i]==-1) c++;
      else {boo = 1;break;}
      c%=period;
    }
    if(boo) printf("impossible\n");
    else printf("%d\n",period);
  }
  return 0;
}

/*
1
5
1 -1 -1 4 1

1
10
1 -1 -1 1 -1 -1 -1 -1 -1 1

*/
