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
vector<int>dp[2];
int n;
int rec(string &s,int ind,int f)
{
	if(ind==2*n)
	{
		return 0;
	}
	int &ans=dp[f][ind];
	if(ans>=0)
	{
		return ans;
	}
	ans=((s[ind]-'0')==f)*(1+rec(s,ind+1,f));
	return ans;
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		dp[0].clear();
		dp[1].clear();
		string s;
		cin>>s;
		cout<<"Case "<<test<<": ";
		if(s.length()==1)
		{
			cout<<1<<endl;
			continue;
		}
		n=s.length();
		dp[0].resize(2*n+5,-1);
		dp[1].resize(2*n+5,-1);
		int a=0,r=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='A')
			{
				s[i]='0';
				a++;
			}
			else
			{
				s[i]='1';
				r++;
			}			
		}
		if(a==n || r==n)
		{
			cout<<n-1<<endl;
			continue;
		}
		s=s+s;		
		rec(s,0,0);
		rec(s,0,1);
		int ma=0;
		int ind=0;
		for(int i=0;i<n;i++)
		{
			if(rec(s,i,0)>ma)
			{
				ma=rec(s,i,0);
				ind=i;
			}
			if(rec(s,i,1)>ma)
			{
				ma=rec(s,i,1);
				ind=i;
			}			
		}
		int change=(ind+(ma/2))%n;
		if(ma==2)
		{
			for(int i=1;i<n;i++)
			{
				if(rec(s,i-1,0)==2 || rec(s,i-1,1)==2)
				{
					int f=s[i]-'0';
					f=!f;
					if(rec(s,i+1,f)==1)
					{
						change=i;
						break;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(rec(s,i,0)==2 || rec(s,i,1)==2)
				{
					int f=s[i]-'0';
					f=!f;
					if(rec(s,(i+n-2)%n,0)==1 || rec(s,(i+n-2)%n,1)==1)
					{
						change=i;
						break;
					}
				}
			}
		}
		// t(change);
		int ff=s[change]-'0';
		ff=!ff;
		s[change]='0'+ff;
		s[change+n]=s[change];
		// t(s);
		dp[0].clear();
		dp[1].clear();
		dp[0].resize(2*n+5,-1);
		dp[1].resize(2*n+5,-1);
		rec(s,0,0);
		rec(s,0,1);
		ma=0;		
		for(int i=0;i<n;i++)
		{
			if(rec(s,i,0)>ma)
			{
				ma=min(n,rec(s,i,0));
				ind=i;
			}
			if(rec(s,i,1)>ma)
			{
				ma=min(n,rec(s,i,1));
				ind=i;
			}			
		}
		cout<<ma<<endl;
	}
}