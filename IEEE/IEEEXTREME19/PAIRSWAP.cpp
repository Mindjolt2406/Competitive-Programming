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
const int N=1e5+10;

int n;
int cnt[5];

vector<int> corr;
int mi=1e9;

void fun2(vector<vector<int> > &v, int a,int b,int c,int &cnt)
{
  int m = min(v[a][b],min(v[b][c],v[c][a]));
  cnt += 2*m;
  v[a][b] -= m;
  v[b][c] -= m;
  v[c][a] -= m;
}

void fun3(vector<vector<int> > &v, int a, int b, int c, int d, int &cnt)
{
  int m = min(v[a][b],min(v[b][c],min(v[c][d],v[d][a])));
  cnt += 3*m;
  v[a][b] -= m;
  v[b][c] -= m;
  v[c][d] -= m;
  v[d][a] -= m;
}

int fun(vector<vector<int> > &v)
{
  int cnt = 0;
  // 012 021 023 032 013 031 123 132
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      int min1 = min(v[i][j],v[j][i]);
      v[i][j]-=min1;
      v[j][i]-=min1;
      cnt += min1;
    }
  }

  fun2(v,0,1,2,cnt);
  fun2(v,0,2,1,cnt);
  fun2(v,0,2,3,cnt);
  fun2(v,0,3,2,cnt);
  fun2(v,0,1,3,cnt);
  fun2(v,0,3,1,cnt);
  fun2(v,1,2,3,cnt);
  fun2(v,1,3,2,cnt);

  fun3(v,0,1,2,3,cnt);
  fun3(v,0,1,3,2,cnt);
  fun3(v,0,2,1,3,cnt);
  fun3(v,0,2,3,1,cnt);
  fun3(v,0,3,1,2,cnt);
  fun3(v,0,3,2,1,cnt);

  return cnt;
}

int solve(vector<int> &ar,vector<int> &ord)
{	
	int l[4],r[4];
	int cur=0;
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	l[0]=0;
	r[0]=cnt[ord[0]]-1;
	for(int i=1;i<4;i++)
	{
		l[i]=r[i-1]+1;
		r[i]=l[i]+cnt[ord[i]]-1;
	}	
	for(int i=0;i<4;i++)
	{
		for(int j=l[i];j<=r[i];j++)
		{
			if(ar[j]==ord[i])
			{
				cur++;
			}
		}
	}
	int ma=cur;
	int shift=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			r[j]=(r[j]+1)%n;
			if(ar[l[j]]==ord[j])
			{
				cur--;
			}
			if(ar[r[j]]==ord[j])
			{
				cur++;
			}
			l[j]=(l[j]+1)%n;			
		}
		if(cur>ma)
		{
			ma=cur;
			shift=i;
		}
	}
	vector<int> nar(n);
	for(int i=0;i<n;i++)
	{
		nar[i]=ar[(i+shift)%n];
	}
	vector<int> comp;
	for(int i=0;i<4;i++)
	{
		int x=cnt[ord[i]];
		while(x--)
		{
			comp.push_back(ord[i]);
		}
	}
	int ans=0;
	vector<vector<int>> vv(4,vector<int>(4,0));
	for(int i=0;i<n;i++)
	{
		if(nar[i]!=comp[i])
		{
			vv[nar[i]][comp[i]]++;
		}
	}
	ans=fun(vv);
	return ans;
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		mi=1e9;
		string s;
		cin>>s;
		n=s.length();
		vector<int> ar;
		for(int i=0;i<n;i++)
		{
			char x=s[i];			
			ar.push_back(x-'A');
			cnt[x-'A']++;
		}
		int ans=1e9;
		vector<int> v(4);
		for(int i=0;i<4;i++)
		{
			v[i]=i;
		}
		for(int i=0;i<6;i++)
		{
			ans=min(ans,solve(ar,v));
			next_permutation(v.begin(),v.end());
		}		
		cout<<ans<<endl;
	}
}