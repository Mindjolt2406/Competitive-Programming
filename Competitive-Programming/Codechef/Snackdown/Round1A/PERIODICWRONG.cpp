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
    for(int i=0;i<n;i++) {sc(l[i]);if(l[i]!=-1) l[i]--;}
    int period = -1;
    int max1 = -1,max2 = -1,boo = 0,boo1 = 0,boo3 = 0;
    for(int i=0;i<n;i++)
    {
      if(l[i]>max1) {max1 = l[i];max2 = i;}
      else if(l[i]==-1) continue;
      else if(l[i]<max1)
      {
        boo3 = 1;
        int p = i-max2;
        if(p<0) {boo1= 1;printf("impossible\n");break;}
        else if(boo && period>p+max1-1) {boo1= 1;printf("impossible\n");break;}
        else if(boo && period<=p+max1-1) {period = p+max1;} 
        else if(!boo) {boo = 1;period = max1+p-1;}
      }
    }
    // cout<<"1: "<<max1<<" 2: "<<max2<<endl;
    // cout<<period<<endl;
    if(boo1) continue;
    else 
    {
      // cout<<"jere"<<endl;
      int boo = 0,k = 0,boo1 = 0,boo2 = 0;
      if(period==-1) {period = max1+1;boo2 = 1;}
      for(int i=0;i<n;i++)
      {
        if(!boo && l[i]==-1) continue;
        else if(l[i]!=-1 && !boo) 
        {
          boo = 1;
          k = l[i];
          k%=period;
        }
        else
        {
          k++;
          k%=period;
        }
        if(l[i]==-1) continue;
        if(k!=l[i]) 
        {
          boo1 = 1;
          break;
        }
      } 
      if(boo1) printf("impossible\n");
      else if(boo2) printf("inf\n");
      else printf("%d\n",period);
    }
  }
  return 0;
}

