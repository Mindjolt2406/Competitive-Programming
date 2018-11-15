#include<bits/stdc++.h>
#define MOD 1000000007
#define m make_pair
using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

pair<long long int, long long int> gp(int n)
{
  long long int a,b;
  a = power(26,n,MOD) -1;
  b = 25*(power(26,n-1,MOD));
  return m(a,b);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long int a,b,c,d,n,e,f;
    pair <long long int,long long int> p;
    cin>>n;
    p = gp((n+1)/2);
    a = p.first;
    b = p.second;
    p = gp(n/2);
    c = p.first;
    d = 26*p.second;
    e = ((a*d)%MOD + (c*b)%MOD)%MOD;
    f = (b*d)%MOD;
    cout<< (e*power(f,MOD-2,MOD))%MOD <<endl;
  }
  return 0;
}
