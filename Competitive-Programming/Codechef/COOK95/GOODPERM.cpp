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

bitset<9> bs;

int recur(vector<int> v,int i,int*l,int n,int j,int counter,int final1)
{
  int count = 0;
  if(i== n) return 0;
  while(!l[i] && i<n) i++;
  if(i==n) return 0;
  if(counter==0)
  {
    int c = 0;
    for(int k=1;k<v.size();k++) if(v[k]>v[k-1]) c++;
    if(c== final1) return 1;
  }
  else
  {
    for(int k=0;k<)
  }
}
int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    int *l = new int[n];
    vector<int> v1,v;
    for(int i=0;i<n;i++) {sc(l[i]);v1.pu(l[i]);}
    bs.reset();
    int counter = 0;
    for(int i=0;i<n;i++) if(l[i]) {bs[l[i]] = true;count++;}
    for(int i=1;i<=n;i++) if(!bs[i]) v.pu(i);
    int count = recur(l,)
  }
  return 0;
}
