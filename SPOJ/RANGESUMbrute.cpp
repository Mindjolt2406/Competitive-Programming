#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  vector<long long int> v;
  for(long long int i=0;i<n;i++)
  {
    int c;
    cin>>c;
    v.pu(c);
  }
  long long int q;
  cin>>q;
  for(long long int h=0;h<q;h++)
  {
    long long int a;
    cin>>a;
    if(a==1)
    {
      long long int sum1 = 0;
      long long int b,c;
      cin>>b>>c;
      b--;c--;
      for(int i=b;i<=c;i++) sum1+=v[i];
      cout<<sum1<<endl;
    }
    else
    {
      long long int b;
      cin>>b;
      v.insert(v.begin(),b);
    }
  }
  return 0;
}
