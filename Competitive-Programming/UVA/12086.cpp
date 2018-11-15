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

struct BIT
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
      // cout<<"i: "<<i<<endl;
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
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
};

int main()
{
  typedef struct BIT BIT;
  int n;
  sc(n);
  int count = 1;
  while(n!=0)
  {
    if(count!=1) printf("\n");
    printf("Case %d:\n",count);
    vector<int> v;
    for(int i=0;i<n;i++) {int a;sc(a);v.pu(a);}
    BIT bit;
    bit.init(v);
    string s;
    scr(s);
    while(s!="END")
    {
      if(s=="M")
      {
        int a,b;
        sc(a);sc(b);
        a--;b--;
        printf("%d\n",bit.getsum(a,b));
      }
      else if(s=="S")
      {
        int a,b;
        sc(a);sc(b);
        a--;
        int inc = b-v[a];
        v[a] +=inc;
        bit.inc(a,inc);
      }
      scr(s);
    }
    count++;
    sc(n);
  }
  return 0;
}

/*
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0

*/