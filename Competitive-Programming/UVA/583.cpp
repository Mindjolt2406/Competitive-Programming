#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

bitset<100001> bs;
vi prime;

void sieve()
{
  bs.set();
  bs.set(0,false);bs.set(1,false);
  for(ll i=2;i<100001;i++)
  {
    if(bs.test((size_t)i))
    {
      for(ll j=i*i;j<100001;j+=i) bs.set((size_t)j,false);
    }
    prime.pu((int)i);
  }
}

int main()
{
  sieve();
  int n;
  scanf("%d",&n);
  while(n)
  {
    if(n<0) {printf("%d = -1 x ",n);n*=-1;}//cout<<n<<" = -1 x ";
    else printf("%d = ",n);//cout<<n<<" = ";
    vector<int> ans;
    int j = 0,i=0;
    while(prime[i]*prime[i]<=n && i<prime.size())
    {
      if(n%prime[i]==0)
      {
        ans.pu(prime[i]);
        ans.pu(0);
        j++;
        while(n%prime[i]==0)
        {
          n/=prime[i];
          ans[j]++;
        }
        j++;
      }
      i++;
    }
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
    if(ans.empty() && n<0) printf("%d\n",n);
    else if(ans.empty()) printf("%d\n",n);//cout<<n<<endl;
    else
    {
      if(n!=1) {ans.pu(n);ans.pu(1);}
      for(int i=0;i<ans.size()-2;i+=2)
      {
        int c = ans[i];
        for(int j=0;j<ans[i+1];j++) printf("%d x ",c);//cout<<c<<" x ";
      }
      int c = ans[ans.size()-2];
      int d = ans[ans.size()-1];
      for(int i=0;i<d-1;i++)
      {
        printf("%d x ",c);//cout<<c<<" x ";
      }
      printf("%d\n",c);
      // cout<<c<<endl;
    }
    scanf("%d",&n);
  }
  return 0;
}

/*
-190
-191
-192
-193
-194
195
196
197
198
199
200
0

*/
