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
  int *l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int beg = 1, end = INF-1,min1 = end;
  bitset<n> bs;
  while(beg<=end)
  {
    bs.reset()
    int mid = (beg+end)/2;
    for(int i=0;i<n;i++)
    {
      if(mid>=l[i]) bs[i] = true;
    }
    vector<int> v;
    int i=0;
    int count = 0;
    while(i<n)
    {
      if(bs[i]==false) count++;
      else {v.pu(count); count = 0;}
      i++;
    }
    int boo = 0;
    if(!v.empty())
    {
      int c = v[0];
      for(int i=0;i<v.size();i++)
      {
        if(v[i]!=c) {boo = 1;break;}
      }
    }
    if(boo) {min1 = min(min1,mid);end = mid-1;}
    else {}
  }
  return 0;
}
