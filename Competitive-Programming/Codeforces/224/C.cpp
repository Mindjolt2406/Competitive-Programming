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
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  sort(l,l+n);
  if(n==2)
  {
    int c = abs(l[0]-l[1]);
    if(c==0) cout<<1<<endl<<l[0]<<endl;
    else if(c%2==0) 
    {
      cout<<3<<endl;
      cout<<l[0]-c<<" "<<l[0]+c/2<<" "<<l[1]+c<<endl;
    }
    else if(c%2==1)
    {
      cout<<2<<endl;
      cout<<l[0]-c<<" "<<l[1]+c<<endl;
    }
  }
  else if(n==1) cout<<-1<<endl;
  else
  {
    map<int,int> d;
    int c;
    for(int i=0;i<n-1;i++)
    {
      c = l[i+1]-l[i];
      if(d.find(c)!=d.end()) d[c]++;
      else d[c] = 1;
    }
    if(d.size()>=3) cout<<0<<endl;
    else
    {
      if(d.size()==1) 
      {
        if(c!=0)cout<<2<<endl<<l[0]-c<<" "<<l[n-1]+c<<endl;
        else cout<<1<<endl<<l[0];
      }
      else
      {
        map<int,int> :: iterator it;
        it = d.begin();
        int a = it->first;
        it++;
        int b = it->first;
        int m[2] = {a,b};
        sort(m,m+2);
        // cout<<m[0]<<" "<<m[1]<<endl;
        if(d[m[1]]==1 && b==2*a)
        {
          cout<<1<<endl;
          for(int i=0;i<n-1;i++)
          {
            if(l[i+1]-l[i]==b) cout<<l[i]+a<<endl;
          }
        }
        else cout<<0<<endl;
      }
    }
  }
  return 0;
}

