//LOOKED AT EDITORIAL
// It's fantastic, the way changing the order of loops can completely change the way you look at a problem
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
  int n,m;
  sc(n);sc(m);
  ll* l = (ll*)calloc(n+1,sizeof(ll));
  int* min1 = (int*)calloc(n+1,sizeof(int));
  for(int i=0;i<n+1;i++) min1[i] = 0;
  l[0] = 1;
  vector<int> v;
  bitset<51> bs;
  bs.reset();
  for(int i=0;i<m;i++)
  {
    int a;
    sc(a);
    v.pu(a);
    if(a<=n){l[a]=0;bs[a] = true;}
  }
  for(int j=0;j<m;j++)
  {
    for(int i=v[j];i<=n;i++) l[i]+=l[i-v[j]];
  }
  // for(int i=1;i<=n;i++)
  // {
    // bitset<251> bs1;
    // bs1.reset();
    // for(int k=0;k<m;k++)
    // {
    //   if(i-v[k]>=0)
    //   {
    //     // bs[i-v[k]] = true;
    //     for(int j=0;j<m;j++) if(i-v[k]-v[j]>0) {bs1[i-v[k]-v[j]] = true;}
    //   }
    // }
    // for(int j=0;j<n;j++) cout<<bs1[j]<<" ";cout<<endl;
    // for(int j=0;j<m;j++)
    // {
    //
    //   if(i>=v[j] && v[j]>=min1[i-v[j]])
    //   {
    //     // l[i]+=l[i-v[j]];
    //     cout<<v[j]<<" "<<min1[i-v[j]]<<endl;
    //     {
    //       l[i]+=l[i-v[j]];
    //       if(bs[i-v[j]]) min1[i] = max(v[j],i-v[j]);
    //       min1[i] = max(v[j],min1[i]);
    //     }

        // else l[i]++;
        // else if(i%v[j]==0) l[i]++;
        // if((bs[i-v[j]] && i-v[j]>v[j]) || (!bs[i-v[j]])) l[i]+=l[i-v[j]];
        // else if(bs[i-v[j]] && i==2*v[j]) l[i]++;
    //   }
    // }
  // }
  // for(int i=0;i<=n;i++) cout<<l[i]<<" ";cout<<endl;
  printf("%lld\n",l[n]);
  return 0;
}
