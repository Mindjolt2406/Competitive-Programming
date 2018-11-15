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

ld min(ld x,ld y)
{
  if(x<y) return x;
  return y;
}

ld f(ld x,ld y)
{
  return (x*x + y*y)/(x*y);
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    map<int,int> d;
    map<int,int> :: iterator it;
    for(int i=0;i<n;i++)
    {
      if(d.find(l[i])!=d.end()) d[l[i]] ++;
      else d[l[i]] = 1;
    }
    vector<int> v,v1;
    for(it = d.begin();it!=d.end();it++)
    {
      if(it->second>=2) v.pu(it->first);
      if(it->second>=4) v1.pu(it->first);
    }
    sort(v.begin(),v.end());
    int min1 = INF;
    ld min2 = INF;
    int a = -1,b = -1;
    for(int i=1;i<v.size();i++)
    {
      if(f(v[i],v[i-1])<min2) {a = v[i];b = v[i-1];min2 = f(v[i],v[i-1]);}
    }
    if(v1.size()>0) cout<<v1[0]<<" "<<v1[0]<<" "<<v1[0]<<" "<<v1[0]<<endl;
    else cout<<a<<" "<<a<<" "<<b<<" "<<b<<endl;
  }
  return 0;
}
