#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

bitset<1000010> bs;
int size = 1000001;
vi prime;

void sieve()
{
  bs.set();bs[0] = false;bs[1] = false;
  for(ll i= 2;i<size;i++)
  {
    if(bs[i])
    {
      for(ll j = i*i;j<size;j+=i)
      {
        bs[j] = false;
      }
      prime.pu((int)i);
    }
  }
}

int bins(int a,int boo)
{
  int beg = 0,end = prime.size()-1;
  int mid;
  while(beg<=end)
  {
    mid = (beg+end)/2;
    if(prime[mid]<a) beg = mid+1;
    else if(prime[mid]>a) end = mid-1;
    else return mid;
  }
  if(boo) return end;
  else return beg;
}

int main()
{
  sieve();
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    int c = bins(a,0);
    int e = bins(b,1);
    // cout<<prime[c]<<" "<<prime[d]<<endl;
    int max1 = 0,max2 = 0;
    map<int,int> d;
    map<int,int> :: iterator it;
    for(int i=c;i<e;i++)
    {
      // cout<<prime[i]<<" "<<prime[i+1]<<endl;
      int c = prime[i+1] - prime[i];
      if(d.find(c)!=d.end()) d[c]++;
      else d[c] = 1;
    }
    for(it = d.begin();it!=d.end();it++)
    {
      max1 = max(it->second,max1);
      if(max1==it->second)max2 = it->first;
    }
    int count = 0;
    for(it = d.begin();it!=d.end();it++)
    {
      if(max1==it->second) count++;
    }
    // cout<<c<<" "<<e<<endl;
    if(count>1 || c>=e || max2==0) printf("No jumping champion\n");
    else printf("The jumping champion is %d\n",max2);
  }
  return 0;
}
