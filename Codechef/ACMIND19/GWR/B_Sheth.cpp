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
#define t(...) GET_MACRO(VA_ARGS,t6,t5, t4, t3, t2, t1)(VA_ARGS)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

const int N=1e5+10;
vector<int> adj[N];
int n;
int ans[N];

int dfs(int node,int par)
{
	int sum=1;
	vector<int> v;
	for(auto x: adj[node])
	{
		if(x==par)
		{
			continue;
		}
		int a=dfs(x,node);
		v.push_back(a);
		sum+=a;
	}
	v.push_back(n-sum);
	sort(v.begin(),v.end());
	int s1=0;
	for(int i=0;i<(int)v.size()-1;i++)
	{
		s1+=v[i];
	}
	int s2=v.back();
	if(s1<s2)
	{
		ans[node]=0;
	}
  else if((n-1)%2 == 0) 
  {
    ans[node] = 0;
  }
	else
	{
		if((s1-s2 + (int)inf)%2 == 0) ans[node] = 0;
    else ans[node] = 1;
	}	
	return sum;
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			adj[i].clear();
			ans[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(n==2)
		{
			cout<<"11\n";
			continue;
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
}