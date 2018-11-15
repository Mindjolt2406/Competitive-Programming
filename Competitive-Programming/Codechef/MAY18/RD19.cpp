#include<bits/stdc++.h>
#include<algorithm>
#define pu push_back
using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int gcd2(int* l,int n)
{
  int gcd1 = l[0];
  for(int i=1;i<n;i++)
  {
    int a = gcd1, b = l[i];
    int c = min(a,b); int d = max(a,b);
    gcd1 = gcd(c,d);
  }
  return gcd1;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++) cin>>l[i];
    sort(l,l+n);
    reverse(l,l+n);
    int k = gcd2(l,n);
    if(k!=1) cout<<-1<<endl;
    else cout<<0<<endl;
  }
  return 0;
}
