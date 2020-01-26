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
#define MOD 1000000007
#define endl "\n" 
//#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ar[n];
		unordered_set<int> adj[31];
		int cur=0;
		set<pair<int,int>> seq;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			cur=cur|ar[i];
			seq.insert({ar[i],i});
			for(int j=0;j<31;j++)
			{
				if((1<<j)&ar[i])
				{
					adj[j].insert(i);
				}
			}
		}
		ll sum=0;	
		vector<int> ans;		
		for(int i=0;i<n;i++)
		{
			sum+=1LL*cur;
			unordered_set<int> save;
			for(int j=30;j>=0;j--)
			{
				if(adj[j].size()==1)
				{
					auto x=adj[j].begin();
					int val=*x;
					save.insert(val);
				}
			}			
			if(save.size()==seq.size())
			{
				auto x=seq.begin();
				auto val=*x;
				seq.erase(x);				
				ans.push_back(val.second);
				for(int j=30;j>=0;j--)
				{
					if((1<<j)&ar[val.second])
					adj[j].erase(val.second);
				}
			}
			else
			{
				for(auto y: save)
				{
					seq.erase({ar[y],y});
				}				
				auto x=seq.begin();
				auto val=*x;
				seq.erase(x);
				ans.push_back(val.second);
				for(int j=30;j>=0;j--)
				{
					adj[j].erase(val.second);
				}
				for(auto y: save)
				{
					seq.insert({ar[y],y});
				}
			}	
			cur=0;
			for(int j=30;j>=0;j--)
			{
				if(adj[j].size()>=1)
				{
					cur=cur|(1<<j);
				}
			}
		}
		cout<<sum<<endl;
		for(auto x: ans)
		{
			cout<<x+1<<' ';
		}
		cout<<endl;
	}
}

