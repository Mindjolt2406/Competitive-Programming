/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(_VA_ARGS_,t6,t5, t4, t3, t2, t1)(_VA_ARGS_)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/

#define endl "\n" 
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/
ll poww(long long a, long long n, long long m)
{
        long long ans = 1;
        long long mul = a;
        while (n != 0)
        {
                if (n % 2)
                {
                        ans = (ans * mul) % m;
                }
                mul = (mul * mul) % m;
                n /= 2;
        }
        return ans;
}
/* 
Fermat's little theorem: 
1) (a/b)%mod= (a*(poww(b,mod-2,mod)))%mod iff a%b==0
2) (a^b)%mod= (a^(b%(mod-1)))%mod iff mod is prime
*/
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int MOD=pow(10,y);
		int ans=MOD;
		if(x%2==0 && x%5==0)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<=86399;i++)
		{
			ans=min(ans,poww(x,i,MOD));
		}
		cout<<ans<<endl;
	}
}