#include <iostream>
#define MOD 1000000007
using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
	  long long int n,w;
	  cin>>n>>w;
	  if(-9>w || w>8) cout<<0<<endl;
	  else if(w<0) cout<<(power(10,n-2,MOD)*(10-abs(w)))%MOD<<endl;
	  else cout<<(power(10,n-2,MOD)*(9-abs(w)))%MOD<<endl;
	}
	return 0;
}
