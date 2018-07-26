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

bitset<32> prime;

void recur(bitset<32> bs1,vector<int> v,int n)
{
  if(bs1.all())
  {
    if(prime[v.back()+1])
    {
      for(int i=0;i<n-1;i++) printf("%d ",v[i]);
      printf("%d\n",v.back());
    }
    return;
  }

  for(int i=2;i<=n;i++)
  {
    if(!bs1[i] && prime[v.back()+i])
    {
      v.pu(i);
      bs1[i] = true;
      recur(bs1,v,n);
      v.pop_back();
      bs1[i] = false;
    }
  }
}

int main()
{
  prime.reset();
  vector <int> prime1 = {2,3,5,7,11,13,17,19,23,29,31};
  for(int i=0;i<prime1.size();i++) prime[prime1[i]] = true;
  int n;
  string s;
  int count = 1;
  while(getline(cin,s))
  {
    if(count>1)printf("\n");
    printf("Case %d:\n",count);
    n = stoi(s);
    bitset<32> bs1;
    // set<int> s1;
    bs1.set();
    for(int i=2;i<=n;i++) bs1[i] = false;
    vector<int> v;
    v.pu(1);
    recur(bs1,v,n);
    count++;
  }
  return 0;
}
