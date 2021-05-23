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
#define __ freopen("reflection.in","r",stdin);
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



struct dat
{
	//Use required attributes
	int mn;

	//Default Values
	dat() : mn(0) {};
};

struct SegTree
{
	int N;
	vector<dat> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(dat &cur, dat &l, dat &r) 
	{
		cur.mn = l.mn+r.mn;
	}
	
	//	Handle lazy propagation appriopriately
	// 	think what should happen if clazy[2*node] is already 1 before propagate is called
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].mn = -st[node].mn;
		cLazy[node] = 0;
	}
	dat Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return dat();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		dat left=Query(node*2, L, M, i, j);
		dat right=Query(node*2 + 1, M + 1, R, i, j);
		dat cur;
		merge(cur, left, right);
		return cur;
	}

	dat pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			st[node].mn=val;
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	dat query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}

	dat query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 1, N, pos, val);
	}

	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

int32_t main()
{
	// __
	fastio();
	int t;
	cin>>t;
	while(t--)
	{
		int n=1e5+5;
		int q;
		cin>>q;
		SegTree st;
		st.init(n);
		vector<int> ar(n,0);
		BIT btree;
		btree.init(n);
		while(q--)
		{
			int x;
			cin>>x;
			if(x==0){cout<<0<<endl;
				st.update(1,1e5+1,1);
				continue;
			}
			int ans=st.query(1,x-1).mn;
			if((btree.rsum(1,x-1))%2==0)
			{
				ans+=x;
			}
			else
			{
				ans-=x;
			}
			cout<<ans<<endl;
			if(btree.rsum(x,x)==1)
			{
				st.update(x,0);
				st.update(x+1,1e5+1,1);
				btree.update(x,-1);
			}
			else
			{
				int cnt=btree.rsum(1,x-1);
				if(cnt%2==0)
				{
					st.update(x,2*x);
				}
				else
				{
					st.update(x,-2*x);
				}
				st.update(x+1,1e5+1,1);
				btree.update(x,1);
			}
		}
	}	
}
