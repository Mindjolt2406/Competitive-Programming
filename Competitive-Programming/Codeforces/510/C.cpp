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
  int countm=0,countp=0,countz = 0;
  vector<int> m,p,z;
  int max1 = -1*INF,max2= -1;
  for(int i=0;i<n;i++)
  {
    if(l[i]<0) 
    {
      countm++;
      m.pu(i);
      if(max1<l[i]) max2 = i;
      max1 = max(max1,l[i]);
    }
    else if(l[i]==0) {countz++;z.pu(i);}
    else {countp++;p.pu(i);}
  }
  if(countz>0)
  {
    for(int i=1;i<z.size();i++) cout<<1<<" "<<z[i-1]+1<<" "<<z[i]+1<<endl;
    if(countm%2==1)
    {
      cout<<1<<" "<<max2+1<<" "<<z[z.size()-1]+1<<endl;
    }
    if(countm>1 || countp>0) cout<<2<<" "<<z[z.size()-1]+1<<endl;
    vector<int> m1;
    for(int i=0;i<m.size();i++) if(m[i]!=max2 || countm%2==0) m1.pu(m[i]);
    for(int i=1;i<m1.size();i++)
    {
      cout<<1<<" "<<m1[i-1]+1<<" "<<m1[i]+1<<endl;
    }
    for(int i=1;i<p.size();i++)
    {
      cout<<1<<" "<<p[i-1]+1<<" "<<p[i]+1<<endl;
    }
    if(!m1.empty() && !p.empty())cout<<1<<" "<<m1[m1.size()-1]+1<<" "<<p[p.size()-1]+1<<endl;
  }
  else
  {
    vector<int> m1;
    for(int i=0;i<m.size();i++) if(m[i]!=max2 || countm%2==0) m1.pu(m[i]);
    if(countm%2==1) cout<<2<<" "<<max2+1<<endl;
    for(int i=1;i<m1.size();i++)
    {
      cout<<1<<" "<<m1[i-1]+1<<" "<<m1[i]+1<<endl;
    }
    for(int i=1;i<p.size();i++)
    {
      cout<<1<<" "<<p[i-1]+1<<" "<<p[i]+1<<endl;
    }
    if(!m1.empty() && !p.empty())cout<<1<<" "<<m1[m1.size()-1]+1<<" "<<p[p.size()-1]+1<<endl;
  }
  return 0;
}
