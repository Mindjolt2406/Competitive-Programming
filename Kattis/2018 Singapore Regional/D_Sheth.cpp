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
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
//#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/
const int N=5e5+10;
int ar[N];
int fi[35];
int la[35];
int n,k;

bool can(int mask)
{
	for(int b=30;b>=0;b--)
	{
		if((1<<b)&mask)
		{
			// if(fi[b]==-1)
			// {
			// 	continue;
			// }
			int cnt=0;
			int cur=0;
			for(int i=0;i<n;i++)
			{
				int ind=(i+la[b])%n;
				cur=cur|ar[ind];
				if((cur&mask)==mask)
				{
					cnt++;
					cur=0;
				}
			}
			if(cnt>=k)
			{
				return true;
			}
		}
	}
	return false;
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	memset(fi,-1,sizeof(fi));
	memset(la,-1,sizeof(la));
	for(int i=0;i<=30;i++)
	{
		// for(int j=0;j<n;j++)
		// {
		// 	if((1<<i)&ar[j])
		// 	{
		// 		fi[i]=j;
		// 		break;
		// 	}
		// }
		for(int j=n-1;j>=0;j--)
		{
			if((1<<i)&ar[j])
			{
				la[i]=j;
				break;
			}
		}
	}
	int mask=0;
	for(int i=30;i>=0;i--)
	{		
		if(can(mask|(1<<i)))
		{
			mask=mask|(1<<i);
		}
	}
	//t(can(7));
	cout<<mask<<endl;
}