#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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

vector <ll> pref;
vll v;

ll getSum(int i,int j)
{
  if(i==0) return pref[j];
  return pref[j]-pref[i-1];
}

ld min(ld x,ld y)
{
  if(x<y) return x;
  return y;
}

int bsearch1(ld value,int n)
{
  int beg = 0,end = n-1,maxindex = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]<=value) {beg = mid+1;maxindex = mid;}
    else end = mid-1;
  }
  return maxindex;
}

int main()
{
  int n;
  sc(n);
  vector<ld> v1;
  for(int i=0;i<n;i++)
  {
    int n1;
    sc(n1);
    ld sum1 = 0;
    int*l = new int[n1];
    for(int i=0;i<n1;i++) {sc(l[i]);sum1+=l[i];v.pu(l[i]);}
    sum1/=n1;
    v1.pu(sum1);
  }
  sort(v.begin(),v.end());

  pref.pu(v[0]);
  for(int i=1;i<v.size();i++)
  {
    pref.pu(pref[i-1]+v[i]);
  }
  ld min1 = INF;
  for(int i=0;i<v1.size();i++)
  {
    int index = bsearch1(v1[i],v.size());
    if(index!=v.size()-1)
    {
      min1 = min(min1,v1[i]*(index+1) - getSum(0,index)+getSum(index+1,v.size()-1) - v1[i]*(v.size()-1-index));
    }
    else min1 = min(min1,v1[i]*(index+1) - getSum(0,v.size()-1));
  }
  cout<<setprecision(15);
  cout<<min1<<endl;
  return 0;
}
