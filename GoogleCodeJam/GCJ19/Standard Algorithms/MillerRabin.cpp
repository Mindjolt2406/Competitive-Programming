#include<bits/stdc++.h>
using namespace std;

int power(int x, int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int MillerRabin(int n)
{
  int p = n;
  p--;
  int prod = 1;
  int s = 0;
  while(p%2==0)
  {
    p/=2;
    prod*=2;
    s++;
  }
  cout<<"n: "<<n<<" p: "<<p<<" s: "<<s<<endl;
  int l[3] = {2,7,61};
  int boo = 0;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<s;j++)
    {
      if(l[i]>=n) continue;
      cout<<"l[i]: "<<l[i]<<" p: "<<p<<" n: "<<n<<" power(l[i],p,n): "<<power(l[i],p,n)<<endl;
      cout<<"j: "<<j<<" power(2,j,n): "<<power(2,j,n)<<" power(l[i],pow*p,n): "<<power(l[i],power(2,j,n)*p,n) <<endl;
      if(power(l[i],p,n)!=1 && power(l[i],power(2,j,n)*p,n) != n-1)  continue;
      else return 1;
    }
  }
  return 0;
}

int main()
{
  // for(int i=3;i<100;i++) if(MillerRabin(i)) cout<<i<<" ";
  // cout<<endl;
  int p;
  cin>>p;
  cout<<MillerRabin(p)<<endl;
  return 0;
}
