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
#define tr(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ freopen("zeros.in","r",stdin);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
//#define MOD 1000000007
#define endl "\n" 
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/
 
int32_t main()
{
	// __
	fastio();
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,m,k;//x ones, y zeros
		cin>>x>>y>>m>>k;

		int half=(x+y)/2;
		// map<pair<int,int>,int> cnt;
		vector<int> v[x+1];
		for(int i=0;i<(1LL<<half);i++)
		{
			int n1=__builtin_popcountll(i);
			int mod=i%m;
			if(n1<=x)
				v[n1].push_back(mod);
		}
		for(int i=0;i<=x;i++)sort(v[i].begin(),v[i].end());
		int ans=0;
		for(int i=0;i<(1LL<<(x+y-half));i++)
		{
			// int mask=i;
			int mask=(i<<half);
			if((mask&(1LL<<(x+y-1)))==0)
			{
				continue;
			}
			int n1=__builtin_popcountll(mask);
			int mod=mask%m;
			int ot=x-n1;
			if(ot<0)continue;
			int ans1=0;
			int ptl=lower_bound(v[ot].begin(),v[ot].end(),k-mod)-v[ot].begin();
			int ptr=upper_bound(v[ot].begin(),v[ot].end(),m-mod)-v[ot].begin();
			ans1+=(ptr-ptl);
			ptl=lower_bound(v[ot].begin(),v[ot].end(),k-mod+m)-v[ot].begin();
			ptr=upper_bound(v[ot].begin(),v[ot].end(),2*m-mod)-v[ot].begin();
			ans1+=ptr-ptl;
			ans+=ans1;
			// tr(ans1);
		}
		cout<<ans<<endl;
	}
}
	
