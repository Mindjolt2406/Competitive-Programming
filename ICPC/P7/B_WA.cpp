#pragma GCC optimize("O3")
#pragma GCC target("sse4")
// #pragma GCC optimize("Ofast")  
// #pragma GCC target("avx,avx2,fma") 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ freopen("tictactoe.in","r",stdin);freopen("tictactoe.out","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long
#define inf 1e18
#define ld long double

template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
/*-------------------------------------------------------------------------------------------------------------------------------------*/

signed main()
{
	fastio();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		pair<int,int> p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		sort(p,p+n);
		multiset<int> se;
		int cur=-1;
		int pt=0;
		int ans=0;
		while(pt<n || !se.empty())
		{	
			while(pt<n && p[pt].first<=cur)
			{
				if(p[pt].second>=cur)
					se.insert(p[pt].second);
				pt++;
			}

			if(se.size()>0)
			{
				// cur++;
				ans++;
				se.erase(se.begin());
                continue;
			}
			while(se.size()>0 && *(se.begin())<=cur)
			{
				se.erase(se.begin());
			}
			if(se.empty() && pt<n && p[pt].first>cur)
			{
				cur=p[pt].first;
			}
		}
		// while(pt<n)
		// {
			// multiset<int> se;
			// se.insert(p[pt].second);
			// while(se.size())
			// {
				
			// }
		// }
		cout<<ans<<endl;
	}
}