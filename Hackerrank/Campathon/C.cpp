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

int bsearch1(int*l,int n,int value)
{
  int beg = 0,end = n-1;
  int maxindex = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(l[mid]<=value){beg = mid+1;maxindex = mid;}
    else end = mid-1;
  }
  return maxindex;
}

int main()
{
  int n,q;
  sc(n);sc(q);
  ll*l = new ll[n];
  for(int i=0;i<n;i++) scll(l[i]);
  for(int i=1;i<n;i++) l[i]+=l[i-1];
  for(int h=0;h<q;h++)
  {
    ll value;
    scll(value);
    value--;
    int c = bsearch1(l,n,value);
    if(c==n-1) cout<<-1<<endl;
    else cout<<(c+1)+1<<endl;
  }
  return 0;
}
