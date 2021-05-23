#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

onst int N = 505;

vector<int> where;
bool done = 0;
void precompute(vector<bitset<N>> a, int n, int m)
{
	where.assign(m, -1);
	for (int col = 0, row = 0; col < m && row < n; ++col)
	{
		for (int i = row; i < n; ++i)
			if (a[i][col])
			{
				swap(a[i], a[row]);
				break;
			}
		if (!a[row][col])
			continue;
		where[col] = row;

		for (int i = 0; i < n; ++i)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		++row;
	}
}
int gauss(vector<bitset<N>> a, int n, int m, bitset<N> &ans)
{
	if (!done)
		precompute(a, n, m);

	ans.assign(m, 0);
	for (int i = 0; i < m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i = 0; i < n; ++i)
	{
		double sum = 0;
		for (int j = 0; j < m; ++j)
			sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > EPS)
			return 0;
	}

	for (int i = 0; i < m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}
vector<bitset<N>> mat;
int n;
signed main()
{
	fastio();
	cin >> n;
	mat.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bool x;
			cin >> x;
			mat[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		mat[i][n] = 0;
		for (int j = i + 1; j < n; j++)
		{
			int tmp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = tmp;
		}
	}
	bitset<N> ans[n];
	for (int i = 0; i < n; i++)
	{
		mat[i][n] = 1;
		int x = gauss(mat, n, n, ans[i]);
		if (x == 0)
		{
			cout << "-1";
			return 0;
		}
		mat[i][n] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j])
			{
				cout << j + 1 << " ";
			}
		}
		cout << endl;
	}
}
