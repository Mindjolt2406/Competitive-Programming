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

// Half baked crap done so far
typedef struct BIT //int
{
  vector<int> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  int sum(int i)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, int delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  int getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(v[i],1);
  }
} fen;

int bsearch1(fen bit, int value)
{
  int beg = 0,end = bit.bit.size()-1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(bit.sum(bit.bit[mid])==value) return mid;
    else if(bit.sum(bit.bit[mid])<value) end =mid-1;
    else beg = mid+1;
  }
  return -1; 
}
int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    vector<int> v;
    v.assign(0,n+1);
    int nz = n;
    int k = n;
    int start = -1;
    int counter = 0;
    int i=0;
    fen bit;
    bit.init(v);
    for(int i=0;i<v.size();i++) cout<<bit.sum(v[i])<<" ";cout<<endl;
    cout<<"here"<<endl;
    while(i<n)
    {
      k = nz;
      cout<<"i: "<<i<<endl;
      if(i+2<=nz)
      {
        int c = bsearch1(bit,i+2);
        cout<<"c: "<<c<<endl;
        bit.inc(c,-1);
        v[c] = i;
        // Change the number
        nz-=(i+2);
        counter++;
      }
      else
      {
        int c = i+2;
        c-=nz;
        nz = k-counter;
        counter = 0;
        c = c%nz;
        int index = bsearch1(bit,c);
        bit.inc(index,-1);
        v[index] = i;
        // Find the cth zero and we're done
        nz-=c;
        counter++;
      }
      i++;
    }
  }
  return 0;
}

