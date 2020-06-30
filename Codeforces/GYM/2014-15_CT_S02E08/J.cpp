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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int curx,cury;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
pair<int,int> next(char x)
{
	if(x=='F')
	{
		return {curx,cury};
	}
	else if(x=='B')
	{	
		return {-curx,-cury};
	}
	else if(x=='R')
	{
		for(int i=0;i<4;i++)
		{
			if(curx==dx[i] && cury==dy[i])
			{
				return {dx[(i+1)%4],dy[(i+1)%4]};
			}
		}
	}	
	else
	{
		for(int i=0;i<4;i++)
		{
			if(curx==dx[i] && cury==dy[i])
			{
				return {dx[(i+3)%4],dy[(i+3)%4]};
			}
		}
	}
	return {0,0};
}

int32_t main()
{
	fastio();
	int t;
	cin>>t;
	while(t--)
	{
		curx=0;
		cury=1;
		bool mat[300][300];
		MEMS(mat,0);
		int x=150;
		int y=150;
		mat[x][y]=1;
		string s;
		cin>>s;
		int mi_x=150,ma_x=150,ma_y=150,mi_y=150;
		for(int i=0;i<s.length();i++)
		{
			auto tmp=next(s[i]);
			x+=tmp.first;
			y+=tmp.second;
			mi_x=min(mi_x,x);
			ma_x=max(ma_x,x);
			mi_y=min(mi_y,y);
			ma_y=max(ma_y,y);
			mat[x][y]=1;
			curx=tmp.first;
			cury=tmp.second;
		}
		cout<<ma_x-mi_x+3<<" "<<ma_y-mi_y+2<<endl;
		for(int i=mi_x-1;i<=ma_x+1;i++)
		{
			for(int j=mi_y;j<=ma_y+1;j++)
			{	
				if(mat[i][j])
				{
					cout<<'.';
				}
				else
					cout<<'#';
			}
			cout<<endl;
		}
	}
}
