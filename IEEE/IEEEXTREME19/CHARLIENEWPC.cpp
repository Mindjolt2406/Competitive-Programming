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
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/

const int N=13;
const int K=105;
int n;
int b;
vector<int> v[N];

int max(int x, int y)
{
  if(x>y) return x;
  return y;
}

unordered_map<int,int> dp[N];

int rec(int ind,int done)
{
  if(done>b)
  {
      return -1e16;
  }
	if(ind==n)
	{
		return 0;
	}

  if(dp[ind].count(done))
  {
    return dp[ind][done];
  }

	int ans=-1e16;
	for(int i=0;i<v[ind].size();i++)
	{
		ans=max(ans,rec(ind+1,done+v[ind][i])+v[ind][i]);
	}
	if(ans<0)
	{
		ans=-1e16;
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>b;
		cin>>n;

		for(int i=0;i<N;i++)
		{
			v[i].clear();
			dp[i].clear();
		}

		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v[i].resize(x);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				cin>>v[i][j];
			}
      sort(v[i].begin(),v[i].end());
		}

    int sum1 = 0;
    for(int i=0;i<n;i++) sum1+=v[i][0];
    if(sum1 > b) 
    {
      cout << 0 << endl;
      continue;
    }

    sum1 = 0;
    for(int i=0;i<n;i++) sum1+=v[i].back();
    if(sum1 <= b) 
    {
      cout << sum1 << endl;
      continue;
    }

		int ans=rec(0,0);
		if(ans<0)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
}