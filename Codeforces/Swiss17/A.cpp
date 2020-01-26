#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
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
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/
 
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	multiset<int,greater<int>> se;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		se.insert(x);
	}
	if(se.count(0))
	{
		for(int i=0;;i++)
		{
			if(!se.count((1LL<<i)))
			{
				cout<<(1LL<<i)<<endl;
				return 0;
			}
		}
	}
	int last=0;
	for(int i=0;;i++)
	{
		if(!se.count(1LL<<i))
		{
			break;
		}
		last=i;
		se.erase(se.find((1LL<<i)));
	}	
	if(se.empty())
	{
		cout<<(1LL<<last)+1;
		return 0;
	}
	int prev=-1;
	for(auto x: se)
	{
		if(x==prev)
		{
			continue;
		}
		prev=x;
		multiset<int,greater<int>> v;
		int dif=(1LL<<last)-x;
		int m=(1LL<<last)+dif;
		int cnt=0;
		int flag=1;
		int pp=1LL<<last;
		pp%=m;
		for(int j=last+1;cnt<se.size();j++,cnt++)
		{
			pp*=2;
			pp%=m;
			if(!se.count(pp))
			{
				flag=0;
				break;
			}
			v.insert(pp);
		}
		if(flag)
		{
			if(v==se)
			{
				cout<<m<<endl;
				return 0;
			}
		}
	}	
}
