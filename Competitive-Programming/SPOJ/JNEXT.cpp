#include<bits/stdc++.h>
#define MAX 1000000001
#define m make_pair
#define pu push_back
#define S cout<<"Here"<<endl;
using namespace std;

void swap(long long int*l, long long int k)
{
  long long int t = l[k];
  l[k] = l[k-1];
  l[k-1] = t;
}
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
  {
    long long int n;
    scanf("%lld",&n);
    long long int l[n];
    for(long long int i=0;i<n;i++) scanf("%lld",&l[i]);
    vector<long long int> v;
    long long int k = n-1;
    while(k>0 && l[k]<=l[k-1]) {v.pu(l[k]);k--;}
    if(k!=n-1) {v.pu(l[k]);k--;}
    if(k==-1 || n==1)printf("-1\n");
    else
    {
      long long int c = l[k];
      sort(v.begin(),v.end());
      if(!v.empty())
      {
        long long int a = *upper_bound(v.begin(),v.end(),c);
        for(long long int i =0;i<v.size();i++) if(v[i]==a) {v[i] = c;break;}
        l[k] = a;
      }
      else {swap(l,k);}
      for(long long int i=0;i<=k;i++) cout<<l[i];
      sort(v.begin(),v.end());
      for(long long int i=0;i<v.size();i++) cout<<v[i];
      cout<<endl;
    }
  }
  return 0;
}
