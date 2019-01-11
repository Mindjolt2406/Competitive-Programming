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

// int primeFactors(int n)
// {
//     int count = 0;
//     while (n%2 == 0)
//     {
//         count++;
//         n = n/2;
//     }
//     for (int i = 3; i <= sqrt(n); i = i+2)
//     {
//         while (n%i == 0)
//         {
//             count++;
//             n = n/i;
//         }
//     }
//
//     if (n > 2) count++;
//     return count;
// }
int size = 5000001;
bitset<5000010> bs;
int*l;

void sieve()
{
  bs.set();
  bs[0] = bs[1] = false;
  // cout<<"here"<<endl;
  l[0] = 0;l[1] = 0;
  for(int i=2;i<size;i++)
  {
    if(bs[i])
    {
      for(ll j = i;j<size;j+=i)
      {
        bs[j] = false;
        int j1 = j;
        while(j1%i==0)
        {
          j1/=i;
          l[j]++;
        }
      }
    }
  }
}

int getSum(int a,int b)
{
  if(a>0) return l[b]-l[a];
  return l[b];
}

int main()
{
  int t;
  sc(t);
  l = (int*)calloc(size+100,sizeof(int));
  sieve();
  // for(int i=0;i<8;i++) cout<<l[i]<<" ";cout<<endl;
  for(int i=1;i<size;i++)
  {
    l[i]+=l[i-1];
  }
  while(t--)
  {
    int a,b;
    sc(a);sc(b);
    int c = getSum(min(a,b),max(a,b));
    printf("%d\n",c);
  }
  return 0;
}