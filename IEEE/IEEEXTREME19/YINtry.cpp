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
#define t(...) GET_MACRO(_VA_ARGS_,t6,t5, t4, t3, t2, t1)(_VA_ARGS_)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	int mi=1e9;
	string s;
	for(int i=0;i<(1<<n);i++)
	{
		string st;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				st+='1';
			}
			else
			{
				st+='0';
			}			
		}
		int cnt=0;
		for(int l=1;l<=n;l++)
		{
			for(int j=0;j<n-2*l;j++)
			{
				string s1=st.substr(j,l);
				string s2=st.substr(j+l,l);
				if(s1==s2)
				{
					cnt++;
				}
			}
		}
		if(cnt<mi)
		{
			mi=cnt;
			s=st;
		}
	}
	cout<<mi<<endl;
	if(s[0]=='0')
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='1')
			{
				s[i]='0';
			}
			else
			{
				s[i]='1';
			}
		}
	}
	cout<<s<<endl;
}