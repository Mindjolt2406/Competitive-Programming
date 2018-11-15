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

bitset<1002> bs;
vi prime;
int size = 1001;

void sieve()
{
  bs.set();
  bs[0] = false;bs[1] = true;prime.pu(1);
  for(int i=2;i<size;i++)
  {
    if(bs[i])
    {
      for(int j=i*i;j<size;j+=i) bs[j] = false;
      prime.pu(i);
    }
  }
}

int bsearch(vector<int> v,int value)
{
  int n = v.size();
  int beg = 0,end = n-1,max1 = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]==value) return mid;
    else if(v[mid]<value) {max1 = max(max1,mid);beg = mid+1;}
    else end = mid-1;
  }
  return max1;
}

int main()
{
  sieve();
  int n,c;
  while(scanf("%d %d",&n,&c)!=EOF)
  {
    printf("%d %d:",n,c);
    int index = bsearch(prime,n);
    int beg,end;
    if(c>=index+1) {beg = 0,end = index;}
    else
    {
      if((index+1)%2==0 && 2*c<index) {beg = index/2 -c +1;end = 2*c -1 + beg;}
      else if((index+1)%2==0) {beg = 0,end = index;}
      else if(2*c-1<index) {beg = index/2 - c +1;end = 2*(c-1) + beg;}
      else if((index+1)%2==1) {beg = 0,end = index;}
    }
    for(int i=beg;i<=end;i++) printf(" %d",prime[i]);
    printf("\n\n");
  }
  return 0;
}
