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

ll getsum(ll*l,int i,int j)
{
  if(i==0) return l[j-1];
  return l[j-1]-l[i-1];
}

ll max(ll i,ll j)
{
  if(i>j) return i;
  return j;
}

ll min(ll i, ll j)
{
  if(i<j) return i;
  return j;
}

int main()
{
  int n;
  sc(n);
  ll*l = new ll[2*n];
  ll start,finish;
  for(int i=0;i<n;i++) {scll(l[i]);l[n+i] = l[i];}
  scll(start);scll(finish);
  for(int i=1;i<2*n;i++)
  {
    l[i]+=l[i-1];
  }
  ll max1 = -1;
  for(int i=0;i<n;i++)
  {
    max1 = max(max1,getsum(l,i,i+finish-start));
  }
  ll min1 = INF;
  for(int i=0;i<n;i++)
  {
    if(getsum(l,i,i+finish-start)==max1)
    {
      // cout<<"i: "<<i<<" time: "<<n-i+start<<endl;
      int c = n-i+start;
      if(c>n) c-=n;
      // cout<<"c: "<<c<<endl;
      min1 = min(min1,c);
    }
  }
  cout<<min1<<endl;
  return 0;
}
