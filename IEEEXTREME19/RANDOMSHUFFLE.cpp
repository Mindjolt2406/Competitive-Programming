/*
Code Author: ADITYA SHETH (^_^)
*/
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
//#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/
const int N=1e5+10;

int n;
int cnt[5];

int solve(vector<int> &ar,vector<int> &ord)
{
	
	int f=ord[0];
	if(cnt[f]==0)
	{
		return 1e9;
	}
	int p1=0;
	int p2=cnt[f]-1;
	int cur=0;
	for(int i=p1;i<=p2;i++)
	{
		if(ar[i]==f)
		{
			cur++;
		}
	}
	int ma=cur;
	int shift=0;
	for(int i=1;i<n;i++)
	{
		p2=(p2+1)%n;
		if(ar[p1]==f)
		{
			cur--;
		}
		if(ar[p2]==f)
		{
			cur++;
		}
		p1+=1;
		p1%=n;
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
	for(int i=0;i<n;i++)
	{
		if(nar[i]!=comp[i])
		{
			ans++;
		}
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
		memset(cnt,0,sizeof(cnt));
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
		for(int i=0;i<30;i++)
		{
			ans=min(ans,solve(ar,v));
			next_permutation(v.begin(),v.end());
		}		
		cout<<ans<<endl;
	}
}
