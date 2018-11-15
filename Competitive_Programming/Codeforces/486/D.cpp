#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pu push_back
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  long long int l[n];
  set<long long int> s;
  long long int m[32] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
  for(long long int i=0;i<n;i++) {cin>>l[i];s.insert(l[i]);}
  set<long long int> ::iterator it;
  long long int count = 0;
  long long int boo = 0,k = 0;
  for(it = s.begin();it!=s.end();it++)
  {
    for(long long int i=0;i<32;i++)
    {
      if(s.find(*it+m[i])!=s.end())
      {
        count = 2;
        boo = i;
        k = *it;
        if(s.find(*it+m[i]+m[i])!=s.end()) {count = 3;boo = i;break;}
      }
    }
    if(count==3)
    {
      cout<<3<<endl;
      cout<<*it<<" "<<*it+m[boo]<<" "<<*it+2*m[boo]<<endl;
      return 0;
      break;
    }
  }
  if(count==2)
  {
    cout<<2<<endl;
    cout<<k<<" "<<k+m[boo]<<endl;
  }
  else if(count!=3)
  {
      cout<<1<<endl;
      cout<<l[0]<<endl;
  }
  else cout<<0<<endl;
  return 0;
}
